# RTOSense

**RTOSense** is a lightweight system for simulating sensor data, processing it on an RTOS-based service, and sending it to clients using REST APIs.  
It’s designed for testing real-time sensor-to-client communication pipelines.

---

## Features

- **sensor.sh**: Acts as a virtual GPS sensor, generating random latitude and longitude data every 10 seconds.
- **RTOSense Service**: Core service running on the RTOS device that receives sensor data, validates it, and forwards it to clients using REST API calls.
- **Test Server**: Python Flask server to simulate client endpoints for testing and validating the system.

---

## Folder Structure

```text
.
├── README.md
├── RTOSenseService
│   ├── Makefile
│   ├── include
│   │   └── ClientAgent.h
│   ├── main.cpp
│   └── src
│       └── ClientAgent.cpp
├── TestServer
│   └── testserver.py
└── sensor
    └── sensor.sh
```
---

## sensor.sh

- Simulates GPS coordinates
- Sends JSON messages every 10 seconds in the format:

```json
{"lat":12.9754,"lon":77.5932}
```

### Run the script:
```chmod +x sensor.sh
./sensor.sh
```
---

## RTOSense Service

- Reads JSON data from the simulated device.
- Sends the data to client endpoints via HTTP POST (REST API).
- Handles multiple clients and validates the JSON before sending.

### Build the service
```
make all
```
### Clean build
```
make clean
```
### Run Application
```
./rtosense
```
---

## Test Server
- Python Flask server to act as a client endpoint.
- Receives sensor data via REST API and prints it to the console.
- Sends back a confirmation response to RTOSense.

### Run the server:
```cd test_server
python3 testserver.py
```
Accessible at: http://<server_ip>:5000/sensor #add your own ip address

---

## How It Works

- sensor.sh generates fake GPS data every 10 seconds.
- RTOSense Service reads the data and forwards it to clients using REST API calls.
- Test Server or actual client applications receive and process the data.

---

## Requirements

- Linux environment
- Python 3.x (for Test Server)
- Flask (pip install flask)
- libcurl (for C++ RTOSense service)

---
## Demo

- You can find the demonstration video here - https://youtu.be/TFEp2hrsw3I
---
