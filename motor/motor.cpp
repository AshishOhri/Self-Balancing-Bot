/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: motor.h
  Theme: Biped Patrol
  Functions: motorInit(), m1Speed(), m2Speed(), m1Direction(), m2Direction(), mspeed(), mdirection(), leftEncoder(), rightEncoder(), RPSCalculate()
  Global Variables: leftEncoderPulse, rightEncoderPulse, leftRPS, rightRPS
*/
#include<Arduino.h>
#include<motor.h>
volatile float leftEncoderPulse = 0; // count for number of left encoder pulses
volatile float rightEncoderPulse = 0; // count for number of right encoder pulses
// float leftMotorSpeed=0;
// float rightMotorSpeed=0;
float lastTime=0; // store the value of the time to calculate the time difference
volatile float leftRPS = 0; // calculates the revolutions per second for left wheel
volatile float rightRPS = 0; // calculates the revolutions per second for right wheel
volatile float prevLeftPulse = 0; // store the value for the previous count of left wheel pulses
volatile float prevRightPulse = 0; // store the value for the previous count of right wheel pulses
// int dlf;
// int dlb;
// int drf;
// int drb;

/*
* Function Name:motorInit
* Input: None
* Output: None
* Logic: Updates Initializes the motor and encoder pins
* Example Call: motorInit()
*/
void motorInit()
{
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR1_EN, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);
  pinMode(MOTOR2_EN, OUTPUT);
  pinMode(ENC1_A, INPUT_PULLUP);
  pinMode(ENC1_B, INPUT_PULLUP);
  pinMode(ENC2_A, INPUT_PULLUP);
  pinMode(ENC2_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENC1_A), leftEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC2_A), rightEncoder, CHANGE);

}
/*
void error_calc()
{
  int SetPoint=0;
  int Kp=100;
  float error=(m1Speed - m2Speed)-SetPoint;
  float output_val=(Kp*error);
  if (error<0)
  {
    rightEncoder(output_val);
  }
  if (error>=0)
  {
    leftEncoder(output_val);
  }
}
*/
// void deadbandInit(int deadband_left_forward,int deadband_left_backward,int deadband_right_forward,int deadband_right_backward)
// {
//   dlf=deadband_left_forward;
//   dlb=deadband_left_backward;
//   drf=deadband_right_forward;
//   drb=deadband_right_backward;
// }

/*
* Function Name:leftEncoder
* Input: None
* Output: None
* Logic: Updates the pulse value of left encoder
* Example Call: leftEncoder()
*/
void leftEncoder(){
  int state = digitalRead(ENC1_A);
  if(digitalRead(ENC1_B)) 
  state ? leftEncoderPulse-- : leftEncoderPulse++;
  else 
  state ? leftEncoderPulse++ : leftEncoderPulse--;
}

/*
* Function Name:rightEncoder
* Input: None
* Output: None
* Logic: Updates the pulse value of right encoder
* Example Call: leftEncoder()
*/
void rightEncoder(){
  int state = digitalRead(ENC2_A);
  if(digitalRead(ENC2_B)) 
  state ? rightEncoderPulse-- : rightEncoderPulse++;
  else 
  state ? rightEncoderPulse++ : rightEncoderPulse--;
}

/*
* Function Name:m1Speed
* Input: required speed
* Output: None
* Logic: Updates the speed of the left wheel
* Example Call: m1Speed(value)
*/
void m1Speed(int mSpeed)
{   
  if(mSpeed<0)
  {
    m1Direction(BACKWARD);
    analogWrite(MOTOR1_EN,map(abs(mSpeed), 0, 255, DEADBAND_LEFT_BACKWARD,255));
    // analogWrite(MOTOR1_EN,map(abs(mSpeed), 0, 255, dlb,255));
  }
  else{
    m1Direction(FORWARD);
    analogWrite(MOTOR1_EN,map(abs(mSpeed), 0, 255, DEADBAND_LEFT_FORWARD,255));
    // analogWrite(MOTOR1_EN,map(abs(mSpeed), 0, 255, dlf,255));
  }
}

/*
* Function Name:m2Speed
* Input: required speed
* Output: None
* Logic: Updates the speed of the right wheel
* Example Call: m2Speed(value)
*/
void m2Speed(int mSpeed)
{ if(mSpeed<0){
    m2Direction(BACKWARD);
    analogWrite(MOTOR2_EN,map(abs(mSpeed), 0, 255, DEADBAND_RIGHT_BACKWARD,255));
    // analogWrite(MOTOR2_EN,map(abs(mSpeed), 0, 255, drb,255));
  }
  else{
    m2Direction(FORWARD);
    analogWrite(MOTOR2_EN,map(abs(mSpeed), 0, 255, DEADBAND_RIGHT_FORWARD,255));
    // analogWrite(MOTOR2_EN,map(abs(mSpeed), 0, 255, drf,255));
  }

}

/*
* Function Name:m1Direction
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the left wheel to forward or backward to move the wheel in that particular direction
* Example Call: m1Direction(value)
*/
void m1Direction(int mDirection){
  if (mDirection == FORWARD){
    digitalWrite(MOTOR1_A,HIGH);
    digitalWrite(MOTOR1_B,LOW);

  }
  else{
    digitalWrite(MOTOR1_A,LOW);
    digitalWrite(MOTOR1_B,HIGH);
  }
  
}

/*
* Function Name:m2Direction
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the right wheel to forward or backward to move the wheel in that particular direction
* Example Call: m2Direction(value)
*/
void m2Direction(int mDirection){
  if (mDirection == FORWARD){
    digitalWrite(MOTOR2_A,HIGH);
    digitalWrite(MOTOR2_B,LOW);
    
  }
  else{
    digitalWrite(MOTOR2_A,LOW);
    digitalWrite(MOTOR2_B,HIGH);
  }
  
}

/*
* Function Name:mSpeed
* Input: speed to left motor and speed to right motor
* Output: None
* Logic: Gives the speed to the left and right wheel respectively
* Example Call: mSpeed(value for left wheel, value for right wheel)
*/
void mSpeed(int motorSpeed1, int motorSpeed2){
  m1Speed(motorSpeed1);
  m2Speed(motorSpeed2);
  
}

/*
* Function Name:mSpeed
* Input: speed value
* Output: None
* Logic: Gives the speed that is then used to give equal speeds to both left and right wheels
* Example Call: mSpeed(equal speed value for left and right wheel)
*/
void mSpeed(int motorSpeed){
  m1Speed(motorSpeed);
  m2Speed(motorSpeed);
  
}

/*
* Function Name:mDirection
* Input: FORWARD or BACKWARD
* Output: None
* Logic: Updates the direction of the right and left motor to an equal value for both the motors
* Example Call: mDirection(value)
*/
void mDirection(int motorDirection)
{
  m1Direction(motorDirection);
  m2Direction(motorDirection);
  
}

// void mDrive(int motorSpeed, float rotOffset){
//   int mySpeed;
//   if(motorSpeed<0)
//   {
//     mDirection(FORWARD);
//     mySpeed = map(abs(motorSpeed), 0, 255, DEADBAND_FORWARD,255);
//   }
//   else{
//     mDirection(BACKWARD);
//     mySpeed = map(abs(motorSpeed), 0, 255, DEADBAND_BACKWARD,255);
//   }
//   mSpeed(mySpeed, rotOffset);
// }

/*
* Function Name:RPSCalculate
* Input: None
* Output: None
* Logic: Calulates the RPS (Revolutions per second) of the wheels
* Example Call: RPSCalculate()
*/
void RPSCalculate()
{
  if (millis()-lastTime>=10)
  {
  float delTime=(millis()-lastTime)/1000;
  volatile float left_pulse_count = leftEncoderPulse;
  volatile float right_pulse_count = rightEncoderPulse;
  leftRPS=(float)((left_pulse_count-prevLeftPulse)/(delTime*540));
  rightRPS=(float)((right_pulse_count-prevRightPulse)/(delTime*540));
  prevLeftPulse = left_pulse_count;
  prevRightPulse = right_pulse_count;
  lastTime=millis();
  }
}