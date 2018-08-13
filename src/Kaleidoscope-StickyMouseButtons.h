#pragma once

#include "Kaleidoscope.h"

typedef enum {
  STICKY_MOUSE_BUTTON_LEFT,
  STICKY_MOUSE_BUTTON_MIDDLE,
  STICKY_MOUSE_BUTTON_RIGHT
}
StickyMouseButton;

namespace kaleidoscope {
class StickyMouseButtons : public kaleidoscope::Plugin {
 public:
  StickyMouseButtons(): left(false), middle(false), right(false) {}
  EventHandlerResult beforeReportingState();

  bool sticky(StickyMouseButton btn);
  void sticky(StickyMouseButton btn, bool value);
  void toggleSticky(StickyMouseButton btn);

 private:
  bool left, middle, right;
};
}

extern kaleidoscope::StickyMouseButtons StickyMouseButtons;
