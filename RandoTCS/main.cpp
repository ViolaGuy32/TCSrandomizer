
#include "Defines.h"
#include "MyForm.h"
#include "pch.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] void main(array<String ^> ^ args) {
	std::ifstream saver("files/data");
	if (saver.good()) {
		std::string savedat;
		getline(saver, savedat);
		vanillaDirectory = savedat;

		getline(saver, savedat);
		logicType = (LogicType)(savedat[0] - 48);
		character = savedat[1] - 48;
		extog = savedat[2] - 48;
		greenVeh = savedat[3] - 48;
		extra = savedat[4] - 48;
		collectable = savedat[5] - 48;
		panelOp = savedat[6] - 48;
		hatOp = savedat[7] - 48;
	}
	saver.close();

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	RandoTCS::MyForm frm;

	Application::Run(% frm);
}

int mainDebug() {
	collectable = true;
	character = true;
	extog = true;
	greenVeh = true;

	extra = true;
	panelOp = true;
	hatOp = true;

	colorOp = false;
	enemyOp = false;
	//enemy = true;
	Randomize();

	return 0;
}
