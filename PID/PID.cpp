/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: PID.h
  Theme: Biped Patrol
  Functions: None
  Global Variables: None
*/
#include<Arduino.h>
#include<PID.h>

/*
* Class Name:PID
* Input: None
* Output: None
* Logic: Creates a PID class to create more than one objects and perform PID operations on it
* Example Call: PID pid_name
*/

/*
* Function Name:PID
* Input: input_variable, output_variable, setpoint, kp, ki, kd, time (in milliseconds)
* Output: None
* Logic: Sets output variable to calculate the PID according to the difference of error in setpoint and input
* Example Call: PID()
*/
PID::PID(double* input, double* output, double* setPoint, double kp, double ki, double kd, unsigned long sampleTime ){
  this->sampleTime = sampleTime; //uses the PID sampleTime in milliseconds
  this->sampleTimeSecs = ((double)sampleTime)/1000;
  this->kp=kp; // variable for propotional value
  this->ki=ki*sampleTimeSecs; // variable for integral value
  this->kd=kd/sampleTimeSecs; // variable for derivative value
  this->PIDInput= input; // input value for the PID
  this->PIDOutput= output; // output variable for the PID
  this->PIDSetPoint= setPoint; // setpoint for the PID to get the value to that point
  this->minOutput = -255; // minOutput for wheel speed
  this->maxOutput = 255; // maxOutput for wheel speed
  this->prevTime=millis()-sampleTime; // storing variable for previous time reading
}

/*
* Function Name:calculate
* Input: None
* Output: None
* Logic: Updates output variable after calculating the PID according to the difference of error in setpoint and input
* Example Call: calculate()
*/
bool PID::calculate(){
  unsigned long now= millis();
  unsigned long timeElapsed = now - prevTime;
  if (timeElapsed >= sampleTime){
    //do something
    double input = *PIDInput;
    double output;
    double setPoint = *PIDSetPoint;
    double error =  setPoint - input;
    integral += ki*error;
    double delError =  input - prevInput;
    output = constrain(kp*error + integral - kd*delError, minOutput, maxOutput);
    prevTime = now;
    prevInput = input;
    *PIDOutput = output;
    return true;      
  }
  else{
    return false; 
  }
}

/*
* Function Name:setPID
* Input: kp, ki, kd
* Output: None
* Logic: Updates the proptional, integral and derivative values of the PID
* Example Call: setPID(kp_value, ki_value, kd_value)
*/   
void PID::setPID(double kp, double ki, double kd){
  //this->integral=0;
  this->kp=kp;
  this->ki=ki*sampleTimeSecs;
  this->kd=kd/sampleTimeSecs;

}