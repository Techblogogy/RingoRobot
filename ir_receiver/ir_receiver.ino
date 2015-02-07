// EN: IRremote library lets you send and receive IR remote codes
//     in multiple protocols.
#include "IRremote.h"

// EN: Pin to connect IR detector.
const int IR_PIN = A0;

// EN: Create an instance of receiver.
IRrecv irrecv(IR_PIN);

void setup() {
  // EN: Initialize serial port for 9600 baud.
  Serial.begin(9600);
  Serial.println("ready");
  
  // EN: Start the IR receiver.
  irrecv.enableIRIn();
}

void loop() {
  // EN: Declare structure for decoded commands.
  decode_results results;
  
  // EN: If IR command is receicved and decoded then send the result to serial port.
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    
    // EN: Must be called to resume decoding.
    irrecv.resume();
  }
}
