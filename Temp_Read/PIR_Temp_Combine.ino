#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5 // Temperature sensor to pin 6
#define PIR_1 6 // PIR sensor to pin 5
#define PIR_2 7
#define PIR_3 8
#define PIR_4 9

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;
float Fahrenheit=0;

void setup(void)
{
  Serial.begin(9600);
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  pinMode(PIR_3, INPUT);
  pinMode(PIR_4, INPUT);
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures();
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print("t");
  Serial.println(Celcius);
//  Serial.println(Fahrenheit);
  int SensorState_1 = digitalRead(PIR_1);
  int SensorState_2 = digitalRead(PIR_2);
  int SensorState_3 = digitalRead(PIR_3);
  int SensorState_4 = digitalRead(PIR_4);
  Serial.print("1");
  Serial.println(SensorState_1);
  Serial.print("2");
  Serial.println(SensorState_2);
  Serial.print("3");
  Serial.println(SensorState_3);
  Serial.print("4");
  Serial.println(SensorState_4);
  delay(100);
}
