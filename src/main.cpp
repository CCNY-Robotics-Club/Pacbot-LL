#include <Adafruit_VL6180X.h>
#include <Wire.h>
#include <Arduino.h>

Adafruit_VL6180X mySens0 = Adafruit_VL6180X();
Adafruit_VL6180X mySens1 = Adafruit_VL6180X();
Adafruit_VL6180X mySens2 = Adafruit_VL6180X();

#define TCAADDR 0x70 // defines i2c address of multiplexer

//tutorial to confirm ports wired correctly:
//https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout/arduino-wiring-and-test
void tcaselect(uint8_t i) { //function for choosing device according to port
  if (i > 7) return; //we only have 7 ports on multiplexer
 
  Wire.beginTransmission(TCAADDR); //initializes device for following wire.functions
  Wire.write(1 << i); // ??
  Wire.endTransmission(); //submites written data to device
}


// standard Arduino setup()
void setup()
{
  while (!Serial);
    delay(1000);

    Wire.begin();
    
    Serial.begin(115200);
    Serial.println("\nTCAScanner ready!");
    
    for (uint8_t t=0; t<8; t++) {
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);

      for (uint8_t addr = 0; addr<=127; addr++) {
        if (addr == TCAADDR) continue;

        Wire.beginTransmission(addr);
        if (!Wire.endTransmission()) {
          Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
        }
      }
    }
    Serial.println("\ndone");
  Serial.begin(9600);

  tcaselect(0);
 if (!mySens0.begin()) {   // 
    Serial.println("Couldn't find Sens1");
    while (1) delay(1);
  }
  
  /* Initialise the 2nd sensor */
  tcaselect(1);
  if (!mySens1.begin()) {   
    Serial.println("Couldn't find Sens2");
    while (1) delay(1);
  }
  
  /* Initialise the 3rd sensor */
  tcaselect(2);
  if (!mySens2.begin()) {   
    Serial.println("Couldn't find Sens3");
    while (1) delay(1);
  }

}

void loop(void) 
{
  /* Get a new sensor event */ 
  
  tcaselect(0);
 
  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("Sensor #1 - ");
  Serial.print(mySens0.readRange());
  Serial.println("");
  
  tcaselect(1);
  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("Sensor #2 - ");
  Serial.print(mySens1.readRange());
  Serial.println("");
  
  delay(500);
}