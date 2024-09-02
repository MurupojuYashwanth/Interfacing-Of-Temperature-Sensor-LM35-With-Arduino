#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int temperaturePin = A0;
const int redLedPin = 11;
const int greenLedPin = 8;

void setup() {
    Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(temperaturePin);
    float voltage = sensorValue * (5.0 / 1023.0);
    float tempC = voltage * 100.0;
    
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(" C");
    
    if (tempC >= 25.0) {
        digitalWrite(redLedPin, HIGH);
        digitalWrite(greenLedPin, LOW);
    } else {
        digitalWrite(redLedPin, LOW);
        digitalWrite(greenLedPin, HIGH);
    }
    
    delay(1000);
}
