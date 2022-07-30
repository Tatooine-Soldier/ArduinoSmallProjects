#include <LiquidCrystal.h>
#include <IRremote.h>
#define button 7
#define buzzer 6
//C = 260
//D = 293.3Hz  
//E = 329Hz 
//F = 349.2Hz 
//G = 391.9Hz 
//A = 440Hz 
//B = 493.8Hz 
//High C = 523.2Hz

int prev =0;

IRrecv irrecv(8);
decode_results results;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int counter=0;
char *playlist[] = {"Twinkle", "McDo", "beep"};
char **choice;
int choose[] = {1,2,3}; 


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.print("Select song: ");
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(choice[counter]);
  lcd.setCursor(0, 1);
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value) {
      case 16769055:   //down
        scrollDown();
        break;
      case 16748655:  //up
        scrollUp();
        break;
      case 16712445:
        playSong(counter);
        break;
    } 
    if (counter > 2) {
      counter = 0;
    }
    if (counter < 0)  {
      counter = 3;
    }
    irrecv.resume();  
  }
}

void scrollDown() {
  lcd.clear();
  lcd.print(choice[counter]);
  counter = counter+1;
}

void scrollUp() {
  lcd.clear();
  counter = counter - 1;
  lcd.print(choice[counter]);
}

void playSong(int song) {
  if (song == 0) {
    tone(buzzer, 260);
    delay(400);
    tone(buzzer, 260);
    delay(400);
    tone(buzzer, 391);
    delay(400);
    tone(buzzer, 391);
    delay(400);
    tone(buzzer, 440);
    delay(400);
    tone(buzzer, 440);
    delay(400);
  }
}
