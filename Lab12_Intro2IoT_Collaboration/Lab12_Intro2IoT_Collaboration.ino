// === Automatic Room Light with Manual Override ===

const int lightSensorPin = A0;  // Photoresistor connected to A0
const int buttonPin = 2;        // Button connected to D2
const int ledPin = 9;           // LED (room light) connected to D9

const int darkThreshold = 500;  // Adjust based on ambient light conditions

bool isDark = false;
bool isButtonOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {
  isDark = isRoomDark();             // Light detection logic
  isButtonOn = isButtonActivated();  // Button-based manual override

  // Control the LED
  if (isDark || isButtonOn) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
  }

  delay(200);  // basic debounce + sampling interval
}

// ===============================
// Light Detection – Student 1
bool isRoomDark() {
  int lightLevel = analogRead(lightSensorPin);

  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Bool logic for light sensor. Fixed on 4/22/2025
  if (lightLevel >= 500) {
    return false;
  } else {
    return true;
  }  
}

// ===============================
// Manual Switch Control – Student 2
bool isButtonActivated() {
  bool state = digitalRead(buttonPin);

  Serial.print("Button: ");

  // TODO: Fix this logic and print the correct status
  // Button is normally HIGH
  if (state == HIGH) {
    // Button not pressed
    Serial.println("OFF");
    return false;
  } else {
    // Button pressed
    return true;
    Serial.println("ON");
  }

  // HINT: Serial.print should say "ON" or "OFF" too
}