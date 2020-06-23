/*
 Name:		Speed_Control.ino
 Created:	4/7/2020 5:28:30 PM
 Author:	PTL21166W-PAN006
*/

// the setup function runs once when you press reset or power the board
int in1 = 2;
int in2 = 3;
int speed = 6;
int aux = 0;

void setup() {
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(speed, OUTPUT);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int n = analogRead(A0) / 4;
	if (n >= 130) {
		SetSpeed(speed, n);
		andar(in1, in2);
	}
	if (n <= 120) {
		aux = abs(255-n);
		SetSpeed(speed, aux);
		andar(in2, in1);
		Serial.println(aux);
	}
	Serial.println(n);
	SetSpeed(speed, 0);
}
void andar(int pin1, int pin2) {
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
}
void SetSpeed(int pinPWM, int SpeedValues) {
	analogWrite(pinPWM, SpeedValues);
}