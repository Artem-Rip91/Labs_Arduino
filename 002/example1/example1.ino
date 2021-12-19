int count1 = 0;
int angle_plus = 0;

void servo(int pin, int angle)
{
	for(int i = 0; i <= 90; i++)
	{
		if(angle >= 0)
			count1++;
		else if(angle < 0)
			count1--;
		
		angle_plus = abs(angle) + count1;
		int pulseWidth = (angle_plus * 11) + 500;
		digitalWrite(pin, HIGH);
		delayMicroseconds(pulseWidth);
		digitalWrite(pin, LOW);
		delay(20 - pulseWidth / 1000);
		//}
	}
	count1 = 0;
}

void setup()
{
	pinMode(9,OUTPUT);

}
void loop()
{
	servo(9, 0); delay(1000);
	servo(9, 90); delay(1000);
	servo(9, -180); delay(1000);
	servo(9, -90); delay(1000);

}