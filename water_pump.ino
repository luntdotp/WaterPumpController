int pump = 11;
int green = 12;
int yellow = 13;
int empty = 1;
int full = 2;
int error = 0;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(full, INPUT);
  pinMode(empty, INPUT);
}

void loop() {
  if(full = HIGH) {
    digitalWrite(green, HIGH); //Enable green LED.
    digitalWrite(yellow, LOW); //Disable yellow LED.
    digitalWrite(pump, LOW); //Disengage pump.
  }
  
  while(error = 1) { //While there is an error.
    digitalWrite(yellow, HIGH); //Enable yellow LED.
    digitalWrite(green, LOW); //Disable green LED.
    digitalWrite(pump, HIGH); //Engage pump.
    delay(15000); //Wait 15 seconds.
    digitalWrite(pump, LOW); //Disengage pump.
    if(empty = LOW) { //If tank is not empty after 10 seconds the error is resolved.
      error = 0;
    } else { //If the error is not resolved...
      delay(240000); //Wait 4 minutes.      
    }
  }
  
  while(full = LOW) { //While the tank is not full...
    digitalWrite(green, HIGH); //Enable green LED.
    digitalWrite(pump, HIGH); //Enable pump.
    digitalWrite(yellow, HIGH); //Enable yellow LED.
    delay(2000);
    if(empty = LOW) { //If the tank is empty engage error mode, tank should not be empty.
      error = 1;
    }
  }
}
