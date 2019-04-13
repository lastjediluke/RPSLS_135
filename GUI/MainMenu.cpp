#include "MainMenu.h"
#include <string>
#include <iostream>

using namespace std;


void Menu::MainMenu() 
{
	string x;
	do 
	{ 
		cout << "Welcome to Rock, Paper Scissor, Lizard, Spock!" << endl;
		cout << "1.) Start Game "     << endl; 
		cout << "2.) User Management" << endl;
		cout << "3.) Leaderboards"    << endl;
		cout << "4.) Settings"        << endl; 
		cout << "5.) Quit"            << endl;
	    getline(cin, x);
	    if(x.compare("1"))
	    {
	    	cout << "Hello" << endl;
	    }
	}
	while(x.compare("5"));
}