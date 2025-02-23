# **TECH TINKERS**

## **AUTO SPROUTS**

### **DESCRIPTION**
Too busy for daily gardening? Sometimes, when we are away from home for a few days or caught up with other tasks, we may forget to water our favorite plants. In such situations, keeping our plants healthy becomes challenging. So we found a solution! Check out our **self-watering plant pots** to keep greenery around the house effortlessly.

### **FEATURES**
- 📡 **Real-time Monitoring:** Track **soil moisture, water level, temperature, and humidity** directly from your mobile device.
- 💧 **Automatic Watering:** The system activates watering when soil moisture drops below a preset level.
- 📱 **Manual Control:** Enable or disable watering via a **smartphone app**.

---

### **OVERVIEW**
The **Smart Pot** is an intelligent plant care system designed to **automate watering** based on real-time environmental conditions. This system utilizes an **ESP microcontroller** to monitor, process, and control all components efficiently.

### **Key Components & Functionality**

#### **1️⃣ Sensors for Environmental Monitoring**
- **Capacitive Soil Moisture Sensor:** Measures soil moisture to determine if watering is needed. Unlike resistive moisture sensors, capacitive sensors are more **durable and corrosion-resistant**.
- **DHT11 Sensor:** Measures **temperature and humidity**, providing essential environmental data for plant care.

#### **2️⃣ Data Transmission & Mobile Monitoring**
- The system uses an **NodeMCU** (ESP8266) to read sensor values and transmit them to the **Blynk cloud server** over **Wi-Fi**.
- Users can **remotely monitor** soil moisture, water levels, temperature, and humidity through a **mobile application**.

#### **3️⃣ Automatic & Manual Watering**
- 🌿 **Automatic Mode:** When the soil moisture level drops below a set threshold, the ESP microcontroller **activates the water pump** to irrigate the plant.
- 📲 **Manual Mode:** Users can also **turn the pump on or off manually** via the **Blynk mobile app**, offering flexible plant care control.

### **How the Smart Pot Works**
1. The ESP microcontroller **continuously reads data** from the sensors.
2. It **sends sensor values** to the **Blynk cloud server**, accessible via a mobile app.
3. If the **soil moisture is too low**, the system **automatically activates the water pump** until the desired moisture level is reached.
4. Users receive **real-time updates** and can **manually control** the water pump when needed.

### **Advantages of Auto Sprouts**
✅ **Automates plant care**, reducing maintenance effort.  
✅ **Smartphone monitoring & control** for convenience.  
✅ **Efficient water management**, minimizing wastage.  
✅ **Helps keep plants healthy**, even when you're away.  

---

### **Getting Started**
#### **1️⃣ Hardware Requirements**
- ESP8266 Microcontroller
- Capacitive Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- Water Level Sensor
- Mini Water Pump 
- Wi-Fi Connection
- Power Supply

#### **2️⃣ Software Requirements**
- Arduino IDE (for programming the ESP microcontroller)
- Blynk IoT Platform
- ESP8266 Board Library
- Required Sensor Libraries


