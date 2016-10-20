# BRF_Visualizations
On Saturday, October 15th to 16th, computer science, education, and geography students from Hunter College travelled upstate for an interdisciplinary excursion to Black Rock Forest Consortium. The trip coordinators were able to purchase twelve Arudino microcontrollers and sensors for use as minature weather stations with the generous funding from Hunter College President Jennifer Raab's Initiative to Increase Student Engagement and Co-curricular Activity.

# Arudino Devices
Prior to the trip, computer science professor Eric Schweitzer held workshops for students to aid in the construction of the twelve microcontroller devices that would be collecting data. Microcontrollers are computers that exist entirely on a single integrated circuit, mainly consisting of a processor, very small amount of RAM and storage memory, pins for I/O, a USB port for loading programs into ROM, and a port for power. Microcontrollers are used primarily for devices whose function are very limited in scope, such as children's toys, microwaves, implanted medical devices, and power tools. 

Twelve [Arudino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno) microcontrollers were purchased for their low cost and simplicity. It is perhaps the most ubiquitous of all Arduino devices, and therefore the most well documented and easy to learn. For comparison to standard computers, which may have processors running on 64-bits at clock rates near 3Ghz, the Arudino Uno operates with 8-bits at 16MHz. Additionally, the Arduino Uno only contains 32KB of flash memory for storage, and 2KB of RAM. For our purpose of collecting meteorological data, the Arduino Uno is sufficient, and cost effective.

In addition to the Arudino Uno is the [Data Logging shield](https://www.adafruit.com/product/1141). The shield provides the Arudino with a real time clock for timestamping points of data, and an SD Card slot to export data off the Arudino. The shield was attached to the Arduino via pins and soldered in place. Soldering ensures that pins are securely connected for proper data transfer, and preventing them from shifting especially during transport.

The data is collected by the [BME280 Temperature, Humidity, Pressure sensor](https://www.adafruit.com/product/2652). Readings are calibrated in degrees Celcius, relative humidity, and pressure in millibars. Accurate readings need to take place in open air away from the device, so 1 foot of wiring distances the sensor from the Arduino.

An LED light was fixed onto the Arudino itself for ease of use. It is not obvious that the device functions once removed from the testing environment. The LED provides a way of signaling to the user that certain functions are happening at any given time. The LED blinks 3 times on startup of the device to signal that all systems and components are functional. The LED will then blink each time a point of data is being written to the SD card. The latter of the two functions is also for safety purposes. The user must not power down the Arudino during writing to the SD card, otherwise the entire SD card may become corrupted.

The final physical component of the devices are the plastic shields which house the sensor and the Arduino. These low cost food containers were improvised to protect Arduino from moisture and morning down that may accumulate on it, as well as protection against wildlife that may interfere. The plastic surrounding the sensor was spray painted white to reduce its albedo value, and thus reducing inaccuracy of the temperature reading from accumulated solar radiation.

# Data and Graphing
`12.05 deg C, 999.39 mBar, 66.81%, 1476532249`
The above is a sample of the data collected from the devices.

The Python Script responsible for generating graphs of the readings makes use of the graphing functionality of the [matplotlib library](http://matplotlib.org/).

# Staff
* Michael Garod, Computer Science Major
* Eric Schweitzer, Department of Computer Science
* Tom Walter, Department of Geography
* Jeanne Weiler, Department of Educational Foundations and Counseling Programs

