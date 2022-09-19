#include <LiquidCrystal.h>

#define incButton 9
#define decButton 10
#define buzzer 8
#define led 7 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float bpm = 40.0;  //bpm starts at 84 

void setup() {
  // put your setup code here, to run once:
  pinMode(incButton, INPUT);
  pinMode(decButton, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("BPM:");
}

void beep() {  //flashes the led and buzzes the buzzer
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
  delayMicroseconds(1000);
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
//  lcd.print(bpm);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay((60.0/bpm)*1000);
  beep();
  lcd.setCursor(0, 1);
  int state1;   //state of incrementing button 
  int state2;   //state of decrementing button  
  Serial.println((60.0/bpm)*1000);
  state1 = digitalRead(incButton); 
  if (state1 == HIGH) { 
    bpm = bpm + 4.0;
    Serial.println(bpm);
  }
  state2 = digitalRead(decButton); 
  if (state2 == HIGH) {
    bpm = bpm - 4.0;
    Serial.println(bpm);
  }
  if (bpm > 208.0){
    bpm = 208.0;  
  }
  if (bpm < 40.0) {
    bpm = 40.0;
  }
  lcd.print(bpm);
  Serial.println(bpm);
  
}
