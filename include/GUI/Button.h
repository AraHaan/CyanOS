/*
 * Cyanyde OS GUI Toolkit.
 * Include file for the button control class.
 */
#ifndef CYANYDE_GUI_BUTTON_H
#define CYANYDE_GUI_BUTTON_H
#include "Control.h"

class Button : public Control
{
public:
  void Button(int width, int height, int x, int y);
  void ~Button();
};

#endif
