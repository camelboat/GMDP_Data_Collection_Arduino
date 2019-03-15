#include <OneWire.h>
#include <DallasTemperature.h>

//#define ONE_WIRE_BUS 5

#define Temp_1 2 // Temperature sensor to pin 2, 3, 4, 5
#define Temp_2 3
#define Temp_3 4
#define Temp_4 5

#define PIR_1 6 // PIR sensor to pin 6, 7, 8, 9
#define PIR_2 7
#define PIR_3 8
#define PIR_4 9

//OneWire oneWire(ONE_WIRE_BUS);
OneWire oneWire_1(Temp_1);
OneWire oneWire_2(Temp_2);
OneWire oneWire_3(Temp_3);
OneWire oneWire_4(Temp_4);

//DallasTemperature sensors(&oneWire);
DallasTemperature Tsensor_1(&oneWire_1);
DallasTemperature Tsensor_2(&oneWire_2);
DallasTemperature Tsensor_3(&oneWire_3);
DallasTemperature Tsensor_4(&oneWire_4);

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
  //sensors.requestTemperatures();
  Tsensor_1.requestTemperatures();
  Tsensor_2.requestTemperatures();
  Tsensor_3.requestTemperatures();
  Tsensor_4.requestTemperatures();

  //Celcius=sensors.getTempCByIndex(0);
  Celcius_1=Tsensor_1.getTempCByIndex(0);
  Celcius_2=Tsensor_2.getTempCByIndex(0);
  Celcius_3=Tsensor_3.getTempCByIndex(0);
  Celcius_4=Tsensor_4.getTempCByIndex(0);
  
  //Fahrenheit=sensors.toFahrenheit(Celcius);

  Serial.print("a");
  Serial.println(Celcius_1);
  Serial.print("b");
  Serial.println(Celcius_2);
  Serial.print("c");
  Serial.println(Celcius_3);
  Serial.print("d");
  Serial.println(Celcius_4);

  //Serial.println(Fahrenheit);
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
