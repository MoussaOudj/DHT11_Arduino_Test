#include "DHT.h"

#define DHTPIN 12
#define DHTTYPE DHT11

#include <Wire.h>
#include "rgb_lcd.h"

DHT dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 10;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  pinMode(2, INPUT_PULLUP);
  Serial.println("SETUP");

}

void loop() {
  delay(1000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (buttonState == HIGH) {
    
    Serial.print("Humidity: ");
    Serial.println(humidity);
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidity);

    Serial.print("Temps: ");
    Serial.println(temperature);
    lcd.setCursor(0, 1);
    lcd.print("Temps: ");
    lcd.print(temperature);
    lcd.print(" C");
    digitalWrite(2, LOW);

    if (temperature < 20) {
      digitalWrite(2, HIGH);
    }
    
  } else {
    digitalWrite(2, LOW);
  }
}
