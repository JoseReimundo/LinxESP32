
#include <LinxESP32.h>
#include <Wire.h>

LinxESP32* LinxDevice;

void setup()
{
  LinxDevice = new LinxESP32();
  
  Wire.begin();
  /* Wire1.begin(32, 33);*/

  /*ch3:SerialBT */
  LinxSerialConnection.Start(LinxDevice, 3);
}

void loop()
{
  LinxSerialConnection.CheckForCommands();
  delay(1);
}
