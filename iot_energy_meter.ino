
#include <ESP8266WiFi.h>

const char* ssid     = "Pixel3"; // Your ssid
const char* password = "12345678"; // Your Password
 
char status;
int count=0;
int amount=0;

WiFiServer server(80);
void setup() {
pinMode(A0,INPUT);  
Serial.begin(9600);
delay(100);
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
 
Serial.println("");
Serial.println("WiFi is connected");
server.begin();
Serial.println("Server started");
 
 
Serial.println(WiFi.localIP());

}
 
void loop(){
   int buttonState = 0;
  buttonState = analogRead(A0);
  // print out the state of the button:
  if(buttonState >= 300)
  {
    count++;
    amount=amount+2.80;
  }
  
  Serial.println(count);
  int amount=230;
  int energyconsumed=30;
  
WiFiClient client = server.available();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");  // the connection will be closed after completion of the response
client.println("Refresh: 10");  // update the page after 10 sec
client.println();
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<style>html { font-family: Cairo; display: block; margin: 0px auto; text-align: center;color: #333333; background-color: #ccffb3;}");
client.println("body{margin-top: 50px;}");
client.println("h1 {margin: 50px auto 30px; font-size: 50px; text-align: center;}");
client.println(".side_adjust{display: inline-block;vertical-align: middle;position: relative;}");
client.println(".text1{font-weight: 180; padding-left: 15px; font-size: 50px; width: 170px; text-align: left; color: #3498db;}");
client.println(".data1{font-weight: 180; padding-left: 80px; font-size: 50px;color: #3498db;}");
client.println(".text2{font-weight: 180; font-size: 50px; width: 650px; text-align: left; color: #ff6600;}");
client.println(".data2{font-weight: 180; padding-left: 2px; font-size: 50px;color: #ff6600;}");
client.println(".text3{font-weight: 180; padding-left: 15px; font-size: 50px; width: 170px; text-align: left; color: #0066ff;}");
client.println(".data3{font-weight: 180; padding-left: 80px; font-size: 50px;color: #0066ff;}");
client.println(".data{padding: 10px;}");
client.println("</style>");
client.println("</head>");
client.println("<body>");
client.println("<div id=\"webpage\">");   
client.println("<h1>IOT Energy Meter</h1>");
client.println("<div class=\"data\">");
client.println("<div class=\"side_adjust text1\">Count:</div>");
client.println("<div class=\"side_adjust data1\">");
client.print(count);
client.println("</div>");
client.println("<div class=\"data\">");
client.println("<div class=\"side_adjust text2\">EnergyConsumed:</div>");
client.println("<div class=\"side_adjust data2\">");
client.println(energyconsumed);
client.println("</div>");
client.println("<div class=\"data\">");
client.println("<div class=\"side_adjust text3\">Amount:</div>");
client.println("<div class=\"side_adjust data3\">");
client.println(amount);
client.println("</div>");

client.println("</div>");
client.println("</div>");
client.println("</div>");
client.println("</body>");
client.println("</html>");
 delay(100);
}
