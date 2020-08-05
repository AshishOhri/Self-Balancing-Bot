/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: DMP.h
  Theme: Biped Patrol
  Functions: MPUInit(), getDMP()
  Global Variables: dmpReady, angle, mpuIntStatus, devStatus, packetSize, fifoCount, fifoBuffer, currentAngle, currentRotation, euler, ypr
*/

#ifndef DMP_H
#define DMP_H
extern bool dmpReady;  // set true if DMP init was successful
extern double angle;
extern uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
extern uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
extern uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
extern uint16_t fifoCount;     // count of all bytes currently in FIFO
extern uint8_t fifoBuffer[64]; // FIFO storage buffer
extern double currentAngle, currentRotation;
extern float euler[3];         // [psi, theta, phi]    Euler angle container
extern float ypr[3];           //


#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards



/*
* Function Name:MPUInit
* Input: None
* Output: None
* Logic: Uses internal Digital Motion Processor of MPU 6050 to get angle Data to save processing time of the main controller
* Example Call: MPUInit()
*/ 
void MPUInit();
/*
* Function Name:getDMP
* Input: None
* Output: None
* Logic: Updates the global current angle and current rotation variable with pitch of the robot
* Example Call: getDMP()
*/
void getDMP();
#endif