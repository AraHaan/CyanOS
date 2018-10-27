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
  if (this.Hovered)
  {
  }
}

void Button::OnDraw()
{
  if (this.Hovered)
  {
    // TODO: Render Hovered state.
  }
  if (!this.Enabled)
  {
    // TODO: Render Disabled state.
  }
  else
  {
    // TODO: Render Enabled state.
  }
}
