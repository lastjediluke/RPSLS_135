#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
    cpu = new ComputerPlayer();
    myPlayer = new HumanPlayer();
    startGameLoop();
}

void GameInstance::startGameLoop()
{
    std::cout << "Game Loop Started" << std::endl;
    char userInput;
    char handInput;
    do
    {
        std::cout << '\n';
        std::cout << "Press 'p' to play" << std::endl;
        std::cout << "Press 'q' to quit" << std::endl;
        std::cout << "Press 'l' to show leaderboard" << std::endl;
        std::cin >> userInput;
        switch(userInput)
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
                std::cin >> handInput;
                std::cout << "You picked " << handInput << "!" << std::endl;
                // cpu.setHand()
                // myPlayer.setHand()
                // showWinner() should be a static func from Hands class
                break;
            }
            case 'l':
            {
                // showLeaderboard() static func from leaderboard class
                break;
            }
            case 'q': std::cout << "QUITTER!!" << std::endl;
        }

    } while (userInput != 'q');
}