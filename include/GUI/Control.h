#ifndef CYANYDE_GUI_CONTROL_H
#define CYANYDE_GUI_CONTROL_H

#include "ControlState.h"
#include "ControlBounds.h"

class Control
{
public:
  /* The state of the control (for which to render on the screen on the control bounds).
  ControlState State;
  /* The bounds of the control. */
  ControlBounds Bounds;

  void Control();
  void ~Control();

  /* control Window Procedure. */
  void WndProc();
  void OnDraw();
  void OnPress();
};
#endif
