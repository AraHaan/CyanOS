#ifndef CYANYDE_GUI_CONTROLBOUNDS_H
#define CYANYDE_GUI_CONTROLBOUNDS_H

class ControlBounds
{
private:
  int X;
  int Y;
  int Width;
  int Height;
public:
  void ControlBounds();
  void ~ControlBounds();
  /* Sets the bounds of the control (for which to render on the screen relative to the parrent control). */
  void SetBounds(int width, int height, int x, int y);

  int GetXCordinate();
  int GetYCordinate();
  int GetWidth();
  int GetHeight();
};

#endif
