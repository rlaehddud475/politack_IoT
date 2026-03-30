#include <SoftwareSerial.h>   // 통신용 라이브러리
#include <MyDelay.h>        // 일정시간 반복용 라이브러리
#include "DHT.h"            // 온습도 라이브러리

#define LED_PIN_Room1 13  //Room1 LED 핀번호 
#define LED_PIN_Room2 12  //Room2 LED 핀번호 
#define BTtx 7           //블루투스 tx핀 번호
#define BTrx 8            //블루투스 rx핀 번호
#define DHTPIN 4            //온습도 핀 번호
#define DHTTYPE 11            //온습도 종류

SoftwareSerial BT(BTtx, BTrx);   //블루투스 객체
MyDelay Timer(3000);    // 3초마다 반복되게 설정
DHT dht(DHTPIN, DHTTYPE);    //온습도 객체

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);         //블루투스 시리얼 통신 시작
  Serial.begin(9600);     //아두이노 시리얼 통신 시작
  pinMode(LED_PIN_Room1,OUTPUT);     //Room1 LED 출력모드
  pinMode(LED_PIN_Room2,OUTPUT);     //Room2 LED 출력모드

  dht.begin();         //온습도 센서 설정
  Timer.start();  //3초 마다 반복 시작

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

    if(Timer.update()){   //3초가 되었다면
      byte t = dht.readTemperature();   //온도값 읽기
      byte h = dht.readHumidity();      //습도값 읽기
      if(!(isnan(t) || isnan(h))) {     //숫자인지 체크
        BT.print(t);         //온도값 보내기(앱으로)
        BT.print(",");       //구분자 보내기(앱으로)
        BT.print(h);         //습도값 보내기(앱으로)
        Serial.println(t);
        Serial.println(",");
        Serial.println(h);
    }
    
  }

}


