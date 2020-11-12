#include "MyGUIApp.h"
#include "hw8.sea.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include<wx/wx.h>
#endif
class MyApp: public wxApp{
	public:
		virtual bool OnInit();
};

bool MyApp::OnInit(){
	MyFrame1 *frame = new MyFrame1(NULL, NULL, "Hello World", wxPoint(50,50), wxSize(450, 340), wxDEFAULT_FRAME_STYLE);
	frame->Show(true);
	return true;
}

void MyFrame1::OnSimulateOneStep( wxCommandEvent& event ){
	int nsharks, nfish;
	Sea S;
	S.SimulateOneStep();
    S.PopulationCensus(nsharks, nfish);
	char buffer[50];
	sprintf (buffer, "There are %d sharks and %d fish ", nsharks, nfish);
	wxLogMessage(buffer);
}


enum{
	ID_OnSimulateOneStep = 1
};

wxBEGIN_EVENT_TABLE(MyFrame1, wxFrame)
	EVT_MENU(ID_OnSimulateOneStep, MyFrame1::OnSimulateOneStep)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

void MyFrame1::OnSimulateNSteps( wxCommandEvent& event ){
	int nsharks, nfish;
	Sea S;
	wxString str = this->m_textCtrl1->GetValue();
	int N = wxAtoi(str);
	for(int i = 0; i < N; i++){
		S.SimulateOneStep();
    	S.PopulationCensus(nsharks, nfish);
	}
	char buffer[50];
	sprintf (buffer, "There are %d sharks and %d fish ", nsharks, nfish);
	wxLogMessage(buffer);
}


MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Simulate One Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
	gbSizer1->Add( m_button1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_textCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
	gbSizer1->Add( m_textCtrl1, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Simulate N Steps"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
	gbSizer1->Add( m_button2, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );


	this->SetSizer( gbSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSimulateOneStep ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSimulateNSteps ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSimulateOneStep ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSimulateNSteps ), NULL, this );

}
