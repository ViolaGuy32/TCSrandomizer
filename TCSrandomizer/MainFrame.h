#pragma once
#include "pch.h"

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);


	void StartRando(wxCommandEvent& evt);

};

