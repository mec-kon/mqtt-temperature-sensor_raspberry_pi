#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 *
 * This file contains all parameters that can be configured
 */
#define MQTT_CLIENT_ID "raspberry_pi_temperature_sensor"
#define MQTT_CLIENT "client-name"
#define MQTT_CLIENT_PASSWORD "passw0rd"
#define MQTT_PUBLISH_TOPIC "home/raspberry_pi/temperature_sensor"
#define MQTT_SUBSCRIPTION_TOPIC "home/raspberry_pi/temperature_sensor"

#define MQTT_ADDRESS "127.0.0.1"
#define MQTT_PORT 1883

#endif // CONFIG_H
