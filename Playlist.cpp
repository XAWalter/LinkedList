#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

//Default Constructor
PlaylistNode::PlaylistNode(){
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = NULL;
}

//Constructor passing info individually
PlaylistNode::PlaylistNode(string ID, string sName, string aName, int length) {
	uniqueID = ID;
	songName = sName;
	artistName = aName;
	songLength = length;
	nextNodePtr = NULL;
}

//Insert passed PlaylistNode* after this
void PlaylistNode::InsertAfter(PlaylistNode* after) {
	PlaylistNode* tmp = NULL;

	tmp = this->nextNodePtr;
	this->SetNext(after);
	after->SetNext(tmp);
}

//Set nextNodePtr to the passed PlaylistNode
void PlaylistNode::SetNext(PlaylistNode* next) {
	this->nextNodePtr = next;
}

//getter for ID
string PlaylistNode::GetID() {
	return uniqueID;
}

//getter for songName
string PlaylistNode::GetSongName() {
	return songName;
}

//getter for artistName
string PlaylistNode::GetArtistName() {
	return artistName;
}

//getter for songLength
int PlaylistNode::GetSongLength() {
	return songLength;
}

//getter for nextNodePtr
PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}

//cout all info on song
void PlaylistNode::PrintPlaylistNode() {
	cout << "Artist: " << this->GetArtistName() << endl;
	cout << "Song Name: " << this->GetSongName() << endl;
	cout << "Unique ID: " << this->GetID() << endl;
	cout << "Song Length " << this->GetSongLength() << endl;
}
