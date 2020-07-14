/* -*- mode: c++ -*-
 *
 * Kaleidoscope-StickyMouseButtons
 *
 * When you want mouse buttons to be sticky (held without user press)
 * Copyright (C) 2018, Shriramana Sharma
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Credit due to Gergely Nagy (algernon)
// See: https://community.keyboard.io/t/mousekeys-plugin-separate-keys-for-press-and-release/877

#include "Kaleidoscope-StickyMouseButtons.h"
#include "Kaleidoscope-MouseKeys.h"

namespace kaleidoscope {

EventHandlerResult StickyMouseButtons::beforeReportingState() {
  if (left)
    Kaleidoscope.hid().mouse().pressButtons(KEY_MOUSE_BTN_L);
  if (middle)
    Kaleidoscope.hid().mouse().pressButtons(KEY_MOUSE_BTN_M);
  if (right)
    Kaleidoscope.hid().mouse().pressButtons(KEY_MOUSE_BTN_R);
  return EventHandlerResult::OK;
}

bool StickyMouseButtons::sticky(StickyMouseButton btn) {
  if (btn == STICKY_MOUSE_BUTTON_LEFT)
    return left;
  else if (btn == STICKY_MOUSE_BUTTON_MIDDLE)
    return middle;
  else if (btn == STICKY_MOUSE_BUTTON_RIGHT)
    return right;
  return false; // to silence compiler warning
}

void StickyMouseButtons::sticky(StickyMouseButton btn, bool value) {
  if (btn == STICKY_MOUSE_BUTTON_LEFT)
    left = value;
  else if (btn == STICKY_MOUSE_BUTTON_MIDDLE)
    middle = value;
  else if (btn == STICKY_MOUSE_BUTTON_RIGHT)
    right = value;
}

void StickyMouseButtons::toggleSticky(StickyMouseButton btn) {
  if (btn == STICKY_MOUSE_BUTTON_LEFT)
    left = !left;
  else if (btn == STICKY_MOUSE_BUTTON_MIDDLE)
    middle = !middle;
  else if (btn == STICKY_MOUSE_BUTTON_RIGHT)
    right = !right;
}

}

kaleidoscope::StickyMouseButtons StickyMouseButtons;
