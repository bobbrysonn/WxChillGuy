#include "chillguypanel.h"

ChillGuyPanel::ChillGuyPanel(wxWindow *parent) : wxPanel(parent)
{
    Bind(wxEVT_LEFT_DOWN, &ChillGuyPanel::onMouseLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ChillGuyPanel::onMouseLeftUp, this);
    Bind(wxEVT_MOTION, &ChillGuyPanel::onMouseMove, this);
    Bind(wxEVT_PAINT, &ChillGuyPanel::onPaint, this);
};

void ChillGuyPanel::onMouseLeftDown(wxMouseEvent &event)
{
};

void ChillGuyPanel::onMouseLeftUp(wxMouseEvent &event)
{
};

void ChillGuyPanel::onMouseMove(wxMouseEvent &event)
{
};

void ChillGuyPanel::onPaint(wxPaintEvent &event)
{
};
