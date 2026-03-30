int Red = 7;
int Yellow = 6;
int Blue = 5;

void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Blue, OUTPUT);
}

void loop() {
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Blue, LOW);
  delay(1000);

  digitalWrite(Red, HIGH);
  delay(1000);
    
  digitalWrite(Yellow, HIGH);
  delay(1000);
    
  digitalWrite(Blue, HIGH);
  delay(1000);
}
