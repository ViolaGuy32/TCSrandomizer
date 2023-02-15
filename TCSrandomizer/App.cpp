#include "pch.h"
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* frame = new MainFrame("TCS Randomizer 1.4");
	frame->SetClientSize(400, 300);
	frame->Center();
	frame->Show();
	return true;
}