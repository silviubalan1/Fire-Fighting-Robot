
<div align="center">
  <p>
      <img width="20%" src="/arduino5804.jpg">
  </p>
  <b><h3> Fire Fighting Robot </h3></b>
  <p> using an <a href="https://docs.arduino.cc/hardware/uno-rev3"> Arduino Uno </a></p>
</div>  
 
## Instructions
* Connect all the parts  
* Download the code and upload it to your arduino
* Fill the tank with water and connect the batteries

## Parts used
1. Arduino Uno
2. Breadboard
3. Water pump 3-6V with tube
4. 2 DC Motors 3-7V gear 1:48
5. H Bridge L298N
6. Relay
7. 4 AA batteries with mount
8. 1 9v battery with mount
9. Servo motor sg 90
10. chassis
11. 3 Flame Sensors

12. ## Apps
 &nbsp;  &nbsp;Arduino IDE 1:   <a href="https://docs.arduino.cc/software/ide-v1"><img src="/arduino5804.jpg" width="40"></a>

 ## How It Works
 When the flame sensor in the middle is activated, the arduino sends a signal to turn on the relay.The pump stays on during a swing of the servo motor.  
 If one of the other sensors is activated the robot does a 90 degree turn in that direction.  
 The robot keeps going forward every second if there are no flames detected.

 ## Schematic  
 ![Alt text](https://github.com/silviubalan1/Fire-Fighting-Robot/blob/main/arduino%20schematic_bb.jpg?sanitize=true)    

## Documentation
