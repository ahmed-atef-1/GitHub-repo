const int trig = 0;
const int echo = 1;

long distance;
int duration;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(echo, LOW);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // create the pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
}