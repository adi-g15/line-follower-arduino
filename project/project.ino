const int RIGHT_MOTOR_1A_OUT = 3;
const int RIGHT_MOTOR_1B_OUT = 5;

const int LEFT_MOTOR_2A_OUT = 6;
const int LEFT_MOTOR_2B_OUT = 9;

const int RIGHT_IR_IN = 12;
const int LEFT_IR_IN = 13;

void setup() {
    Serial.begin(9600);

    pinMode(RIGHT_MOTOR_1A_OUT, OUTPUT);
    pinMode(RIGHT_MOTOR_1B_OUT, OUTPUT);
    pinMode(LEFT_MOTOR_2A_OUT, OUTPUT);
    pinMode(LEFT_MOTOR_2B_OUT, OUTPUT);

    pinMode(RIGHT_IR_IN, INPUT);
    pinMode(LEFT_IR_IN, INPUT);
}

void loop() {
    int right_ir_val = digitalRead(RIGHT_IR_IN);
    int left_ir_val = digitalRead(LEFT_IR_IN);

    Serial.println("Right IR: " + String(right_ir_val));
    Serial.println("Left IR: " + String(left_ir_val));
    
    // ignore the IR for now

    analogWrite(RIGHT_MOTOR_1A_OUT, 0);
    analogWrite(RIGHT_MOTOR_1B_OUT, 255);

    // should be in reverse order
    analogWrite(LEFT_MOTOR_2A_OUT, 255);
    analogWrite(LEFT_MOTOR_2B_OUT, 0);

    delay(2000);
}
