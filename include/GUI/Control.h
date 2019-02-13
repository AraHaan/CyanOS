#ifndef CYANOS_GUI_CONTROL_H
#define CYANOS_GUI_CONTROL_H

#include "ControlState.h"
#include "ControlBounds.h"

// Control base class.
class Control
{
public:
  /* The state of the control (for which to render on the screen on the control bounds). */
  ControlState State;
  /* The previous state of the control (only used when State is set to invisible).
  ControlState PrevState;
  /* The bounds of the control. */
  ControlBounds Bounds;

  typedef void (__stdcall WndProcPtr*)(Control *control);

  /* Changes the visubility of the control to invisible if it is visible. If not then makes it visible again at the previous state. */
  void ChangeVisibility();

  Control(int width, int height, int x, int y);
  ~Control();

  /* control Window Procedure. */
  void WndProc();
};
#endif
