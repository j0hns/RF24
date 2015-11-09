
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <RF24.h>
#include <bcm2835.h>
#include <unistd.h>

using namespace std;
//
// Hardware configuration
//

// CE Pin, CSN Pin, SPI Speed

// Setup for GPIO 22 CE and CE1 CSN with SPI Speed @ 1Mhz
//RF24 radio(RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_26, BCM2835_SPI_SPEED_1MHZ);

// Setup for GPIO 22 CE and CE0 CSN with SPI Speed @ 4Mhz
//RF24 radio(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_4MHZ);

// Setup for GPIO 22 CE and CE0 CSN with SPI Speed @ 8Mhz
RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);


// Radio pipe addresses for the 2 nodes to communicate.
const uint8_t pipes[][6] = {"1Node","2Node"};
//const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

int main(int argc, char** argv){

  printf("Temperature Receiver starting...\n");

  // Setup and configure rf radio
  radio.begin();

  // optionally, increase the delay between retries & # of retries
  //radio.setRetries(15,15);
  // Dump the configuration of the rf unit for debugging
  radio.printDetails();


  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();

	while (1)
	{
		float temperature;
		radio.read( &temperature, sizeof(float) );

		std::cout  << currentDateTime() << " " << temperature <<std::endl;
		//printf("%s : %f ",now,temperature);
		sleep(1);
	}

  return 0;
}



