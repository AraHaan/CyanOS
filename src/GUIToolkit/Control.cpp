#include "../../include/GUI/Control.h"

Control::Control(int width, int height, int x, int y)
{
  this.Bounds = new ControlBounds();
  this.Bounds.SetBounds(width, height, x, y);
}

Control::~Control()
{
  // Delete bounds instance created from this class.
  delete[] this.Bounds;
}

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
