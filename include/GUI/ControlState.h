#ifndef CYANOS_GUI_CONTROLSTATE_H
#define CYANOS_GUI_CONTROLSTATE_H

enum ControlState
{
  Enabled = 0,
  Hovered = 1,
  Pressed = 2,
  /* Only for implementing a 3 state radio button if the button is desired to have 3 states. */
  PartialyPressed = 3,
  Disabled = 4,
  /* For when the system allows touch screen inputs. */
  Touched = 5,
  Scrolling = 6,
  Dragging = 7,
  /* When the control's state is set to checked. */
  Checked = 8,
  /* When the control's state is set to invisible. */
  Invisible = 9,
};

#endif
