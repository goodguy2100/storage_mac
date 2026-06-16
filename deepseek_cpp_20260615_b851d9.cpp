#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

// ── PINS ──
#define RST_PIN     9
#define SS_PIN      10
#define TRIG_PIN    2
#define ECHO_PIN    3
#define BT_RX       7   // HC‑05 TX
#define BT_TX       8   // HC‑05 RX

MFRC522 mfrc522(SS_PIN, RST_PIN);
SoftwareSerial btSerial(BT_RX, BT_TX);

const String RACK_ID = "RACK_A1";
const int EMPTY_THRESHOLD_CM = 25;

String lastStatus = "UNKNOWN";
String activeUID = "NONE";

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("--- StorageMAC Bridge Node Ready ---");
  btSerial.println("--- StorageMAC Bridge Node Ready ---");
}

void loop() {
  // Read ultrasonic
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distanceCM = duration * 0.034 / 2;
  if(distanceCM <= 0 || distanceCM > 200) distanceCM = EMPTY_THRESHOLD_CM + 10;

  // Read RFID
  String currentUID = "NONE";
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    currentUID = "";
    for(byte i=0; i<mfrc522.uid.size; i++) {
      if(mfrc522.uid.uidByte[i] < 0x10) currentUID += "0";
      currentUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    currentUID.toUpperCase();
    activeUID = currentUID;
    mfrc522.PICC_HaltA();
  }

  // State determination
  String currentStatus = (distanceCM < EMPTY_THRESHOLD_CM) ? "LOADED" : "EMPTY";
  if(currentStatus == "EMPTY") activeUID = "NONE";

  // Send telemetry on change
  if(currentStatus != lastStatus) {
    sendTelemetry(currentStatus, activeUID, distanceCM);
    lastStatus = currentStatus;
  }

  // Handle incoming commands ('R' request)
  if(Serial.available()) {
    char c = Serial.read();
    if(c == 'R') sendTelemetry(currentStatus, activeUID, distanceCM);
  }
  if(btSerial.available()) {
    char c = btSerial.read();
    if(c == 'R') sendTelemetry(currentStatus, activeUID, distanceCM);
  }

  delay(200);
}

void sendTelemetry(String status, String uid, long dist) {
  String packet = "PKT:" + RACK_ID + ";" + status + ";" + uid + ";" + String(dist) + ";";
  Serial.println(packet);
  btSerial.println(packet);
}