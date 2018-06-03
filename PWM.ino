void setup() {
    DDRC = 1<<PC7; // Set Direction of PC7 (pin 13) as output
    DDRB = 1<<PB7; // Set Direction of PB7 (pin 11) as output

    PORTB = 0<<PB7; // Set PB7 (pin 11) to Low

    PWM(); // Run PWM function
}

void loop() {
}

void PWM() {
   // set output mode -> non-inverting mode. --> Page 130/131 of ATMega32U4 datasheet. Or page 138/139 in ATMega328 Datasheet.
  TCCR4A |= (1 << COM4A1);

  // set PWM waveform generation Mode -> 10 bit phase correct PWM. --> Page 131/132 of ATMega32U4 datasheet. Or page 140 in ATMega328 Datasheet.
  TCCR4A |= (1 << WGM41) | (1 << WGM40);

  // set prescaler to 8 and starts PWM --> Page 133 of ATMega32U4 datasheet. Or page 142 in ATMega328 Datasheet.
  TCCR4A |= (1 << CS41);

    while (1)
    {
        // loop for transition in increments of 2
        for (int dutyCycle = 0 ; dutyCycle <= 255; dutyCycle += 2) {
            // sets the value (range from 0 to 255):
            //analogWrite(ledPin, dutyCycle);
            OCR4A = dutyCycle;  // set PWM duty cycle
            delay(40);  // Use delay for a smoothing transition
        }

        // loop for transition in reductions of 2
        for (int dutyCycle = 255 ; dutyCycle >= 0; dutyCycle -= 2) {
            // sets the duty cycle value (range from 0 to 255):
            //analogWrite(ledPin, dutyCycle);
            OCR4A = dutyCycle; // set PWM duty cycle
            // Use delay for a smoothing transition
            delay(40);  // Use delay for a smoothing transition
        }
    }
}
