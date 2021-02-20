// Digital pin 8 will be called 'pin8'

#define TRIG 11 //Module pins
#define ECHO 12 
int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
// Analog pin 0 will be called 'sensor'
int sensor = A0;
// Set the initial sensorValue to 0
int sensorValue = 0;

// The setup routine runs once when you press reset
void setup() {
  // Initialize the digital pin 8 as an output
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

// The loop routine runs over and over again forever
void loop() { digitalWrite(TRIG, LOW);
    delayMicroseconds(2); 
    
    digitalWrite(TRIG, HIGH); 
    delayMicroseconds(20); 
    
    digitalWrite(TRIG, LOW);
    int distance = pulseIn(ECHO, HIGH,26000); 
    
    distance= distance/58; //Convert the pulse duration to distance
                           //You can add other math functions to calibrate it well
                           
    Serial.print("Distance ");
    Serial.print(distance);
    Serial.println("cm");
   
    delay(1000);
 
  sensorValue = analogRead(sensor);
  // Print out the value you read
  Serial.println(sensorValue, DEC);
  delay(300);
  if (sensorValue <110 ){
    digitalWrite(pin10,HIGH);
     
  }else{
    digitalWrite(pin10,LOW);
   
  if (sensorValue > 100) {
    // Activate digital output pin 8 - the LED will light up
    //digitalWrite(pin8, HIGH);
    digitalWrite(pin8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(pin8, LOW);    // turn the LED off by making the voltage LOW
  delay(300);  
  } else if(distance < 50 && sensorValue >70){
   digitalWrite(pin10,LOW);
    digitalWrite(pin8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(pin8, LOW);    // turn the LED off by making the voltage LOW
  delay(300);  
       digitalWrite(pin9,HIGH);//beep goes on after 0.3sec
  delay(300);
  digitalWrite(pin9,LOW);//beep goes on and off
  delay(300);
    }
  else {
    // Deactivate digital output pin 8 - the LED will not light up
    digitalWrite(pin8, LOW);
  }

  }
  }
