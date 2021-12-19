#include <Servo.h>
Servo myservo;
int pos;
int potpin = 0;
int switchPin = 10;

void setup()
{
	myservo.attach(9);
	pinMode(switchPin, INPUT);
}
void loop()
{
	if(digitalRead(switchPin) == HIGH){
		pos = analogRead(potpin);
		pos = map(pos, 0, 1023, 0 ,180);
		myservo.write(pos);
		delay(15);
	}
	else if(digitalRead(switchPin) == LOW){
		for(pos = 0; pos <= 180; pos += 1){
			myservo.write(pos);
			delay(15);
		}
		for(pos = 180; pos >= 0; pos -= 1){
			myservo.write(pos);
			delay(15);
		}
	}
}