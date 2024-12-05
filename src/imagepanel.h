#pragma once

#include <wx/wx.h>
#include <wx/dcbuffer.h>

class wxImagePanel : public wxPanel 
{
    bool isDragging = false, isResizing = false;
    int imgX = 0, imgY = 0;
    int imgHeight = 200, imgWidth = 200;
    wxImage image;
    wxPoint dragStartPoint;

public:
    wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
    void onMouseUp(wxMouseEvent& event);
    void onMouseDown(wxMouseEvent& event);
    void onMouseMove(wxMouseEvent& event);
    void onPaint(wxPaintEvent& event);
    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()
};