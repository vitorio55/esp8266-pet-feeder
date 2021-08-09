//#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <Servo.h>
//#include <BlynkSimpleEsp8266.h>

Servo servo_A;
Servo servo_B;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
// char auth[] = "<BLYNK_AUTH_TOKEN>";

// Your WiFi credentials.
// Set password to "" for open networks.
// char ssid[] = "<NETWORK_SSID>";
// char pass[] = "<NETWORK_PASS>";

#define BUTTON_PRESSED 1

#define RADIO_PIN_A D6
#define RADIO_PIN_B D8
#define RADIO_PIN_D D7

#define SERVO_A_PIN D2
#define SERVO_B_PIN D3

//int blynkButtonState;

enum CommandTypes {
  ONLY_SERVO_A,
  ONLY_SERVO_B,
  SERVOS_AB,
  NONE,
};

CommandTypes commandIssued = NONE;

//BLYNK_CONNECTED() {
//  Blynk.syncVirtual(V2);
//}

//BLYNK_WRITE(V2) {
//  blynkButtonState = param.asInt();
//  Serial.print("Blynk app V2 button pressed: ");
//  Serial.println(blynkButtonState);
//  mainLogic();
//}

void setup() { 
  Serial.begin(9600);

  // Blynk.begin(auth, ssid, pass);
  // delay(1000);
  
  pinMode(RADIO_PIN_A, INPUT);
  pinMode(RADIO_PIN_B, INPUT);
  pinMode(RADIO_PIN_D, INPUT);

  // Servos are inverted, therefore their values must be the opposite
  servo_A.attach(SERVO_A_PIN, 450, 2550); // MG996R servo
  servo_A.write(185); // MG996R servo
  servo_B.attach(SERVO_B_PIN, 450, 2550); // MG996R servo
  servo_B.write(5); // MG996R servo
}

void checkRadioCommand() {
  if (digitalRead(RADIO_PIN_A) == BUTTON_PRESSED) {
    commandIssued = ONLY_SERVO_A;
    return;
  }
  else if (digitalRead(RADIO_PIN_B) == BUTTON_PRESSED) {
    commandIssued = ONLY_SERVO_B;
    return;
  }
  else if (digitalRead(RADIO_PIN_D) == BUTTON_PRESSED) {
    commandIssued = SERVOS_AB;
    return;
  }
}

void operateSingleServoOnce(CommandTypes cmd) {
  if (cmd == ONLY_SERVO_A) {
    servo_A.write(5);
    delay(1000);
    servo_A.write(185);
    delay(1000);
  } else {
    servo_B.write(185);
    delay(1000);
    servo_B.write(5);
    delay(1000);    
  }
}

void operateBothServosTwice() {
  for (int i = 1; i <= 2; i++) {
    servo_A.write(5); 
    servo_B.write(185);
    delay(1000);
    servo_A.write(185);
    servo_B.write(5);
    delay(1000);
  }
}

void releaseFood() {
  switch(commandIssued) {
    case ONLY_SERVO_A: // Same as B
    case ONLY_SERVO_B: operateSingleServoOnce(commandIssued); return;
    case    SERVOS_AB:    operateBothServosTwice(); return;
    default: return;
  }
}

void loop() {
  // Blynk.run();
  checkRadioCommand();

  if (commandIssued != NONE) {
    releaseFood();
    commandIssued = NONE;
  }
}
