#include "buttons.h"

uint8_t buttons_readAll() {
  uint8_t buttons_enabled = 0;
  if (digitalRead(BTN_A)) buttons_enabled = buttons_enabled | BITMASK_BTN_A;
  if (digitalRead(BTN_B)) buttons_enabled = buttons_enabled | BITMASK_BTN_B;
  if (digitalRead(BTN_UP)) buttons_enabled = buttons_enabled | BITMASK_BTN_UP;
  if (digitalRead(BTN_DOWN))buttons_enabled = buttons_enabled | BITMASK_BTN_DOWN;
  if (digitalRead(BTN_LEFT))buttons_enabled = buttons_enabled | BITMASK_BTN_LEFT;
  if (digitalRead(BTN_RIGHT))buttons_enabled = buttons_enabled | BITMASK_BTN_RIGHT;
  return buttons_enabled;
}
