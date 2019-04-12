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

/*
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /*
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
        round_count = 1;
        roundMax = 20;
        game = new GameInstance();
        getPattern = "";
        playerChar = '\0';
    }

    std::string getPattern;
    char playerChar;
    void on_ML(wxCommandEvent& event);
    void on_rand(wxCommandEvent& event);

    // Luke
    void setRoundMax(int max)   { roundMax = max; }
    int getRoundMax()           { return roundMax; }
    

    /*
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /*
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /*
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);

private:
    // facilitates closing the chooser panel window after a chooser is selected
    wxPanel *chooser_panel;
    wxSizer *chooser_sizer;
    wxStaticText *chooser_text;
    wxButton *ML_button;
    wxButton *rand_button;

    // necessary to show these panels again after chooser is selected
    wxPanel *button_panel;
    wxPanel *chosen_panel;
    wxPanel *computer_panel;
    wxPanel *winner_panel;
    wxPanel *stats_panel;

    // texts
    wxStaticText *button_chosen_text;
    wxStaticText *winner_text;
    wxStaticText *round_counter_text;
    wxStaticText *dummy_text;
    wxStaticText *ties_text;
    wxStaticText *computerWins_text;
    wxStaticText *humanWins_text;
    wxStaticText *blank_text;
    wxStaticText *humanPrediction_text;
    wxStaticText *computerNextPick_text;

    int round_count;
    GameInstance *game;
    char playerChoice;

    // Luke
    int roundMax;
    

    /**
     * Initialize the panel contents.
     */
    void init();
    void winnerInit();
    void show_game();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);
    void update_round_counter_text(int round_count);
    void update_stats_text(char wtl);
    void updatePredictions(char p);
};

#endif /* BUTTONPANEL_H_ */
