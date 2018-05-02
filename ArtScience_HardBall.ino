#include <Adafruit_CircuitPlayground.h>

#define MIN 0
#define MAX 9

float maxAcc = 0;

void setup() {

  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
}

void loop() {
  // put your main code here, to run repeatedly:
  float acc=sqrt(CircuitPlayground.motionX()*CircuitPlayground.motionX()+CircuitPlayground.motionY()*CircuitPlayground.motionY()+CircuitPlayground.motionZ()*CircuitPlayground.motionZ());

  Serial.println(acc);
  if (acc > maxAcc) maxAcc = acc;
  if (CircuitPlayground.slideSwitch())maxAcc = 0;
  //divide entre 9, cada led representa un G
  pixelMeter(maxAcc/9.8, MIN, MAX);
}

void pixelMeter(float value, float minimum, float maximum) {
  int p = map(value-1, minimum, maximum, 0, 9);
  CircuitPlayground.clearPixels();
  for (int i = 0; i <= p; i++) {
    int c = map(i, 0, 9, 0, 255);
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
}
