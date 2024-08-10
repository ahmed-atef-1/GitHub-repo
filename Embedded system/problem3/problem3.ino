void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite (10, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite (11, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  Serial.println("Yaw RIGHT");
  digitalWrite (3, LOW);
  digitalWrite (2, HIGH);
  digitalWrite (4, LOW);
  digitalWrite (5, HIGH);

  delay(1000);

  Serial.println("Yaw Left");
  digitalWrite (3, HIGH);
  digitalWrite (2, LOW);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);

  delay(1000);

  Serial.println("Move Forward");
  digitalWrite (3, LOW);
  digitalWrite (2, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);

  delay(1000);

  Serial.println("Move Backward");
  digitalWrite (3, HIGH);
  digitalWrite (2, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, HIGH);

  delay(1000);
}
