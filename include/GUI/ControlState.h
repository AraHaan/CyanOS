#ifndef CYANYDE_GUI_CONTROLSTATE_H
#define CYANYDE_GUI_CONTROLSTATE_H

enum ControlState
{
  Enabled = 0;
  Hovered = 1;
  Pressed = 2;
  /* Only for implementing a 3 state radio button if the button is desired to have 3 states. */
  PartialyPressed = 3;
  Disabled = 4;
};

#endif
