#include "main.h"

bool WxChillGuyApp::OnInit()
{
    // Else image won't load
    wxInitAllImageHandlers();

    frame = new wxChillGuyFrame(wxT("Chill Guy"), wxSize(800, 800));
    frame->SetMinSize(wxSize(800, 800));
    
    panel = new wxImagePanel(frame, "ChillGuy.png", wxBITMAP_TYPE_PNG);
    panel->SetSize(200, 200);

    frame->Show(true);

    return true;
}

wxChillGuyFrame::wxChillGuyFrame(const wxString& title, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
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
    SetStatusText(wxT("Chilling"));

    // Bind the menu items to their respective functions
    Bind(wxEVT_MENU, &wxChillGuyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &wxChillGuyFrame::OnExit, this, wxID_EXIT);
}

void wxChillGuyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(wxT("This is a chill guy!"), wxT("About"), wxOK | wxICON_INFORMATION, this);
}

void wxChillGuyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

// Implement app
wxIMPLEMENT_APP(WxChillGuyApp);
