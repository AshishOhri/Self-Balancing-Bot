## Self Balancing Bot
This project was created as a part of [e-yantra robotics competition](https://e-yantra.org/). The project is a two wheeled balance bot that was able to **balance** itself as well as had **joystick control**. As a plus point, it also had the capability of **picking up and delivering boxes** from one place to another.

## Authors
<table>
  <tbody><tr>
    <td align="center"><a href="https://github.com/adiagr"><img src="https://avatars1.githubusercontent.com/u/21157331?s=400&u=b85230f9847b83c55bc04fd52458e98410a01b64&v=4" width="100px;" alt="Shashank Agrawal" style="max-width:100%;"><br><sub><b>Aditya Agrawal</b></sub></a></td>
    <td align="center"><a href="https://github.com/AshishOhri"><img src="https://avatars1.githubusercontent.com/u/44030156?s=460&amp;v=4" width="100px;" alt="Ashish Ohri" style="max-width:100%;"><br><sub><b>Ashish Ohri</b></sub></a></td>
    <td align="center"><a href="https://github.com/jaigarg2"><img src="https://avatars3.githubusercontent.com/u/44141271?s=400&v=4" width="100px;" alt="Subhahu Jain" style="max-width:100%;"><br><sub><b>Jai Garg</b></sub></a></td>
  </tr>
 </tbody></table>

## Bot Design
<div class="row">
<img align="left" src="https://github.com/AshishOhri/Self-Balancing-Bot/blob/master/images/bot2.JPG" height="300px"/>
<img align="center" src="https://github.com/AshishOhri/Self-Balancing-Bot/blob/master/images/bot.png" height="300px"/>
</div><br>

## Description
The bot was tried and tested on various approaches. These approaches include both single PID as well as cascaded PIDs. The uses of each file/library has been described in the table below.

|File|Description|
|---------------|---------------------------------------------|
|Blynk|Blynk library is an IOT platform that allows one to control hardware over internet or bluetooth|
|DMP|DMP library is used to initialize and get packet data from MPU6050|
|I2Cdev|Deals with the communication protocols of the MPU|
|MPU6050|It is used to initialize the MPU6050 as well as provides various functionalites of the MPU|
|PID|PID library is a custom built library used for creating PID objects and perform PID operations|
|Timer1|This library provides PWM and interrupt utilities|
|XBee|XBee library is used for reading data from XBee module|
|code|The final arduino code that runs the bot using all the libraries created|
|motor|motor library helps in initializing and controlling the PWM motor|
|support|support library provides additional functionalities as per the theme requirements related to electromagnets and starting/stopping the run|
