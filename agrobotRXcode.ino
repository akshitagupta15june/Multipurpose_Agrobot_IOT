#define motorLA 2
#define motorLB 3
#define motorRA 4
#define motorRB 5

#define frontMotor 6
#define seedMotor 7
#define waterMotor 8
#define anchorMotor 9

#define buzzer 11
#define rxLed 12
#define rxLed1 13
char sw1,sw2,sw3,sw4,sw5;


void setup() {
	delay(200);
	Serial.begin(9600);
	Serial.println("Agricutture Robot Rx");
	pinMode(motorLA, OUTPUT);
	pinMode(motorLB, OUTPUT);
	pinMode(motorRA, OUTPUT);
	pinMode(motorRB, OUTPUT);
	pinMode(frontMotor, OUTPUT);
	pinMode(seedMotor, OUTPUT);
	pinMode(waterMotor, OUTPUT);
	pinMode(anchorMotor, OUTPUT);
	pinMode(buzzer, OUTPUT);
	pinMode(rxLed, OUTPUT);
	pinMode(rxLed1, OUTPUT);

	digitalWrite(motorLA, LOW);
	digitalWrite(motorLB, LOW);
	digitalWrite(motorRA, LOW);
	digitalWrite(motorRB, LOW);

	digitalWrite(frontMotor, LOW);
	digitalWrite(seedMotor, LOW);
	digitalWrite(waterMotor, LOW);
	digitalWrite(anchorMotor, LOW);
	

	digitalWrite(buzzer, LOW);
	digitalWrite(rxLed, LOW);
	digitalWrite(rxLed1, LOW);

}

void loop() {
	
  if (Serial.find("#")){
  	digitalWrite(rxLed, HIGH);
  	digitalWrite(rxLed1, HIGH);
    delay(50);
    sw1 = Serial.read();
    sw2 = Serial.read();
    sw3 = Serial.read();
    sw4 = Serial.read();
    sw5 = Serial.read();


// update car motor

	switch (sw1){
		case 'F':
		digitalWrite(motorLA, HIGH);
		digitalWrite(motorLB, LOW);
		digitalWrite(motorRA, HIGH);
		digitalWrite(motorRB, LOW);
		break;

		case 'B':
		digitalWrite(motorLA, LOW);
		digitalWrite(motorLB, HIGH);
		digitalWrite(motorRA, LOW);
		digitalWrite(motorRB, HIGH);
		break;

		case 'L':
		digitalWrite(motorLA, LOW);
		digitalWrite(motorLB, HIGH);
		digitalWrite(motorRA, HIGH);
		digitalWrite(motorRB, LOW);
		break;

		case 'R':
		digitalWrite(motorLA, HIGH);
		digitalWrite(motorLB, LOW);
		digitalWrite(motorRA, LOW);
		digitalWrite(motorRB, HIGH);
		break;

		case 'S':
		digitalWrite(motorLA, LOW);
		digitalWrite(motorLB, LOW);
		digitalWrite(motorRA, LOW);
		digitalWrite(motorRB, LOW);
		break;
	}    

// update front motor

	if (sw2 == '0'){
		digitalWrite(frontMotor,	LOW);
	}else{
		digitalWrite(frontMotor, HIGH);
	}

//update seed motor

	if (sw3 == '0'){
		digitalWrite(seedMotor, LOW);
	}else{
		digitalWrite(seedMotor, HIGH);
	}

//update water motor

	if (sw4 == '0'){
		digitalWrite(waterMotor, LOW);
	}	else{
		digitalWrite(waterMotor, HIGH);
	}

//upadte anchor motor

	if (sw5 == '0'){
		digitalWrite(anchorMotor, LOW);
	}else{
		digitalWrite(anchorMotor, HIGH);
	}

	

	delay(20);

	digitalWrite(rxLed, LOW);
	digitalWrite(rxLed1, LOW);
}

}
