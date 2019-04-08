#include "ComputerPlayer.h"
#include <stdlib.h>


ComputerPlayer::ComputerPlayer(char randOrSmart)
{
    wins = 0;
    losses = 0;
    ties = 0;
    
    if (randOrSmart == 'm')
    {
        randFlag = false;
        
        chooser = ChooserFactory::make_chooser("smart");
    }

    else 
    {
        randFlag = 1;
        std::cout << "Random Chooser Created" << std::endl;
        chooser = ChooserFactory::make_chooser("random"); 
    }
}

void ComputerPlayer::getScore()
{
    std::cout << "CPU Wins: " << wins << "; Losses: " << losses << "; Ties: " << ties << std::endl;
}

void ComputerPlayer::insertNewPattern(std::string s)
{
    // std::cout << "insert new pattern..." << std::endl;
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

    // start at 6
    while (i != lineLen)
    {
        temp += line[i];
        i++;
    }

    std::string::size_type sz;   // alias of size_t

    // convert string temp to int
    int i_dec = std::stoi(temp, &sz);
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
            // std::cout << "Match writing to text file!" << std::endl;
            found = true;
            int newFreq = strToInt(line);

            // update freq
            newFreq++;

            // send to new file
            fout << s << ":" << std::to_string(newFreq) << std::endl;
            // std::cout << line << std::endl;
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

void ComputerPlayer::makePrediction(std::string s, int patternLen, char c)
{
    // at this point, cpu will pick a random hand and prepare for his educated pick                             
    // append the arrayNum[RandIndex] to the end of the pattern
    // std::cout << "Making a prediction..." << std::endl;
    std::ifstream myfile ("test.txt");
    std::string line;
    std::size_t pos = 0;
    bool found = false;
    int bigFreq = 0;
    std::string bigString = "";
    s = s + c;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            pos = line.find(s);
            if (pos != std::string::npos) 
            {
                // std::cout << "Match in makePrediction()" << std::endl;
                found = true;
                int checkFreq = strToInt(line);
                if(checkFreq > bigFreq)
                {
                    bigFreq = checkFreq;
                    bigString = line;
                }
            }
        }
        myfile.close();
        // std::cout << "Biggest String: " << bigString << std::endl;

        // if the bigString == "", then pick a random hand
        if (bigString == "")
        {
            prediction = 'x';
        }
        else 
        {
            switch(bigString[4])
            {
                case 'r': { prediction = 'p'; break; }
                case 'p': { prediction = 's'; break; }
                case 's': { prediction = 'r'; break; }
                case 'l': { prediction = 'r'; break; }
                case 'v': { prediction = 'p'; break; }
            }
        }
    }
    else std::cout << "Unable to open file"; 
}

char ComputerPlayer::setHand(std::string s, int patternLen, char difficulty)
{  
    char choice = chooser->make_choice(s, patternLen, prediction);
    cpuHand.setHand(choice);
    if (s.length() == patternLen - 2 && randFlag == false)
    {
        makePrediction(s, patternLen, choice);
    } 
    
    return choice;
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

