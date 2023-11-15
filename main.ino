#include "HX711.h"

#define DOUT_1 32
#define CLK_1 33
#define TrigPin1 2
#define EchoPin1 4
#define TrigPin2 5
#define EchoPin2 15
#define TrigPin3 18
#define EchoPin3 19

const float MAX_MUSCLE_CM = 40.0;
const float MAX_BONE_CM = 30.0;
const float MAX_FAT_CM = 80.0;

const float ADJUSTED_FAT_MAX_PERCENTAGE = 80.0;
const float ADJUSTED_BONE_MAX_PERCENTAGE = 30.0;
const float ADJUSTED_MUSCLE_MAX_PERCENTAGE = 40.0;

HX711 scale_1;

void setup() {
  Serial.begin(9600);
  scale_1.begin(DOUT_1, CLK_1);
  scale_1.set_scale(100);
  scale_1.tare();
  pinMode(TrigPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  pinMode(TrigPin2, OUTPUT);
  pinMode(EchoPin2, INPUT);
  pinMode(TrigPin3, OUTPUT);
  pinMode(EchoPin3, INPUT);
}

void loop() {
  float weight_1 = scale_1.get_units();

  long duration1, distance1;
  digitalWrite(TrigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin1, LOW);
  duration1 = pulseIn(EchoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  long duration2, distance2;
  digitalWrite(TrigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin2, LOW);
  duration2 = pulseIn(EchoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  long duration3, distance3;
  digitalWrite(TrigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin3, LOW);
  duration3 = pulseIn(EchoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  float percentage_muscle = (distance1 / MAX_MUSCLE_CM) * ADJUSTED_MUSCLE_MAX_PERCENTAGE;
  float percentage_bone = (distance2 / MAX_BONE_CM) * ADJUSTED_BONE_MAX_PERCENTAGE;
  float percentage_fat = (distance3 / MAX_FAT_CM) * ADJUSTED_FAT_MAX_PERCENTAGE;

  percentage_muscle = min(percentage_muscle, ADJUSTED_MUSCLE_MAX_PERCENTAGE);
  percentage_bone = min(percentage_bone, ADJUSTED_BONE_MAX_PERCENTAGE);
  percentage_fat = min(percentage_fat, ADJUSTED_FAT_MAX_PERCENTAGE);

  Serial.print("Sensor de Peso: ");
  Serial.print(weight_1);
  Serial.println(" kg");

  Serial.print("Peso em massa muscular: ");
  Serial.print(percentage_muscle);
  Serial.println("%");

  Serial.print("Peso em massa óssea: ");
  Serial.print(percentage_bone);
  Serial.println("%");

  Serial.print("Peso em gordura: ");
  Serial.print(percentage_fat);
  Serial.println("%");

  delay(1000);
}
