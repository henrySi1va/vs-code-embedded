#include "Heart_Beat.h" // Include the Heart_Beat library
#include "MyLibrary.h" // Include the custom MyLibrary

HeartBeatSL HB; // Create an instance of the HeartBeatSL class
int counter = 0; // Initialize a counter variable

void setup() {
  HB.begin(LED_BUILTIN, 3); // Init a heartbeat on the board's built-in LED with a frequency of 3 beats per second
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  HB.code("LS"); // Set the heartbeat pattern to "LS" (Long Short)
  HB.beat(); // Let the heart beat

  // Print a message every 100 cycles
  if (counter >= 100) {
    Serial.println(getMyMessage());
    counter = 0; // Reset the counter
  }

  counter++; // Increment the counter
  delay(10); // Delay for 10 milliseconds
}
