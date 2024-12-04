#include <wx/wx.h>

class WxChillGuyApp : public wxApp
{
public:
  virtual bool OnInit ();
};

class WxChillGuyFrame : public wxFrame
{
public:
  WxChillGuyFrame (const wxString &title, const wxSize &size);

private:
  void OnAbout (wxCommandEvent &event);
  void OnExit (wxCommandEvent &event);
};