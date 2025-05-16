#include "pch.h"
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* frame = new MainFrame("TCS Randomizer 1.6");
	frame->SetClientSize(400, 320);
	frame->Center();
	frame->Show();
	return true;
}
