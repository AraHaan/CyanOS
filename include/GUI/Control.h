#ifndef CYANYDE_GUI_CONTROL_H
#define CYANYDE_GUI_CONTROL_H

#include "ControlState.h"
#include "ControlBounds.h"

// Control base class.
class Control
{
public:
  /* The state of the control (for which to render on the screen on the control bounds).
  ControlState State;
  /* The bounds of the control. */
  ControlBounds Bounds;

  typedef void (__stdcall WndProcPtr*)(Control *control);

  void Control(int width, int height, int x, int y);
  void ~Control();

  /* control Window Procedure. */
  void WndProc();
};
#endif
