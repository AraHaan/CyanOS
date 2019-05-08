#define GUI_TOOLKIT_BUILD
#include "../../include/GUI/Button.h"

// TODO: Make x and y be based upon the client area of a Window.
Button::Button(int width, int height, int x, int y)
{
  // initialize the members using the base constructor.
  this->control = new Control(width, height, x, y);

  this->control->WndProcPtr = this->WndProc;
}

void Button::WndProc(Control &control)
{
  // process each specific message (even the paint ones).
  this->OnDraw(control);
  // TODO: Call out user added events here.
  switch (control.State)
  {
    case ControlState::Hovered:
    {
      break;
    }
    case ControlState::Pressed:
    {
      break;
    }
    case ControlState::Touched:
    {
      break;
    }
  }
}

void Button::OnDraw(Control &control)
{
  switch (control.State)
  {
    case ControlState::Hovered:
    {
      // TODO: Render Hovered state.
      break;
    }
    case ControlState::Disabled:
    {
      // TODO: Render Disabled state.
      break;
    }
    case ControlState::Enabled:
    {
      // TODO: Render Enabled state.
      break;
    }
    // for when the item is clicked or touched.
    case ControlState::Pressed:
    {
      this->OnPress(control);
      break;
    }
    case ControlState::Touched:
    {
      this->OnPress(control);
      break;
    }
    case ControlState::Invisible:
    {
      // render what is under the control now (hiding the control from sight).
      break;
    }
//    case default:
//    {
//      // if this is triggered then something is possibly not supported yet.
//      break;
//    }
  }
}

// No need to recall WndProc here. The system will do it instead.
void Button::OnPress(Control &control)
{
  // TODO: Do not reset this unless the mouse or touch input stops (finger is lifted or from some hardware issue).
  if (control.State == ControlState::Pressed)
  {
    control.State = ControlState::Enabled;
  }
}
