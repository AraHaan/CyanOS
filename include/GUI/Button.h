/*
 * CyanOS GUI Toolkit.
 * Include file for the button control class.
 */
#ifndef CYANOS_GUI_BUTTON_H
#define CYANOS_GUI_BUTTON_H
#include "Control.h"

class Button/* : public Control*/
{
#ifdef GUI_TOOLKIT_BUILD
private:
  void WndProc(Control &control);
  void OnDraw(Control &control);
  void OnPress(Control &control);
#endif
public:
  Control *control;

  Button(int width, int height, int x, int y);
};

#endif
