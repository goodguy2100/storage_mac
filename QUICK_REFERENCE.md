# StorageMAC v2 - Quick Reference Card

## 🚀 Launch
```
Open: StorageMAC_v2.html in Chrome or Edge
```

---

## 📍 Main Workflow

### 1. Build Map
| Action | Do This |
|--------|---------|
| Place shelf | Click `＋ SHELF` → tap cell → name it → Save |
| Move shelf | Click `↔ MOVE` → drag shelf to new cell |
| Add obstacle | Click `⬛ BLOCK` → tap cells to toggle |
| Clear all | Click `⌫` button (danger red) |

### 2. Create Route
| Method | Steps |
|--------|-------|
| **Quick Auto** | Click `⚡ AUTO` → done in 1 second |
| **Manual Quick** | Go Route tab → click Quick Add button → pick shelf |
| **Tap Menu** | Click shelf on map → choose action from popup |
| **Full Manual** | Go Route tab → add each shelf one-by-one |

### 3. Edit Movement
1. Click a step in route list → editor popup opens
2. Adjust **shelf** or **action** (pickup/dropoff/move/wait)
3. Scroll to **Movement Legs** section
4. Edit each leg:
   - Direction: FORWARD/BACK/RIGHT/LEFT/TURN_*
   - Distance: 600mm, 750mm, etc.
   - Angle: 90°, 45°, etc.
5. Watch **total distance** update at top ✨
6. Click **Save** when done

### 4. Verify & Export
| Tab | Use For |
|-----|---------|
| 📡 Packet | Raw binary format (Arduino) |
| 🐍 Python | VEX IQ code (copy to IDE) |
| 📏 Stats | Route summary (printable) |

---

## ⚡ Quick Keys

| Goal | Do This |
|------|---------|
| Edit leg distances | Click route step → scroll to legs → type new mm value |
| See total path | Look at top of legs section (should update live) |
| Reset messed-up path | Click `↺ Regen` button in leg editor |
| Test without running | Click `▶ SIM` button |
| Move step earlier | Click `↑` button in editor popup |
| Move step later | Click `↓` button in editor popup |
| Undo all changes | Refresh page (F5) or click `⌫` clear button |
| Quick start location | All routes begin at home (0,0) in bottom-left |

---

## 🎮 Simulation Controls

```
⏮  ← rewind to start
⏸  ← pause (or play if paused)
⏭  ← step forward once
```

Progress bar = current position along route

---

## 🔌 USB Connection

```
1. Plug in VEX or Arduino
2. Click 🔌 USB badge (top-left)
3. Pick device in browser dialog
4. Badge turns green = connected ✓
5. Go Output tab → click ⚡ Send
```

**Important:** Chrome/Edge only (no Firefox/Safari)

---

## ⚙️ Settings to Adjust

| Setting | Range | Notes |
|---------|-------|-------|
| Columns | 3-20 | Warehouse width |
| Rows | 3-16 | Warehouse depth |
| Cell size | 100-3000mm | Per-cell distance |
| Drive speed % | 10-100 | Motor power (adjust if slow) |
| Turn speed % | 10-100 | Turn power (adjust if jerky) |
| Robot width | 200-2000mm | Collision buffer |

---

## 🐛 Troubleshooting

| Problem | Fix |
|---------|-----|
| Route won't generate | Shelves not on top of each other? Home cell empty (0,0)? |
| Leg total not updating | Refresh page (F5) |
| USB won't connect | Use Chrome/Edge, check cable |
| Simulation shows red (collision) | Click ↺ Regen or move block |
| Code has errors | Click Compile button, check syntax in Python tab |

---

## 📋 Pre-Fair Checklist

- [ ] Test on actual VEX IQ robot
- [ ] Adjust `Drive speed %` & `Turn speed %` based on real runs
- [ ] Verify `Cell size (mm)` matches your physical setup
- [ ] Save route by screenshotting or copying code
- [ ] Practice editing legs quickly (for live adjustments)
- [ ] Bring USB cable
- [ ] Charge laptop/tablet battery

---

## 💡 Pro Tips

1. **Tight corners?** Edit leg distance up to 750mm or down to 500mm
2. **Need to wait?** Use "Wait" action (set 2-3 seconds in busy aisles)
3. **Test first:** Always run SIM before sending to real robot
4. **Save backup:** Take screenshot or email yourself the Python code
5. **Fine-tune speeds:** Start at 50% drive, 35% turn; adjust up/down by 5%

---

## 🎯 For Competition Day

**Scenario:** "Your robot needs to adapt. Here's the new shelf layout."

**Your moves:**
1. Clear old shelves (click `⌫`)
2. Place new shelves quickly
3. Click `⚡ AUTO`
4. Adjust any legs that look wrong (tap step → edit)
5. Run simulation to verify
6. Copy Python code
7. Paste into VEX IDE
8. Download to robot

**Time estimate:** 2-3 minutes (with practice)

---

## 📞 Quick Support

- **Docs:** See USAGE_GUIDE.md (detailed walkthrough)
- **Testing:** See TESTING_GUIDE.md (step-by-step verification)
- **Info:** See README.md (full release notes)
- **Changes:** See CHANGELOG.md (what's new in v2)

---

## 🎓 What Judges Want to See

✅ **Route Planning** → Place shelves, show AUTO route  
✅ **Flexibility** → Edit legs, adjust distances  
✅ **Verification** → Run simulation, show code  
✅ **Integration** → Connect USB, send code to robot  
✅ **Adaptation** → Handle new scenarios quickly  

---

**Version:** 2.0 (June 15, 2026)  
**For:** KSEF VEX IQ Robotics | Warehouse Automation  
**Status:** ✅ Production Ready
