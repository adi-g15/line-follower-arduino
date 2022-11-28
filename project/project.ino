/**
    IOT Project - Arduino based line and lane follower

    ©️ Members:
    Aditya Gupta - 1906082
    Rabin Gaurav - 1906083
    Raja	 - 1906054
    Salman	 - 1906085
    Shivam	 - 1906102
    Vishnu	 - 1906101

    This supports two modes, can chose either when compiling, by changing CurrentMode:
    1. MODE_LINE_FOLLOWER - 
       The IR sensor values are used to ensure that the robot follows a SINGLE black line

    2. MODE_LANE_MAINTAIN -
       In this mode, the robot ensures that it is maintains its position to be between
       TWO PARALLEL black lines/lane

*/

#define MODE_LINE_FOLLOWER 7
#define MODE_LANE_MAINTAIN 8

const int CurrentMode = MODE_LINE_FOLLOWER;	// 0 - Line follower
						// 1 - Lane maintainer

// Pins connected to the Motor 1a, 1b, 2a, 2b pins on the l293D motor controller
const int LEFT_MOTOR_1A_OUT = 3;
const int LEFT_MOTOR_1B_OUT = 5;

const int RIGHT_MOTOR_2A_OUT = 6;
const int RIGHT_MOTOR_2B_OUT = 9;

// Pins connected to 'OUT' pin of the IR sensors
const int LEFT_IR_IN = 13;
const int RIGHT_IR_IN = 12;

// Predefined values returned by the IR sensors, NOT_REFLECTED generally means black on a surface
#define REFLECTED 0
#define NOT_REFLECTED 1	

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

    Serial.println("=======================");
    Serial.println("Left IR: " + String(left_ir_val));
    Serial.println("Right IR: " + String(right_ir_val));
    Serial.println("");

    if (left_ir_val == NOT_REFLECTED and right_ir_val == NOT_REFLECTED) {
	Serial.println("FINISHED");

	analogWrite(LEFT_MOTOR_1B_OUT, 0);
	analogWrite(RIGHT_MOTOR_2B_OUT, 0);

	delay(5000);

	return;
    }

    if ( CurrentMode == MODE_LINE_FOLLOWER ) {
	if (right_ir_val == NOT_REFLECTED) {
	    Serial.println("Black line on right side, turning right");
	    analogWrite(RIGHT_MOTOR_2B_OUT, 0);
	    analogWrite(LEFT_MOTOR_1B_OUT, 170);

	    while(right_ir_val == NOT_REFLECTED && left_ir_val== REFLECTED) {
	    	left_ir_val = analogRead(LEFT_IR_IN);
	    	right_ir_val = analogRead(RIGHT_IR_IN);
	    }

	    return;
	}

	if (left_ir_val == NOT_REFLECTED) {
	    Serial.println("Black line on left side, turning left side");
	    analogWrite(LEFT_MOTOR_1B_OUT, 0);
	    analogWrite(RIGHT_MOTOR_2B_OUT, 170);

	    while(left_ir_val == NOT_REFLECTED && right_ir_val== REFLECTED) {
	    	left_ir_val = analogRead(LEFT_IR_IN);
	    	right_ir_val = analogRead(RIGHT_IR_IN);
	    }

	    return;
	}
    } else if ( CurrentMode == MODE_LANE_MAINTAIN ) {
	if (left_ir_val == NOT_REFLECTED) {
	    analogWrite(LEFT_MOTOR_1B_OUT, 150);
	    analogWrite(RIGHT_MOTOR_2B_OUT, 0);
	    return;
	}

	if (right_ir_val == NOT_REFLECTED) {
	    // black line on right, turn right
	    //analogWrite(RIGHT_MOTOR_2A_OUT, 0);
	    analogWrite(RIGHT_MOTOR_2B_OUT, 150);

	    analogWrite(LEFT_MOTOR_1B_OUT, 0);
	    return;
	}

    }

    Serial.println("Driving both");
    // Left side pin should be connected to top
    analogWrite(LEFT_MOTOR_1A_OUT, 0);
    analogWrite(RIGHT_MOTOR_2A_OUT, 0);

    analogWrite(LEFT_MOTOR_1B_OUT, 255);
    analogWrite(RIGHT_MOTOR_2B_OUT, 255);
}

// ex: shiftwidth=2 expandtab:
