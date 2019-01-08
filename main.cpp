#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

void PrintMenu(string);

int main() {
	//PlaylistNode* songOne = NULL;
	//PlaylistNode* songTwo = NULL;
	//
	//songOne = new PlaylistNode("1","song","artist",3);
	//songTwo = new PlaylistNode("2","song2", "artist2",2);
	//
	//songOne->InsertAfter(songTwo);
	//songOne->PrintPlaylistNode();
	//
	//cout << "Mem of next: " << songOne->GetNext() << endl;
	//cout << "Mem of song2: " << songTwo << endl;
	//cout << "Mem of next2: " << songTwo->GetNext() << endl;
	string plyName;
	char choice = 0;
	PlaylistNode* head = NULL;
	PlaylistNode* curr = NULL;
	PlaylistNode* one = NULL;
	PlaylistNode* two = NULL;
	PlaylistNode* three = NULL;
	
	one = new PlaylistNode();
	two = new PlaylistNode();
	three = new PlaylistNode();

	
	head = one;
	curr = two;
	one->InsertAfter(two);
	two->InsertAfter(three);
	

	cout << "Playlist Name: ";
	cin >> plyName;
	do {
		PrintMenu(plyName);
		cin >> choice;
		if (choice == 'a') {
			cout << "A" << endl;
		}
		else if (choice == 'q')
		{
			break;
		}
		else {
			cout << "Invalid" << endl;
		}

	} while (choice != 'q');





	system("pause");
	return 0;
}

void PrintMenu(string pName) {
	cout << pName << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change positiong of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;
}