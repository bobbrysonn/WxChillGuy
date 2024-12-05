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
    isResizing = false;
}

void wxImagePanel::onMouseDown(wxMouseEvent &event)
{
    dragStartPoint = event.GetPosition();

    // Check if the mouse is within the image
    if (dragStartPoint.x > imgX && dragStartPoint.x < imgX + imgWidth && dragStartPoint.y > imgY && dragStartPoint.y < imgY + imgHeight)
    {
        isDragging = true;
    }
    // If mouse is outside image resize
    else
    {
        isResizing = true;
    }
}

void wxImagePanel::onMouseMove(wxMouseEvent &event)
{
    wxPoint currentPoint = event.GetPosition();
    if (isResizing)
    {
        int dx = currentPoint.x - dragStartPoint.x;
        int dy = currentPoint.y - dragStartPoint.y;

        imgWidth += dx;
        imgHeight += dy;

        dragStartPoint = currentPoint;

        Refresh();
    }
    else if (isDragging)
    {
        int dx = currentPoint.x - dragStartPoint.x;
        int dy = currentPoint.y - dragStartPoint.y;

        imgX += dx;
        imgY += dy;

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
   
    dc.DrawBitmap(bitmap, imgX, imgY);
}

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::onMouseDown)
    EVT_LEFT_UP(wxImagePanel::onMouseUp)
    EVT_MOTION(wxImagePanel::onMouseMove)
    EVT_PAINT(wxImagePanel::onPaint)
END_EVENT_TABLE()