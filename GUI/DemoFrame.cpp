#include "DemoFrame.h"
#include <wx/numdlg.h>

// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_Rounds, DemoFrame::on_rounds)
    EVT_BUTTON(RPS_OK, DemoFrame::on_rounds)
    EVT_BUTTON(RPS_Cancel, DemoFrame::on_rounds)
wxEND_EVENT_TABLE()

const int SIDE_MARGINS = 40;

DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      button_panel(new ButtonPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

DemoFrame::~DemoFrame()
{
    delete button_panel;
}

void DemoFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_Quit,  "&Exit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");

    wxMenu *settingsMenu = new wxMenu;
    settingsMenu->Append(RPS_Rounds,  "&Rounds\tAlt-R", "Select number of rounds");



    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    menuBar->Append(settingsMenu, "&Settings");
    SetMenuBar(menuBar);
}

void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a button demo\n"
                    "built with %s\n"
                    "and running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                ),
                "About the button demo",
                wxOK | wxICON_INFORMATION,
                this);
}

void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

void DemoFrame::on_rounds(wxCommandEvent& event)
{

	    res = wxGetNumberFromUser( wxT("Please enter how many rounds you would like to play.\n")
                                    wxT("Enter a number from 1 to 100."),
                                    wxT("Enter a number:"), wxT("Number of rounds"),
                                     20, 1, 100, this ); //creates window + textbox + text for user to enter value

    wxString msg;
    if ( res == -1 ) //result if user presses cancel or enters value outside the range
    {
        msg = wxT("Invalid number entered or dialog cancelled.");     
    }
    else //result if value entered is valid
    {
        msg.Printf(wxT("You've entered %lu"), res );
    }

	//verification pop-up + OK button
	wxMessageBox(msg, wxT("Number of rounds"), wxOK | wxICON_INFORMATION, this);

}

long getRes()
{
    return res;
}
