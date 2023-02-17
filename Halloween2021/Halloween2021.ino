#include <Servo.h>
#include <IRremote.h>

int IRpin = 5;
IRrecv IR(IRpin);
decode_results cmd;

int trigPin = 7;
int echoPin = 6;
long duration;
int distance;
int threshold = 20; //20ish? Do some tests.
int counter = 0;
bool justDispensed = false;


Servo left;
Servo right;

int servoOpen = 200;
int servoSpeed = 5;
int totalDelay = servoOpen * 2 + servoSpeed * 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();

  left.attach(11);
  right.attach(10);

  left.write(90);
  right.write(0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println(totalDelay);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  Serial.println(counter);

  if (distance < threshold) {
    counter += 1;
    delay(totalDelay / 4);
  } else {
    if (justDispensed) {
      counter = -1;
    } else if (counter < 0) {
      counter += 1;
    } else {
      counter = 0;
    }

    if (IR.decode(&cmd) != 0) {
      readRemote();
    } else {
      for (int i = 0; i < 20; i += 1)
      {
        delay(totalDelay / 20);
        if (IR.decode(&cmd) != 0) {
          readRemote();
          break;
        }
      }
    }
  }

  if (counter == 2) {
    dispense();
    justDispensed = true;
  } else if (counter < 2) {
    justDispensed = false;
  }


}

int readRemote() {
  if (cmd.value == 0xFF02fd) {
    dispense();
  }
  else {
    delay(totalDelay);
  }

  IR.resume();
}

int dispense() {
  Serial.println("Dispense the candy!");
  for (int pos = 0; pos < 91; pos += 1)
  {
    left.write(90 - pos);
    right.write(pos);
    delay(servoSpeed);
  }

  delay(servoOpen);

  for (int pos = 0; pos < 91; pos += 1)
  {
    left.write(pos);
    right.write(90 - pos);
    delay(servoSpeed);
  }

  delay(servoOpen);
}
