#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x8410

#define Y 104

Adafruit_TFTLCD tft;

void setup(void) {
  Serial.begin(9600);
  tft.begin(0x9341);//type here your driver id
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setCursor(130, 80);
  tft.setTextColor(WHITE); tft.setTextSize(1);
  tft.print("Loading...");
  tft.drawRect(10, 10 + Y, 300, 20, WHITE);
  for (int i = 0; i < 298; i++) {
    tft.fillRect(135,150,34,14,BLACK);
    tft.drawRect(12, 11 + Y, i, 18, GREY);
    tft.setCursor(135, 150);
    tft.setTextSize(2);
    tft.print(map(i,0,297,0,100));
    tft.print("%");
    delay(10);
  }
}

void loop(void) {
}
