// btnPin defines the Arduino input pin to which the
// button is connected
const int btnPin = 2;

// btnState stores the current button state (HIGH or LOW)
// initialize it to LOW so the LED stays off until the sketch
// reads a HIGH state for the button input
int btnState = LOW;

// The setup function runs once every time the Arduino
// powers up or resets (after a sketch update, for example)
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(btnPin, INPUT);

  // set the initial state of the LED (off)
  digitalWrite(LED_BUILTIN, btnState);
}

// The loop function runs repeatedly as long as a sketch is
// loaded and the Arduino has power.
void loop() {
  // Read the state of the button; its a digital input,
  // so possible returned values are HIGH or LOW.
  btnState = digitalRead(btnPin);
  // Use the measured value to set the LED state
  digitalWrite(LED_BUILTIN, btnState);

  // This could very easily be simplified to the following
  // single line of code:
  // digitalWrite(LED_BUILTIN, digitalRead(btnPin));
}

