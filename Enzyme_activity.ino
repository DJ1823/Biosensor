
#include <LiquidCrystal.h>
#include <math.h>

// LCD pin configuration -> RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// TMP36 Sensor
const int sensorPin = A0;

// LEDs for enzyme activity indication
const int led1 = 6;  // Very Low
const int led2 = 7;  // Low (1–50%)
const int led3 = 8;  // Medium (50–99%)
const int led4 = 9;  // Peak (≈100%)

float reading, voltage, tempC, activity;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // 16 columns, 2 rows

  lcd.print("Catalase System");

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  delay(1000);
  lcd.clear();
}

void loop() {
  // Step 1: Read sensor value
  reading = analogRead(sensorPin);

  // Step 2: Convert to voltage (using 5V reference)
  voltage = reading * (5.0 / 1023.0);

  // Step 3: Convert to Celsius
  tempC = (voltage - 0.5) * 100.0;

  // Step 4: Enzyme activity (Gaussian formula)
  float optimalTemp = 37.0;  
  float sigma = 5.0;         
  activity = exp(-pow((tempC - optimalTemp), 2) / (2 * pow(sigma, 2))) * 100;

  // Step 5: LED indication
  if (activity < 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (activity >= 1 && activity < 50) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (activity >= 50 && activity < 99) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }

  // Step 6: Print on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(tempC, 1);
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Enzyme Act:");
  lcd.print(activity, 1);
  lcd.print("%   ");

  // Step 7: Print in Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C | Enzyme Activity: ");
  Serial.print(activity);
  Serial.println(" %");

  delay(500);
}
