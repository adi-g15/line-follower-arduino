// undefined behaviour... start me ghum rha tha, baad me wo yellow wala light hi
// band ho jata tha

const int MOTOR_OUT = 13; // Motor output pin

void setup() {
    Serial.begin(9600);
    pinMode(MOTOR_OUT, OUTPUT);
}

void loop() {
    Serial.println("Forward");
    digitalWrite(MOTOR_OUT, HIGH);
    delay(2000);
    Serial.println("Stop");
    digitalWrite(MOTOR_OUT, LOW);
    delay(2000);
}
