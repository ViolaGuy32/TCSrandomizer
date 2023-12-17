#include "pch.h"
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* frame = new MainFrame("TCS Randomizer 1.5");
	frame->SetClientSize(400, 300);
	frame->Center();
	frame->Show();
	return true;
}