const int pwmPin1 = 2;  // Pin connected to the PWM output of the other Arduino
const int pwmPin2 = 3;
const int pwmPin3 = 4;
const int pwmPin4 = 5;
void setup() {
  Serial.begin(9600);
  pinMode(pwmPin1, INPUT);
  pinMode(pwmPin2, INPUT);
  pinMode(pwmPin3, INPUT);
  pinMode(pwmPin4, INPUT);
}
bool isValidPWM(unsigned long value) {
  return value > 0 && value < 3000;
}

void loop() {
  // Measure the length (in microseconds) of the HIGH pulse
  unsigned long pwmValue1 = pulseIn(pwmPin1, HIGH, 25000); // 25ms timeout
  unsigned long pwmValue2 = pulseIn(pwmPin2, HIGH, 25000); // 25ms timeout
  unsigned long pwmValue3 = pulseIn(pwmPin3, HIGH, 25000); // 25ms timeout
  unsigned long pwmValue4 = pulseIn(pwmPin4, HIGH, 25000); // 25ms timeout



if (isValidPWM(pwmValue1) || isValidPWM(pwmValue2) || isValidPWM(pwmValue3) || isValidPWM(pwmValue4)) {    Serial.print("PWM Pulse Width1: ");
    Serial.print(pwmValue1);
    Serial.print(" us \t");
    Serial.print("PWM Pulse Width2: ");
    Serial.print(pwmValue2);
    Serial.print(" us \t");
    Serial.print("PWM Pulse Width3: ");
    Serial.print(pwmValue3);
    Serial.print(" us \t");
    Serial.print("PWM Pulse Width4: ");
    Serial.print(pwmValue4);
    Serial.println(" us");
  } else {
    Serial.println("No signal detected");
  }

  delay(100);  // Adjust rate as needed
}
