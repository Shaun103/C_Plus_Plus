#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// displays the user with options to start the program
void menu(){
    std::cout << "\n**********************************************************************\n" << std::endl;
	std::cout << "This prgram will display MLB world series championships winning teams!\n\n"
		<< "Press 1 to start, 2 to display the team list, and 3 to quit\n\n"
		<< "*************************IMPORTANT!***********************************\n" 
		<< "You must press 2 for teams, to be able to enter the name of a team\n"
		<< "from the list. It is also reccomended that you copy and\n" 
		<< "paste from the list to avoid any typo errors\n"
		<< "**********************************************************************\n"
		<< "1. Information\n"
		<< "2. Teams\n"
		<< "3. quit\n"
        << "\n"
		<< "Select option:";
}

// program information
void intro(){
    std::cout << "**********************************************************\n" << std::endl;
	std::cout << "This is the world championship list!\n\n"
		<< "This list consists of teams that have won the\n\n"
		<< "world series between the years 1903 and 2012,\n\n"
		<< "Enter the name of the team to see how many times\n\n"
		<< "they have won!\n\n" << std::endl;
}

// presents user with all teams to choose from
void displayTeams(std::vector<std::string>&teams){
	teams.clear();

	std::ifstream fileTeamNames; 
	std::string teamRoster = " ";
	fileTeamNames.open("Teams.txt");

	if (fileTeamNames){
		while(getline(fileTeamNames, teamRoster) && !fileTeamNames.eof()){
			std::cout << teamRoster << "\n";    
		}
        std::cout << "From the list copy and paste a name below" << std::endl; 
	} else {
		std::cout << "There was a error opening the file!\n\n"
			<< "Teams.txt was not able to be opened";
	}
	fileTeamNames.close();
}

// finds the number of times the team appears
// in the file: WorldSeriesWinners.txt
void findwins(std::vector<std::string> &winners){
	std::ifstream winnersFile;
	std::string winningRoster = " "; // stores name into string
	winnersFile.open("WorldSeriesWinners.txt");

	if (winnersFile){
		while (getline(winnersFile, winningRoster) && !winnersFile.eof()){
			winners.push_back(winningRoster); // places string into winners vector
		}
	} else {
		std::cout << "There was a error opening the file!\n\n"
			      << "WorldSeriesWinners.txt was not able to be opened";
	}
	winnersFile.close();
}

// compares and counts the number of times
// the team names appear in vector 
void numberwins(const std::vector<std::string>winners, const std::vector<std::string>teams){
	std::string teamName = " "; // holds team name
	int wins1 = 0; // counter

    // user choose team name to count
	std::cin.get();
	getline(std::cin, teamName);

    // counts the number of times the user selected
    // baseball team appears in winners vector
	for (size_t x = 0; x < winners.size(); x++){
		if (teamName == winners[x]){
			wins1++;
		}
	}
	std::cout << "\nThe " << teamName << " have won "  << wins1 << " times!\n\n" << std::endl;
}

// menu for the user to navigate program
void menuprocessed(){
	const double quit = 3;
	int choice = 0; // boolean to beak out of do-while loop

	std::vector<std::string> teams = { "  " }; // holds all teams
	std::vector<std::string> winners = { "  " }; // holds only the winners

	do {
		std::cin >> (choice); // user selected menu choice, 
		switch (choice){
		case 1:
			intro();
			menu();
			break;
		case 2:
			winners.clear();
			teams.clear();
			displayTeams(teams);
			findwins(winners);
			numberwins(winners, teams);
			menu(); // re-occuring menu prompt
			break;
		case 3:
			if (choice == quit){
				std::cout << "The program will now exit!\n";
			}
			break;
		}
	} 
	while (choice != quit);
}

int main(){
	
	menu();
	menuprocessed();

	return 0;
}