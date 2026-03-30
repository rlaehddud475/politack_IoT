#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;

char* formatFloat(float value, int width=6, int precision = 2) {
  static char buffer[15];
  dtostrf(value, width, precision, buffer);
  return buffer;
}

void setup() {
  Serial.begin(115200);

  if (!mpu.begin()) {
    Serial.println("MPU6050모듈을 찾을 수 없습니다.");
    while (true) {
      delay(10);
    }
  }
  Serial.println("MPU6050모듈 초기화 완료");
}

void loop() {
  sensors_event_t a, g, t;
  mpu.getEvent(&a, &g, &t);

  Serial.print("가속도 X:");
  Serial.print(formatFloat(a.acceleration.x));
  Serial.print(", Y: ");
  Serial.print(formatFloat(a.acceleration.y));
  Serial.print(", Z: ");
  Serial.print(formatFloat(a.acceleration.z));

  Serial.print(" / 자이로 X:");
  Serial.print(formatFloat(g.gyro.x));
  Serial.print(", Y: ");
  Serial.print(formatFloat(g.gyro.y));
  Serial.print(", Z: ");
  Serial.print(formatFloat(g.gyro.z));

  Serial.print(" / 온도:");
  Serial.print(formatFloat(t.temperature));
  Serial.println("℃");
}
[출처] [아두이노] MPU6050 6축 가속도 & 자이로 센서|작성자 기계공