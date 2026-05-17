
//#include "memHeader.h"
#include "pch.h"

#include "Characters.h"
#include "Defines.h"
#include "MainFrame.h"
#include "OtherStuff.h"
#include "Randomize.h"

bool character = 0;
bool extog = 0;
bool greenVeh = 0;
bool unusedChar = 0;
bool bdOp = 0;

bool extra = 0;
bool collectable = 0;
bool enemy = 0;
bool panelOp = 0;
bool hatOp = 0;
bool colorOp = 0;
//bool enemyOp = 0;
std::string out = "out";
std::string vanillaDirectory = "";
LogicType logicType = casual;

wxStaticText* directoryLabel;
wxStaticText* seedLabel;
wxDirPickerCtrl* tcsFolder;
wxTextCtrl* seedSet;
wxButton* start;
wxRadioBox* logType;
wxCheckBox* characterType;
wxCheckBox* etType;
wxCheckBox* greenType;
wxCheckBox* bdType;
wxCheckBox* unusedType;

wxCheckBox* extraType;
wxCheckBox* collectableType;
wxCheckBox* panelOpType;
wxCheckBox* hatOpType;
uint32_t seed = 0;

std::mt19937* randoPTR;

//wxCheckBox* enemyOpType;

//wxCheckBox* colorType;

//std::unique_ptr<std::ofstream> loggingIt;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);

	wxArrayString logOpt;
	logOpt.Add("Casual");
	logOpt.Add("Glitched");
	logOpt.Add("Super Glitched");

	//wxTextValidator valid("abcdefABCDEF1234567890");
	wxTextValidator valid(wxFILTER_NUMERIC);

	directoryLabel = new wxStaticText(
		panel, wxID_ANY, "Unmoddified TCS Directory with GOG exe:", wxPoint(45, 10));
	tcsFolder = new wxDirPickerCtrl(
		panel, wxID_ANY, wxEmptyString, "Game Files", wxPoint(40, 25), wxSize(300, 25));

	seedLabel =
		new wxStaticText(panel, wxID_ANY, "Seed (leave blank for random seed):", wxPoint(45, 60));
	seedSet = new wxTextCtrl(
		panel, wxID_ANY, "", wxPoint(40, 75), wxSize(300, 25), 0, wxTextValidator(valid));

	start = new wxButton(panel, wxID_ANY, "Randomize", wxPoint(100, 280), wxSize(200, 50));

	logType = new wxRadioBox(panel, wxID_ANY, "Logic", wxPoint(45, 110), wxDefaultSize, logOpt, 1);

	characterType = new wxCheckBox(panel, wxID_ANY, "Randomize Characters", wxPoint(165, 110));
	etType = new wxCheckBox(panel, wxID_ANY, "Include Extra Toggle Characters", wxPoint(185, 130));
	greenType = new wxCheckBox(panel, wxID_ANY, "Include Green Vehicles", wxPoint(185, 150));
	bdType = new wxCheckBox(panel, wxID_ANY, "Exclude IG-88 and 4-LOM", wxPoint(185, 170));
	//unusedType = new wxCheckBox(panel, wxID_ANY, "Include Unused Characters", wxPoint(185, 170));

	//enemyOpType = new wxCheckBox(panel, wxID_ANY, "Randomize Enemies", wxPoint(165, 120));
	extraType = new wxCheckBox(panel, wxID_ANY, "Randomize Extras", wxPoint(165, 190));
	collectableType = new wxCheckBox(panel, wxID_ANY, "Randomize Collectables", wxPoint(165, 210));
	panelOpType = new wxCheckBox(panel, wxID_ANY, "Randomize Panels", wxPoint(165, 230));
	hatOpType = new wxCheckBox(panel, wxID_ANY, "Randomize Hat Machines", wxPoint(165, 250));
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
		bdType->SetValue(savedat[4] - 48);
		extraType->SetValue(savedat[5] - 48);
		collectableType->SetValue(savedat[6] - 48);
		panelOpType->SetValue(savedat[7] - 48);
		hatOpType->SetValue(savedat[8] - 48);
		//unusedType->SetValue(savedat[8] - 48);
		//enemyOpType->SetValue(savedat[8] - 48);
		//colorType->SetValue(savedat[6] - 48);

		saver.close();
	}

	start->Bind(wxEVT_BUTTON, &MainFrame::StartRando, this);

	CreateStatusBar();
}

void MainFrame::StartRando(wxCommandEvent& evt) {

	vanillaDirectory = tcsFolder->GetPath();

	if (vanillaEXE(0x40, vanillaDirectory + "\\LEGOStarWarsSaga.exe") != 0x0e) {
		wxLogStatus("You need the GOG exe.");
		return;
	}

	std::remove("files/log.txt");
	std::remove("files/log2.txt");
	//loggingIt = std::make_unique<std::ofstream>("files/log.txt");

	character = characterType->GetValue();
	extog = etType->GetValue();
	greenVeh = greenType->GetValue();
	bdOp = bdType->GetValue();
	//unusedChar = unusedType->GetValue();
	//enemyOp = enemyOpType->GetValue();
	extra = extraType->GetValue();
	collectable = collectableType->GetValue();
	panelOp = panelOpType->GetValue();
	hatOp = hatOpType->GetValue();
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
	dat << std::to_string(panelOp);
	dat << std::to_string(hatOp);
	//dat << std::to_string(enemyOp);
	//dat << std::to_string(colorOp);

	dat.close();

	/*out = "out1";
	Randomize();

	out = "out2";
	Randomize();

	out = "out3";
	Randomize();

	out = "out4";
	Randomize();

	out = "out5";
	Randomize();

	out = "out6";*/

	if (seedSet->GetValue() == "") {

		//do {
		std::random_device rd;
		seed = rd();
		//} while (seed >= std::numeric_limits<int32_t>::max()); //wxAtoi thinks that seed is
		//signed, so I need a seed in the bottom half of numbers.

		std::string temp1 = std::to_string(seed);
		wxString temp2(temp1);
		//temp2 << seed;
		seedSet->SetValue(temp2);
	}

	//seed = seedSet->GetValue().c_str();

	wxString temp3 = seedSet->GetValue();
	//std::string temp4 = wxString::ToStdString(temp3);
	std::string temp4 = std::string(temp3.mb_str());
	seed = std::stoul(temp4);
	//seed = wxAtoi(seedSet->GetValue()); //wxAtoi doesn't work.

	//if (seed >= std::numeric_limits<int32_t>::max()) {
	//	wxLogStatus("Seed out of range.");
	//	return;
	//}

	Update();

	std::mt19937 rando(seed);
	randoPTR = &rando;

	logR("\n\t\t\t\t\tRandomizing. . .");
	wxLogStatus("Randomizing. . .");
	Randomize(rando);

	//std::thread randomize{ Randomize };
	//randomize.detach();
}
