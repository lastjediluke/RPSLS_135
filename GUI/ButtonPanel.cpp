#include "ButtonPanel.h"

void ButtonPanel::init()
{
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

    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Chosen object:");
    wxStaticText *round_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Round:");

    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    //adds where the round_counter text should be
    round_counter_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    round_counter_text->SetFont(round_counter_text->GetFont().Larger());
    chosen_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(round_counter_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    game->setRoundCount();
    std::cout << "Round " << game->getRoundCount() << std::endl;
    char playerChar = game->getPlayer()->setHand('r');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(ROCK);
    update_round_counter_text(round_count);
    if(round_count<20){
   	round_count++;
    }
    else if(round_count=20){ //resets case
	round_count = round_count - 19;
    }
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    game->setRoundCount();
    std::cout << "Round " << game->getRoundCount() << std::endl;
    char playerChar = game->getPlayer()->setHand('p');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(PAPER);
    update_round_counter_text(round_count);
    if(round_count<20){
   	round_count++;
    }
    else if(round_count=20){
	round_count = round_count - 19;
    }
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    game->setRoundCount();
    std::cout << "Round " << game->getRoundCount() << std::endl;
    char playerChar = game->getPlayer()->setHand('s');
    getPattern = game->recordHand(playerChar, 5);
    update_button_choice_text(SCISSORS);  
    update_round_counter_text(round_count);
    if(round_count<20){
   	round_count++;
    }
//reset rounds
    else if(round_count=20){
	round_count = round_count - 19;
    }
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
    char cpuChar = game->getCpu()->setHand(getPattern, 5, 'm');
    getPattern = game->recordHand(cpuChar, 5);
    Hands::handType win = Hands::getWinner(game->getPlayer()->getHand(), game->getCpu()->getHand());
    game->updateScore(win);
    if (game->getRoundCount() == 20)
    {
        std::cout << "Game Over!" << std::endl;
        game->getPlayer()->getScore();
        game->getCpu()->getScore();
        game->resetRoundCount();
    }
}

void ButtonPanel::update_round_counter_text(Round_count round_count)
{
    round_counter_text->SetLabelText(round_count_to_wxString(round_count));
}
