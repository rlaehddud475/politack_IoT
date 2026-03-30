#include <SoftwareSerial.h>

#define LED_PIN_Room1 13
#define LED_PIN_Room2 12
#define BTtx 7
#define BTrx 8

SoftwareSerial BT(BTtx, BTrx);

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN_Room1,OUTPUT);
  pinMode(LED_PIN_Room2,OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available() > 0){
    char data = BT.read();
    Serial.println(data);
    if(data == '1') digitalWrite(LED_PIN_Room1, HIGH);
    else if(data == '2') digitalWrite(LED_PIN_Room1, LOW);
    else if(data == '3') digitalWrite(LED_PIN_Room2, HIGH);
    else if(data == '4') digitalWrite(LED_PIN_Room2, LOW);

  }

}


