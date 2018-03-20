
#ifndef __CC3200R1M1RGC__
#include <SPI.h>
#endif
#include <WiFi.h>
char ssid[] = "g3";
char password[] = "wickiiiiii";
int keyIndex = 0;
int outpin = 19;
int outpin2 = 18;
int outpin3 = 17;
int outpin4 = 15;
int outpin5 = 14;
int outpin6 = 12;
int outpin7 = 11;
int outpin8 = 32;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);      
  pinMode(outpin,OUTPUT);     
  pinMode(outpin2,OUTPUT); 
  Serial.print("Attempting to connect to Network named: ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
      Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  
  
  printWifiStatus();

  Serial.println("Starting webserver on port 80");
  server.begin();                          
  Serial.println("Webserver started!");
}

void loop() {
  int i = 0;
  WiFiClient client = server.available();  

  if (client) {                            
    Serial.println("new client");         
    char buffer[150] = {0};               
    while (client.connected()) {          
      if (client.available()) {           
        char c = client.read();           
        Serial.write(c);                  
        if (c == '\n') {                  
          if (strlen(buffer) == 0) {
          )
           client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            
            client.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"><title>Energia CC3200 WiFi Web Server</title></head><body align=center>");
            client.println("<br/><br/><h1 align=center><font color=\"black\"><marquee>TEAM RANSOMWARE</marquee></font></h1>");
            client.println("<br/><br/><hr/>");
            client.print("<div id=\"Motor1\" style=\"background-color:red; padding-top:100px; align=\"center\"><div class=\"container\"><div class=\"centered\">MOTOR 1   :  <button onclick=\"location.href='/H'\">HIGH</button>");
            client.print(" <button onclick=\"location.href='/L'\">LOW</button>");
            client.println(" <button onclick=\"location.href='/OFF'\">OFF</button></div></div></div>");
            client.println("<hr/>");
            client.print("<div id=\"Motor2\" style=\"background-color:blue; padding-top:100px\"><div class=\"container\"><div class=\"centered\">MOTOR 2   :  <button onclick=\"location.href='/H1'\">HIGH</button>");
            client.print(" <button onclick=\"location.href='/L1'\">LOW</button>");
            client.println(" <button onclick=\"location.href='OFF1'\">OFF</button></div></div></div>");
            client.println("<hr/>");
            client.print("<div id=\"Motor3\" style=\"background-color:green; padding-top:100px\"><div class=\"container\"><div class=\"centered\">MOTOR 3  :   <button onclick=\"location.href='/H2'\">HIGH</button>");
            client.print(" <button onclick=\"location.href='/L2'\">LOW</button>");
            client.println(" <button onclick=\"location.href='OFF2'\">OFF</button></div></div></div>");
            client.println("<hr/>");
            client.print("<div id=\"Inflator\" style=\"background-color:yellow; padding-top:100px\"><div class=\"container\"><div class=\"centered\">INFLATOR   :  <button onclick=\"location.href='/ON'\">ON</button>");
            client.println(" <button onclick=\"location.href='/OFF3'\">OFF</button></div></div></div>");
            client.println();
            break;
          }
          else {    
            memset(buffer, 0, 150);
            i = 0;
          }
        }
        else if (c != '\r') {   
          buffer[i++] = c;      
        }

        
        if (endsWith(buffer, "GET /H")) {
          digitalWrite(outpin, HIGH); 
         digitalWrite(outpin2, LOW);
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /L")) {
          digitalWrite(outpin, LOW);  
           digitalWrite(outpin2, HIGH);
           digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /OFF")) {
          digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /H1")) {
          digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, HIGH);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /L1")) {
          digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, HIGH);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /OFF1")) {
         digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /H2")) {
          digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, HIGH);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /L2")) {
         digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, HIGH);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /OFF2")) {
         digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /ON")) {
        digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, HIGH);
         digitalWrite(outpin8, LOW);
        }
        if (endsWith(buffer, "GET /OFF3")) {
          digitalWrite(outpin, LOW); 
         digitalWrite(outpin2, LOW);  
         digitalWrite(outpin3, LOW);
         digitalWrite(outpin4, LOW);
         digitalWrite(outpin5, LOW);
         digitalWrite(outpin6, LOW);
         digitalWrite(outpin7, LOW);
         digitalWrite(outpin8, LOW);
        }
      }
    }
    
    client.stop();
    Serial.println("client disonnected");
  }
}

boolean endsWith(char* inString, char* compString) {
  int compLength = strlen(compString);
  int strLength = strlen(inString);
  
   int i;
  for (i = 0; i < compLength; i++) {
    char a = inString[(strLength - 1) - i];
    char b = compString[(compLength - 1) - i];
    if (a != b) {
      return false;
    }
  }
  return true;
}

void printWifiStatus() {
 
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

 
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

 
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
