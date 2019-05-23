//lys 1

#include <Servo.h>

 
int red = 10;
int yellow = 9;
int green = 8;
int button = 12; 
int pos = 0;   

// lys2
int red2 = 13;
int green2 = 11;

Servo myservo; 




void setup() {
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  digitalWrite(green, HIGH);
  digitalWrite(red2,HIGH);
  myservo.attach(7); 
}

void changeLights(){
    delay(1000);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    delay(2000);
    digitalWrite(green2, HIGH);
    digitalWrite(red2, LOW);



    
    for (pos = 0; pos <= 90; pos += 1) { 
   
    myservo.write(pos);              
    delay(15);  
    }          
    delay(5000);
    digitalWrite(red2,HIGH);
    digitalWrite(green2,LOW);

    
    for (pos = 90; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    }
    
    delay(2000);
    digitalWrite(yellow,HIGH);
    delay(3000);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
    delay(1000);
}

void loop() {
    if (digitalRead(button) == HIGH){
        delay(15); 
        if (digitalRead(button) == HIGH) {
            
            changeLights();
            delay(1000); 
       
  }
        }
    }



