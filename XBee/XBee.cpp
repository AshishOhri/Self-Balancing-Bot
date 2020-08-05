/*
  Team Id: 2268
  Author List: Aditya Agrawal, Ashish Ohri, Jai Garg
  Filename: XBee.h
  Theme: Biped Patrol
  Classes: XBee
  Global Variables: None
*/
#include<Arduino.h>
#include<XBee.h>

XBee::XBee(HardwareSerial* mySerial){
  this->mySerial = mySerial;
  this->XZone = 0;
  this->YZone = 0;

}
void XBee::readData(){
  if(mySerial->available())
  {
    if(mySerial->read()==0x7E)
    {
      int lengthMSB = mySerial->read();
      int lengthLSB = mySerial->read();
      int frameLength = (lengthMSB*256)+lengthLSB;
      if(frameLength!=16)
        return;
      
      
      int calcChecksum=0;
      
      int frameType=mySerial->read();
      calcChecksum+=frameType;
      
      int sourceMSB = mySerial->read();
      calcChecksum+=sourceMSB;
      int sourceLSB = mySerial->read();
      calcChecksum+=sourceLSB;
      int sourceAddress = (sourceMSB*256)+sourceLSB;

      if(sourceAddress == 4)
      {


        int rssi = mySerial->read();
        calcChecksum+=rssi;
        byte options = mySerial->read();
        calcChecksum+=options;
        int totalSamples= mySerial->read();
        calcChecksum+=totalSamples;
        int maskMSB = mySerial->read();
        calcChecksum+=maskMSB;
        int maskLSB = mySerial->read();
        calcChecksum+=maskLSB;
        int mask = maskMSB*256+maskLSB;

        int digiDataMSB = mySerial->read();
        calcChecksum+=digiDataMSB;
        int digiDataLSB = mySerial->read();
        calcChecksum+=digiDataLSB;
        int digiData = digiDataMSB*256 + digiDataLSB;



        int anaData1MSB = mySerial->read();
        calcChecksum+=anaData1MSB;
        int anaData1LSB = mySerial->read();
        calcChecksum+=anaData1LSB;
        int anaData1 = anaData1MSB*256 + anaData1LSB;
        
        int anaData2MSB = mySerial->read();
        calcChecksum+=anaData2MSB;
        int anaData2LSB = mySerial->read();
        calcChecksum+=anaData2LSB;
        int anaData2 = anaData2MSB*256 + anaData2LSB;

        int anaData3MSB = mySerial->read();
        calcChecksum+=anaData3MSB;
        int anaData3LSB = mySerial->read();
        calcChecksum+=anaData3LSB;
        int anaData3 = anaData3MSB*256 + anaData3LSB;

        //int anaData3MSB = mySerial->read();
        //calcChecksum+=anaData3MSB;
        //int anaData3LSB = mySerial->read();
        byte checksum = mySerial->read();
        //calcChecksum+=anaData3LSB;
        //int anaData3 = anaData3MSB*256 + anaData3LSB;

        byte finalChecksum= lowByte(calcChecksum);
        finalChecksum = 0xFF - finalChecksum;

        // Serial.print("Received Checksum: ");
        // Serial.println(checksum, HEX);
        // Serial.print("Calculated Checksum: ");
        // Serial.println(finalChecksum, HEX);

        if(checksum==finalChecksum)
        {
          isSwitch1=bitRead(digiData,3);
          isSwitch2=bitRead(digiData,4);
          isSwitch3=bitRead(digiData,5);
          isSwitch4=bitRead(digiData,6);
          isSwitch5=bitRead(digiData,7);
          isSwitch6=!bitRead(digiData,8); //Internally Pulled up
          
          analog1=anaData1;
          analog2=anaData2;
          analog3=anaData3;
          // Serial.print(analog1);
          // Serial.print("\t");
          // Serial.println(analog2);
          XZone = map(analog2, 0, 799, -2,2);
          YZone = map(analog1, 0, 630, -2,2);
          if(analog2>250 && analog2<500)
            XZone=0; 
          if(analog1>240 && analog1<400)
            YZone=0;
        }
        else
        {
          //Serial.println("Invalid Checksum");
        }
      }

    }
  }

  
}
bool XBee::getSwitch1(){
  return isSwitch1;
}
bool XBee::getSwitch2(){
  return isSwitch2;
}
bool XBee::getSwitch3(){
  return isSwitch3;
}
bool XBee::getSwitch4(){
  return isSwitch4;
}
bool XBee::getSwitch5(){
  return isSwitch5;
}
bool XBee::getSwitch6(){
  return isSwitch6;
}
int XBee::getAnalog1(){
  return analog1;  
}
int XBee::getAnalog2(){
  return analog2;  
}
int XBee::getAnalog3(){
  return analog2;  
}
int XBee::getYZone(){
return YZone;
}
int XBee::getXZone(){

  return XZone;
}
