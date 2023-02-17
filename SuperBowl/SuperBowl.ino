//Interface with phone
#define CUSTOM_SETTINGS
#define INCLUDE_LEDCONTROL_MODULE  //change if using a different app in dabble
#include <DabbleESP32.h>

//Servo Setup
#include <ESP32Servo.h> 
Servo servo;
int pos=0;
//Use any GPIO pin except for 6-11, 34-36, 39
int servoPin=14;

//Pulse widths i guess, not really sure
int minUs = 1000;
int maxUs = 2000;
ESP32PWM pwm;


//Switch Setup
int switchPin=12; //Use any GPIO pin 12-39


void setup() {
  //Setting up for BLE connection
  Serial.begin(115200);
  Dabble.begin("Super Bowl");

  //Setting up swtich pin connection
  pinMode(switchPin, INPUT);
  servo.attach(servoPin);
  
}



void loop() {  
  //Read data from phone
  Dabble.processInput();

  //Define variables for on or off detection
  int PhoneState=LedControl.getpinState(); //change if using a different app in dabble
  //Switch State is reversed, so put it back to normal
  int SwitchState=swap(digitalRead(switchPin));


  //Make an overall state variable for easier if else statements
  int State=SwitchState+PhoneState;

  //Control Door based on state
  if(State>0){
    Serial.println("Switch is on");
    pos=50;
  }
  else{
    Serial.println("Switch is off");
    pos=0;
  }

  //Move the servo to the correct location
  servo.write(pos);


}


//Swap Function
int swap(int r){
  if(r){return(0);}
  else{return(1);}
}
