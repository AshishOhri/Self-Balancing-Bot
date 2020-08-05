/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: support.h
  Theme: Biped Patrol
  Functions: electro1(), electro2(), electroInit(), peripheralInit(), startRun(), endRun()
  Global Variables: None
*/
#ifndef support_h
#define support_h

#include <Arduino.h>

// Pin values for electromagnet and LEDs
#define ELECTRO_1 9
#define ELECTRO_2 10
#define BUZZER 11
#define RED_LED 13
#define GREEN_LED 12
/*
* Function Name:electro1
* Input: HIGH or LOW
* Output: None
* Logic: Sets the eLectromagnet1 to high or low
* Example Call: electro1(value)
*/
void electro1(bool state);
/*
* Function Name:electro2
* Input: HIGH or LOW
* Output: None
* Logic: Sets the eLectromagnet2 to high or low
* Example Call: electro2(value)
*/
void electro2(bool state);
/*
* Function Name:electroInit
* Input: None
* Output: None
* Logic: Initializes the electromagnets
* Example Call: electroInit()
*/
void electroInit();
/*
* Function Name:peripheralInit
* Input: None
* Output: None
* Logic: Initializes the buzzer and the LEDs
* Example Call: peripheralInit()
*/
void peripheralInit();
/*
* Function Name:startRun
* Input: None
* Output: None
* Logic: Switches on the buzzer and green led to indicate the start of the arena traversal
* Example Call: startRun()
*/
void startRun();
/*
* Function Name:endRun
* Input: None
* Output: None
* Logic: Switches on the buzzer and red led to indicate the end of the arena traversal
* Example Call: endRun()
*/
void endRun();
#endif