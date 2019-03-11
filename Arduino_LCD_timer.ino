/*
 В сутках 86400000 мс
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define relay_pin 2    // пин реле
#define day 95000000  // Время работы таймера в мс

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  pinMode(relay_pin, OUTPUT);		// пин реле как выход
  lcd.init();                 
  lcd.backlight();            
  lcd.setCursor(0, 0);
  lcd.print("Timer v2");
}

void loop() {

  lcd.init();  
  if (millis() <= day){
  do {
      lcd.setCursor(0, 0);
      lcd.print("Shutdown after");
      lcd.setCursor(0, 1);
      lcd.print("seconds:");
      lcd.setCursor(11, 1);
      lcd.print(day - millis());
      
     } while (millis() >= day);

                }
  else {
    digitalWrite(relay_pin, HIGH);   // выключаем реле
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Please turn off");
    lcd.setCursor(0, 1);
    lcd.print("before next use.");
    delay(1000000);
    }
 }
