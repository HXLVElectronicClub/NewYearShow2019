#include "LedControl.h"
#include "displayHelper.h"

#define DIN 12
#define CLK 10
#define CS  11
#define DIN2 5
#define CLK2 6
#define CS2  7

#define DEVICE_NUM 16
                                                     
LedControl lc = LedControl(DIN,CLK,CS,DEVICE_NUM/2);
LedControl lc2 = LedControl(DIN2,CLK2,CS2,DEVICE_NUM/2);

uint64_t heart = 0x10387cfefeee4400;

byte POT [4*32] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x78, 0xf8, 0x01, 0x00, 0xfc, 0xf0, 
0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00,
0xff, 0x03, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x03, 0x00,
0x00, 0x80, 0x02, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x40, 0x05, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0xb0,
0x1a, 0x00, 0x00, 0x50, 0x15, 0x00, 0xaa, 0xb0, 0x1a, 0x00, 0xff, 0xfe, 0x1f, 0x95, 0x00, 0xa1, 0xc0, 0xff,
0x48, 0x92, 0x24, 0x00, 0xf9, 0xff, 0x3f, 0x49, 0x07, 0x26, 0xc0, 0xff, 0x00, 0x33, 0x00, 0x00, 0x00, 0x19,
0x00, 0x00};

byte POT2 [4*32] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x54, 0x15, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0xab, 0x6a, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x80, 0xff, 0xff, 0x00, 0xc0, 0xff, 0xff, 0x01, 0xe0, 0xff, 0xff, 0x03, 0xf0, 0xff, 0xff, 0x07, 0xf8, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0xff, 0x1f, 0xfe, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x7f
};

byte POT3[4*32]=
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0xa0, 0x02, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0xaa, 0x2a, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x8e, 0x1f, 0x0f, 0x80, 0x83, 0x18, 0x78, 0xe0, 0x40, 0x60, 0x80, 0x38, 0x20, 0x80, 0x03, 0x07, 0x30, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x60, 0x00, 0x02, 0x00, 0x80, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
byte POT4[4*32]=
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0xf0, 0x07, 0x84, 0x3f, 0x80, 0x00, 0x04, 0x00, 0x80, 0x00, 0x9f, 0x3f, 0xf0, 0x07, 0x04, 0x04, 0x80, 0x00, 0x14, 0x02, 0x40, 0x01, 0x0c, 0x09, 0x20, 0x02, 0x82, 0x1f, 0x10, 0x04, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x24, 0xb9, 0x24, 0x44, 0x6a, 0x51, 0x2d, 0x44, 0xae, 0xd1, 0x35, 0xe4, 0x2a, 0x51, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup() {
  for (int i=0;i<DEVICE_NUM/2;i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i,0);
    lc.clearDisplay(i);
    lc2.shutdown(i, false);
    lc2.setIntensity(i,0);
    lc2.clearDisplay(i);
  }
  setLC(lc2,lc);
  Serial.begin(9600);
}

void loop() {
    setImage(POT);
    display(1500);
    setImage(POT2);
    display(1500);
    setImage(POT3);
    display(1500);
    setImage(POT4);
    display(1500);
}
