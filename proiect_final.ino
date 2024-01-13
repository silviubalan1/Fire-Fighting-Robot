#include <Servo.h>
#include <L298NX2.h>


Servo myservo;

const unsigned int EN_A = 3;
const unsigned int IN1 = 5;
const unsigned int IN2 = 4;

const unsigned int EN_B = 2;
const unsigned int IN3 = 13;
const unsigned int IN4 = 12;

L298NX2 motors(EN_A, IN1, IN2, EN_B, IN3, IN4);

int pos = 0;    

boolean fire = false;

 

/*-------defining Inputs------*/

#define Left_S 9      // left sensor

#define Right_S 10      // right sensor

#define Forward_S 8 //forward sensor

 

/*-------defining Outputs------*/

#define pump 6

 

void setup()

{

  pinMode(Left_S, INPUT);

  pinMode(Right_S, INPUT);

  pinMode(Forward_S, INPUT);

  pinMode(pump, OUTPUT);

  digitalWrite(pump, HIGH);
 
 // motors.setSpeedA(30);
 // motors.setSpeedB(30);

  myservo.attach(11);

  myservo.write(90); 

  motors.setSpeed(120);

}

 

void put_off_fire()

{

    delay (500);

 

    motors.stopA();
    motors.stopB();

   digitalWrite(pump, LOW); 
   delay(500);

    

    for (pos = 50; pos <= 130; pos += 1) { 

    myservo.write(pos); 

    delay(10);  

  }

  for (pos = 130; pos >= 50; pos -= 1) { 

    myservo.write(pos); 

    delay(10);

  }

  

  digitalWrite(pump,HIGH);

  myservo.write(90);

  

  fire=false;

}

 

void loop()

{

   myservo.write(90); //Sweep_Servo();  
 

    if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero

    {

    //Do not move the robot
      delay(500);
      motors.forwardA();
      motors.forwardB();
      delay(500);
      motors.stopA();
      motors.stopB();
    }

    

    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead

    {

    //Move the robot forward
    motors.stopA();
    motors.stopB();

    fire = true;

    }

    

    else if (digitalRead(Left_S) ==0) //If Fire is to the left

    {
      digitalWrite(pump, HIGH);//DC SE ACTIVEAZA
    //Move the robot left
    motors.backwardA();
    motors.forwardB();

    }

    

    else if (digitalRead(Right_S) ==0) //If Fire is to the right

    {
      digitalWrite(pump, HIGH);
    //Move the robot right
    motors.forwardA();
    motors.backwardB();

    }

    

delay(300); //Slow down the speed of robot

 

     while (fire == true)

     {

      put_off_fire();

     }

}