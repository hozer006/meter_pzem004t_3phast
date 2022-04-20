#include <WiFi.h>
#include <FirebaseESP32.h>
#include <PZEM004Tv30.h>

#define FIREBASE_HOST "https://meter-3-phase-default-rtdb.firebaseio.com/" //--> URL address of your Firebase Realtime Database.
#define FIREBASE_AUTH "hdPkmrJ9FnIhOJCSUJnKBFC5ZQPtM37uT6BDzQtJ" //--> Your firebase database secret code.

#define WIFI_SSID "Holmes" 
#define WIFI_PASSWORD "01234567"
    
PZEM004Tv30 pzem1(Serial2, 22, 23);  //RX -> D23 , TX -> D22
PZEM004Tv30 pzem2(Serial2, 21, 19);  //RX -> D21 , TX -> D19
PZEM004Tv30 pzem3(Serial2, 18, 5);  //RX -> D18 , TX -> D5

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

bool val;
int countcheck = 0;

void setup() {
  Serial.begin(115200);
  firebase_wifl();
  delay(500);
}


void loop() {
  
    if (val) {
      val = false;
      Serial.println(1);
    Firebase.setInt(firebaseData, "phase/Link", 1);
    }else{
      val = true;
      Serial.println(0);
    Firebase.setInt(firebaseData, "phase/Link", 0);
    }

    countcheck ++;
    if (countcheck == 1) {
      read_pzem1();
    }
    if (countcheck == 2) {
      read_pzem2();
    }
    if (countcheck == 3) {
      read_pzem3();
    }
    if (countcheck == 4) {
      countcheck = 0;
    }
    delay(1000);
}

void firebase_wifl() {
   Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true); 
}



void read_pzem1() {
  float voltage = pzem1.voltage();
    if(!isnan(voltage)){
        Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
        Firebase.setFloat(firebaseData, "phase/L1/Voltage", voltage);
    } else {
        Serial.println("Error reading voltage");
    }

    float current = pzem1.current();
    if(!isnan(current)){
        Serial.print("Current: "); Serial.print(current); Serial.println("A");
        Firebase.setFloat(firebaseData, "phase/L1/Curren", current);
    } else {
        Serial.println("Error reading current");
    }

    float power = pzem1.power();
    if(!isnan(power)){
        Serial.print("Power: "); Serial.print(power); Serial.println("W");
        Firebase.setFloat(firebaseData, "phase/L1/Power", power);
    } else {
        Serial.println("Error reading power");
    }

    float energy = pzem1.energy();
    if(!isnan(energy)){
        Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
        Firebase.setFloat(firebaseData, "phase/L1/Energy", energy);
    } else {
        Serial.println("Error reading energy");
    }

    float frequency = pzem1.frequency();
    if(!isnan(frequency)){
        Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
        Firebase.setFloat(firebaseData, "phase/L1/Frequency", frequency);
    } else {
        Serial.println("Error reading frequency");
    }

    float pf = pzem1.pf();
    if(!isnan(pf)){
        Serial.print("PF: "); Serial.println(pf);
        Firebase.setFloat(firebaseData, "phase/L1/PF", pf);
    } else {
        Serial.println("Error reading power factor");
    }
}

void read_pzem2() {
  float voltage = pzem2.voltage();
    if(!isnan(voltage)){
        Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
        Firebase.setFloat(firebaseData, "phase/L2/Voltage", voltage);
    } else {
        Serial.println("Error reading voltage");
    }

    float current = pzem2.current();
    if(!isnan(current)){
        Serial.print("Current: "); Serial.print(current); Serial.println("A");
        Firebase.setFloat(firebaseData, "phase/L2/Current", current);
    } else {
        Serial.println("Error reading current");
    }

    float power = pzem2.power();
    if(!isnan(power)){
        Serial.print("Power: "); Serial.print(power); Serial.println("W");
        Firebase.setFloat(firebaseData, "phase/L2/Power", power);
    } else {
        Serial.println("Error reading power");
    }

    float energy = pzem2.energy();
    if(!isnan(energy)){
        Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
        Firebase.setFloat(firebaseData, "phase/L2/Energy", energy);
    } else {
        Serial.println("Error reading energy");
    }

    float frequency = pzem2.frequency();
    if(!isnan(frequency)){
        Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
        Firebase.setFloat(firebaseData, "phase/L2/Frequency", frequency);
    } else {
        Serial.println("Error reading frequency");
    }

    float pf = pzem2.pf();
    if(!isnan(pf)){
        Serial.print("PF: "); Serial.println(pf);
        Firebase.setFloat(firebaseData, "phase/L2/PF", pf);
    } else {
        Serial.println("Error reading power factor");
    }
}

void read_pzem3() {
  float voltage = pzem3.voltage();
    if(!isnan(voltage)){
        Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
        Firebase.setFloat(firebaseData, "phase/L3/Voltage", voltage);
    } else {
        Serial.println("Error reading voltage");
    }

    float current = pzem3.current();
    if(!isnan(current)){
        Serial.print("Current: "); Serial.print(current); Serial.println("A");
        Firebase.setFloat(firebaseData, "phase/L3/Current", current);
    } else {
        Serial.println("Error reading current");
    }

    float power = pzem3.power();
    if(!isnan(power)){
        Serial.print("Power: "); Serial.print(power); Serial.println("W");
        Firebase.setFloat(firebaseData, "phase/L3/Power", power);
    } else {
        Serial.println("Error reading power");
    }

    float energy = pzem3.energy();
    if(!isnan(energy)){
        Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
        Firebase.setFloat(firebaseData, "phase/L3/Energy", energy);
    } else {
        Serial.println("Error reading energy");
    }

    float frequency = pzem3.frequency();
    if(!isnan(frequency)){
        Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
        Firebase.setFloat(firebaseData, "phase/L3/Frequency", frequency);
    } else {
        Serial.println("Error reading frequency");
    }

    float pf = pzem3.pf();
    if(!isnan(pf)){
        Serial.print("PF: "); Serial.println(pf);
        Firebase.setFloat(firebaseData, "phase/L3/PF", pf);
    } else {
        Serial.println("Error reading power factor");
    }
}
