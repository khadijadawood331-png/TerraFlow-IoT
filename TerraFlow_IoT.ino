/**
 * Project: TerraFlow IoT (Smart Irrigation System)
 * Developed by: (Khadijah Dawood)
 */

// Pin Configuration as per your circuit diagram
const int MOISTURE_PIN = A0;  // Soil Moisture Sensor connected to Analog Pin A0
const int RELAY_PIN    = 2;   // Relay control wire connected to Digital Pin 2

// Threshold Values for Automation
const int DRY_SOIL_THRESHOLD = 400; // Value above this means soil is dry
const int WET_SOIL_THRESHOLD = 700; // Value below this means soil is wet enough

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Keep pump OFF at system boot
  
  Serial.begin(9600);
}

void loop() {
  int moistureRawValue = analogRead(MOISTURE_PIN); // Read sensor data
  
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureRawValue);

  // Automated Pump Logic
  if (moistureRawValue > DRY_SOIL_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Turn ON the Water Pump
    Serial.println("Status: Soil is Dry. Pump Activated.");
  } 
  else if (moistureRawValue < WET_SOIL_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);  // Turn OFF the Water Pump
    Serial.println("Status: Soil is Wet. Pump Deactivated.");
  }

  delay(2000); // 2-second delay for stability
}
