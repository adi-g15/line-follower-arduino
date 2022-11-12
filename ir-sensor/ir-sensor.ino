const int IR_IN = 2;

void setup() {
    Serial.begin(9600);
    pinMode(IR_IN, INPUT);
}

void loop() {
    // 0 means something in front
    // 1 means nothing
    int val = digitalRead(IR_IN);
    Serial.println(val);
}
