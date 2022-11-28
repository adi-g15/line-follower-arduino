const int M1_A_OUT = 3;
const int M1_B_OUT = 5;

const int M2_A_OUT = 6;
const int M2_B_OUT = 9;

int curr_speed = 0;

void setup() {
    Serial.begin(9600);
    pinMode(M1_A_OUT, OUTPUT);
    pinMode(M1_B_OUT, OUTPUT);
}

void loop() {
    analogWrite(M1_A_OUT, 0);
    analogWrite(M2_A_OUT, 0);

    while(1) {
	Serial.print("Moving both: ");
	Serial.println(curr_speed);

        analogWrite(M1_B_OUT, curr_speed);
        analogWrite(M2_B_OUT, curr_speed);
        delay(2000);
        curr_speed = (curr_speed + 20)%210 + 45;
    }
}
