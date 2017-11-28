// btnPin defines the Arduino input pin to which the
// button is connected
const int btnPin = 2;

// btnState stores the current button state (HIGH or LOW)
// initialize it to LOW so the LED stays off until the sketch
// reads a HIGH state for the button input
int btnState = LOW;
// A place to store the previous loop's button state
int prevBtnState = LOW;
// Used to track the current state of the LED
int ledState = LOW;
// Specifies the amount of time the button must stay pushed for it
// to trigger the LED on or off. Increase this value if your LED
// flickers
const unsigned long DEBOUNCE_DELTA = 100;    // milliseconds
// Stores the last time the status of the button changed
unsigned long lastToggle = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(btnPin, INPUT);
  // set the initial state of the LED
  digitalWrite(LED_BUILTIN, ledState);
}

void loop() {
  // Read the current state of the button
  btnState = digitalRead(btnPin);

  // Is the button in the same state as the last time we came through the
  // loop? No? Then we need to record the current time (in milliseconds)
  if (btnState != prevBtnState) {
    // store the current time in milliseconds
    //It doesn't matter what the actual time is, all we need to know is
    //how long did the button stay in this state
    lastToggle = millis();
    //Reset our previous state, so this check skips next time
    prevBtnState = btnState;
  } else {
    // OK, the button states (current and previous) are the same
    //Lets see if they've been the same for DEBOUNCE_DELTA milliseconds
    if ((millis() - lastToggle) > DEBOUNCE_DELTA) {
      // the button's been pushed (or not pushed) for at least debounceDelta
      // milliseconds, so its time to toggle the LED if needed
      //Is the LED at the same state as the button?
      if (ledState != btnState) {
        // No? Then toggle it
        digitalWrite(LED_BUILTIN, btnState);
        //Then reset the LED status
        ledState = btnState;
      }
    }
  }
}

