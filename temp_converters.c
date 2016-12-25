#include "temp_converters.h"

double celsius_to_fahrenheit(double temp) {
	return ((temp * CELSIUS_TO_FAHRENHEIT) + FAHRENHEIT_OFFSET);
}

double celsius_to_kelvin(double temp) {
	return (temp + KELVIN_OFFSET);
}

double kelvin_to_fahrenheit(double temp) {
	return (celsius_to_fahrenheit(kelvin_to_celsius(temp)));
}

double kelvin_to_celsius(double temp) {
	return (temp - KELVIN_OFFSET);
}

double fahrenheit_to_kelvin(double temp) {
	return (celsius_to_kelvin(fahrenheit_to_celsius(temp)));
}

double fahrenheit_to_celsius(double temp) {
	return ((temp - FAHRENHEIT_OFFSET) / CELSIUS_TO_FAHRENHEIT);
}

