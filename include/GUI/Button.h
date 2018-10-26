/*
 * Cyanyde OS GUI Toolkit.
 * Include file for the button control class.
 */
#ifndef CYANYDE_GUI_BUTTON
#define CYANYDE_GUI_BUTTON

class Button
{
public:
  /* controls state images. */
  bool Hovered;
  bool Pressed;
  bool Enabled;

  /* control Window Procedure. */
  void WndProc();
  void Button();
  void ~Button();
};

#endif
