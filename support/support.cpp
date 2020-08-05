/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: support.h
  Theme: Biped Patrol
  Functions: electro1(), electro2(), electroInit(), peripheralInit(), startRun(), endRun()
  Global Variables: None
*/
#include<Arduino.h>
#include<support.h>
#include <TimerOne.h>
#include <XBee.h>

XBee *periXBee;


void XBeeinit(XBee* inpXBee){
	periXBee = inpXBee;

}

void checkPeri(){
	if(periXBee->getSwitch1()){
		electro1(HIGH);
	}
	else{
		electro1(LOW);
	}
	if(periXBee->getSwitch2()){
		electro2(HIGH);
	}
	else{
		electro2(LOW);
	}
	if(periXBee->getSwitch3()){
		startRun();
	}
	if(periXBee->getSwitch4()){
		endRun();	
	}



}

void electro1(bool state){
  digitalWrite(ELECTRO_1, state);
}

void electro2(bool state){
  digitalWrite(ELECTRO_2, state);
}

void electroInit(){
  pinMode(ELECTRO_1, OUTPUT);
  pinMode(ELECTRO_2, OUTPUT);
}

void peripheralInit(){
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
}

void stopEverything(){
	digitalWrite(BUZZER, LOW);
	digitalWrite(RED_LED, LOW);
	digitalWrite(GREEN_LED, LOW);
	Timer1.stop();
		Serial.println("Run  Started");

}

void startRun(){
		Timer1.attachInterrupt(stopEverything);

	digitalWrite(BUZZER, HIGH);
	digitalWrite(GREEN_LED, HIGH);	
	Serial.println("Starting Run");

	Timer1.initialize();
	
  
}


void endRun(){
	Timer1.attachInterrupt(stopEverything);

	digitalWrite(BUZZER, HIGH);
	digitalWrite(RED_LED, HIGH);	
	Serial.println("Ending Run");
	
	Timer1.initialize();
	
}