#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer()
{
    wins = 0;
    losses = 0;
    ties = 0;
}

void ComputerPlayer::getScore()
{
    std::cout << "CPU Wins: " << wins << "; Losses: " << losses << "; Ties: " << ties << std::endl;
}

void ComputerPlayer::insertNewPattern(std::string s)
{
    std::cout << "insert new pattern..." << std::endl;
    std::ofstream ofs;
    ofs.open ("test2.txt", std::ios::out | std::ofstream::app);
    ofs << s << ":1" << std::endl;
    ofs.close();
}

void ComputerPlayer::increasePatternFreq(std::string s)
{
     
}

int ComputerPlayer::strToInt(std::string line)
{
    int lineLen = line.length();
    std::string temp = "";
    int i = 6;
    std::cout << "Line at i: " << line[i] << std::endl;

    // start at 6
    while (i != lineLen)
    {
        temp += line[i];
        i++;
    }

    std::string::size_type sz;   // alias of size_t

    // convert string temp to int
    int i_dec = std::stoi (temp, &sz);
    return i_dec;
}

void ComputerPlayer::toTextFile(std::string s)
{
    std::ifstream fin;
    std::ofstream fout;

    // open for standard input
    fin.open("test.txt");

    // open for standard out
    fout.open("test2.txt");

    // file is read into this string line by line
    std::string line;
    std::size_t pos = 0;
    bool found = false;

    // read from text file into line
    while ( getline (fin, line) ) 
    {
        pos = line.find(s);
        if (pos != std::string::npos) 
        {
            std::cout << "Match!" << std::endl;
            found = true;
            int newFreq = strToInt(line);

            // update freq
            newFreq++;

            // send to new file
            fout << s << ":" << std::to_string(newFreq) << std::endl;
        }

        else
        {
            fout << line << std::endl;
        }
    }
    fin.close();
    fout.close();
    if (!found) insertNewPattern(s);

    // write from test2 to test
    fout.open("test.txt");
    fin.open("test2.txt");
    while ( getline (fin, line) ) 
    {
        // std::cout << line << std::endl;
        fout << line << std::endl;
    }
    fout.close();
    fin.close(); 
}

char ComputerPlayer::setHand(std::string s, int patternLen)
{
                // should be s.length() == patternLen - 1
    if (false)  // set to false for now, so it always makes a random choice
    {
                // make a prediction
                // Derick's code will go here
    }

    // else we will pick a random one
    else
    {
        // set random hand
        srand ( time(NULL) ); //initialize the random seed
        const char arrayNum[3] = {'r', 'p', 's'};
        int RandIndex = rand() % 3; //generates a random number between 0 and 4
        // std::cout << "CPU picked " << arrayNum[RandIndex] << std::endl;
        cpuHand.setHand(arrayNum[RandIndex]);
        return arrayNum[RandIndex];
    }
    
}

void ComputerPlayer::setScore(int sc)
{
    switch (sc)
    {
        case 0: ties++; break;
        case 1: wins++; break;
        case -1: losses++; break;
    }
}

