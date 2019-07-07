#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 3
float hue;
float inc = 0;
float noisePos = 0;
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(30);
  hue = 0;
}

void loop() {

  float toAdd = map(inoise8(noisePos), 0, 255, -2, 7);
  noisePos += .03; // how fast the variablaity changes
  inc += toAdd; // controls speed, make it randomize between range of 1 to 4
  hue = inc;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
    hue += 1.5; // incremenration of hues in the strip
  }

  FastLED.show();
  //  delay(60);
}
