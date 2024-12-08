#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>

// Define DHT11 sensor pin and type
#define DHTPIN 7      // Pin connected to DHT11
#define DHTTYPE DHT11 // DHT11 sensor type

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

int counter = 0;
int Senderled = 5;
int Errorled = 6;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  pinMode(Senderled, OUTPUT);
  pinMode(Errorled, OUTPUT);
  digitalWrite(Senderled, LOW);
  digitalWrite(Errorled, LOW);

  // Initialize DHT sensor
  dht.begin();

  // Initialize LoRa
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    digitalWrite(Errorled, HIGH);
    delay(2000);
    while (1);
  }
}

void loop() {
  digitalWrite(Senderled, LOW);
  digitalWrite(Errorled, LOW);

  // Read temperature and humidity from DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    digitalWrite(Errorled, HIGH);
    delay(2000);
    return;
  }

  // Print readings to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send data via LoRa
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("Temp: ");
  LoRa.print(temperature);
  LoRa.print(" °C, Humidity: ");
  LoRa.print(humidity);
  LoRa.print(" %, Counter: ");
  LoRa.print(counter);
  LoRa.endPacket();

  // Indicate successful sending with LED
  digitalWrite(Senderled, HIGH);
  delay(500);
  digitalWrite(Senderled, LOW);

  counter++;
  delay(2000);
}
