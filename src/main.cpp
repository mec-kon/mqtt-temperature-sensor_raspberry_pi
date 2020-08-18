#include <cmath>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "config.h"
#include "Mqtt.h"
#ifdef IS_RASPBERRY_PI
#include <wiringPiI2C.h>
#endif

using namespace std;
using namespace std::chrono;


float get_temperature(int8_t slave_address_read){
#ifdef IS_RASPBERRY_PI
    uint16_t lm75_temp_int = wiringPiI2CReadReg16(slave_address_read,0x00);

    if(lm75_temp_int == 0xffff){
        return 1000.00;
    }

    // swap bytes
    uint16_t upper_byte = (lm75_temp_int << 8) & 0xff00;
    uint16_t lower_byte = (lm75_temp_int >> 8) & 0x00ff;

    int16_t lm75_temp = (upper_byte | lower_byte);
    int16_t bitshift = 5; // last 5 bits are don't cares

    float precision = 0.125;
    float temp = (lm75_temp >> bitshift) * precision;
    temp = round(temp * 100) / 100;
    return temp;
#else
    cerr << "device is no raspberry pi!" << endl;
    return 1000.0;
#endif
}

template <typename T>
string to_string_with_precision(const T value, const int n = 2)
{
    ostringstream out;
    out.precision(n);
    out << fixed << value;
    return out.str();
}



int main()
{
    vector<string> subscription_topic_list;

    Mqtt *mqtt = new Mqtt(MQTT_CLIENT_ID, MQTT_PUBLISH_TOPIC, subscription_topic_list, MQTT_ADDRESS, MQTT_PORT, MQTT_CLIENT, MQTT_CLIENT_PASSWORD);

#ifdef IS_RASPBERRY_PI
    int8_t slave_address_read = wiringPiI2CSetup (0x48);
#else
    int8_t slave_address_read = 0;
#endif
    while (true) {
        string temp = to_string_with_precision(get_temperature(slave_address_read));
        cout << "temp = " << temp << endl;
        mqtt->publish(temp);

        this_thread::sleep_for(minutes(10));
    }

    delete mqtt;

    return 0 ;
}