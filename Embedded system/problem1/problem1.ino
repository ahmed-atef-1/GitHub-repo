void setup() {
  pinMode (A1 , INPUT);
  pinMode (3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int test = analogRead(A1);
  int final_result = map(test, 619, 1021, 0, 1023);
  if (final_result < 500){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
  Serial.println(final_result);
}