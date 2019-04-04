#include "ButtonPanel.h"


// currently unused
void ButtonPanel::winnerInit()
{
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *winner_title = new wxStaticText(winner_panel, wxID_ANY, "Winner:");
    winner_text = new wxStaticText(winner_panel, wxID_ANY, "");
    winner_text->SetFont(winner_text->GetFont().Larger());
    winner_sizer->Add(winner_title, 0, wxALIGN_RIGHT, 0);
    winner_sizer->Add(winner_text, 0, 0, 0);
    winner_panel->SetSizer(winner_sizer); 
}

void ButtonPanel::init()
{
    // Buttons
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));
    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);
    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    // Panels and Sizers
    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2, 0, 5);
    wxPanel *stats_panel = new wxPanel(this, wxID_ANY);
    wxSizer *stats_sizer = new wxGridSizer(2, 0, 5);

    // Static Text
    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "Human Chooses:");
    wxStaticText *round_text = new wxStaticText(chosen_panel, wxID_ANY, "Round:");
    wxStaticText *winner_title = new wxStaticText(winner_panel, wxID_ANY, "Winner:");
    wxStaticText *stats_title = new wxStaticText(stats_panel, wxID_ANY, "STATS");
    wxStaticText *humanWins_title = new wxStaticText(stats_panel, wxID_ANY, "Human Wins:");
    wxStaticText *computerWins_title = new wxStaticText(stats_panel, wxID_ANY, "Computer Wins:");
    wxStaticText *ties_title = new wxStaticText(stats_panel, wxID_ANY, "Ties:");

    // Chosen
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    // Round Counter
    round_counter_text = new wxStaticText(chosen_panel, wxID_ANY, "1");
    round_counter_text->SetFont(round_counter_text->GetFont().Larger());
    chosen_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(round_counter_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    // Winner
    winner_text = new wxStaticText(winner_panel, wxID_ANY, "");
    winner_sizer->Add(winner_title, 0, wxALIGN_RIGHT, 0);
    winner_sizer->Add(winner_text, 0, 0, 0);
    winner_panel->SetSizer(winner_sizer);
    
    // Stats
    dummy_text = new wxStaticText(stats_panel, wxID_ANY, "");
    stats_title->SetFont(stats_title->GetFont().Larger());
    stats_sizer->Add(stats_title, 0, wxALIGN_RIGHT, 0);
    stats_sizer->Add(dummy_text, 0, 0, 0);
    stats_panel->SetSizer(stats_sizer);

    // Human Wins 
    humanWins_text = new wxStaticText(stats_panel, wxID_ANY, "");
    stats_sizer->Add(humanWins_title, 0, wxALIGN_RIGHT, 0);
    stats_sizer->Add(humanWins_text, 0, 0, 0);
    stats_panel->SetSizer(stats_sizer);

    // Computer Wins
    computerWins_text = new wxStaticText(stats_panel, wxID_ANY, "");
    stats_sizer->Add(computerWins_title, 0, wxALIGN_RIGHT, 0);
    stats_sizer->Add(computerWins_text, 0, 0, 0);
    stats_panel->SetSizer(stats_sizer);

    // Ties
    ties_text = new wxStaticText(stats_panel, wxID_ANY, "");
    stats_sizer->Add(ties_title, 0, wxALIGN_RIGHT, 0);
    stats_sizer->Add(ties_text, 0, 0, 0);
    stats_panel->SetSizer(stats_sizer);

    // Add panels to the screen
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(stats_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    char playerChar = game->getPlayer()->setHand('r');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(ROCK);
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    char playerChar = game->getPlayer()->setHand('p');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(PAPER);
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    char playerChar = game->getPlayer()->setHand('s');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(SCISSORS);  
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
    char cpuChar = game->getCpu()->setHand(getPattern, 5, 'm');
    game->setRoundCount();
    getPattern = game->recordHand(cpuChar, 5);
    Hands::handType win = Hands::getWinner(game->getPlayer()->getHand(), game->getCpu()->getHand());
    char winner = game->updateScore(win);
    update_stats_text(winner);
    if (game->getRoundCount() == 21)
    {
        std::cout << "Game Over!" << std::endl;
        game->getPlayer()->getScore();
        game->getCpu()->getScore();
        game->resetRoundCount();
    }
    update_round_counter_text(game->getRoundCount());
    std::cout << "Round " << game->getRoundCount() << std::endl;
}

void ButtonPanel::update_round_counter_text(Round_count round_count)
{
    round_counter_text->SetLabelText(round_count_to_wxString(round_count));
}

void ButtonPanel::update_stats_text(char wtl)
{
    // CPU Wins
    if (wtl == 'c')
    {
        computerWins_text->SetLabelText(round_count_to_wxString(game->getCpu()->getWins()));
        winner_text->SetLabelText("CPU!");
    }

    // Human Wins
    else if (wtl == 'h')
    {
        humanWins_text->SetLabelText(round_count_to_wxString(game->getPlayer()->getWins()));
        winner_text->SetLabelText("Human!");
    }

    // Tie
    else 
    {
        ties_text->SetLabelText(round_count_to_wxString(game->getPlayer()->getTies()));
        winner_text->SetLabelText("Tie!");
    }
}