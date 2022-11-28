const int LEFT_IR_IN = 13;
const int RIGHT_IR_IN = 12;

void setup() {
    Serial.begin(9600);
    pinMode(LEFT_IR_IN, INPUT);
    pinMode(RIGHT_IR_IN, INPUT);
}

void loop() {
    // 0 means something light reflected
    // 1 means no light (black)
    int left_ir_val = digitalRead(LEFT_IR_IN);
    int right_ir_val = digitalRead(RIGHT_IR_IN);

    Serial.println("=======================");
    Serial.println("Left IR: " + String(left_ir_val));
    Serial.println("Right IR: " + String(right_ir_val));
    Serial.println("");

    delay(500);
}
