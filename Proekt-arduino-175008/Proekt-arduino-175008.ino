
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int led1 = 7;
int led2 = 8;
int led3 = 9;
int buzz = 6;
int flagStudy = 1; //we are starting with the study time

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(led1, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  ////this is the alarm part it reminds you that you need to switch
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Ready?");
  //first
  tone(buzz, 92, 300); 
  digitalWrite(led1, HIGH);
  delay(250); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250); 
  digitalWrite(led3, LOW);
  //second
 tone(buzz, 92, 300); 
  digitalWrite(led1, HIGH);
  delay(250); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250); 
  digitalWrite(led3, LOW);
  //third
  tone(buzz, 92, 300); 
  digitalWrite(led1, HIGH);
  delay(250); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250); 
  digitalWrite(led3, LOW);
  //this is the study mode
  if(flagStudy==1){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Study Time");

    //it reminds you that almost 1/3 of the time passed
    delay(17000); 
    tone(buzz, 92, 300); 
    digitalWrite(led1, HIGH);
    delay(250); 
    digitalWrite(led1, LOW);
    //it reminds you that almost 1/3 of the time passed
    delay(17000);
     tone(buzz, 92, 300); 
    digitalWrite(led2, HIGH);
    delay(250); 
    digitalWrite(led2, LOW);
    //it reminds you that almost all of the time passed
    delay(17000);
     tone(buzz, 92, 300); 
    digitalWrite(led3, HIGH);
    delay(250); 
    digitalWrite(led3, LOW);    
    delay(1000); //last minute (or second in this case)
    flagStudy=0; //switch to break time mode
  }else{ //this is the break mode
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Break Time");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(17000); //break time
    flagStudy=1; //switch to study time mode
  }
}
