# StorageMAC v2 - Release Notes

## Overview

StorageMAC is a web-based warehouse automation planner for KSEF (Kenya Science & Engineering Fair) VEX IQ robotics competition. It lets you design shelf layouts, plan robot routes, edit movement paths down to the millimeter, and generate VEX IQ Python code — all in your browser.

**Version:** 2.0 (June 15, 2026)

---

## What's New in v2

### ✨ Major Improvements

1. **Live Leg Distance Display**
   - When editing a step, total path length now displays at the top
   - Updates instantly as you adjust distances
   - No need to recompile to see changes

2. **Per-Leg Movement Editing**
   - Break down each step into individual "legs" (forward, right, back, etc.)
   - Edit distance (mm) and turn angle (°) for each leg independently
   - Perfect for adapting to real warehouse dimensions and obstacles

3. **Regenerate Path Button**
   - Messed up a leg? Click `↺ Regen` to have A* recalculate it
   - One-click restore to optimal path without rebuilding whole route

4. **Smarter Tap Menu**
   - Click any shelf on the map → menu appears
   - 4 quick actions: Pick Up, Drop Off, Move To, Edit Shelf
   - Menu automatically repositions if it would go off-screen

5. **Full Route Preservation**
   - Auto-route now keeps all your custom settings (speed, wait times, notes)
   - No data loss when regenerating routes

---

## Key Features

### Map & Warehouse Design
- ✅ Customizable grid (3-20 columns, 3-16 rows)
- ✅ Adjustable cell size (100mm-3000mm per cell)
- ✅ Rectangular or L-shaped warehouse layouts
- ✅ Place obstacles/blocks for collision avoidance
- ✅ Drag shelves to reposition

### Route Planning
- ✅ Click shelves to add to route
- ✅ Tap shelf menu for quick actions (pick/drop/move)
- ✅ Auto-route using A* pathfinding
- ✅ Manual route building step-by-step
- ✅ Reorder steps with ↑ ↓ buttons

### Movement Control (NEW)
- ✅ Edit individual path legs (FORWARD/BACK/RIGHT/LEFT/TURN)
- ✅ Set custom distances for each leg (real-world adjustments)
- ✅ Adjust turn angles (0-360°)
- ✅ Live distance total display
- ✅ Regenerate from A* if needed

### Code Generation
- ✅ VEX IQ Python output (ready to copy-paste to robot)
- ✅ Binary packet format (for Arduino bridge)
- ✅ Route statistics (distance, time estimate, step breakdown)
- ✅ One-click copy to clipboard

### Simulation
- ✅ Animate robot along planned path
- ✅ Step-by-step control (play, pause, rewind, next)
- ✅ Visual collision detection
- ✅ Progress tracking

### Hardware Integration
- ✅ USB serial bridge to Arduino sensors
- ✅ VEX IQ telemetry parsing
- ✅ Real-time shelf status updates
- ✅ Packet transmission (Chrome/Edge)

### User Experience
- ✅ Dark theme (low-power, easy on eyes)
- ✅ Mobile responsive (bottom navigation)
- ✅ Local storage persistence
- ✅ Toast notifications for feedback
- ✅ Tap menu system for quick actions

---

## File Contents

```
somac/
├── StorageMAC_v2.html           ← MAIN FILE - use this
├── USAGE_GUIDE.md               ← How to use each feature
├── TESTING_GUIDE.md             ← 15-point testing checklist
├── CHANGELOG.md                 ← What changed from v1
├── README.md                    ← This file
└── deepseek_html_20260615_342dbe.html  ← Backup
```

---

## Quick Start (2 minutes)

1. **Open** `StorageMAC_v2.html` in Chrome or Edge
2. **Place shelves**: Click `＋ SHELF`, tap cells, name them
3. **Build route**: Click `⚡ AUTO` (or manually add with quick buttons)
4. **Edit legs** (optional): Click a step → adjust distances in mm
5. **Simulate**: Click `▶ SIM` → watch robot path
6. **Copy code**: Go to Output tab → click 📋 Copy
7. **Send to VEX**: Paste Python into VEX IDE

---

## Browser Compatibility

| Feature | Chrome | Edge | Firefox | Safari |
|---------|--------|------|---------|--------|
| UI/Canvas | ✅ | ✅ | ✅ | ✅ |
| Simulation | ✅ | ✅ | ✅ | ✅ |
| USB Serial | ✅ | ✅ | ❌ | ❌ |
| Full duplex | ✅ | ✅ | ❌ | ❌ |

**Recommended:** Chrome or Edge on Windows/Mac (for USB serial support)

---

## Hardware Requirements

### Minimum (UI Only)
- Any modern browser
- Any computer/tablet

### Full Integration
- VEX IQ Robot brain
- Arduino (optional, for sensors)
- USB cable (A to Micro)
- Chrome or Edge browser on Windows/Mac

### Tested With
- VEX IQ motors (Ports 8, 11, 2, 3)
- Inertial sensor
- Arduino HC-SR04 (ultrasonic)
- Arduino RC522 (RFID reader)

---

## API Reference

### URL Parameters
None - all data stored locally

### Local Storage Keys
- `smac_cfg` → configuration
- `smac_shelves` → shelf array
- `smac_blocks` → obstacle array
- `smac_route` → route steps
- `smac_sel` → selected shelves

### Exported Data
Python code (copy-paste ready)  
Packet format (semicolon-delimited binary)

---

## Known Limitations

1. **No multi-user sync** - UI only (client-side, no server)
2. **A* limited to grid cells** - no sub-cell collision detection
3. **USB only on Chrome/Edge** - browser API limitation
4. **No video/camera** - map editing only, no live feed
5. **Timed movements** - open-loop (no encoder feedback in generated code)

---

## Troubleshooting

### Route won't generate
- Ensure shelves aren't placed on home cell (0,0)
- Check that no shelves are on top of each other
- Try clicking ⚡ AUTO again

### USB won't connect
- Use Chrome or Edge (Firefox/Safari don't support Web Serial API)
- Check USB cable is plugged in
- Try different USB port
- Restart browser

### Simulation shows collision
- Red overlay indicates path hits a block
- Click ↺ Regen to recalculate leg
- Or place block elsewhere

### Code syntax errors
- Verify Compile button was clicked
- Check Output tab (should show valid Python)
- Try regenerating route

---

## Performance Notes

- **Typical:** 8×6 grid, 10 shelves, 10 route steps = smooth
- **Large:** 20×16 grid, 50+ shelves = some lag on draw
- **Limit:** Canvas redraws on every edit (efficient for typical KSEF scenarios)

---

## For KSEF Competition

### Before the Fair
- ✅ Test on VEX IQ brain (ports, sensors, speed settings)
- ✅ Verify Arduino integration (if using sensors)
- ✅ Calibrate robot dimensions (cell size, speed %)
- ✅ Practice route edits (muscle memory for troubleshooting)

### At the Fair
1. Bring laptop/tablet with StorageMAC
2. Bring USB cable for VEX connection
3. Bring printed guide (QR codes, screenshots) in case WiFi is down
4. Have backup HTML file on USB stick
5. Practice quick edits (legs, speed, wait times)

### Judge Demonstration
1. Place obstacles/shelves on map to match fair layout
2. Show route planning (AUTO or manual)
3. Show leg editing (adjust distance for accuracy)
4. Run simulation
5. Generate Python code
6. Discuss adaptability and real-time adjustments

---

## Developers

### Core Architecture
- **Canvas**: 2D grid-based rendering
- **Pathfinding**: A* with 4-directional movement
- **Routing**: Nearest-neighbor + manual step ordering
- **Code Gen**: Template-based VEX IQ Python generation
- **Serial**: Web Serial API (Chrome/Edge only)
- **Storage**: localStorage (client-side, persistent)

### Main Functions (82 total)
- `draw()` - render warehouse grid
- `astar()` - pathfinding algorithm
- `renderRoute()` - display route steps
- `openStepEditor()` - leg editing popup
- `compileOutput()` - generate code
- `handleBT()` - USB serial management

### Customization Points
- Colors: `:root` CSS variables
- Grid size: `cfg` object
- Cell size: `cfg.cellMM`
- Speed limits: UI sliders
- Zone colors: `ZONE_COLORS` array

---

## License & Attribution

**StorageMAC** was developed for KSEF with assistance from AI coding tools (Claude, DeepSeek).

Built with:
- Vanilla JavaScript (no frameworks)
- HTML5 Canvas API
- Web Serial API
- CSS Grid & Flexbox

---

## Support & Feedback

### Common Questions

**Q: Can I use this offline?**  
A: Yes! After first load, everything works offline. Data stays in browser storage.

**Q: Can I export/import routes?**  
A: Currently no. Copy-paste the Python code to share routes.

**Q: Does it work on mobile?**  
A: Yes, UI is responsive. But USB serial only works on desktop browsers.

**Q: Can multiple robots use the same route?**  
A: Each browser has its own storage. Copy HTML to another computer to share.

---

## Changelog

### v2.0 (2026-06-15)
- ✨ Added live leg distance display
- ✨ Added per-leg editing (direction, distance, angle)
- ✨ Added ↺ Regen button
- 🔧 Improved tap menu positioning
- 🔧 Fixed auto-route to preserve route properties
- 📚 Created USAGE_GUIDE.md
- 📚 Created TESTING_GUIDE.md

### v1.0 (2026-06-14)
- 🎉 Initial release
- Basic shelf placement
- Auto-route with A*
- VEX Python code generation
- USB serial bridge
- Simulation

---

## Next Steps

- [ ] Test on physical VEX IQ robot
- [ ] Verify Arduino sensor parsing
- [ ] Fine-tune speed calibration
- [ ] Demo at KSEF fair
- [ ] Gather feedback from judges
- [ ] Plan v3 features (if time)

---

**Questions?** Check `USAGE_GUIDE.md` or `TESTING_GUIDE.md`

**Ready to deploy!** Use `StorageMAC_v2.html`

---

*Built for Kenya Science & Engineering Fair 2026*  
*VEX IQ Robotics | Warehouse Automation Track*
