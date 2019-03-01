#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
    cpu = new ComputerPlayer();
    myPlayer = new HumanPlayer();
    roundCount = 0;
    gameCount = 0;
    startGameLoop();
}

bool GameInstance::isValidHand(char key)
{
    if (myPlayer->isHand(key)) return true;
    else return false;
}

void GameInstance::updateScore(Hands::handType winner)
{
    if (winner == Hands::tie)
    {
        std::cout << "Tie game This Round!" << std::endl;
        myPlayer->setScore(0);
        cpu->setScore(0);
    }
    else if (myPlayer->getHand() == winner)
    {
        std::cout << "You Win This Round!" << std::endl;
        myPlayer->setScore(1);
        cpu->setScore(-1);
    }
    else
    {
        std::cout << "Computer Wins This Round!" << std::endl;
        myPlayer->setScore(-1);
        cpu->setScore(1);
    }
    // myPlayer->getScore();
    // cpu->getScore();
}

void GameInstance::startGameLoop()
{
    std::cout << "Game Loop Started" << std::endl;
    std::string userInput;
    std::string handInput;
    std::cout << '\n';
    bool quit = false;

    do
    {
        setRoundCount();
        if(getRoundCount() == 21)
        {
            std::cout << "Game Over!" << std::endl;
            myPlayer->getScore();
            cpu->getScore();
            resetRoundCount();
            while(1)
            {
                std::cout << "Would you like to play again? " << "Yes [y], No [n]: ";
                std::cin >> userInput;
                if (userInput[0] == 'n') 
                {
                    quit = true; 
                    break;
                }
                else if (userInput[0] == 'y') break;
                else 
                {   
                    std::cout << "Invalid Input" <<std::endl;
                }
            }
            if (quit) break;
        }
        std::cout << "Round " << getRoundCount() << std::endl;
        // std::cout << "Press 'p' to play" << std::endl;
        // std::cout << "Press 'q' to quit" << std::endl;
        // std::cout << "Press 'l' to show leaderboard" << std::endl;
        // std::cin >> userInput;                  

        std::cout << "It's Gametime!" << std::endl;
        std::cout << "Here's how you play: " << std::endl;
        std::cout << "Rock beats SCISSORS" << std::endl;
        std::cout << "Paper beats ROCK" << std::endl;
        std::cout << "Scissors beats PAPER" << std::endl;
        // std::cout << "Lizard beats PAPER and SPOCK" << std::endl;
        // std::cout << "Spock beats ROCK and SCISSORS" << std::endl;
        std::cout << '\n';
        std::cout << "Press 'r' to pick rock" << std::endl;
        std::cout << "Press 'p' to pick paper" << std::endl;
        std::cout << "Press 's' to pick scissors" << std::endl;
        // std::cout << "Press 'l' to pick lizard" << std::endl;
        // std::cout << "Press 'v' to pick spock" << std::endl;
        while(1)
        {
            std::cin >> handInput;
            if (isValidHand(handInput[0])) break;   // check for invalid inputs
        }
        std::cout << "CPU picked ";
        cpu->setHand();
        std::cout << "You picked ";
        myPlayer->setHand(handInput[0]);
        Hands::handType win = Hands::getWinner(myPlayer->getHand(), cpu->getHand());
        updateScore(win);

    } while (!quit);
    std::cout << "You have now quit the game" << std::endl;
}