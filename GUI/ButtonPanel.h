#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "ButtonDemo.h"
#include <iostream>
#include <stdio.h>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameInstance.h"
#include <string>
#include <fstream>
#include "Choice.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        // Luke mod
        // myPlayer = new HumanPlayer();
        // cpu = new ComputerPlayer('r');
        game = new GameInstance();
        getPattern = "";
        init();
    }

    std::string getPattern;

    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);

private:
    wxStaticText *button_chosen_text;
    // HumanPlayer *myPlayer;
    // ComputerPlayer *cpu;
    GameInstance *game;

    /**
     * Initialize the panel contents.
     */
    void init();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);
};

#endif /* BUTTONPANEL_H_ */
