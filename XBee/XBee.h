/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: XBee.h
  Theme: Biped Patrol
  Classes: XBee
  Global Variables: None
*/
#ifndef XBee_H
#define XBee_H
#include <Arduino.h>
class XBee
{
  bool isSwitch1; //Stores the state of switch 1
  bool isSwitch2; //Stores the state of switch 2
  bool isSwitch3; //Stores the state of switch 3
  bool isSwitch4; //Stores the state of switch 4
  bool isSwitch5; //Stores the state of switch 5

  bool isSwitch6; //Stores the state of switch 6

  int analog1; //Stores raw value of AD0 of XBee
  int analog2; //Stores raw value of AD1 of XBee
  int analog3; //Stores raw value of AD2 of XBee
  int XZone; //Stores mapped value of analog 2
  int YZone; //Stores mapped value of analog 1
  HardwareSerial* mySerial;
  public:
  /*
* Function Name:XBee
* Input: Serial of Arduino
* Output: None
* Logic: Constructor of XBee to initialize it with Serial to read data from
* Example Call: XBee(&Serial1)
*/
  XBee(HardwareSerial* mySerial);
  /*
* Function Name:readData
* Input: None
* Output: None
* Logic: Reads API frame from input serial and updates class attributes accordingly 
* Example Call: myXBee.readData()
*/
  void readData();
  /*
* Function Name:getSwitch1
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 1
* Example Call: myXBee.getSwitch1()
*/
bool getSwitch1();
  /*
* Function Name:getSwitch2
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 2
* Example Call: myXBee.getSwitch2()
*/
  bool getSwitch2();
  /*
* Function Name:getSwitch3
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 3
* Example Call: myXBee.getSwitch3()
*/
  bool getSwitch3();
  /*
* Function Name:getSwitch4
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 4
* Example Call: myXBee.getSwitch4()
*/
  bool getSwitch4();
  /*
* Function Name:getSwitch5
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 5
* Example Call: myXBee.getSwitch5()
*/
  bool getSwitch5();
  /*
* Function Name:getSwitch6
* Input: None
* Output: HIGH or LOW
* Logic: Returns state of switch 6
* Example Call: myXBee.getSwitch6()
*/
  bool getSwitch6();
  /*
* Function Name:getAnalog1
* Input: None
* Output: 0-1023
* Logic: Returns raw value of analog channel 1
* Example Call: myXBee.getAnalog1()
*/
int getAnalog1();
/*
* Function Name:getAnalog2
* Input: None
* Output: 0-1023
* Logic: Returns raw value of analog channel 2
* Example Call: myXBee.getAnalog2()
*/
int getAnalog2();
/*
* Function Name:getAnalog3
* Input: None
* Output: 0-1023
* Logic: Returns raw value of analog channel 3
* Example Call: myXBee.getAnalog3()
*/
  int getAnalog3();
/*
* Function Name:getXZone
* Input: None
* Output: -2-2
* Logic: Returns the joystick zone of the left-right XBee
* Example Call: myXBee.getXZone()
*/
  int getXZone();
/*
* Function Name:getYZone
* Input: None
* Output: -2-2
* Logic: Returns the joystick zone of the up-down XBee
* Example Call: myXBee.getYZone()
*/
  int getYZone();

};
#endif