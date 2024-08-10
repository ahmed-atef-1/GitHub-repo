#include "Servo.h"

#define servoPin 9

Servo myservo;

const unsigned long sec = 1000;
unsigned long previousTime = 0;

const int trig1 = 4;
const int echo1 = 3;
const int trig2 = 7;
const int echo2 = 6;
long distance1;
int duration1;
long distance2;
int duration2;

int x = 0;
int y = 0;

int prev_x;
void defuse_the_spike(){
  digitalWrite(A4, HIGH);
  myservo.write(60);
  delay(2000);
  myservo.write(0);
  digitalWrite(A4, LOW);
}
void move_forward(){
  Serial.println("Move Forward");
  digitalWrite (8, LOW);
  digitalWrite (2, HIGH);
  digitalWrite (13, HIGH);
  digitalWrite (5, LOW);
  prev_x = x;
}

void yaw_right(){
  Serial.println("YAW RIGHT");
  digitalWrite (8, LOW);
  digitalWrite (2, HIGH);
  digitalWrite (13, LOW);
  digitalWrite (5, HIGH);
  delay(500);
}

void yaw_left(){
  Serial.println("YAW LEFT");
  digitalWrite (8, HIGH);
  digitalWrite (2, LOW);
  digitalWrite (13, HIGH);
  digitalWrite (5, LOW);
  delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode (A1 , INPUT); //mine detector pins
  pinMode (A4, OUTPUT);

  pinMode(2, OUTPUT); //motor pins
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite (10, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite (11, HIGH);

  pinMode(trig1, OUTPUT); //ultrasonic sensor pins
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  
  myservo.attach(9); //servo pins
  
}

void loop() {
  digitalWrite(trig1, LOW); //check obstacle exist
  delayMicroseconds(2);

  // create the pulse
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  
  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 0.0343 / 2;

  while (distance1 > 150){ 
  move_forward();
  while (prev_x == x){
    if (millis() - previousTime >= sec){
     x++;
     y++;
     Serial.println("live location is (x , y)");
     Serial.println(x);
     Serial.println(y);
     previousTime = millis();
   }
  }
  int test = analogRead(A1);  //check mines
  int final_result = map(test, 619, 1021, 0, 1023);
  if (final_result < 500){
    defuse_the_spike(); //remove mine function
  }

  }
  if(distance1 <= 150){ //avoid the obstacle
    yaw_right();
    while (distance2 < 150){
      digitalWrite(trig2, LOW);
      delayMicroseconds(2);

      digitalWrite(trig2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig2, LOW);

      duration2 = pulseIn(echo2, HIGH);
      distance2 = duration2 * 0.0343 / 2;
      move_forward();
      while (prev_x == x){
        if (millis() - previousTime >= sec){
          x++;
          Serial.println("live location is (x , y)");
         Serial.println(x);
         Serial.println(y);
         previousTime = millis();
        }
      }
    }
    yaw_left();
  }
  
}