#include "imagepanel.h"

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) : wxPanel(parent)
{
    image.LoadFile(file, format);
    dragStartPoint = wxDefaultPosition;

    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void wxImagePanel::onMouseUp(wxMouseEvent &event)
{
    
    isDragging = false;
}

void wxImagePanel::onMouseDown(wxMouseEvent &event)
{
    dragStartPoint = event.GetPosition();
    isDragging = true;
}

void wxImagePanel::onMouseMove(wxMouseEvent &event)
{
    wxPoint currentPoint = event.GetPosition();
    if (isDragging)
    {
        int dx = currentPoint.x - dragStartPoint.x;
        int dy = currentPoint.y - dragStartPoint.y;

        imgWidth += dx;
        imgHeight += dy;

        dragStartPoint = currentPoint;

        Refresh();
    }
}

void wxImagePanel::onPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC& dc)
{
    dc.Clear();

    wxImage img = image;
    img.Rescale(imgWidth, imgHeight);

    wxBitmap bitmap(img);
   
    dc.DrawBitmap(bitmap, 0, 0);
}

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::onMouseDown)
    EVT_LEFT_UP(wxImagePanel::onMouseUp)
    EVT_MOTION(wxImagePanel::onMouseMove)
    EVT_PAINT(wxImagePanel::onPaint)
END_EVENT_TABLE()