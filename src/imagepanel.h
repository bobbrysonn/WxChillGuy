#pragma once

#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class wxImagePanel : public wxPanel 
{
    bool isDragging = false, isResizing = false;
    int imgX = 100, imgY = 100;
    int imgHeight = 200, imgWidth = 200;
    int height = 600, width = 600, orginX, orginY;
    int prevWindowWidth, prevWindowHeight;
    wxImage image;
    wxPoint dragStartPoint;

public:
    wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
    void onMouseUp(wxMouseEvent& event);
    void onMouseDown(wxMouseEvent& event);
    void onMouseMove(wxMouseEvent& event);
    void onPaint(wxPaintEvent& event);
    void onSize(wxSizeEvent& event);
    void render(wxGraphicsContext& gc);

    DECLARE_EVENT_TABLE()
};