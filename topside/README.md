# rov-control
Work in progress, homebuilt ROV upgrade to proportional control with joysticks.

Current hardware: 
3 thrusters, 1 forward/reverse thruster on each side, left/right, and 1 up/down thruster. The ROV is held level by floats being placed at the top and weights at the bottom. Thrusters, lights, and camera wired to battery power (12V or 24V) and control switches at the surface through 2 cat5 cables. Motors are bilge pump motors.

Plan: replace clunky on/off/on switch controls with arduino joysticks and H bridge motor controllers. Likely using an ESP32 and HW 039 motor controllers because I have used those controllers before and I have plenty of ESP32s lying around. I have no further justification of these choices. 
