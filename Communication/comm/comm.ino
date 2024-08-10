#include <Wire.h>
char c;
void setup() {
  Wire.begin(8);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Wire.onReceive(receiveFunc);
  Wire.onRequest(requestFunc);
}

void loop() {
  delay (100);
  digitalWrite(12,0);
  digitalWrite (11,0);
}

void receiveFunc(int bytename){
  while(Wire.available()){
  	c = Wire.read();
    digitalWrite(11,1);
    
  }
  Serial.println("");
}
        
void requestFunc(){
  Wire.write("slave1");
}