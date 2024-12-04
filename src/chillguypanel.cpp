#include "chillguypanel.h"

ChillGuyPanel::ChillGuyPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY), image("ChillGuy.png", wxBITMAP_TYPE_PNG)
{
  if (!image.IsOk())
  {
    wxMessageBox(wxT("Could not load image!"), wxT("Error"), wxOK | wxICON_ERROR, this);
  }
  else 
  {
    imageWidth = image.GetWidth();
    imageHeight = image.GetHeight();
    angle = 0;
    isDragging = false;
  }

  SetBackgroundStyle(wxBG_STYLE_PAINT);

  Bind(wxEVT_LEFT_DOWN, &ChillGuyPanel::onMouseLeftDown, this);
  Bind(wxEVT_LEFT_UP, &ChillGuyPanel::onMouseLeftUp, this);
  Bind(wxEVT_MOTION, &ChillGuyPanel::onMouseMove, this);
  Bind(wxEVT_PAINT, &ChillGuyPanel::onPaint, this);
};

void ChillGuyPanel::onMouseLeftDown(wxMouseEvent &event)
{
  lastMousePos = event.GetPosition();
  isDragging = true;
};

void ChillGuyPanel::onMouseLeftUp(wxMouseEvent &event)
{
  isDragging = false;
};

void ChillGuyPanel::onMouseMove(wxMouseEvent &event)
{
  if (isDragging)
  {
    wxPoint currPos = event.GetPosition();
    int dx = currPos.x - lastMousePos.x;
    int dy = currPos.y - lastMousePos.y;

    if (imageWidth > 10)
      imageWidth += dx;
    if (imageHeight > 10)
      imageHeight += dy;

    lastMousePos = currPos;
    Refresh();
  }
};

void ChillGuyPanel::onPaint(wxPaintEvent &event)
{
  wxAutoBufferedPaintDC dc(this);
  dc.Clear();

  wxImage img = image;
  img.Rescale(imageWidth, imageHeight);
  img = img.Rotate(angle, wxPoint(imageWidth / 2, imageHeight / 2));

  wxBitmap bitmap(img);
  dc.DrawBitmap(bitmap, 10, 10);
};
