# StorageMAC v2 - Quick Usage Guide

## Getting Started

Open `StorageMAC_v2.html` in a modern browser (Chrome/Edge recommended for USB serial).

---

## Main Features

### 1️⃣ **Map & Shelves Panel**
- **Left side**: Warehouse grid (8×6 cells by default)
- **Tools at top**: SHELF, BLOCK, MOVE, Settings, AUTO, SIM, CLEAR
- **Right panel**: Shelves list organized by zone color

**How to place shelves:**
1. Click `＋ SHELF` tool (top-left)
2. Tap on a cell in the grid
3. Name it, set slots (2/3/4/6/8), pick a zone color
4. Click `Save`

**How to move a shelf:**
1. Click `↔ MOVE` tool
2. Drag any shelf to a new cell

**How to add blocks/obstacles:**
1. Click `⬛ BLOCK` tool
2. Tap cells to toggle blocks on/off

---

### 2️⃣ **Routing & Path Building**

#### Quick Route Build
1. Select shelves in the left panel (click them to check)
2. Click `Build Route →` button
3. Route appears in the Route tab with nearest-neighbor order

#### Auto-Route
1. Click `⚡ AUTO` button
2. System calculates optimal path using A* + nearest neighbor
3. All shelves included with "pickup" action

#### Manual Route
1. Go to **Route** tab
2. Use Quick Add buttons (📦 Pick Up / 📬 Drop Off / ➡ Move To)
3. Pick shelves from the popup picker
4. Route builds step-by-step

---

### 3️⃣ **Editing Individual Steps**

**Click any step in the route list** to open the step editor popup:

- **TARGET SHELF**: Change which shelf this step goes to
- **ACTION**: Pick Up / Drop Off / Move / Wait
  - If **Wait** is selected: set wait time in seconds
  - If anything else: edit movement legs (see below)

#### Movement Legs (Advanced)
Each step breaks down into "legs" - individual movements:

- **Leg 1**: Forward 600mm (move forward one cell)
- **Leg 2**: Right 600mm with 90° turn (move right one cell)
- etc.

**Edit a leg:**
1. Click the direction dropdown (FORWARD/BACK/RIGHT/LEFT/TURN_RIGHT/TURN_LEFT)
2. Change distance in mm (e.g., 750mm for a slightly longer reach)
3. Adjust turn angle in degrees (usually 90° for grid turns)

**The distance display at top shows your total path length** ← watch this!

**Regen button:**
- If you mess up and want A* to recalculate: click `↺ Regen`
- Puts you back on the optimal path for this step

#### Speed & Notes
- Drag **APPROACH SPEED** slider (10-100%)
- Type a **NOTE** (e.g., "tight corner at B2")

#### Reorder Steps
- Click `↑` to move step earlier
- Click `↓` to move step later

**Save** or **Delete** when done

---

### 4️⃣ **Compilation & Code Generation**

Go to the **Output** tab after building a route:

#### Three views available:
- **📡 Packet**: Binary command format (for Arduino/VEX telemetry)
- **🐍 Python**: Full VEX IQ Python code ready to copy
- **📏 Stats**: Route summary (distance, time estimate, step breakdown)

**Copy** button → copies text to clipboard  
**Send** button (⚡) → if USB is connected, sends packet to robot

---

### 5️⃣ **Simulation**

Click `▶ SIM` button to animate the robot following your route:

- **⏮ ⏸ ⏭** buttons: rewind, play/pause, next
- Progress bar shows position along route
- Green square = robot, showing live location
- Yellow square = picking/dropping action happening

**Red overlay** = collision warning (if path hits a block)

---

### 6️⃣ **USB & Serial Connection**

Click `🔌 USB` badge in top-left:

1. Browser asks you to pick a COM port → select Arduino/VEX
2. Badge turns green `🔌 USB ON` when connected
3. Now you can:
   - Send compiled route packets to the robot
   - Receive sensor telemetry (shelf fullness, status)

**Note:** Web Serial only works on Chrome/Edge on desktop (not Safari/Firefox).

---

### 7️⃣ **Settings** ⚙️

Click the `⚙` tool button:

- **Columns / Rows**: Adjust grid size (3-20)
- **Cell size (mm)**: Distance per cell (100-3000mm)
- **Robot width (mm)**: Used for collision checks
- **Drive speed %**: Motor percentage for forward/back
- **Turn speed %**: Motor percentage for rotation
- **Shape**: Rectangle or L-Shape warehouse

**Changes apply immediately** after you hit `Apply`

---

## Pro Tips 🚀

1. **Set realistic speeds**: 45-50% drive, 35-40% turn (adjust after testing on robot)
2. **Test a leg**: Set distance to something non-standard (e.g., 750mm) and watch the Compile output
3. **Collision avoidance**: Place blocks where the robot can't go; A* will route around them
4. **Wait at shelves**: Use "Wait 2-3 seconds" in cramped aisles
5. **Backup your layout**: Everything saves to browser storage, but export your shelf config if important
6. **Simulation first**: Always run SIM before sending to real robot

---

## Keyboard Shortcuts

| Action | Shortcut |
|--------|----------|
| Tap to close menus | Anywhere on canvas |
| Delete shelf | Open shelf → click Delete button |
| Clear everything | Click `⌫` button (top-right) |
| Copy output code | Go to Output tab → click Copy |

---

## Common Issues & Fixes

| Problem | Solution |
|---------|----------|
| Route not appearing after AUTO | Ensure shelves are placed and valid; check for home (0,0) conflicts |
| Leg editor frozen | Close and re-open step |
| USB won't connect | Use Chrome/Edge on Windows/Mac; Arduino must be plugged in first |
| Simulation jerky | Reduce grid size or cell count; close other tabs |
| Code output is blank | Click Compile button or switch tabs |

---

## Next Steps

1. ✅ Place shelves & build a route
2. ✅ Edit legs to match your real warehouse dimensions
3. ✅ Run simulation to verify
4. ✅ Connect USB and send to VEX IQ robot
5. ✅ Tune speeds based on real-world results
6. ✅ Add blocks around obstacles for accurate routing

---

**Version:** 2.0 (2026-06-15)  
**Tested with:** VEX IQ, Arduino HC-SR04/RC522 sensors  
**Browser support:** Chrome 89+, Edge 89+, Firefox 88+ (no USB), Safari (no USB)
