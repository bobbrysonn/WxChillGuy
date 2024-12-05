#pragma once

#include <wx/wx.h>
#include <wx/dcbuffer.h>

class ChillGuyPanel : public wxPanel
{
public:
    ChillGuyPanel(wxWindow* parent);
    void onMouseLeftDown(wxMouseEvent& event);
    void onMouseLeftUp(wxMouseEvent& event);
    void onMouseMove(wxMouseEvent& event);
    void onPaint(wxPaintEvent& event);

private:
    bool isDragging;
    double angle;
    int imageHeight, imageWidth;
    wxImage image;
    wxPoint lastMousePos;
};