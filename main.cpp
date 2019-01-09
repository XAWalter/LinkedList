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
	PlaylistNode* tail = NULL;
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

		//add song to the end of the playlist
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

			tail = add;

			//clear choices
			songName = "none";
			ID = "none";
			artName = "none";
			length = 0;
			choice = 0;

			cout << "\n\n\n";
		}

		//Remove song given ID
		else if (choice == 'd') {
			curr = head;
			PlaylistNode* tmp = NULL;
			cout << "ID of song to remove: ";
			cin >> ID;
			do {
				if (ID == curr->GetNext()->GetID()){
					break;
				}
				curr = curr->GetNext();
			} while (curr != NULL);
				tmp = curr->GetNext();
				curr->SetNext(tmp->GetNext());
				if (tail == tmp)
				{
					tail = tmp->GetNext();
				}
				delete tmp;

				//clear choice
				ID = "none";
				choice = 0;

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
			if(dPos < 1){
				dPos = 1;
			}
			else if(dPos >{

			}
			for (int i = 0; i < cPos - 1; i++) {
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

			//clear choice
			length = 0;

			cout << "\n\n\n";
		}

		else if (choice == 's') {
			curr = head;
			int count = 0;
			string dArtist = "no";
			cout << "Desired Artist: ";
			cin >> dArtist;
			do {
				curr = curr->GetNext();
				if (dArtist == curr->GetArtistName()) {
					count++;
					cout << count << ". Song Name: " << curr->GetSongName() << endl;
				}

			} while (curr->GetNext() != NULL);
			if (count == 0) {
				cout << "No songs by desired artist." << endl;
			}
		}

		else if (choice == 't'){
			curr = head;
			int add = 0;
			do {
				curr = curr->GetNext();
				add = add + curr->GetSongLength();

			} while (curr->GetNext() != NULL);
			cout << "Total Playlist Length (in seconds): " << add << endl;
			cout << "\n\n\n";

		}

		//Print Full linked list
		else if (choice == 'o') {
			curr = head;
			int count = 0;
			do {
				curr = curr->GetNext();
				count++;
				cout << count << "." << endl;
				cout << "Unique ID: " << curr->GetID();
				cout << "Song Name: " << curr->GetSongName();
				cout << "Artist Name: " << curr->GetArtistName();
				cout << "Song Length (in seconds): " << curr->GetSongLength();
			} while (curr->GetNext() != NULL);
			//if list is empty
			if (count == 0) {
				cout << "Playlist is empty" << endl;
			}

			//clear choice
			length = 0;

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