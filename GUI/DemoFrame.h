#ifndef DEMOFRAME_H_
#define DEMOFRAME_H_

#include "ButtonPanel.h"

/**
 * The application frame.
 */
class DemoFrame : public wxFrame
{
public:
    /**
     * Constructor.
     * @param title the window title.
     */
    DemoFrame(const wxString& title);

    /**
     * Destructor.
     */
    virtual ~DemoFrame();

    /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
    void on_about(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);

    /**
     * Event handler for the Rounds menu item.
     * @param event the item selection event.
     */
    void on_rounds(wxCommandEvent& event);

    long getRes();
    

private:
    // The event table that maps events to their handlers.
    wxDECLARE_EVENT_TABLE();

    ButtonPanel *button_panel;
    wxString m_Rounds;
    wxButton* m_OK;
    wxButton* m_cancel;
    wxTextCtrl* m_textField;

    /**
     * Initialize the contents of the application frame.
     */
    void init();

    /**
     * Initialize the application frame's menu and status bars.
     */
    void init_menu_bar();

    /**
     * Initialize the application frame's sizer.
     */
    void init_sizer();

    long res;

};

// IDs for the menu commands.
enum
{
    RPS_Quit  = wxID_EXIT,
    RPS_Rounds = wxID_UNDO,
    RPS_About = wxID_ABOUT,
    RPS_OK = wxID_OK,
    RPS_Cancel = wxID_CANCEL
};

#endif /* DEMOFRAME_H_ */
