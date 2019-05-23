int buttonPin = 2; 
int ledPin = 0; 
int buttonstate = 0;
int ledstate = 0;

void setup() {

pinMode(ledPin, OUTPUT); 

pinMode(buttonPin, INPUT);
}

void loop(){

buttonstate = digitalRead(buttonPin);
ledstate = digitalRead(ledPin);
int timer=0;
if (buttonstate == LOW) {
  int startTid = millis(); 
  delay(100);
  while (true){
    buttonstate = digitalRead(buttonPin);
    int naaTid = millis();
    if(naaTid - startTid > 500){
      break;
    }
    if(buttonstate == LOW){
      timer = 1;
      break;
    }
  }
  if (timer == 1){
    if (ledstate == LOW ) { 
      delay(250);
      digitalWrite(ledPin, HIGH); 
    }
    else{
      delay(250);
      digitalWrite(ledPin, LOW); 
    }
  }
 }
}
  
  
  
