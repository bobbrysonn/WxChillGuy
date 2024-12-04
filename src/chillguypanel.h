#include <wx/wx.h>

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