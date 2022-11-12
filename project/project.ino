const int LEFT_MOTOR_1A_OUT = 3;
const int LEFT_MOTOR_1B_OUT = 5;

const int RIGHT_MOTOR_2A_OUT = 6;
const int RIGHT_MOTOR_2B_OUT = 9;

const int LEFT_IR_IN = 12;
const int RIGHT_IR_IN = 13;

void setup() {
    Serial.begin(9600);

    pinMode(LEFT_MOTOR_1A_OUT, OUTPUT);
    pinMode(LEFT_MOTOR_1B_OUT, OUTPUT);
    pinMode(RIGHT_MOTOR_2A_OUT, OUTPUT);
    pinMode(RIGHT_MOTOR_2B_OUT, OUTPUT);

    pinMode(LEFT_IR_IN, INPUT);
    pinMode(RIGHT_IR_IN, INPUT);
}

void loop() {
    int left_ir_val = digitalRead(LEFT_IR_IN);
    int right_ir_val = digitalRead(RIGHT_IR_IN);

    Serial.println("Left IR: " + String(left_ir_val));
    Serial.println("Right IR: " + String(right_ir_val));
    Serial.println("");

    while (left_ir_val == 0) {
        left_ir_val = digitalRead(LEFT_IR_IN);
        // black line on left, turn left
        analogWrite(LEFT_MOTOR_1A_OUT, 0);
        analogWrite(LEFT_MOTOR_1B_OUT, 150);

        analogWrite(RIGHT_MOTOR_2A_OUT, 150);
    }

    while (right_ir_val == 0) {
        right_ir_val = digitalRead(RIGHT_IR_IN);
        // black line on right, turn right
        analogWrite(RIGHT_MOTOR_2A_OUT, 0);
        analogWrite(RIGHT_MOTOR_2B_OUT, 150);

        analogWrite(LEFT_MOTOR_1A_OUT, 150);
    }

    // ignore the IR for now

    // Left side pin should be connected to top
    analogWrite(LEFT_MOTOR_1A_OUT, 255);
    analogWrite(LEFT_MOTOR_1B_OUT, 0);

    analogWrite(RIGHT_MOTOR_2A_OUT, 255);
    analogWrite(RIGHT_MOTOR_2B_OUT, 0);

    delay(2000);
}
