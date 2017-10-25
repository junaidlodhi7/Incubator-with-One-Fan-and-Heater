#include <DHT.h> //temperature and humidity
#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" // Added library*
#include <SoftwareSerial.h>
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
///////////////////////////////////////////////////////////////////////////HEATRODRELAY
#define    HeatRodRelay 9
///////////////////////////////////////////////////////////////////////////////////////////////BLUETOOTH
SoftwareSerial mySerial(7, 8);
///////////////////////////////////////////////////////////////////////////////////////////////END BLUETOOTH
///////////////////////////////////////////////////////////////////////////////////////////////variable for  temperature DHT22
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 11  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
float hum;  //Stores humidity value
float temp; //Stores temperature value
/////////////////////// sensor # 2
#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 11  (AM2302)
DHT dht2(DHTPIN, DHTTYPE);
float hum2;  //Stores humidity value
float temp2; //Stores temperature value

////////////////////////////////////////////////////////////////////////////////////////////////End of variable for  temperature DHT22
///////////////////////////////////////////////////////////////////////////////////////////////variable for moisture
int sensor_pin = A0;
int output_value ;
///////////////////////////////////////////////////////////////////////////////////////////////ENF OF MOISTURE VARIABLES
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the default I2C bus address of the backpack-see article
void setup()
{
  ////////////////////////////////////////////////////////////////////////////////////////////// SETUP FOR HEATRELAY
   pinMode(HeatRodRelay, OUTPUT);
 digitalWrite(HeatRodRelay, HIGH);
///////////////////////////////////////////////////////////////////////////////////////////////BLUETOOTH
mySerial.begin(9600);
///////////////////////////////////////////////////////////////////////////////////////////////END BLUETOOTH
  /////////////////////////////////////////////////////////////////////////////////////////// Set up For Lcd Module
  lcd.begin (16, 2); // 16 x 2 LCD module
  lcd.setBacklightPin(3, POSITIVE); // BL, BL_POL
  lcd.setBacklight(HIGH);
  /////////////////////////////////////////////////////////////////////////////////////////////End of LCD Module

  ////////////////////////////////////////////////////////////////////////////////////////////SET UP FOR Moisture
  Serial.begin(9600);
  // delay(2000);
  ///////////////////////////////////////////////////////////////////////////////////////////END OF MOISTURE SET UP
  ////////////////////////////////////////////////////////////////////////////////////////////SET up for DHT22
  dht.begin();
  dht2.begin();


  ////////////////////////////////////////////////////////////////////////////////////////////END OF  SET up for DHT22
}
void loop()
{///////////////////////////////////////////////////////////////////
//   digitalWrite(HeatRodRelay, LOW);
//  delay(5000);
 //digitalWrite(HeatRodRelay, LOW);

  ///////////////////////////////////////////////////////////////////////////////////////////////MOISTURE CODE
  //output_value= analogRead(sensor_pin);
  //output_value = map(output_value,1024,0,0,100);

  ///////////////////////////////////////////////////////////////////////////////////////////////END OF MOISTURE CODE


  //////////////////////////////////////////////////////////////////////////////////////////     LCD MODULE CODE
  lcd.home ();
  // lcd.clear();// Set cursor to 0,0
  //////////////////////////////////////////////////////////////////////////////////////////Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
   hum2 = dht2.readHumidity();
  temp2 = dht2.readTemperature();
///////////////////////////////////////////////////////////

  lcd.setCursor (0, 0);
  lcd.print("Humidity:");// Go to home of 2nd line
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor (0, 1);
  lcd.print("Temperature:");// Go to home of 2nd line
  lcd.print(temp);
  lcd.print("C");//
  //    delay(5000); // Blinks of backlight
  //    lcd.clear();// Set cursor to 0,0
  //      lcd.print("Moisture:");// Go to home of 2nd line
  //    lcd.print(output_value);
  //    delay(5000);
    mySerial.print("temp");
  mySerial.print(temp);
  mySerial.print(",");
    mySerial.print("hum");
  mySerial.print(hum);
 // delay(3000);
  
  ////////////////////////////////////////////////////////////////////////////////////////////// END OF LCD MODULE CODE


  ///////////////////////////////////////////////////////////////////////////////////////////////////Decisional Structures


if(temp >29.3)
{
  digitalWrite(HeatRodRelay, LOW);  
}
else if (temp < 29)
{
  digitalWrite(HeatRodRelay, HIGH);  
  }

///////////////////////// Actaul Logic
//if(temp 37.6)
//{
//  digitalWrite(HeatRodRelay, LOW);  
//}
//else if (temp < 37.4)
//{
//  digitalWrite(HeatRodRelay, HIGH);  
//  }  







}
