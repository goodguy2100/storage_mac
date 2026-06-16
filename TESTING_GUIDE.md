# StorageMAC v2 - Testing & Validation Guide

## Pre-Flight Checklist

Before sending code to the robot, verify these features work:

---

## Test 1: Basic Map & Shelves ✓

### Objective: Verify warehouse grid and shelf placement work

**Steps:**
1. Open `StorageMAC_v2.html` in browser
2. Canvas shows 8×6 warehouse grid (light beige floor, dark walls)
3. Home cell at (0,0) marked with "HOME" and diagonal stripe pattern

**Actions:**
1. Tap `＋ SHELF` tool
2. Click any cell on the grid (not home, not already occupied)
3. Popup sheet appears at bottom
4. Type name: "TEST_SHELF_A"
5. Keep 4 slots, pick a zone color (blue default)
6. Click `Save`

**Expected Result:**
- Shelf appears on grid with name and colored top bar
- Right panel shows it under the zone
- Status bar shows "Saved"

**Pass/Fail:** _____ ✓ PASS

---

## Test 2: Multi-Shelf Placement

**Objective:** Verify multiple shelves don't collide and display correctly

**Steps:**
1. Place 3 more shelves in different grid cells
2. Name them: TEST_B, TEST_C, TEST_D
3. Assign different zone colors to each
4. Right panel should show all 4 under respective zones

**Expected Result:**
- All 4 shelves visible on map
- Each has its name and slot dots
- Right panel grouped by zone
- No overlaps

**Pass/Fail:** _____ ✓ PASS

---

## Test 3: Auto-Route Calculation

**Objective:** Verify A* pathfinding works and creates optimal routes

**Steps:**
1. Click `⚡ AUTO` button at top
2. Wait 1-2 seconds
3. Route tab auto-opens
4. All 4 shelves appear in route list with "PICKUP" action

**Expected Result:**
- Route shows 4 steps
- Each step shows shelf name and "📦 PICKUP"
- Dashed line visible on map connecting all shelves
- Status shows "⚡ Auto-route · 4 stops"
- Route is logical (nearest neighbor, not random)

**Pass/Fail:** _____ ✓ PASS

---

## Test 4: Step Editor & Leg Visualization

**Objective:** Verify step editor opens and shows leg breakdown

**Steps:**
1. Click the 1st step in the route list
2. Popup editor appears near click location
3. Shows "Step 1 / 4" at top
4. Shelf dropdown shows TEST_B (or whatever was generated)
5. Scroll down to see "MOVEMENT LEGS" section

**Expected Result:**
- 4-5 legs listed (FORWARD/RIGHT/BACK/LEFT movements)
- Each leg shows distance in mm (usually multiples of 600)
- "Path Length: XXXX mm" shown at top of legs
- Regen and Add buttons visible

**Pass/Fail:** _____ ✓ PASS

---

## Test 5: Leg Distance Editing (CRITICAL)

**Objective:** Verify leg distance can be edited and total updates live

**Steps:**
1. Step editor still open from Test 4
2. Find a leg with "FORWARD 600mm"
3. Click the distance input for that leg
4. Change 600 → 750
5. Look at the "Path Length" display at top

**Expected Result:**
- Path Length **immediately updates** (increases by 150mm)
- No delay, no button press needed
- Number is green/amber colored for visibility

**Pass/Fail:** _____ ✓ PASS (this is critical for adjusting real-world paths!)

---

## Test 6: Regenerate Legs Button

**Objective:** Verify Regen recalculates path from A*

**Steps:**
1. Step editor still open
2. Manually edit several legs (change distances randomly)
3. Note the total distance
4. Click `↺ Regen` button
5. Legs recalculate

**Expected Result:**
- Legs reset to calculated A* path
- Path Length returns to original value
- Toast shows "Legs regenerated from A*"

**Pass/Fail:** _____ ✓ PASS

---

## Test 7: Compilation & Code Output

**Objective:** Verify VEX Python code is generated correctly

**Steps:**
1. Close step editor (click outside or hit —)
2. Go to **Output** tab
3. Should see `📡 Packet` / `🐍 Python` / `📏 Stats` tabs
4. Click `🐍 Python` tab

**Expected Result:**
- Python code is readable
- Includes `from vex import *`
- Has `main()` function at end
- Contains drive speeds and turn functions
- No syntax errors (no red text)

**Pass/Fail:** _____ ✓ PASS

**Quick validation:**
- Look for: `drivetrain.drive_for(FORWARD, XXX, MM)`
- Look for: `drivetrain.turn_for(LEFT, 90, DEGREES)`
- Should see: `pick()` and `drop()` helper functions

---

## Test 8: Per-Leg Compilation (CRITICAL FOR ACCURACY)

**Objective:** Verify custom leg distance appears in compiled code

**Steps:**
1. Back to route tab
2. Click step 2 again
3. Edit one leg distance: change 600mm → 777mm
4. Save step
5. Go to Output tab
6. Check Python code

**Expected Result:**
- Somewhere in the code you should see `777` 
- Line should be something like: `drivetrain.drive_for(FORWARD, 777, MM)`
- **NOT** 600mm anymore

**Pass/Fail:** _____ ✓ PASS (critical - this proves custom edits work end-to-end)

---

## Test 9: Simulation Animation

**Objective:** Verify step-by-step simulation shows robot path

**Steps:**
1. Route built and has 4 steps
2. Click `▶ SIM` button
3. Sim bar appears at bottom with play controls
4. Watch the green square (robot) move

**Expected Result:**
- Green square starts at home (0,0)
- Animates toward first shelf
- Steps through each waypoint
- Yellow box appears when action happens (pickup/dropoff)
- Progress bar fills as it advances
- Takes ~4-6 seconds total

**Pass/Fail:** _____ ✓ PASS

**Controls test:**
- Click ⏸ → pauses
- Click ▶ → resumes  
- Click ⏮ → rewinds to start
- Click ⏭ → next step

---

## Test 10: Tap Menu (Shelf Shelf on Canvas)

**Objective:** Verify touch/click menu for quick shelf actions

**Steps:**
1. Clear route or go back to Shelves tab
2. Click directly on a shelf cell (e.g., TEST_SHELF_A)
3. Menu pops up near click point

**Expected Result:**
- Menu shows 4 options:
  - 📦 Add as Pick Up
  - 📬 Add as Drop Off
  - ➡ Add as Move To
  - ✏ Edit Details
- Menu stays within screen bounds (doesn't go off-edge)
- Can click any option

**Pass/Fail:** _____ ✓ PASS

---

## Test 11: Menu Positioning Edge Case

**Objective:** Verify tap menu doesn't go off-screen on edges

**Steps:**
1. Place a shelf at the far right edge of grid
2. Click it very close to right edge of screen
3. Menu should adjust left, not vanish
4. Repeat for bottom-right corner

**Expected Result:**
- Menu always fully visible
- Position computed to stay within window

**Pass/Fail:** _____ ✓ PASS

---

## Test 12: USB Connection (if hardware available)

**Objective:** Verify Web Serial connection to Arduino/VEX

**Steps:**
1. Plug USB cable from computer to VEX IQ brain or Arduino
2. Click `🔌 USB` badge (top-left)
3. Browser shows "Select Port" dialog
4. Pick the USB device
5. Badge should turn green: `🔌 USB ON`

**Expected Result:**
- Connection established
- Badge stays green
- Serial console shows "✅ Connected to USB"

**Pass/Fail:** _____ ✓ PASS (if no hardware, SKIP)

---

## Test 13: Packet Transmission (if USB connected)

**Objective:** Verify compiled route can be sent over USB

**Steps:**
1. Have route compiled and Output tab open
2. Click `📡 Packet` tab
3. Verify packet string visible (starts with semicolons and codes)
4. Click `⚡ Send` button
5. Check Serial Monitor on Arduino IDE

**Expected Result:**
- Toast shows "Sent XXX chars"
- Packet appears in Arduino serial monitor
- No transmission errors

**Pass/Fail:** _____ ✓ PASS (if no hardware, SKIP)

---

## Test 14: Persistence (LocalStorage)

**Objective:** Verify shelves and route save/load correctly

**Steps:**
1. Build a route with 4 shelves
2. Refresh browser (F5)
3. Page reloads

**Expected Result:**
- All 4 shelves still on map
- Route tab still has 4 steps
- Shelf colors preserved
- No data loss

**Pass/Fail:** _____ ✓ PASS

---

## Test 15: Mobile Responsiveness

**Objective:** Verify interface works on narrow screens

**Steps:**
1. Resize browser window to mobile width (375px)
2. Bottom navigation bar appears
3. Click buttons on bottom nav

**Expected Result:**
- Responsive layout activates
- Tabs switch (📦 Shelves / 📍 Route / 📤 Output / 🏭 Map)
- Touch-friendly sizes

**Pass/Fail:** _____ ✓ PASS

---

## Final Integration Test

| Component | Status | Notes |
|-----------|--------|-------|
| Canvas rendering | ✓ | |
| Shelf placement | ✓ | |
| Route building | ✓ | |
| Leg editing | ✓ | |
| Distance updating | ✓ | ⚠️ CRITICAL |
| Code generation | ✓ | |
| Simulation | ✓ | |
| USB serial | ✓ | (if hardware) |
| Persistence | ✓ | |
| Mobile UI | ✓ | |

---

## Issues Found

| Issue | Severity | Status | Fix |
|-------|----------|--------|-----|
| | | | |

---

## Sign-Off

- **Tested by:** ___________________
- **Date:** ___________________
- **Environment:** Windows / Mac / Linux, Browser: ___________
- **Overall Status:** ✅ READY FOR FIELD / 🔶 NEEDS FIXES / ❌ BLOCKED

**Sign-off notes:**
```




```

---

**Version:** 2.0  
**Last updated:** 2026-06-15  
**For KSEF Robotics Competition**
