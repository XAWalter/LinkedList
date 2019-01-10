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
	//PlaylistNode* one = NULL;
	//PlaylistNode* two = NULL;
	//PlaylistNode* three = NULL;
	
	//one = new PlaylistNode("a","a","a",1);
	//two = new PlaylistNode("b", "b", "b", 2);
	//three = new PlaylistNode("c", "c", "c", 3);

	
	head = new PlaylistNode();
	curr = head;
	//head->InsertAfter(one);
	//one->InsertAfter(two);
	//two->InsertAfter(three);
	//tail = three;
	

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
			bool found = false;
			curr = head;
			PlaylistNode* tmp = NULL;
			if (head->GetNext() == 0) {
				cout << "Playlist is empty" << endl;
			}
			else {
				cout << "ID of song to remove: ";
				cin >> ID;
				do {
					if (ID == curr->GetNext()->GetID()) {
						found = true;
						break;
					}
					curr = curr->GetNext();
				} while (curr->GetNext() != NULL);
				if (found) {
					tmp = curr->GetNext();
					curr->SetNext(tmp->GetNext());

					//reassign head or tail if appropriate
					if (tail == tmp) {
						tail = tmp->GetNext();
					}

					if (head->GetNext() == tmp) {
						head->SetNext(tmp->GetNext());
					}
					cout << tmp->GetSongName() << " removed" << endl;
					delete tmp;
				}
				else {
					cout << "Not Found" << endl;
				}
			}

				//clear choice
				ID = "none";
				choice = 0;

				cout << "\n\n\n";
		}

		//geeks for geeks helped ALOT for this
		else if (choice == 'c') {
			PlaylistNode* tmp1 = NULL;
			PlaylistNode* tmp2 = NULL;
			PlaylistNode* tmp3 = NULL;
			PlaylistNode* tmp4 = NULL;
			PlaylistNode* tmp5 = NULL;
			int cPos = 0;
			int dPos = 0;
			int tPos = 0;

			curr = head;
			if (head->GetNext() == NULL) {
				cout << "Playlist is empty" << endl;
			}
			else {
				do {
					curr = curr->GetNext();
					tPos++;
				} while (curr != tail);

				cout << "Current Position: ";
				cin >> cPos;
				cout << "Desired Position: ";
				cin >> dPos;

				if (dPos < 1) {
					dPos = 1;
				}
				if (dPos > tPos)
				{
					dPos = tPos;
				}

				//find the current position and the previous to
				tmp1 = head;

				for (int i = 0; i < cPos; i++) {
					tmp2 = tmp1;
					tmp1 = tmp1->GetNext();
				}

				//find the desired position and the previous to
				tmp3 = head;

				for (int i = 0; i < dPos; i++) {
					tmp4 = tmp3;
					tmp3 = tmp3->GetNext();
				}

				//check if cPos is tail
				if (tmp1 == tail) {
					tail = tmp4->GetNext();
				}
				//check if dPos is tail
				else if (tmp3 == tail) {
					tail = tmp2->GetNext();
				}

				//check if cPos is head
				if (tmp2 != head) {
					tmp2->SetNext(tmp3);
				}
				else {
					head->SetNext(tmp3);
				}

				//check if dPos is head
				if (tmp4 != head) {
					tmp4->SetNext(tmp1);
				}
				else {
					head->SetNext(tmp1);
				}

				//swap pointers
				tmp5 = tmp3->GetNext();
				tmp3->SetNext(tmp1->GetNext());
				tmp1->SetNext(tmp5);

				cout << tmp1->GetSongName() << " moved to position " << dPos << endl;
			}

			cout << "\n\n\n";
		}

		else if (choice == 's') {
			curr = head;
			int count = 0;
			string dArtist = "no";

			if (head->GetNext() == NULL)
			{
				cout << "Playlist is empty" << endl;
			}
			else {
				cout << "Desired Artist: ";
				cin >> dArtist;
				do {
					curr = curr->GetNext();
					if (dArtist == curr->GetArtistName()) {
						count++;
						cout << "Unique ID: " << curr->GetID() << endl;
						cout << "Song Name: " << curr->GetSongName() << endl;
						cout << "Artist Name: " << curr->GetArtistName() << endl;
						cout << "Song Length (in seconds): " << curr->GetSongLength() << endl;
						cout << endl;
					}

				} while (curr->GetNext() != NULL);
				if (count == 0) {
					cout << "No songs by desired artist." << endl;
				}
			}
			cout << "\n\n\n";
		}

		else if (choice == 't'){
			curr = head;
			int add = 0;
			if (head->GetNext() == NULL) {
				cout << "Playlist is empty" << endl;
			}
			else {
				do {
					curr = curr->GetNext();
					add = add + curr->GetSongLength();

				} while (curr->GetNext() != NULL);
				cout << "Total Playlist Length (in seconds): " << add << endl;
			}
			cout << "\n\n\n";

		}

		//Print Full linked list
		else if (choice == 'o') {
			curr = head;
			int count = 0;

			//check if list is empty
			if (head->GetNext() == NULL)
			{
				cout << "Playlist is empty" << endl;
			}
			else {
				cout << plyName << " - Full Playlist" << endl;
				do {
					curr = curr->GetNext();
					count++;
					cout << count << "." << endl;
					cout << "Unique ID: " << curr->GetID() << endl;
					cout << "Song Name: " << curr->GetSongName() << endl;
					cout << "Artist Name: " << curr->GetArtistName() << endl;
					cout << "Song Length (in seconds): " << curr->GetSongLength() << endl;
					cout << endl;
				} while (curr->GetNext() != NULL);
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
			cout << "Invalid Input\n\n" << endl;
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