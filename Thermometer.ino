#include <LiquidCrystal.h>
int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop()
{
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  //  Temp Kelvin
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK ); 
   // K to Celcius
  float tempC = tempK - 273.15;     
  // Celcius Fahrenheit      
  float tempF = (tempC * 9.0)/ 5.0 + 32.0;

  //displays temperature in F on the LCD display
  lcd.setCursor(0, 0);
  lcd.print("Temp:       F  ");
  lcd.setCursor(6, 0);
  lcd.print(tempF);
  // output of the temperature in F in the serial monitor 
  Serial.print(tempF);
  Serial.println(" F");
  delay(500);
}
