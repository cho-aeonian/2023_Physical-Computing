int sensor_value = 0;       // 조도 센서 저장값
int pir_sensor_pin = 2;     // 인체 감지 센서 핀
int buzzer_pin = 3;         // 부저 핀

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  pinMode(pir_sensor_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensor_value = analogRead(A0);

  // 조도 센서의 아날로그 값이 500 이하이고, 인체 감지 센서가 HIGH 값을 반환할 때
  if (sensor_value > 500 && digitalRead(pir_sensor_pin) == HIGH) {
    digitalWrite(buzzer_pin, HIGH);   // 레이저 포인트가 조도 센서에 없고, 인체를 감지한 경우 부저를 울린다.
    Serial.println("Intruder detected!");
  } else {
    digitalWrite(buzzer_pin, LOW);    // 레이저 포인트가 조도 센서에 있거나 인체를 감지하지 않은 경우 부저를 멈춘다.
  }
  
  delay(1);                           // 0.001초마다 조도 센서값을 체크
  Serial.println(sensor_value);
}
