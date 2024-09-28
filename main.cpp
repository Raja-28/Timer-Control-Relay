#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
int relayPin = 7;
int buzzerPin = 6;
int startButtonPin = 2;
int stopButtonPin = 3;

unsigned long startTime = 0;
unsigned long timerDuration = 0;
bool timerRunning = false;

void setup() {
  
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP); 
  pinMode(stopButtonPin, INPUT_PULLUP);
  
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Timer Control");
  
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  
  if (digitalRead(startButtonPin) == LOW && !timerRunning) {
    startTime = millis();
    timerDuration = 5000;
    timerRunning = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Timer Started");
    delay(500); 
  }
  

  if (digitalRead(stopButtonPin) == LOW && timerRunning) {
    timerRunning = false;
    digitalWrite(relayPin, LOW); 
    digitalWrite(buzzerPin, LOW); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Timer Stopped");
    delay(500); 
  }

  
  if (timerRunning) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;

    
    if (elapsedTime >= timerDuration) {
      digitalWrite(relayPin, LOW); 
      digitalWrite(buzzerPin, HIGH);
      timerRunning = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time's up!");
    } else {
      digitalWrite(relayPin, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Time: ");
      lcd.print((timerDuration - elapsedTime) / 1000);
      lcd.print(" sec");
    }
  }

  delay(200);
}
