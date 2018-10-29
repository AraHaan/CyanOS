#include "../../include/GUI/Control.h"

Control::ChangeVisibility()
{
  if (this.State != ControlState.Invisible)
  {
    this.PrevState = this.State;
    this.State = ControlState.Invisible;
  }
  else
  {
    this.State = this.PrevState;
    this.PrevState = nullptr;
  }
}

Control::WndProc()
{
  # call the wndproc pointer of the control using the instance of the control.
  this.WndProcPtr(&this);
}
