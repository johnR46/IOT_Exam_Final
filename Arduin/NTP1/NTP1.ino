#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>

const char *ssid     = "SunLuCiFer";
const char *password = "0827704588";
const char* ntpServerName1 = "ntp.sut.ac.th";
const char* ntpServerName2 = "time.nist.gov";
const char* ntpServerName3 = "clock.nectec.or.th";

int mainHH, mainMM, mainSS;
WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, ntpServerName3);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
timeClient.update();
Serial.print("\nThe UTC time is ");
Serial.println(timeClient.getFormattedTime());
Serial.print("The UTC+7:00 time is ");
mainHH = (timeClient.getHours() + 7) % 23;
mainMM = timeClient.getMinutes();
mainSS = timeClient.getSeconds();
if (mainHH < 10) Serial.print("0"); Serial.print(mainHH); Serial.print(":");
if (mainMM < 10) Serial.print("0"); Serial.print(mainMM); Serial.print(":");
if (mainSS < 10) Serial.print("0"); Serial.print(mainSS); Serial.println();
delay(1000);
}
