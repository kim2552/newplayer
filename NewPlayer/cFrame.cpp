#include "cFrame.h"

// Bind controls to callback functions
wxBEGIN_EVENT_TABLE(cFrame, wxFrame)
	EVT_MENU(ID_FILE, cFrame::NewVideoCallback)
wxEND_EVENT_TABLE()

cFrame::cFrame(wxString title, wxPoint point, wxSize size) : 
	wxFrame(nullptr, wxID_ANY, title, point, size)
{
	// New file menu
	m_menufile = new wxMenu;
	m_menufile->Append(ID_FILE, "New Video");

	// Menu bar
	m_menubar = new wxMenuBar;
	m_menubar->Append(m_menufile, "File");
	SetMenuBar(m_menubar);
	
	//Load media into controller
	m_panel = new cPanel(this);
}

cFrame::~cFrame()
{

}

void cFrame::NewVideoCallback(wxCommandEvent& event)
{
	const wxString& VIDEO_PATH = "C:/Users/jooho/Downloads/test_video_new.mp4";

	//TODO:: load video file here.
	cVideoProccess* vidproc = new cVideoProccess();
	vidproc->ProcessVideo();

	bool bOK = m_panel->m_mediactrl->Load(VIDEO_PATH);
	wxASSERT_MSG(bOK, "Could not load media file!");
	wxUnusedVar(bOK);
}