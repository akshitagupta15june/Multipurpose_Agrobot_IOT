#define txLed 2
#define frontMotorSw 3
#define seedMotorSw 4
#define WaterMotorSw 5
#define anchorMotorSw 6

#define leftSw 8
#define forwordSw 9
#define backSw 10
#define rightSw 11



char sw1;
char sw2;
char sw3;
char sw4;
char sw5;
bool swPressed = false;

void setup() {
  delay(200);
  Serial.begin(9600);
  Serial.println("Agricutture Robot Tx");
  pinMode(forwordSw,INPUT_PULLUP);
  pinMode(backSw, INPUT_PULLUP);
  pinMode(leftSw, INPUT_PULLUP);
  pinMode(rightSw, INPUT_PULLUP);
  pinMode(frontMotorSw, INPUT_PULLUP);
  pinMode(seedMotorSw, INPUT_PULLUP);
  pinMode(WaterMotorSw, INPUT_PULLUP);
  pinMode(anchorMotorSw, INPUT_PULLUP);
  pinMode(txLed, OUTPUT);
  digitalWrite(txLed, LOW);


}

void loop() {
  
  // for vechile wheels

	swPressed = false;	

  if (digitalRead(forwordSw) == false){
    sw1 = 'F';
    swPressed = true;
    }
    
  if (digitalRead(backSw) == false){
  	sw1 = 'B';
  	swPressed = true;
  	}
   
  if (digitalRead(leftSw) == false){
  	sw1 = 'L';
  	swPressed = 1;
  }
  	
  if (digitalRead(rightSw) == false){
  	sw1 = 'R';
  	swPressed = 1;
  }

  if (swPressed == false){
  	sw1 = 'S';
  }

// for front motot

  if (digitalRead(frontMotorSw) == false){
  	sw2 = '1';
  }else{
  	sw2 = '0';
  }

// for seed motor

	if (digitalRead(seedMotorSw) == false){
		sw3 = '1';
	} else{
		sw3 = '0';
	} 

// water motor

	if (digitalRead(WaterMotorSw) == false){
		sw4 = '1';
	}	else{
		sw4 = '0';
	}


// for anchor motor

	if (digitalRead(anchorMotorSw) == false){
		sw5 = '1';
	}	else{
		sw5 = '0';
	}

	

//send data via bluetooth

	digitalWrite(txLed, HIGH);
	Serial.print("#");
	Serial.print(sw1);
	Serial.print(sw2);
	Serial.print(sw3);
	Serial.print(sw4);
	Serial.print(sw5);
	Serial.println("\r\n");
	digitalWrite(txLed, LOW);

	delay(250);

}
