# Battle Tank

This is going to be a game about tank warfare.

## Concept

You are a tank in an open-world head-to-head tank battle.
 
## Rules

* You can move anywere in the terrain, which is surrounded by mountains
* Both players start with finite health and ammo
* Each direct hit takes away health
* Last player standing wins

## Requirements

### SFX

* Gun firing
* Explosion
* Barrel moving
* Turret Moving
* Engine sound

### Static Mesh

Simple tank comprising of tracks, body, turret and barrel

### Textures

Later-on we'll want to add visual flare

### Music

Background music to create tension

## Controls

| Intention            | Manual Control           | Fly-by-Wire Control                    | Actuator(s)                        |
|----------------------|--------------------------|----------------------------------------|------------------------------------|
| Forward              | Symmetric Triggers       | Left Stick Forward *or W Key*          | Both Tracks Forward - Same Speed   |
| Backwards / Breaking | Symmetric Bumbers        | Left Stick backward *or S Key*         | Both Tracks Backwards - Same Speed |
| Strafe               | N/A                      | N/A                                    | N/A "You can't strafe a tank fool" |
| Rotate Body          | A-Sym Triggers / Bumpers | Left Stick Left / Right *or A/D Keys*  | Tracks - Different Speeds          |
| Rotate Turret        | N/A                      | Look & Aim with Right Stick *or Mouse* | Turret Rotator                     |
| Elevate Barrel       | N/A                      | Look & Aim with Right Stick *or Mouse* | Barrel Elevator                    |
