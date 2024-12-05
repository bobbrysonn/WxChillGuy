#pragma once

#include <wx/wx.h>
#include "main.h"
#include "chillguypanel.h"
#include "imagepanel.h"

class WxChillGuyApp : public wxApp
{
private:
    wxFrame* frame;
    wxImagePanel* panel; 
public:
    virtual bool OnInit ();
};

class wxChillGuyFrame : public wxFrame
{
public:
    wxChillGuyFrame (const wxString &title, const wxSize &size);

private:
    void OnAbout (wxCommandEvent &event);
    void OnExit (wxCommandEvent &event);
};