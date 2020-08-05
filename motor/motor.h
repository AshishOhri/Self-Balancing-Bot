/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: motor.h
  Theme: Biped Patrol
  Functions: motorInit(), m1Speed(), m2Speed(), m1Direction(), m2Direction(), mspeed(), mdirection(), leftEncoder(), rightEncoder(), RPSCalculate()
  Global Variables: leftEncoderPulse, rightEncoderPulse, leftRPS, rightRPS
*/
#ifndef motor_h
#define motor_h

#include<Arduino.h>
#define MOTOR1_A 7
#define MOTOR1_B 6
#define MOTOR1_EN 8
#define MOTOR2_A 5
#define MOTOR2_B 4
#define MOTOR2_EN 3
#define FORWARD 1
#define BACKWARD 0
#define ENC1_A 18
#define ENC1_B A4
#define ENC2_A 19
#define ENC2_B A3
#define DEADBAND_LEFT_FORWARD 40 // Left wheel forward deadband
#define DEADBAND_LEFT_BACKWARD 40 // left wheel backward deadband
#define DEADBAND_RIGHT_FORWARD 60 // right wheel forward deadband
#define DEADBAND_RIGHT_BACKWARD 60 // right wheel backward deadband

extern volatile float leftEncoderPulse; // count for number of left encoder pulses
extern volatile float rightEncoderPulse; // count for number of right encoder pulses
// extern float leftMotorSpeed; 
// extern float rightMotorSpeed;
extern volatile float leftRPS; // calculates the revolutions per second for left wheel
extern volatile float rightRPS; // calculates the revolutions per second for right wheel

/*
* Function Name:motorInit
* Input: None
* Output: None
* Logic: Updates Initializes the motor and encoder pins
* Example Call: motorInit()
*/
void motorInit();

/*
* Function Name:getDMP
* Input: None
* Output: None
* Logic: Updates the global current angle and current rotation variable with pitch of the robot
* Example Call: getDMP()
*/
                // void deadbandInit(int deadband_left_forward,int deadband_left_backward,int deadband_right_forward,int deadband_right_backward);

/*
* Function Name:m1Speed
* Input: required speed
* Output: None
* Logic: Updates the speed of the left wheel
* Example Call: m1Speed(value)
*/
void m1Speed(int mSpeed);

/*
* Function Name:m2Speed
* Input: required speed
* Output: None
* Logic: Updates the speed of the right wheel
* Example Call: m2Speed(value)
*/
void m2Speed(int mSpeed);

/*
* Function Name:m1Direction
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the left wheel to forward or backward to move the wheel in that particular direction
* Example Call: m1Direction(value)
*/
void m1Direction(int mDirection);

/*
* Function Name:m2Direction
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the right wheel to forward or backward to move the wheel in that particular direction
* Example Call: m2Direction(value)
*/
void m2Direction(int mDirection);

/*
* Function Name:mSpeed
* Input: speed to left motor and speed to right motor
* Output: None
* Logic: Gives the speed to the left and right wheel respectively
* Example Call: mSpeed(value for left wheel, value for right wheel)
*/
void mSpeed(int motorSpeed1, int motorSpeed2);

/*
* Function Name:mSpeed
* Input: speed value
* Output: None
* Logic: Gives the speed that is then used to give equal speeds to both left and right wheels
* Example Call: mSpeed(equal speed value for left and right wheel)
*/
void mSpeed(int motorSpeed);


/*
* Function Name:mDirection
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the right and left motor to an equal value for both the motors
* Example Call: mDirection(value)
*/
void mDirection(int motorDirection);

/*
* Function Name:leftEncoder
* Input: None
* Output: None
* Logic: Updates the pulse value of left encoder
* Example Call: leftEncoder()
*/
void leftEncoder();

/*
* Function Name:rightEncoder
* Input: None
* Output: None
* Logic: Updates the pulse value of right encoder
* Example Call: leftEncoder()
*/
void rightEncoder();

/*
* Function Name:RPSCalculate
* Input: None
* Output: None
* Logic: Calulates the RPS (Revolutions per second) of the wheels
* Example Call: RPSCalculate()
*/
void RPSCalculate();
#endif
