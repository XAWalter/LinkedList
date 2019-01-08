#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

int main() {
	PlaylistNode* songOne = NULL;
	PlaylistNode* songTwo = NULL;

	songOne = new PlaylistNode("1","song","artist",3);
	songTwo = new PlaylistNode("2","song2", "artist2",2);

	songOne->InsertAfter(songTwo);
	songOne->PrintPlaylistNode();

	cout << "Mem of next: " << songOne->GetNext() << endl;
	cout << "Mem of song2: " << songTwo << endl;
	cout << "Mem of next2: " << songTwo->GetNext() << endl;


	system("pause");
	return 0;
}