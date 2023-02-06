//code of (distance measure using aurdino with ultrasonic sensor in C language).
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define trigPin1 A1       // us1
#define echoPin1 A0
long duration, distance, sensor1;
int delay_time;
void setup() 
{
 Serial.begin(115200); // your esp's baud rate might be different
 lcd.begin(16, 2);//initializing LCD
 lcd.setCursor(0,0);
 lcd.print("Distance");
 lcd.setCursor(0,1);
 lcd.print("Measurement");
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT); 
}
void loop() 
{
 ultrasensor(trigPin1, echoPin1);
 sensor1 = distance;
 sensor1=sensor1*1.05;
 lcd.clear();
 lcd.setCursor(3,0);
 lcd.print(" Distance(cm) ");
 lcd.setCursor(7,1);
 lcd.print(sensor1); 
 delay(200);
 
} 
 void ultrasensor(int trigPin,int echoPin) //main  
 {  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 }
