#include <Servo.h>

Servo myServo;
int servoPin = 6;
int led[] = {9, 10, 11, 12};
int inputs[] = {2, 3, 4, 5};
int angle[] = {135, 85, 40, 0};

void setup() {
    myServo.attach(servoPin);
    pinMode(led[0],OUTPUT);
    pinMode(led[1],OUTPUT);
    pinMode(led[2],OUTPUT);
    pinMode(led[3],OUTPUT);
    pinMode(inputs[0],INPUT);
    pinMode(inputs[1],INPUT);
    pinMode(inputs[2],INPUT);
    pinMode(inputs[3],INPUT);

    myServo.write(135); // initial position for servo motor
}

void loop() {
    int activeLed = -1;
    for (int i = 0; i < 4; i++) {
        if (digitalRead(inputs[i]) == HIGH) {
            activeLed = i;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (i <= activeLed) {
            digitalWrite(led[i], HIGH);
        } else {
            digitalWrite(led[i], LOW);
        }
    }
    
    if (activeLed >= 0) {
        myServo.write(angle[activeLed]);
    }
}


