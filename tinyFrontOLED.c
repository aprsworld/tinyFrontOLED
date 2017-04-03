#include "ArduiPi_SSD1306.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#include <stdio.h>

#define OLED_POWER_EN RPI_GPIO_P1_07 /* GPIO pin power enable is connected to, or -1 if not used */

// Instantiate the display
Adafruit_SSD1306 display;

int main(int argc, char **argv) {
	int i;

	if ( -1 != OLED_POWER_EN ) {
		/* turn on power to the display */
		fprintf(stderr,"# turning on OLED display\n");
		/* set GPIO 4 to output */
		bcm2835_init();
		bcm2835_gpio_fsel(OLED_POWER_EN, BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_write(OLED_POWER_EN, HIGH);
		bcm2835_delay(10);
	}
	
	/* I2C 128x32 */
	if ( !display.init(2) ) {
		exit(EXIT_FAILURE);
	}



	display.begin();
	
	// init done
	display.clearDisplay();   // clears the screen and buffer

	if ( 5 == argc ) {
		fprintf(stderr,"# printing 4 lines with top line inverted\n");

		/* truncate lines to 20 characters so they don't wrap */
		for ( i=1 ; i<5 ; i++ ) {
			if ( strlen(argv[i]) > 20 ) {
				argv[i][20]='\0';
			}
		}	

		display.setTextSize(1);
		display.setTextColor(BLACK, WHITE); // 'inverted' text
		display.setCursor(0,0);

		display.printf("%s\n",argv[1]);
	
		display.setTextColor(WHITE);
		display.printf("%s\n",argv[2]);
		display.printf("%s\n",argv[3]);
		display.printf("%s\n",argv[4]);

		display.display();
	} else if ( 4 == argc ) {
		fprintf(stderr,"# printing 3 lines with top line inverted and double size\n");
		display.setTextSize(2);
		display.setTextColor(BLACK, WHITE); // 'inverted' text
		display.setCursor(0,0);

		/* truncate to 9 characters */
		if ( strlen(argv[1]) > 9 ) {
			argv[1][9]='\0';
		}
		display.printf("%s\n",argv[1]);
	

		/* truncate lines to 20 characters so they don't wrap */
		for ( i=2 ; i<4 ; i++ ) {
			if ( strlen(argv[i]) > 20 ) {
				argv[i][20]='\0';
			}
		}	

		display.setTextSize(1);
		display.setTextColor(WHITE);
		display.printf("%s\n",argv[2]);
		display.printf("%s\n",argv[3]);

		display.display();
	} else if ( 3 == argc ) {
		fprintf(stderr,"# printing 2 lines with top line inverted and both linesdouble size\n");
		display.setTextSize(2);
		display.setTextColor(BLACK, WHITE); // 'inverted' text
		display.setCursor(0,0);

		/* truncate to 9 characters */
		for ( i=1 ; i<2 ; i++ ) {
			if ( strlen(argv[i]) > 9 ) {
				argv[i][9]='\0';
			}
		}
		display.printf("%s\n",argv[1]);
	

		display.setTextColor(WHITE);
		display.printf("%s\n",argv[2]);

		display.display();
	} else {
		fprintf(stderr,"# invalid number of arguements\n");
	}


#if 0
	if ( -1 != OLED_POWER_EN ) {
		/* turn on power to the display */
		fprintf(stderr,"# turning off OLED display\n");
		/* set GPIO 4 to output */
		bcm2835_gpio_write(OLED_POWER_EN, LOW);
	}
#endif

	// Free PI GPIO ports
	display.close();

}

