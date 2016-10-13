import os
import re
from datetime import datetime
import matplotlib.figure as fig
import matplotlib.ticker as tick
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from pandas import Series

dev_num = 1
path = "./22hrs_data"

xtime = list()
ytemp = list()
ypressure = list()
yhumidity = list()

for filename in os.listdir(path):
    with open(path+"/"+filename) as openfile:
        for line in openfile:
            data = [d.strip() for d in line.split(',')]
            temp, pressure, humidity, time = data

            temp = re.search(r'\d+.\d+', temp).group()
            pressure = re.search(r'\d+.\d+', pressure).group()
            humidity = re.search(r'\d+.\d+', humidity).group()
            time = datetime.fromtimestamp(int(time))

            xtime.append(time)
            ytemp.append(temp)
            ypressure.append(pressure)
            yhumidity.append(humidity)

# Make graph and 3 different Axes
f, (temp_ax, pres_ax, humid_ax) = plt.subplots(3, sharex=True)

# Set Title
datetitle = xtime[0].strftime('%m/%d/%Y')+" - "+xtime[-1].strftime('%m/%d/%Y')
f.suptitle("Device {} readings for {}".format(dev_num, datetitle), fontsize=18)

# Set temperature data, title and labels
temp_ax.plot_date(xtime, ytemp, linewidth=1, linestyle='-', color='b')
temp_ax.set_title('Temperature (in Celcius)', fontsize=10)
temp_ax.set_ylabel("Temperature (C)")

# Set pressure data, title and labels
pres_ax.plot_date(xtime, ypressure, linewidth=1, linestyle='-', color='r')
pres_ax.set_title('Pressure (in mBar)', fontsize=10)
pres_ax.set_ylabel("Pressure (mBar)")

# Set humidity data, title and labels
humid_ax.plot_date(xtime, yhumidity, linewidth=1, linestyle='-', color='g' )
humid_ax.set_title('Relative Humidity', fontsize=10)
humid_ax.set_ylabel("Percent")

# Format The Hour labels nicely
temp_ax.xaxis.set_major_locator(mdates.HourLocator())
temp_ax.xaxis.set_major_formatter(mdates.DateFormatter('%H:%M'))
f.autofmt_xdate()

# Do not adjust the Pressure y-axis to scientific notation
pres_ax.get_yaxis().get_major_formatter().set_useOffset(False)
f.savefig('temp_pres_humid.png')
