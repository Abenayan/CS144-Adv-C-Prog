#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
#include "hw8.sea.h"

class MyFrame1 : public wxFrame
{
	private:
		void OnSimulateOneStep( wxCommandEvent& event );
		wxDECLARE_EVENT_TABLE();
		void OnSimulateNSteps( wxCommandEvent& event ); 

	protected:
		wxButton* m_button1;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button2;
		
	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

