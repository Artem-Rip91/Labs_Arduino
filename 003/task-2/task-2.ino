int pinPWE1 = 5, pinPWE2 = 6, pinDIR1 = 7, pinDIR2 = 8, pinEnc = 9;
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
	pinMode(pinPWE1, OUTPUT);
	pinMode(pinPWE2, OUTPUT);
	pinMode(pinDIR1, OUTPUT);
	pinMode(pinDIR2, OUTPUT);
	Serial.begin(9600);
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
	Serial.println(flag);
	int sensorReading = analogRead(A0);
	int t1 = map(sensorReading, 0, 1023, 0, 255);

	int sensorReading1 = analogRead(A1);
	int t2 = map(sensorReading1, 0, 1023, 0, 255);

	if (sensorReading <= 410)
		digitalWrite(pinDIR1, LOW);
	if (sensorReading >= 614)
		digitalWrite(pinDIR1, HIGH);
	if ((sensorReading >= 410) && (sensorReading <= 614))
		t1 = 0; 

	if (sensorReading1 <= 410)
		digitalWrite(pinDIR2, LOW);
	if (sensorReading1 >= 614)
		digitalWrite(pinDIR2, HIGH);
	if ((sensorReading1 >= 410) && (sensorReading1 <= 614))
		t1 = 0; 

	analogWrite(pinPWE2, t2);
	analogWrite(pinPWE1, t1);

}
