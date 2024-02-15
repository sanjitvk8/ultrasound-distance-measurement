//team 9 eex project


//connections:
//ultrasound sensor Vin to aurdino Vin
//ultrasound gnd to aurdino gnd
//i2c display gnd to aurdino gnd
//i2c display vcc to +5v of aurdino
//i2c display SDA to A4 of aurdino
//i2c display SCL to A5 of aurdino



#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define trigPin 3 //Sensor Echo pin connected to Arduino pin 3
#define echoPin 2 //Sensor Trip pin connected to Arduino pin 2

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
   lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Team 9");
  delay(2000);
  lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  lcd.print("Target Distance:");  //Print Message on First Row
}

void loop()
{
  long duration, distance;
  float meter;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.0344/2;
  meter = float(distance)/100;
  Serial.print("Distance: ");
  Serial.print(distance); // Print the output in serial monitor
  Serial.println(" cm");
  delay(100);

  lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0,1);   //Set Cursor again to first column of second row
  lcd.print(distance); //Print measured distance
  lcd.print(" cm, ");  //Print your units.
  lcd.print(meter);
  lcd.print(" M");
  delay(250); //pause to let things settle
}
