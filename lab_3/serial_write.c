#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int num_chars(char *message) {
	int counter = 0;
	while (message[counter] != '\0') {
		counter++;
	}
	return counter;
}

int main() {
	int serial_port;
	char *message = "CSE467 Embedded Computing Systems";
	int message_length = num_chars(message);

	if ((serial_port = serialOpen ("/dev/ttyS0", 115200)) < 0) {
		fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
		return 1;
	}

	if (wiringPiSetup() == -1) {
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return 1;
	}

	while (1) {
		for (int i = 0; i < message_length; i++) {
			serialPutchar(serial_port, message[i]);
		}
	}
}
