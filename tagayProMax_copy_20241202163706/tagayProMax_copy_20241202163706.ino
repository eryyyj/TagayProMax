/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-water-sensor
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define POWER_PIN  7
#define SIGNAL_PIN A3

LiquidCrystal_I2C lcd(0x27, 16, 2);
int value = 0; // variable to store the sensor value

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Sensor value: ");
  Serial.println(value);
  if(value <= 500){
    lcd.print("tagay pa!");
  }else{
    lcd.print("tama na pre...");
  }
  delay(1000);
  lcd.clear();
}
