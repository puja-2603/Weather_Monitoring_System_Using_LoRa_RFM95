# Weather_Monitoring_System_Using_LoRa_RFM95
This project is a Wireless Weather Monitoring System that uses the LoRa (Long Range) communication protocol to transmit and receive temperature and humidity data from a DHT11 sensor. The sender sends the data, and the receiver displays it on an I2C LCD screen.

# Features
- Temperature and Humidity Monitoring using the DHT11 sensor.
- Wireless Communication over long distances using the RFM95 LoRa module.
- Displays received data on an I2C LCD Screen.
- Efficient and low-power design for remote weather monitoring.

# Components Used
# Component               	Quantity	                      Description
Arduino UNO 	              2	                          Microcontroller to process and send data.
RFM95 LoRa Module	          2	                          LoRa module for wireless communication.
DHT11 Sensor	              1                          	Sensor for measuring temperature and humidity.
I2C LCD Display (Receiver)	1                          	LCD screen to display received data.
Jumper Wires	              As required	                For connections.
Power Supply	              1	                          For powering the Arduino Nano.

# Sender Pin Setup
# Component	        Pin on Component	Connection to Arduino UNO
DHT11 Sensor 	        VCC	                    5V
                      GND	                    GND
                      Data	                  D2
RFM95 LoRa Module	    GND1	                  GND
                      GND2	                  GND
                      3V	                    3.3V
                      MISO	                  D12
                      MOSI	                  D11
                      SCK	                    D13
                      NSS	                    D10
                      RST	                    D9
                      DIO0                  	D3
                      DIO1	                  D4
                      DIO2	                  D5

# Reciever Pin Setup
# Component         	Pin on Component	  Connection to Arduino UNO
RFM95 LoRa Module	      GND1	                 GND
                        GND2	                 GND
                        3V	                   3.3V
                        MISO	                 D12
                        MOSI	                 D11
                        SCK	                   D13
                        NSS	                   D10
                        RST                    D9
                        DIO0	                 D3
                        DIO1	                 D4
                        DIO2	                 D5
I2C LCD Display	        VCC	                   5V
                        GND	                   GND
                        SDA	                   A4
                        SCL                    A5

# Software Requirements
Arduino IDE: To program the Arduino UNO.
# Libraries:
[DHT Library](https://github.com/adafruit/DHT-sensor-library)
[LoRa Library](https://github.com/sandeepmistry/arduino-LoRa).
[LiquidCrystal I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
