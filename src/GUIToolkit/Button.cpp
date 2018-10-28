#include "../../include/GUI/Button.h"

void Button::Button(int width, int height, int x, int y)
{
  this.Bounds = new ControlBounds();
  this.Bounds.SetBounds(width, height, x, y);
  this.WndProcPtr = WndProc;
}

void Button::~Button()
{
  // Delete bounds instance created from this class.
  delete[] this.Bounds;
}

private void WndProc(Control *control)
{
  // process each specific message (even the paint ones).
  OnDraw(control);
  // TODO: Call out user added events here.
  switch (control.State)
  {
    case ControlState.Hovered:
    {
      break;
    }
    case ControlState.Pressed:
    {
      break;
    }
    case ControlState.Touched:
    {
      break;
    }
  }
}

private void OnDraw(Control *control)
{
  switch (control.State)
  {
    case ControlState.Hovered:
    {
      // TODO: Render Hovered state.
      break;
    }
    case ControlState.Disabled:
    {
      // TODO: Render Disabled state.
      break;
    }
    case ControlState.Enabled:
    {
      // TODO: Render Enabled state.
      break;
    }
    // for when the item is clicked or touched.
    case ControlState.Pressed:
    {
      OnPress(control);
      break;
    }
    case ControlState.Touched:
    {
      OnPress(control);
      break;
    }
    case default;
    {
      // if this is triggered then something is possibly not supported yet.
      break;
    }
  }
}

// No need to recall WndProc here. The system will do it instead.
private void OnPress(Control *control)
{
  // TODO: Do not reset this unless the mouse or touch input stops (finger is lifted or from some hardware issue).
  if (control.State == ControlState.Pressed)
  {
    control.State = ControlState.Enabled;
  }
}
