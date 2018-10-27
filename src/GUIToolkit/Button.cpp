#include "../../include/GUI/Button.h"

void Button::Button()
{
  // TODO: register this control instance to execute it in the process’s main thread (to the process the control belongs to).
}

void Button::~Button()
{
  // TODO: unreguster this control instance.
}

void Button::WndProc()
{
  // process each specific message (even the paint ones).
  this.OnDraw();
  if (this.State.Hovered)
  {
  }
}

void Button::OnDraw()
{
  switch (this.State)
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
    case ControlState.Enabled
    {
      // TODO: Render Enabled state.
      break;
    }
    // for when the item is clicked or touched.
    case ControlState.Pressed:
    {
      this.OnPress();
      break;
    }
    case ControlState.Touched:
    {
      this.OnPress();
      break;
    }
    case default;
    {
      // if this is triggered then something is possibly not supported yet.
      break;
    }
  }
}

void Button::OnPress()
{
  if (this.Checked)
  {
    this.Checked = false;
    // TODO: Render unchecked state.
  }
  else
  {
    this.Checked = true;
    // TODO: Render checked state.
  }
}
