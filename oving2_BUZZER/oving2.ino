/*Buzzer*/

#include <LiquidCrystal.h>
const int buzzer = 9; //buzzer to arduino pin 9
int skruFrekvens = 5;
int skruHastighet = 4;
int volum = 0;
int val = 0;
int pause = 100;
int knapp = 13;
int kjor = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("*********************************************************************************************");
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output 
  pinMode(kjor, INPUT);
}

void loop(){
  if (digitalRead(knapp)== LOW){
    if (kjor == 0){
      kjor = 1;
    }
    else{
      kjor = 0;
    }
  }
  if (kjor == 1){
    val = analogRead(skruFrekvens);
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    pause = analogRead(skruHastighet);
    tone(buzzer, val); // Send 1KHz sound signal...
    lcd.noDisplay();
    // print the number of seconds since reset:
    delay(pause*10);
    noTone(buzzer);     // Stop sound...
    lcd.display();
    delay(pause*10);
  }
  else{
    delay(1000);
  }
}
