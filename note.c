// 基礎プログラミングII 第3回 Scrummyプロジェクト


int lightSensor = A0;
int soundSensor = A1;
int button = 2;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int buzzer = 8;

void setup() {
  pinMode(button, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void rainbowLight() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(300);

  analogWrite(redPin, 255);
  analogWrite(greenPin, 127);
  analogWrite(bluePin, 0);
  delay(300);

  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  delay(300);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  delay(300);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  delay(300);
}

void loop() {
  int lightValue = analogRead(lightSensor);
  int soundValue = analogRead(soundSensor);
  int buttonValue = digitalRead(button);

  // 暗い＋元気なさそう or ボタン
  if ((lightValue < 300 && soundValue < 200) || buttonValue == HIGH) {

    tone(buzzer, 523); // ド
    rainbowLight();

  } else {

    noTone(buzzer);

  }
}
