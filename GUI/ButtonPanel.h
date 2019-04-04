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
        round_count = 1;
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
    wxStaticText *winner_text;
    wxStaticText *round_counter_text;
    wxStaticText *dummy_text;
    wxStaticText *ties_text;
    wxStaticText *computerWins_text;
    wxStaticText *humanWins_text;
    int round_count;
    GameInstance *game;

    /**
     * Initialize the panel contents.
     */
    void init();
    void winnerInit();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);

    void update_round_counter_text(int round_count);
    void update_stats_text(char wtl);
};

#endif /* BUTTONPANEL_H_ */
