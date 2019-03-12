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

char ComputerPlayer::setHand(std::string s, int patternLen)
{
    std::ifstream myfile ("test.txt");
    std::string line;
    std::size_t pos = 0;
    bool found = false;
    int bigFreq = 1;
    std::string bigString;
    
    
    const char arrayNum[3] = {'r', 'p', 's'};
                                            // should be s.length() == patternLen - 1
    if (s.length() == patternLen -1)  // set to false for now, so it always makes a random choice
    {
        std::cout << "Ping!" << std::endl;
        std::string line;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                pos = line.find(s);
                if (pos != std::string::npos) 
                {
                    // std::cout << "Match!!!" << std::endl;
                    found = true;
                    // std::cout << line << std::endl;
                    int checkFreq = strToInt(line);
                    if(checkFreq > bigFreq){
                        bigFreq = checkFreq;
                        bigString = line;
                    }

                    // std::cout <<"big: "<< bigFreq << std::endl;
                    // send to new file
                }
            }
            myfile.close();
        switch(bigString[4])
            {
                case 'r':
                {
                    cpuHand.setHand(arrayNum[1]);
                    return arrayNum[1];   
                }
                case 'p':
                {
                    cpuHand.setHand(arrayNum[2]);
                    return arrayNum[2]; 
                }
                case 's':
                {
                    cpuHand.setHand(arrayNum[0]);
                    return arrayNum[0]; 
                }
                case 'l':
                {
                    cpuHand.setHand(arrayNum[2]);
                    return arrayNum[2]; 
                }
                case 'v':
                {
                    cpuHand.setHand(arrayNum[1]);
                    return arrayNum[1]; 
                }
            }

        // read from text file into line
        
        }

        else std::cout << "Unable to open file"; 

                // make a prediction
                // Derick's code will go here
    }

    // else we will pick a random one
    else
    {
        // set random hand
        srand ( time(NULL) ); //initialize the random seed
        int RandIndex = rand() % 3; //generates a random number between 0 and 4
        // std::cout << "CPU picked " << arrayNum[RandIndex] << std::endl;
        cpuHand.setHand(arrayNum[1]);
        return arrayNum[RandIndex]; //change to random later
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

