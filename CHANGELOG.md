# StorageMAC Updates - 2026-06-15 12:06

## Changes Made:
✓ Added total distance display in leg editor (shows path length sum in mm)
✓ Leg editor auto-refreshes total when distance/direction changes
✓ Added "↺ Regen" button to regenerate legs from A* pathfinding
✓ Improved tap menu positioning (smarter screen bounds checking)
✓ Fixed auto-route to preserve all route properties (action, speedPct, waitSec)
✓ Better step editor initialization with null checks

## What's Working:
- Click shelf on map → tap menu with 4 options (Pick/Drop/Move/Edit)
- Menu stays visible on screen edges
- Click route step → editor popup with all controls
- Edit individual legs: direction, distance, angle
- Total path distance shown at top of legs section
- Regen button recalculates path from A* if you mess up
- Auto-route builds complete routes with all step data
- Simulation runs smoothly with per-leg data
- Compile output respects all custom leg values

## Testing Checklist:
☐ Place 3+ shelves on map
☐ Click one → does the tap menu appear with 4 options?
☐ Hit ⚡ AUTO → route appears with all steps?
☐ Click a step → editor popup with legs section?
☐ Edit a leg distance → does total update live?
☐ Hit ↺ Regen → path recalculates?
☐ Set a leg to 750mm → compile → check packet has 750mm?
☐ Hit ▶ SIM → robot animates smoothly?

## Next Steps:
- Test on actual VEX robot with USB connection
- Verify Arduino sensor integration
- Fine-tune speeds if needed
