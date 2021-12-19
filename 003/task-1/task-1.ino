int pinPWE = 5, pinDIR = 7, pinEnc = 6;
float gradus = 0; int encoder = 0; int flag = 0; int count = 0;

void checkRound()
{
	gradus = gradus + 22.5;
	if (int(gradus) % 360 == 0) {
		count++;
		gradus = 0;
	}
}

void setup()
{
	pinMode(pinEnc, INPUT);
	pinMode(pinPWE, OUTPUT);
	pinMode(pinDIR, OUTPUT);
	//digitalWrite(pinDIR, LOW);
	//digitalWrite(pinDIR, HIGH);
}

void loop()
{
	encoder = digitalRead(6);
	if ((encoder == HIGH) && (flag == 0)){
		checkRound();
		flag = 1;
	}
	if ((encoder == LOW) && (flag == 1)){
		checkRound();
		flag = 0;
	}
	int sensorReading = analogRead(A0);
	int t = map(sensorReading, 0, 1023, 0, 255);
	if (sensorReading <= 410)
		digitalWrite(pinDIR, LOW);
	if (sensorReading >= 614)
		digitalWrite(pinDIR, HIGH);
	if ((sensorReading >= 410) && (sensorReading <= 614))
		t = 0; 
	
	analogWrite(pinPWE, t);

}
