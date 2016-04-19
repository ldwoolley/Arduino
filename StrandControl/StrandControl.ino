#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(50,50,50));  // Set strip to White 25% power
  }
    strip.show(); //Display white
  delay(10000); // wait on white
  rainbow(20);
  
  for(uint16_t i=0; i<250; i=i+50) {
    colorChase(strip.Color(250-i, i, 0), strip.Color((250-i)/50, i/50, 0), 25);  //Chase light and leave shadow.
    colorChase(strip.Color(0, 250-i, i), strip.Color(i/50, 0, (250-i)/50), 25);  //Chase light and leave offset color shadow.
  }
  rainbowCycle(20);

  for(uint16_t i=0; i<250; i=i+50) {
    colorWipe(strip.Color(255-i, i, 0), 50); // Red to Green
    colorWipe(strip.Color(0,0,0), 5);  //Clear the lights.
    delay(100);  // Pause between colors
  }
}

// Move the dots one after the other with a color
void colorChase(uint32_t c, uint32_t d, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, d);
    strip.show();
    delay(wait/10);
  }
  delay(wait);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(strip.numPixels()-i-1, c);
    strip.show();
    delay(wait);
    strip.setPixelColor(strip.numPixels()-i-1, strip.Color(0,0,0));
    strip.show();
    delay(wait/10);
  }
  delay(wait);
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

