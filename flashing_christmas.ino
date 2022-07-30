#define redled 7
#define whiteled 6
#define greenled 5


void setup() {
  pinMode(redled,OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(whiteled, OUTPUT);
  DDRD = B11111111; 
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = B11100000;
  delay(500);
  PORTD = B01100000;
  delay(500);
  PORTD = B10100000;
  delay(500);
  PORTD = B11000000;
  delay(500);
  PORTD = B00000000;
  delay(500);
  PORTD = B00100000;
  delay(500);
  PORTD = B01100000;
  delay(500);
  PORTD = B11100000;
  delay(500);
  PORTD = B00000000;
  delay(200);
  PORTD = B11100000;
  delay(200);
   PORTD = B00000000;
  delay(200);
  PORTD = B11100000;
  delay(200);
   PORTD = B00000000;
  delay(200);
  PORTD = B11100000;
  delay(200);
}
