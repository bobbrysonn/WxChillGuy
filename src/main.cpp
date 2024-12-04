#include "main.h"
#include "chillguypanel.h"

bool WxChillGuyApp::OnInit()
{
    WxChillGuyFrame* frame = new WxChillGuyFrame(wxT("Chill Guy"), wxSize(800, 600));
    
    frame->Show(true);

    return true;
}

WxChillGuyFrame::WxChillGuyFrame(const wxString& title, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
    // Create an exit menu item
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT, wxT("E&xit\tAlt-D"), wxT("Quit being a chill guy"));
    // Create a help menu item
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, wxT("&About\tF1"), wxT("Much chill"));

    // Create a menu bar
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, wxT("&File"));
    menuBar->Append(menuHelp, wxT("&Help"));
    // Set the menu bar
    SetMenuBar(menuBar);

    // Create a status bar
    CreateStatusBar();

    wxImage::AddHandler(new wxPNGHandler);
    wxImage image(wxGetCwd() + "\\ChillGuy.png", wxBITMAP_TYPE_PNG);
    if (!image.IsOk())
    {
        wxMessageBox(wxT("Could not load image!"), wxT("Error"), wxOK | wxICON_ERROR, this);
    }
    else
    {
        wxBitmap bitmap(image);
        wxStaticBitmap* staticBitmap = new wxStaticBitmap(this, wxID_ANY, bitmap);
    }


    // Bind the menu items to their respective functions
    Bind(wxEVT_MENU, &WxChillGuyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &WxChillGuyFrame::OnExit, this, wxID_EXIT);
}

void WxChillGuyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(wxT("This is a chill guy!"), wxT("About"), wxOK | wxICON_INFORMATION, this);
}

void WxChillGuyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

// Implement app
wxIMPLEMENT_APP(WxChillGuyApp);