#include <wx/filepicker.h>
#include <fstream>
#include <string>
#include <thread>

//#include "memHeader.h"

#include "Characters.h"
#include "MainFrame.h"
#include "OtherStuff.h"
#include "Defines.h"
#include "Randomize.h"

bool character = 0;
bool extog = 0;
bool greenVeh = 0;

bool extra = 0;
bool collectable = 0;
bool enemy = 0;
bool colorOp = 0;
bool advanceMus = 0;
std::string out = "out";
std::string vanillaDirectory = "";
LogicType logicType = casual;

wxStaticText* directoryLabel;
wxDirPickerCtrl* tcsFolder;
wxButton* start;
wxRadioBox* logType;
wxCheckBox* characterType;
wxCheckBox* etType;
wxCheckBox* greenType;
wxCheckBox* extraType;
wxCheckBox* collectableType;
wxCheckBox* colorType;


MainFrame::MainFrame(const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);

	wxArrayString logOpt;
	logOpt.Add("Casual");
	logOpt.Add("Glitched");
	logOpt.Add("Super Glitched");

	directoryLabel = new wxStaticText(panel, wxID_ANY, "Unmoddified TCS Directory:", wxPoint(45, 10));
	tcsFolder = new wxDirPickerCtrl(panel, wxID_ANY, wxEmptyString, "Game Files", wxPoint(40, 25), wxSize(300, 25));

	start = new wxButton(panel, wxID_ANY, "Randomize", wxPoint(100, 225), wxSize(200, 50));

	logType = new wxRadioBox(panel, wxID_ANY, "Logic", wxPoint(45, 60), wxDefaultSize, logOpt, 1);

	characterType = new wxCheckBox(panel, wxID_ANY, "Randomize Characters", wxPoint(165, 60));
	etType = new wxCheckBox(panel, wxID_ANY, "Include Extra Toggle Characters", wxPoint(185, 80));
	greenType = new wxCheckBox(panel, wxID_ANY, "Include Green Vehicles", wxPoint(185, 100));

	extraType = new wxCheckBox(panel, wxID_ANY, "Randomize Extras", wxPoint(165, 120));
	collectableType = new wxCheckBox(panel, wxID_ANY, "Randomize Collectables", wxPoint(165, 140));
	//colorType = new wxCheckBox(panel, wxID_ANY, "Randomize Colors", wxPoint(165, 160));

	//loads save data
	std::ifstream saver("files/data");
	if (saver.good()) {
		std::string savedat;
		getline(saver, savedat);
		tcsFolder->SetPath(savedat);

		getline(saver, savedat);
		logType->SetSelection(savedat[0] - 48);
		characterType->SetValue(savedat[1] - 48);
		etType->SetValue(savedat[2] - 48);
		greenType->SetValue(savedat[3] - 48);
		extraType->SetValue(savedat[4] - 48);
		collectableType->SetValue(savedat[5] - 48);
		//colorType->SetValue(savedat[6] - 48);

		saver.close();
	}

	start->Bind(wxEVT_BUTTON, &MainFrame::StartRando, this);

	CreateStatusBar();
}



void MainFrame::StartRando(wxCommandEvent& evt) {
	wxLogStatus("Randomizing. . .");

	character = characterType->GetValue();
	extog = etType->GetValue();
	greenVeh = greenType->GetValue();
	extra = extraType->GetValue();
	collectable = collectableType->GetValue();
	vanillaDirectory = tcsFolder->GetPath();
	//colorOp = colorType->GetValue();

	switch (logType->GetSelection()) {
	case 0:
		logicType = casual;
		break;
	case 1:
		logicType = glitched;
		break;
	case 2:
		logicType = superGlitched;
		break;
	}

	//saves options
	std::remove("files/data");
	std::ofstream dat("files/data");
	dat << vanillaDirectory << '\n';
	dat << std::to_string(logicType);
	dat << std::to_string(character);
	dat << std::to_string(extog);
	dat << std::to_string(greenVeh);

	dat << std::to_string(extra);
	dat << std::to_string(collectable);
	dat << std::to_string(colorOp);

	dat.close();

	Randomize();
	//std::thread randomize{ Randomize };
	//randomize.detach();
}


