#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
    cpu = new ComputerPlayer();
    myPlayer = new HumanPlayer();
    startGameLoop();
}

bool GameInstance::isValidHand(char key)
{
    if (myPlayer->isHand(key)) return true;
    else return false;
}

void GameInstance::startGameLoop()
{
    std::cout << "Game Loop Started" << std::endl;
    std::string userInput;
    std::string handInput;
    std::cout << '\n';

    do
    {
        std::cout << '\n';
        std::cout << "Press 'p' to play" << std::endl;
        std::cout << "Press 'q' to quit" << std::endl;
        std::cout << "Press 'l' to show leaderboard" << std::endl;
        std::cin >> userInput;                  // I should also validate here too

        switch(userInput[0])
        {
            case 'p':
            {
                std::cout << "It's Gametime!" << std::endl;
                std::cout << "Here's how you play: " << std::endl;
                std::cout << "Rock beats SCISSORS and LIZARD" << std::endl;
                std::cout << "Paper beats ROCK and SPOCK" << std::endl;
                std::cout << "Scissors beats PAPER and LIZARD" << std::endl;
                std::cout << "Lizard beats PAPER and SPOCK" << std::endl;
                std::cout << "Spock beats ROCK and SCISSORS" << std::endl;
                std::cout << '\n';
                std::cout << "Press 'r' to pick rock" << std::endl;
                std::cout << "Press 'p' to pick paper" << std::endl;
                std::cout << "Press 's' to pick scissors" << std::endl;
                std::cout << "Press 'l' to pick lizard" << std::endl;
                std::cout << "Press 'v' to pick spock" << std::endl;
                while(1)
                {
                    std::cin >> handInput;

                    // check for invalid inputs
                    if (isValidHand(handInput[0])) break;
                    else continue;
                }
                cpu->setHand();
                myPlayer->setHand(handInput[0]);
                // showWinner() should be a static func from Hands class
                break;
            }
            case 'l':
            {
                // showLeaderboard() static func from leaderboard class
                break;
            }
            case 'q': std::cout << "QUITTER!!" << std::endl; break;
            default: std::cout << "That isn't an option, young jedi" << std::endl;

        }

    } while (userInput[0] != 'q');
}