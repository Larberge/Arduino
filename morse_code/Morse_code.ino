const int buttonPin = 2; //Butten settes til pin to som registrerer push
int buttonState = LOW; //Setter buttenstate til low til å begynne med
int startTime; //tider til å beregne lengden på push og pause
int endTime;
int greenLed = 3;
int redLed = 4;
int shortbreakLed = 5;



void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(shortbreakLed,OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin); //Loopen kjøres for første gang
  
  if(buttonState == HIGH){ //Loopen holdes her helt til butten blir pushed
    startTime = millis(); //Setter starttid til mills() tiden som har gått siden programmet startet
    
    while(buttonState){ //Kjøres så lenge buttonState ikke endres
      buttonState = digitalRead(buttonPin);
    }
    
    endTime = millis(); //Slutter tidtaker //Når buttonState endres, stopper whileloopen og endTime
    //Serial.println(endTime-startTime);
  
    if(endTime - startTime > 300){ //Dash for over 300 ms
      Serial.println(1);
      digitalWrite(greenLed, HIGH);   // Setter outputen høy
      delay(300);                  // venter 300ms
      digitalWrite(greenLed, LOW);    // Setter outputen lav
    }
    else if(  (endTime-startTime<300) && (endTime-startTime>35)){ //Dot
      Serial.println(0);
      digitalWrite(redLed, HIGH);   // setter outputen høy
      delay(300);                  // venter 300ms
      digitalWrite(redLed, LOW);    // setter outputen lav
    }

    
    startTime = millis(); //Måler tid for å kunne beregne hvor lange pausen er
    while(buttonState == LOW){
       digitalWrite(shortbreakLed, HIGH);   // setter outputen høy
       buttonState = digitalRead(buttonPin);
    }
    digitalWrite(shortbreakLed, LOW); 
    endTime = millis();
    if(endTime - startTime > 5000){ //Returnerer 3 som pause mellom ord
       Serial.println(3);
    }
    else if (endTime - startTime > 1000){ //Returnerer 2 som pause mellom bokstavver
       Serial.println(2);
    }
    else if(endTime - startTime >= 10000){
      Serial.println(4);
    }
  }
}
