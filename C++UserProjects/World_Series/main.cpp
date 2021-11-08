#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void menu();
void intro();
void menuprocessed();
void findTeams(vector<string> &);
void findwins(vector<string> &);
void numberwins(const vector<string>, const vector<string>);

int main(){
	
	menu();
	menuprocessed();

	return 0;
}

void menu(){
	cout << "This prgram will display MLB world series championships winning teams!\n\n"
		<< "Press 1 to start, 2 to display the team list, and 3 to quit\n\n"
		<< "*************************IMPORTANT!*********************************\n" 
		<< "You must press 2 for teams, to be able to enter the name of a team\n"
		<< "from the list. It is also reccomended that you copy and\n" 
		<< "paste from the list to avoid any type of error\n"
		<< "********************************************************************\n"
		<< " 1. Start\n"
		<< "2. Teams\n"
		<< "3. quit\n"
		<< "Your option:";

}

void menuprocessed(){
	const double start = 1,
	// 	roster = 2,
		quit = 3;
	int choice = 0;

	vector<string> teams = { "  " };
	vector<string> winners = { "  " };

	do {
		cin >> (choice);

		switch (choice){
		case 1:
			intro();
			menu();
			break;
		case 2:
			winners.clear();
			teams.clear();
			findTeams(teams);
			findwins(winners);
			numberwins(winners, teams);
			menu();
			break;
		case 3:
			if (choice == quit){
				cout << "The program will now exit!\n";
			}
			break;
		}
	} 
	while (choice != quit);
}

void intro(){
	cout << "This is the world championship list!\n\n"
		<< "This list consists of teams that have won the\n\n"
		<< "world series between the years 1903 and 2012,\n\n"
		<< "Enter the name of the team to see how many times\n\n"
		<< "they have won!\n\n";
}

void findTeams(vector<string>&teams){
	teams.clear();

	ifstream fileTeamNames;
	string teamRoster = " ";
	fileTeamNames.open("Teams.txt");

	if (fileTeamNames){
		while(getline(fileTeamNames, teamRoster) && !fileTeamNames.eof()){
			cout << teamRoster << "\n";
		}
	} else {
		cout << "There was a error opening the file!\n\n"
			<< "Teams.txt was not able to be opened";
	}
	fileTeamNames.close();
}
void findwins(vector<string> &winners){
	ifstream winnersFile;
	string winningRoster = " ";
	winnersFile.open("WorldSeriesWinners.txt");

	if (winnersFile){
		while (getline(winnersFile, winningRoster) && !winnersFile.eof()){
			winners.push_back(winningRoster);
		}
	} else {
		cout << "There was a error opening the file!\n\n"
			<< "WorldSeriesWinners.txt was not able to be opened";
	}
	winnersFile.close();
}

void numberwins(const vector<string>winners, const vector<string>teams){
	string teamName = " ";
	int wins1 = 0;

	for (string v : teams){
		cout << v << "n";
	}
	cin.get();
	getline(cin, teamName);

	for (size_t x = 0; x < winners.size(); x++){
		if (teamName == winners[x]){
			wins1++;
		}
	}
	cout << "\nThe " << teamName << " have won "  << wins1 << " times!\n\n";
}