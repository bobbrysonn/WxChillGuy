#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame();
};

MyFrame::MyFrame() 
    : wxFrame(NULL, wxID_ANY, "Hello World", wxDefaultPosition, wxSize(450, 350)) {
    // Optional: Add some content to the frame
    wxStaticText* text = new wxStaticText(this, wxID_ANY, "Hello, wxWidgets!", 
                                          wxPoint(10, 10), wxDefaultSize);
}

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);