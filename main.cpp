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
	string ID = "none";
	string songName = "none";
	string artName = "none";
	int length = 0;
	char choice = 0;
	PlaylistNode* head = NULL;
	PlaylistNode* curr = NULL;
	PlaylistNode* one = NULL;
	PlaylistNode* two = NULL;
	PlaylistNode* three = NULL;
	
	one = new PlaylistNode("a","a","a",1);
	two = new PlaylistNode("b", "b", "b", 2);
	three = new PlaylistNode("c", "c", "c", 3);

	
	head = new PlaylistNode();
	curr = head;
	head->InsertAfter(one);
	one->InsertAfter(two);
	two->InsertAfter(three);
	

	cout << "Playlist Name: ";
	cin >> plyName;
	do {
		PrintMenu(plyName);
		cin >> choice;
		if (choice == 'a') {
			curr = head;
			PlaylistNode* add = NULL;
			cout << "New song name: ";
			cin >> songName;
			cout << "Song ID: ";
			cin >> ID;
			cout << "Artist's Name: ";
			cin >> artName;
			cout << "Song Length: ";
			cin >> length;
			add = new PlaylistNode(ID, songName, artName, length);

			while (curr->GetNext() != NULL)
			{
				curr = curr->GetNext();
			}
			curr->InsertAfter(add);
			cout << "\n\n\n";
		}
		else if (choice == 'd') {
			curr = head;
			PlaylistNode* tmp = NULL;
			cout << "Name of song to remove: ";
			cin >> songName;
			do {
				if (songName == curr->GetNext()->GetSongName()){
					break;
				}
				curr = curr->GetNext();
			} while (curr != NULL);
				tmp = curr->GetNext();
				curr->SetNext(tmp->GetNext());
				delete tmp;
				cout << "\n\n\n";
		}

		else if (choice == 'c') {
			PlaylistNode* tmp1 = NULL;
			PlaylistNode* tmp2 = NULL;
			int cPos = 0;
			int dPos = 0;
			curr = head;
			cout << "Current Position of song: ";
			cin >> cPos;
			cout << "Desired Position of song: ";
			cin >> dPos;

			for (int i = 0; i < cPos-1; i++) {
				curr = curr->GetNext();
			}

			tmp1 = curr->GetNext();
			curr->SetNext(tmp1->GetNext());

			curr = head;
			for (int i = 0; i < dPos - 1; i++) {
				curr = curr->GetNext();
			}

			tmp1->SetNext(curr->GetNext());
			curr->SetNext(tmp1);
		}

		else if (choice == 'o') {
			curr = head;
			int count = 0;
			do {
				curr = curr->GetNext();
				count++;
				cout << count << ". Song Name: " << curr->GetSongName() << endl;
			} while (curr->GetNext() != NULL);
			cout << "\n\n\n";
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