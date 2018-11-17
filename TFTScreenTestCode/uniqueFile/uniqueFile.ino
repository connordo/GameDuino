#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x8410


int width = tft.width();
int height = tft.height();

uint16_t version = MCUFRIEND_KBV_H_;

void setup() {
  tft.setRotation(0);
  Serial.begin(9600);
 if (!Serial) delay(5000);           //allow some time for Leonardo
 uint16_t ID = tft.readID(); //
 tft.begin(ID);
}

void loop() {
  tft.fillScreen(RED);
  delay(500);
  tft.fillScreen(BLUE);
  delay(200);
}
