#pragma once
#include <wx/wx.h>

class App : public wxApp {
public:
	bool OnInit();
};

wxDECLARE_APP(App);
