#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "temp_convert.h"
#include "temp_converters.h"

int main(int argc, char *argv[]) {

	int index;
  	int arg;
  	char intype = 'c';
  	char outtype = 'f';
  	int verbose = 0;

	opterr = 0;

	while ((arg = getopt (argc, argv, "vhi:o:")) != -1) {
		switch (arg) {
			case 'v':
				verbose = 1;
				break;
			case 'i':
				intype = *optarg;
				break;
			case 'o':
				outtype = *optarg;
				break;
			case 'h':
				printf("Usage: %s -i (c|k|f) -o (c|k|f) -v\n", argv[0]);
				return 0;
			case '?':
				if (optopt == 'c')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
				fprintf (stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
				return 1;
			default:
			abort ();
		}
	}

	if (verbose) {	
		printf(
			"Converting from %s to %s...\n", 
			opt_to_string(intype), 
			opt_to_string(outtype));
	}

	double (*convertFnPtr)(double);

	if (intype == 'c' & outtype == 'f') 
		convertFnPtr = &celsius_to_fahrenheit;
	else if (intype == 'c' & outtype == 'k') 
		convertFnPtr = &celsius_to_kelvin;
	else if (intype == 'k' & outtype == 'f') 
		convertFnPtr = &kelvin_to_fahrenheit;
	else if (intype == 'k' & outtype == 'c') 
		convertFnPtr = &kelvin_to_celsius;
	else if (intype == 'f' & outtype == 'k') 
		convertFnPtr = &fahrenheit_to_kelvin;
	else if (intype == 'f' & outtype == 'c') 
		convertFnPtr = &fahrenheit_to_celsius;
	else if (intype == outtype) 
		convertFnPtr = &identity;

	double temps[100];
	double temp;
	for (int i = 0; i < 100; i ++) {
		temp = (*convertFnPtr)(i * 5);
		printf("%f\t", temp);
		temps[i] = temp;
	}
	printf("\n");

	return(0);
}

// http://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
const char* opt_to_string(char type) {
	static char* temps[] = {"Kelvin", "Fahrenheit", "Celsius"}; 
	switch(type) {
		case 'k':
		return temps[0];
		case 'f':
		return temps[1];
		case 'c':
		return temps[2];
	};
}
