#include "GameInstance.h"


GameInstance::GameInstance()
{
    // moved cpu and player down into gameloop
    roundCount = 0;
    gameCount = 0;
    pattern = "";
    startGameLoop();
}

void GameInstance::printInstructions()
{
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
        std::cout << "" << std::endl;
        myPlayer->setScore(0);
        cpu->setScore(0);
    }
    else if (myPlayer->getHand() == winner)
    {
        std::cout << "You Win This Round!" << std::endl;
        std::cout << "" << std::endl;
        // increase player score by 1, decrease CPU score by 1
        myPlayer->setScore(1);
        cpu->setScore(-1);
    }
    else
    {
        std::cout << "Computer Wins This Round!" << std::endl;
        std::cout << "" << std::endl;
        // decrease player score by 1, increase CPU score by 1
        myPlayer->setScore(-1);
        cpu->setScore(1);
    }
    // myPlayer->getScore();
    // cpu->getScore();
}

std::string GameInstance::recordHand(char a, int patternSize)
{
    
    if (pattern.length() == patternSize)
    {
        
        std::string temp = pattern;
        cpu->toTextFile(pattern);

        // clear the pattern
        pattern = "";
        return temp;
    }
    pattern += a;
    
    return pattern;
    }

void GameInstance::startGameLoop()
{
    std::cout << "Game Loop Started" << std::endl;
    std::string userInput;
    std::string handInput;
    std::cout << '\n';
    bool quit = false;
    char randOrSmart;

    std::cout << "Here's how you play: " << std::endl;
    std::cout << "Rock beats SCISSORS" << std::endl;
    std::cout << "Paper beats ROCK" << std::endl;
    std::cout << "Scissors beats PAPER" << std::endl;
    std::string getPattern = "";
    std::cout << "Would you like the CPU to pick randomly or use machine learning?" << std::endl;
    std::cout << "Press m for machine learning and any other key for random" << std::endl;
    std::cin >> randOrSmart;
    cpu = new ComputerPlayer(randOrSmart);
    myPlayer = new HumanPlayer();
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
        // std::cout << "Lizard beats PAPER and SPOCK" << std::endl;
        // std::cout << "Spock beats ROCK and SCISSORS" << std::endl;
        
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
        std::cout << "You picked ";
        char playerChar = myPlayer->setHand(handInput[0]);
        getPattern = recordHand(playerChar, 5);
        std::cout << "CPU picked ";

        // Luke modified setHand
        char cpuChar = cpu->setHand(getPattern, 5, randOrSmart);
        getPattern = recordHand(cpuChar, 5);
        // std::cout << "Pattern: " << getPattern << std::endl;
        // cpu->setHand(getPattern, 5, randOrSmart);
        Hands::handType win = Hands::getWinner(myPlayer->getHand(), cpu->getHand());
        updateScore(win);
        

    } while (!quit);
    std::cout << "You have now quit the game" << std::endl;
}

/* To DO

1. Record Hands as chars
2. Store chars into a string
3. return the string to the cpu setHand func
4. cpu setHand will check the size of the string
    a. if the size == 5, then we will check the txt file for a match
    b. if we find a match, we will pick that hand

We also need to figure out how to change n(frequency)


*/

/*
    rrrrr:3
    rpsrs:1
    rpppp:1


*/

/*

functions

GameInstance.cpp
recordHand()
- add to the pattern until n == 5


ComputerPlayer.cpp
bool inFile()
- read txt file into a string and look for a match

insertNewPattern()
- append the new pattern to the text file

increment()
- increase pattern frequency


chooserFactory class


*/