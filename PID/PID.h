/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: PID.h
  Theme: Biped Patrol
  Functions: None
  Global Variables: None
*/

#ifndef PID_H
#define PID_H
#include <Arduino.h>

/*
* Class Name:PID
* Input: None
* Output: None
* Logic: Creates a PID class to create more than one objects and perform PID operations on it
* Example Call: PID pid_name
*/

class PID{
  double kp; // variable for propotional value
  double ki; // variable for integral value
  double kd; // variable for derivative value
  double* PIDInput; // input value for the PID
  double* PIDOutput; // output variable for the PID
  double* PIDSetPoint; // setpoint for the PID to get the value to that point
  double minOutput; // minOutput for wheel speed
  double maxOutput; // maxOutput for wheel speed
  unsigned long sampleTime; //uses the PID sampleTime in milliseconds
  double integral=0; // integrates the value of the integral over time
  double prevInput; // stores the previous input
  unsigned long prevTime; // storing variable for previous time reading
  double sampleTimeSecs; // time for input delays in seconds
  public:
    /*
    * Function Name:PID
    * Input: input_variable, output_variable, setpoint, kp, ki, kd, time (in milliseconds)
    * Output: None
    * Logic: Sets output variable to calculate the PID according to the difference of error in setpoint and input
    * Example Call: PID()
    */
    PID(double* input, double* output, double* setPoint, double kp, double ki, double kd, unsigned long sampleTime );
    /*
    * Function Name:calculate
    * Input: None
    * Output: None
    * Logic: Updates output variable after calculating the PID according to the difference of error in setpoint and input
    * Example Call: calculate()
    */
    bool calculate();
    /*
    * Function Name:setPID
    * Input: kp, ki, kd
    * Output: None
    * Logic: Updates the proptional, integral and derivative values of the PID
    * Example Call: setPID(kp_value, ki_value, kd_value)
    */
    void setPID(double kp, double ki, double kd);
};





#endif