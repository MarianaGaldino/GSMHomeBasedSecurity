#include <SoftwareSerial.h>
SoftwareSerial sim(5,6); //portas TXD RXD do sim
String number = "+5511984839039";                                    
int pirsensor = 10; //porta do sensor
int _timeout;
String _buffer;


void setup() {
  delay(5000); //delay for 5 seconds to make sure the modules get the signal
  Serial.begin(115200);
  _buffer.reserve(50);
  Serial.println("Sistem Started...");
  sim.begin(9600);
  delay(1000);
}

void loop(){
  
    Serial.print("Leitura do sensor");
    Serial.print(pirsensor);
    delay(1000);

  if(digitalRead(pirsensor) == HIGH)
  {     
    Serial.println("Theft Alert");
    callNumber();
    delay(2000);
  }
    else { 
    digitalRead(pirsensor) == LOW;
    Serial.println("Safe");
    }  
}

void callNumber() {
  Serial.print("calling...");
  Serial.print(sim.available());
  sim.print("ATD");
  sim.print(number);
  
}


