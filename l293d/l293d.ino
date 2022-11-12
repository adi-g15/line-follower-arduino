const int M1_A_OUT = 3;
const int M1_B_OUT = 5;
int curr_speed = 0;

void setup() {
    pinMode(M1_A_OUT, OUTPUT);
    pinMode(M1_B_OUT, OUTPUT);
}

void loop() {
    analogWrite(M1_B_OUT, 0);

    while(1) {
        analogWrite(M1_A_OUT, curr_speed);
        delay(2000);
        curr_speed = (curr_speed + 20)%210 + 45;
    }
}
