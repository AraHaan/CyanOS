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
  if (this.Hovered)
  {
    // TODO: Render Hovered state and maybe deploy a callback (event)?
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
