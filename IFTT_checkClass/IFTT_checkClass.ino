#include <IFTTTMaker.h>

/*******************************************************************
 *  Trigger event at end of the setup                              *
 *                                                                 *
 *  adapted by Brian Lough                                         *
 *******************************************************************/


#include <WiFi.h>
#include <WiFiClientSecure.h>

//------- Replace the following! ------
char ssid[] = "kidbright";       // your network SSID (name)
char password[] = "12345678";  // your network key
#define KEY "b3Gdj0fYYsoJKjFNAvZMCf"   // Get it from this page https://ifttt.com/services/maker/settings
#define EVENT_NAME "ClassChk0921" // Name of your event name, set when you are creating the applet




WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

void setup() {

  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);


  //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
  if(ifttt.triggerEvent(EVENT_NAME, ssid, ip.toString(),"B5814824")){
    Serial.println("Successfully sent");
  } else
  {
    Serial.println("Failed!");
  }

}

void loop() {
}
