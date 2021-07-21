
#include <LinxESP32.h>
#include <Wire.h>

/*Create A Pointer To The LINX Device Object We Instantiate In Setup()*/
LinxESP32* LinxDevice;

/*Initialize LINX Device And Listener*/
void setup() {
  
  /*Instantiate The LINX Device*/
  LinxDevice = new LinxESP32();

  /*I2C Begin ch0:Wire, ch1:Wire1*/
  /* Wire1.begin(32, 33);*/
  Wire.begin();
  
  /* The LINX Listener Is Pre Instantiated.
   * Set SSID (Network Name), Security Type, Passphrase/Key, And Call Start With Desired Device IP and Port
   * If not set, it will connect with the last connection information */
  
  /*LinxWifiConnection.SetSsid("YOUR_NETWORK_NAME");
    LinxWifiConnection.SetSecurity(WPA2_NONE);  //NONE, WPA2_PASSPHRASE, WPA2_KEY, WEP40, WEO104
    LinxWifiConnection.SetPassphrase("PASSPHRASE");  */
    
  LinxWifiConnection.Start(LinxDevice, 44300);
}

void loop()
{
  /*Listen For New Packets From LabVIEW */
  LinxWifiConnection.CheckForCommands();
  delay(1);
}
