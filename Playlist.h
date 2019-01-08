#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>

using namespace std;

class PlaylistNode{
public:
	PlaylistNode();
	PlaylistNode(string, string, string, int);
	//void InsertAfter();
	void SetNext(PlaylistNode*);
	//string GetID();
	//string GetSongName();
	//string GetArtistName();
	//int GetSongLength();
	//PlaylistNode GetNext();
	//void PrintPlaylistNode();

private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;

};

#endif