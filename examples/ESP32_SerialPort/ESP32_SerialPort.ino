
#include <LinxESP32.h>
#include <Wire.h>

/* Create A Pointer To The LINX Device Object We Instantiate In Setup() */
LinxESP32* LinxDevice;

/* Initialize LINX Device And Listener */
void setup()
{
  /*Instantiate The LINX Device*/
  LinxDevice = new LinxESP32();

  /*I2C Begin ch0:Wire, ch1:Wire1*/
  /*Wire1.begin(32, 33);*/
  Wire.begin();

  /* ch0:Serial*/
  LinxSerialConnection.Start(LinxDevice, 0);
}

void loop()
{
  /*Listen For New Packets From LabVIEW*/
  LinxSerialConnection.CheckForCommands();

  /*Your Code Here, But It will Slow Down The Connection With LabVIEW*/
  delay(1);
}
