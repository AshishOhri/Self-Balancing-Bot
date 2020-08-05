/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: code.ino
  Theme: Biped Patrol
  Functions: setup(), loop(),
  Global Variables:
*/
#include <PID.h>
#include <DMP.h>
#include <XBee.h>
#include <motor.h>
#include <support.h>

XBee myXBee(&Serial2);

void setup() {
  Serial2.begin(115200);
  Serial.begin(115200);
  MPUInit();
  motorInit();
  electroInit();
  peripheralInit();
}
float kp = 62.76;
float ki = 75.56;
float kd = 1.66;

double wheelSpeed;
double nominalSetAngle = -1.52;
double delRPS;
double currentRPS;
double rotOffset;
double wheelPIDAngle = 0;


unsigned long startTime = millis();
int startTimeFlag = 0;
double giveAngle;
PID wheelPID(&currentAngle, &wheelSpeed, &wheelPIDAngle, kp, ki, kd, (unsigned long)10);

/*
   Right tic tac| Switch 5 | Hill Climb
   Left tic tac | Switch 6 | Gravel
   Right Switch | Switch 2 | Electromagnet 1
   Left Switch  | Switch 3 | Electromagnet 2
*/


void loop() {
  myXBee.readData(); //read XBee data
  getDMP(); // to calculate angle through MPU
  if (startTime + 10000 < millis() && startTimeFlag == 0)
  {
    /*This indicates the start of run after 10 seconds of stabalizing the bot*/
    startTimeFlag = 1;
    startRun();

  }
  else if (myXBee.getSwitch6() && myXBee.getSwitch5())
  { /*This indicates the end of run upon a specific switch combination*/
    
    endRun();
  }
  if (abs(currentAngle) > 40) // During fall stop the bot
  { /*This is to stop the robot automatically in the case of a fall*/
    mSpeed(0, 0);
    wheelPIDAngle = 0;
  }
  else
  {
    if (myXBee.getSwitch5() && !myXBee.getSwitch6()) // Hill Climb mode
    {
      /*This case indicates the mode wherein the bot needs to climb the hill*/
      nominalSetAngle = -7.5;
    }
    else                    
    {
      /*This inndicates the case wherein the bot needs to stabalize itself*/
      nominalSetAngle = -0.8;
    }
    

    //Turn on the first electromagnet
    if (myXBee.getSwitch2())
      electro1(HIGH);
    //Turn off the first electromagnet
    else
      electro1(LOW);

   
    //Turn on the second electromagnet
    
    if (myXBee.getSwitch3())
      electro2(HIGH);
    //Turn off the second electromagnet
    
    else
      electro2(LOW);
    if (myXBee.getYZone()==0)
    {
    if (myXBee.getXZone() == 0 || myXBee.getXZone() >= 3   || myXBee.getXZone() <= -3)
      {
        /*If second joystick is also in the middle, stabalize*/
        wheelPIDAngle = nominalSetAngle;
        wheelPID.calculate();
        mSpeed(wheelSpeed, wheelSpeed);
      }
       //Condition for bot to turn left
      if (myXBee.getXZone() < 0) {
        /*If second joystick is to the left, turn left*/
        
        wheelPIDAngle = nominalSetAngle;
        wheelPID.calculate();
        if (myXBee.getSwitch6()) // Gravel mode
          mSpeed(wheelSpeed + 60, wheelSpeed - 60);
        else                      // Normal turn
          mSpeed(wheelSpeed + 35, wheelSpeed - 35);
      }

      //Condition for bot to turn right
      else if (myXBee.getXZone() > 0) {
        /*If second joystick is to the right, turn right*/
        
        wheelPIDAngle = nominalSetAngle;
        wheelPID.calculate();
        if (myXBee.getSwitch6()) // Gravel mode
          mSpeed(wheelSpeed - 60, wheelSpeed + 60);
        else                      // Normal turn
          mSpeed(wheelSpeed - 35, wheelSpeed + 35);
      }
    }

    // Condition for the bot to move forward
    else if (myXBee.getYZone() > 0) {
      nominalSetAngle += 2.32;
      if (myXBee.getSwitch6()) // Gravel mode
        nominalSetAngle += 1.1;
      wheelPIDAngle = nominalSetAngle;
      wheelPID.calculate();
      mSpeed(wheelSpeed, wheelSpeed);
      
    }

    //Condition for bot to move backward
    else if (myXBee.getYZone() < 0) {
      nominalSetAngle -= 2.18;
      if (myXBee.getSwitch6()) // Gravel mode
        nominalSetAngle -= 1.8;
      wheelPIDAngle = nominalSetAngle;
      wheelPID.calculate();
      mSpeed(wheelSpeed, wheelSpeed);
      
    }
      
  }

}
