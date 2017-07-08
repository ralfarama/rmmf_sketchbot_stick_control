
# rmmf_sketchbot_stick_control

A simple Arduino sketch to provide joystick control for a sketching robot, part of a project for Reno Mini Maker Faire 2017.

## Hardware

This sketch is intended to work with the CNC shield V3:

    http://blog.protoneer.co.nz/arduino-cnc-shield/

Since the objective is to simply translate joystick motion in the four cardinal directions into stepper motions, instead of getting GRBL involved this sketch merely senses the joystick switches and generates the appropriate direction and pulse outputs.  The Arduino output lines used are:

* pin 2: X axis step
* pin 3: Y axis step
* pin 5: X axis direction
* pin 6: Y axis direction
* pin 8: stepper enable
* pin 13: LED output, for simple status and diagnostics
* Pins A0-A3: Joystick switch inputs
