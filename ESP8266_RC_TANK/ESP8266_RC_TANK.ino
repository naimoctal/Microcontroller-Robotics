/* Copyright (c) 2022, N@IM_0CTAL
 * All rights reserved.*/
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "mainPage.h"
const int Load1=16;
const int Load2=14;
const int Load3=12;
const int Load4=13;
const int Load5=4;
const int Load6=5;
int Load7=15;
int i;
/* Set these to your desired credentials. */
const char *ssid = "N@IM_0CTAL";
const char *password = "12345678";
ESP8266WebServer server(80);
String L1Status,L2Status,L3Status,L4Status,L5Status,L6Status,L7Status;

//=======================================================================
//                    handles main page 192.168.4.1
//=======================================================================
/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */

void handleRoot() {
  String s = MAIN_page;    
  s.replace("@@L1@@", L1Status);
  s.replace("@@L2@@", L2Status);
  s.replace("@@L3@@", L3Status);
  s.replace("@@L4@@", L4Status);
  s.replace("@@L5@@", L5Status);
  s.replace("@@L6@@", L6Status);
  server.send(200, "text/html", s);    
} 

void handleForm() {
  String t_state = server.arg("submit");

//Change Channel 1 & 2 State as per request
  if(t_state=="ON1")
  {
    L1Status="ON";    
    digitalWrite(Load1, HIGH);
    digitalWrite(Load2, LOW);
  }

  if(t_state=="ON2")
  {
    L2Status="ON";    
    digitalWrite(Load2, HIGH);
    digitalWrite(Load1, LOW);
  }
  
  if(t_state=="OFF12")
  {
    L1Status="OFF";
    L2Status="OFF";
    digitalWrite(Load1, LOW);
    digitalWrite(Load2, LOW); 
  }
//Change Channel 3 & 4 State as per request
  if(t_state=="ON3")
  {
    L3Status="ON";    
    digitalWrite(Load3, HIGH);
    digitalWrite(Load4, LOW);
  }

  if(t_state=="ON4")
  {
    L4Status="ON";    
    digitalWrite(Load4, HIGH);
    digitalWrite(Load3, LOW);
  }
  
  if(t_state=="OFF34")
  {
    L3Status="OFF";
    L4Status="OFF";
    digitalWrite(Load3, LOW);
    digitalWrite(Load4, LOW); 
  }
//Change Channel 5 State as per request
  if(t_state=="ON5")
  {
    L5Status="ON";    
    digitalWrite(Load5, HIGH);       //Load5 Turned on
  }
  
  if(t_state=="OFF5")
  {
    L5Status="OFF";    
    digitalWrite(Load5, LOW);      //Load5 Turned off  
  }
//Change Channel 6 State as per request
  if(t_state=="ON6")
  {
    L6Status="ON";    
    digitalWrite(Load6, HIGH);       //Load6 Turned on
  }
  
  if(t_state=="OFF6")
  {
    L6Status="OFF";    
    digitalWrite(Load6, LOW);      //Load6 Turned off  
  }
  //Change Channel 7 State as per request
  if(t_state=="ON7")
  {
    sound();
  }
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");  //This Line Keeps It on Same Page
   
  delay(500);
}

//=======================================================================
//                    Power on setup
//=======================================================================
void setup() {
  delay(1000);
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/form", handleForm);
 
  server.begin();
  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);
  pinMode(Load5, OUTPUT); 
  pinMode(Load6, OUTPUT); 
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  server.handleClient();
}
//=======================================================================

void sound() {
  for(i=440;i<1000;i++)
  {
    tone(Load7,i,50);
    delay(5);
  }
  for(i=1000;i>440;i--)
  {
    tone(Load7,i,50);
    delay(5);
    }
} 