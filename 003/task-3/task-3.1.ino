int pinPWE = 5, pinDir = 7, pinEnc = 6;
float gradus = 0; int encoder = 0; int flag = 0; int count = 0;
void checkRound()
{
	// ? ?????? ???????? 8 ????????? ?? 1 ??????, ?????
	// 8 ????????? ?? 360 ????????. 360/8=45, ?????
	// ??? ????????? (???????? ??? ?????? ?????) ?? 45/2==22,5 ???????
	gradus = gradus + 22.5;
	if (int(gradus) % 360 == 0) {
		count++;
		gradus = 0;
	}
}

byte MOTOR = 0;
void directionMOTOR(byte MOTOR, int value)
{
	switch(MOTOR){
		case 1:
		
			if (value <= 410)
				digitalWrite(pinDIR2, LOW);
			if (value >= 614)
				digitalWrite(pinDIR2, HIGH);
			if ((value >= 410) && (value <= 614))
				t1 = 0; 
		
		break;
		
		case 2:
		
			if (value <= 410)
				digitalWrite(pinDIR2, LOW);
			if (value >= 614)
				digitalWrite(pinDIR2, HIGH);
			if ((value >= 410) && (value <= 614))
				t1 = 0; 
		break;
		
		case 3:
		break;
		
	}
	
}

void setup() {
	pinMode(pinEnc, INPUT); // ???????, ??????? ????????? ??????
	pinMode(pinPWE, OUTPUT); // PWM - ????? ????????? ??????
	pinMode(pinDir, OUTPUT); // Dir - ???????? ????????? ??????
	digitalWrite(pinDir, LOW); // ????????? ??????
	//digitalWrite(pinDir, HIGH); // ????????? ?????
}
void loop() {
	encoder = digitalRead(6);
	if ((encoder == HIGH) && (flag == 0))  {	checkRound(); flag = 1;  }
	if ((encoder == LOW) && (flag == 1))  {	checkRound(); flag = 0;  }

	//??????? A0 - ?????? ? ?????????????
	int sensorReading1 = analogRead(A0);
	int sensorReading2 = analogRead(A1);
	// ????????????? ??????? ? ADC (??? 0 ?? 1023)
	// ?? ???????? PWM (??? 0 ?? 255)
	int t1 = map(sensorReading, 0, 1023, 0, 255);
	int t2 = map(sensorReading, 0, 1023, 0, 255);
	// ????????? PWM ??????? (????????? ????????? ??????)
	analogWrite(pinPWE, t);
}
