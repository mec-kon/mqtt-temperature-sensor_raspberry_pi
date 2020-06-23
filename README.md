# mqtt-temperature-sensor_raspberry_pi
### a mqtt client that sends the current temperature to openHAB every 10 minutes 

## Installation: ## 
The easiest way to build the program is with CMake.

First you need to install all required dependencies.
You can do this with ```sudo apt-get install cmake wiringpi build-essential libmosquittopp-dev```.


Then, all you have to do is create a new folder with ```mkdir build``` in the current project folder, change to this folder with ```cd build``` and create a makefile with ```cmake ..```.
Then you can create the executables by simply typing ```make```
Now install the program with ```sudo make install```.
