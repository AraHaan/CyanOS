/*
 * CyanOS GUI Toolkit.
 * Include file for the button control class.
 */
#ifndef CYANOS_GUI_BUTTON_H
#define CYANOS_GUI_BUTTON_H
#include "Control.h"

class Button : public Control
{
public:
  Button(int width, int height, int x, int y);
  ~Button();
};

#endif
