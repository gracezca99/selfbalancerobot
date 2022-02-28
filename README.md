# Self Balance Robot
The self-balance robot is a laser-cut plastic frame with only two wheels, one on each side. Inside the plastic frame, we have the controller Arduino Uno, an accelerometer gyroscope module (MPU6050), and a Stepper Motor Control Module (L298N). 
The motor connects to wheels, and the controller controls the motor. We programmed the controller, so it can take inputs from the accelerometer gyroscope module, calculate what it should do to keep the robot balanced on two wheels, and then send signals to the motor to controls the wheels.

The main code logic is in file: https://github.com/gracezca99/selfbalancerobot/blob/main/selfbalrocode.ino

The robot box was made of plastic boards, and the layout is in this file:  https://github.com/gracezca99/selfbalancerobot/blob/main/selfbalrocut_updatedai.ai

All of the libraries used are from GitHub.com:

L298N library: 
https://github.com/AndreaLombardo/L298N/

MPU6050 library:
https://github.com/rfetick/MPU6050_light

