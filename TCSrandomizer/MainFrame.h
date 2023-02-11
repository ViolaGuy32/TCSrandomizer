#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	void StartRando(wxCommandEvent& evt);
};

