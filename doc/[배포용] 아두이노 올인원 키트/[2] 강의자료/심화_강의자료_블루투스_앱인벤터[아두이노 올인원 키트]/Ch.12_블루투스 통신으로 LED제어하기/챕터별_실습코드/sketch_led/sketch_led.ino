#include <SoftwareSerial.h>   // 통신용 라이브러리

#define LED_PIN_Room1 13  //Room1 LED 핀번호 
#define LED_PIN_Room2 12  //Room2 LED 핀번호 
#define BTtx 7           //블루투스 tx핀 번호
#define BTrx 8            //블루투스 rx핀 번호

SoftwareSerial BT(BTtx, BTrx);   //블루투스 객체

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);         //블루투스 시리얼 통신 시작
  Serial.begin(9600);     //아두이노 시리얼 통신 시작
  pinMode(LED_PIN_Room1,OUTPUT);     //Room1 LED 출력모드
  pinMode(LED_PIN_Room2,OUTPUT);     //Room2 LED 출력모드

}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available() > 0){
    
    char data = BT.read();
    Serial.println(data);
    //digitalWrite(LED_PIN_Room1, HIGH);

    if(data == '1') digitalWrite(LED_PIN_Room1, HIGH);
    else if(data == '2') digitalWrite(LED_PIN_Room1, LOW);
    else if(data == '3') digitalWrite(LED_PIN_Room2, HIGH);
    else if(data == '4') digitalWrite(LED_PIN_Room2, LOW);

  }
  else{
    //digitalWrite(LED_PIN_Room2, HIGH);
  }

}


