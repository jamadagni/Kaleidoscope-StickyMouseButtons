# Kaleidoscope-StickyMouseButtons

![status][st:stable] [![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.com/jamadagni/Kaleidoscope-StickyMouseButtons.svg?branch=master
 [travis:status]: https://travis-ci.com/jamadagni/Kaleidoscope-StickyMouseButtons

 [st:stable]: https://img.shields.io/badge/stable-✔-black.svg?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.svg?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.svg?style=flat&colorA=dfb317&colorB=494e52

When you want mouse buttons to be sticky (held without user press)…

## Using the extension

This is best illustrated by the following code:

```c++
// include the MouseKeys (of course), StickyMouseButtons and Macros headers
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-StickyMouseButtons.h"

// declare a macro id with an appropriate name in your macros enum
enum { M_STICKY_LMB };

// define the macro to call the plugin function
const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
    case M_STICKY_LMB:
      if (keyToggledOn(keyState))
        StickyMouseButtons.toggleSticky(STICKY_MOUSE_BUTTON_LEFT);
      break;
  }
  return MACRO_NONE;
}

// add the macro key somewhere in the keymap...
KEYMAPS(
  ...
  M(M_STICKY_LMB)
  ...
)

// and don't forget to enable the Macros and StickyMouseButtons plugins:
KALEIDOSCOPE_INIT_PLUGINS(
  MouseKeys,
  Macros,
  StickyMouseButtons
);
```

## Plugin properties

The plugin provides the `StickyMouseButtons` object, which has the following
accessor methods to respectively get, set and toggle the sticky state of each
mouse button:

### `sticky(btn)`
### `sticky(btn, value)`
### `toggleSticky(btn)`

where `btn` is one of:

* `STICKY_MOUSE_BUTTON_LEFT`,
* `STICKY_MOUSE_BUTTON_MIDDLE`,
* `STICKY_MOUSE_BUTTON_RIGHT`

and `value` is either `true` or `false`.

## Dependencies

For practical usefulness from a sketch, this plugin depends upon:

* [Kaleidoscope-MouseKeys](https://github.com/keyboardio/Kaleidoscope-MouseKeys)
* [Kaleidoscope-Macros](https://github.com/keyboardio/Kaleidoscope-Macros)
