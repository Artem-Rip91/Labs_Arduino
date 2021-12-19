#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);
int columnLCD = 20, rowsLCD = 4;

int X = 0;

String empty = ("                        ");

unsigned long time = 0;
String str = "Witcher 3 The Wild Hunt ";//23

int pass = 0;

void setup()
{
	lcd.begin(columnLCD, rowsLCD);
	lcd.setBacklight(HIGH);

}

void loop()
{
	lcd.setCursor(X,3);
	lcd.print(str);

	lcd.setCursor(0,0);
	lcd.print(empty);
	lcd.setCursor(0,1);
	lcd.print(empty);
	lcd.setCursor(0,2);
	lcd.print(empty);

	if(++X == 20){
		X = columnLCD;
		//lcd.print("         ");
	}
	if(++pass >= 2){
		pass = 0;
		lcd.print(empty);
	}
	delay(100);

}