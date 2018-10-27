/*
 * Cyanyde OS GUI Toolkit.
 * Include file for the button control class.
 */
#ifndef CYANYDE_GUI_BUTTON_H
#define CYANYDE_GUI_BUTTON_H
#include "Control.h"

class Button : public Control
{
private:
  bool Checked = false;
public:
  void Button();
  void ~Button();
};

#endif
