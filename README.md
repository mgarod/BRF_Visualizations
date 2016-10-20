# BRF_Visualizations
On Saturday, October 15th to 16th, computer science, education, and geography students from Hunter College travelled upstate for an interdisciplinary excursion to Black Rock Forest Consortium. The trip coordinators were able to purchase twelve Arudino microcontrollers and sensors for use as minature weather stations with the generous funding from Hunter College President Jennifer Raab's Initiative to Increase Student Engagement and Co-curricular Activity.

# Arudino Devices
Prior to the trip, computer science professor Eric Schweitzer held workshops for students to aid in the construction of the twelve microcontroller devices that would be collecting data. Microcontrollers are computers that exist entirely on a single integrated circuit, mainly consisting of a processor, very small amount of RAM and storage memory, pins for I/O, a USB port for loading programs into ROM, and a port for power. Microcontrollers are used primarily for devices whose function are very limited in scope, such as children's toys, microwaves, implanted medical devices, and power tools. 

Twelve [Arudino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno) microcontrollers were purchased for their low cost and simplicity. It is perhaps the most ubiquitous of all Arduino devices, and therefore the most well documented and easy to learn. For comparison to standard computers, which may have processors running on 64-bits at clock rates near 3Ghz, the Arudino Uno operates with 8-bits at 16MHz. Additionally, the Arduino Uno only contains 32KB of flash memory for storage, and 2KB of RAM. For our purpose of collecting meteorological data, the Arduino Uno is sufficient, and cost effective.

In addition to the Arudino Uno is the [Data Logging shield](https://www.adafruit.com/product/1141). The shield provides the Arudino with a real time clock for timestamping points of data, and an SD Card slot to export data off the Arudino. The shield was attached to the Arduino via pins and soldered in place. Soldering ensures that pins are securely connected for proper data transfer, and preventing them from shifting especially during transport.

The data is collected by the [BME280 Temperature, Humidity, Pressure sensor](https://www.adafruit.com/product/2652). Readings are calibrated in degrees Celcius, relative humidity, and pressure in millibars. Accurate readings need to take place in open air away from the device, so 1 foot of wiring distances the sensor from the Arduino.

An LED light was fixed onto the Arudino itself for ease of use. It is not obvious that the device functions once removed from the testing environment. The LED provides a way of signaling to the user that certain functions are happening at any given time. The LED blinks 3 times on startup of the device to signal that all systems and components are functional. The LED will then blink each time a point of data is being written to the SD card. The latter of the two functions is also for safety purposes. The user must not power down the Arudino during writing to the SD card, otherwise the file or the entire SD card may become corrupted.

The final physical component of the devices are the plastic shields which house the sensor and the Arduino. These low cost food containers were improvised to protect Arduino from moisture and morning down that may accumulate on it, as well as protection against wildlife that may interfere. The plastic surrounding the sensor was spray painted white to reduce its albedo value, and thus reducing inaccuracy of the temperature reading from accumulated solar radiation.

# Data
`12.05 deg C, 99.39 mBar, 66.81%, 1476532249`

The above is a sample of the data collected from the devices.

From left to right is the temperature, air pressure, relative humidity, and unix timestamp. Erroneously, the timestamps collected were configured in Greenwich Mean Time.

The addition of "deg C", "mBar", and "%" in the data aids readability for humans, but makes data processing more complicated. Regular expressions were used to extract the relevant portions of data.

Each device generated data in bursts. Every 30 minutes, the Arduino created a new file. Each file would contain 6 readings, taken every 5 minutes. This obfuscation of data was taken as a precautionary measure against power failure. In the inevitablility that the batteries run out of power, if the power failure occurs during a write, then it is more likely that only that file may be corrupted.

# Visualizations
```
Built with python2.7
Usage: python viz_multifolder.py <all_data_folders> <output_path>
```

The first parameter, all_data_folders is a folder, containing many folders. The folders in all_data_folders are the given name of the device, and will be used to identify the graph generated. Each subfolder in all_data_folders contains the many text files that device generated.

The second parameter is a folder which will contain the graphs generated.

The python script, viz_multifolder.py, is responsible for generating graphs of the readings makes use of the graphing functionality of the [matplotlib library](http://matplotlib.org/). Each device is given its own plot, with each of the three data readings sharing a single x-axis, time.

# Field Work
Devices were placed in various places in Black Rock Forest, at varying times due to the cost of travel by foot. It was decided that devices be paired off when planted, and placed only a few feet apart, in order to observe any variation of readings that might occur due to error in data collection.

Below are the times, geolocation, and altitude of the devices placed.
```
Device 1 & 2
* Time Planted: 11:55am
* Latitude:     41 degrees, 24.768 minutes
* Longitude:    74 degrees, 00.660 minutes
* Altitude:     116 meters

Device 3 & 4
* Time Planted: 12:05pm
* Latitude:     41 degrees, 24.704 minutes
* Longitude:    74 degrees, 00.651 minutes
* Altitude:     286 meters

Device 5 & 6
* Time Planted: 12:17pm
* Latitude:     41 degrees, 24.633 minutes
* Longitude:    74 degrees, 00.671 minutes
* Altitude:     306 meters

Device 7 & 8
* Time Planted: 12:27am
* Latitude:     41 degrees, 24.628 minutes
* Longitude:    74 degrees, 00.797 minutes
* Altitude:     335 meters

Device 9 & 10
* Time Planted: 1:30pm
* Latitude:     41 degrees, 24.374 minutes
* Longitude:    74 degrees, 00.794 minutes
* Altitude:     318 meters

Device 11 & 12
* Time Planted: 4:37pm
* Latitude:     41 degrees, 24.616 minutes
* Longitude:    74 degrees, 00.408 minutes
* Altitude:     311 meters
```

Device 3 did not function upon arrival to the location. Device 4 failed to produce any data when the SD card was read. There is no data associated with the entry for Device 3 & 4, though the metadata is preserved for records.


# Staff
* Michael Garod, Computer Science Major
* Eric Schweitzer, Department of Computer Science
* Tom Walter, Department of Geography
* Jeanne Weiler, Department of Educational Foundations and Counseling Programs
