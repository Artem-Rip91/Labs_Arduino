#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);
int columnLCD = 20, rowsLCD = 4;

unsigned long time = columnLCD;
String str = "Witcher 3 The Wild Hunt";//23

void setup()
{
	lcd.begin(columnLCD, rowsLCD);
	lcd.setBacklight(HIGH);

	

}

void loop()
{
	if( millis() > time + 1000)
	{
		time = millis();

		//for (int posCount = 0; posCount < 20; posCount++){
		lcd.setCursor(0,0);
		lcd.print("Witcher 3 The Wild Hunt");
		lcd.scrollDisplayRight();
		delay(150);
		//}

/*for(int posCount = 0; posCount < 43; posCount++){
			lcd.scrollDisplayLeft();
			delay(150);
		}

		for(int posCount = 0; posCount < 20; posCount++){
			lcd.scrollDisplayRight();
		}*/

	}

}
