int pinPWE1 = 5, pinPWE2 = 6, pinDIR1 = 7, pinDIR2 = 8, pinEnc1 = 9, pinEnc2 = 10;
float gradus = 0; int encoder1 = 0, encoder2 = 0; int flag1 = 0, flag2 = 0; int count = 0;

int sensorRecent1 = 0;
int sensorRecent2 = 0;

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
	pinMode(pinEnc1, INPUT);
	pinMode(pinEnc2, INPUT);
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
	encoder1 = digitalRead(9);
	encoder2 = digitalRead(10);

	if ((encoder1 == HIGH) && (flag1 == 0)){
		checkRound();
		flag1 = 1;
	}
	if ((encoder1 == LOW) && (flag1 == 1)){
		checkRound();
		flag1 = 0;
	}

	if ((encoder2 == HIGH) && (flag2 == 0)){
		checkRound();
		flag2 = 1;
	}
	if ((encoder2 == LOW) && (flag2 == 1)){
		checkRound();
		flag2 = 0;
	}

	int sensorReading = analogRead(A0);
	int t1 = map(sensorReading, 0, 1023, 0, 255);

	int sensorReading1 = analogRead(A1);
	int t2 = map(sensorReading1, 0, 1023, 0, 255);

	if ((sensorReading <= 410) && (digitalRead(pinDIR1) != LOW)){
		//sensorRecent1 = sensorReading;
		digitalWrite(pinDIR1, LOW);
		Serial.print("MOTOR A: R");
		Serial.print("\n");
	}

	if ((sensorReading >= 614) && (digitalRead(pinDIR1) != HIGH)){
		//sensorRecent1 = sensorReading;
		digitalWrite(pinDIR1, HIGH);
		Serial.print("MOTOR A: L");
		Serial.print("\n");
	}

	if (((sensorReading >= 410) && (sensorReading <= 614))){
		//sensorRecent1 = sensorReading;
		t1 = 0;
		//sensorRecent1 = 0;
		if((sensorRecent1 == 0) && (sensorRecent1 != 1)){
			Serial.print("MOTOR A: S");
			Serial.print("\n");
			//sensorRecent1 = 1;
		} 

	}

	if ((sensorReading1 <= 410)&&(digitalRead(pinDIR2) != LOW)){
		//sensorRecent2 = sensorReading1;
		digitalWrite(pinDIR2, LOW);
		Serial.println("\t");	
		Serial.println("MOTOR B: R");
		//Serial.println("\t");	
	}

	if ((sensorReading1 >= 614) && (digitalRead(pinDIR2) != HIGH)){
		//sensorRecent2 = sensorReading1;
		digitalWrite(pinDIR2, HIGH);
		Serial.println("\t");	
		Serial.println("MOTOR B: L");
		//Serial.println("\t");	
	}

	if (((sensorReading1 >= 410) && (sensorReading1 <= 614))){
		sensorRecent2 = sensorReading1;
		t2 = 0;
		if((sensorRecent2 < 410) || (sensorRecent2 > 614)){
		Serial.println("\t");	
		Serial.println("MOTOR B: S"); 
		}
		//Serial.println("\t");
	}

	analogWrite(pinPWE2, t2);
	analogWrite(pinPWE1, t1);

}
