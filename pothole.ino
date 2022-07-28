
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;
const int pingPin = A4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A5; // Echo Pin of Ultrasonic Sensor
const int buzzer = A3;
Adafruit_LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

int i1 = 6;
int i2 = 7;

int e = 10;

int s= 100;

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
 pinMode(A0, OUTPUT);
   pinMode(A1, OUTPUT);
  // Print a message to the LCD.
    pinMode(buzzer, OUTPUT); 

      delay(5000);
  pinMode(i1, OUTPUT);
  pinMode(i2, OUTPUT);

  
  pinMode(e, OUTPUT);

 Serial.begin(9600);
}

void loop()
{
    digitalWrite(i1, HIGH);
  digitalWrite(i2, LOW);
analogWrite(e,s);
  
  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");

   Serial.println();
   delay(100);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd_1.print(inches);
  if(inches<20){
       digitalWrite(i1, HIGH);
  digitalWrite(i2, LOW);
analogWrite(e,40);
  
    
    digitalWrite(A1, LOW);
     digitalWrite(A0, HIGH);
      lcd_1.setCursor(0, 1);
  lcd_1.print("Danger");
     Serial.print("Danger");
      tone(buzzer, 1000); // Send 1KHz sound signal...
      // ...for 1 sec
     // Stop sound...

  }
  else{

 digitalWrite(A1, HIGH);
    digitalWrite(A0, LOW);
    lcd_1.print("");
     noTone(buzzer); 
  }
  delay(200);
  
     lcd_1.clear();
   // Wait for 1000 millisecond(s)

}



long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}