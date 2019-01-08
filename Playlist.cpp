#include <iostream>

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

PlaylistNode::PlaylistNode(string ID, string sName, string aName, int length) {
	uniqueID = ID;
	songName = sName;
	artistName = aName;
	songLength = length;
	nextNodePtr = NULL;
}

//void PlaylistNode::InsertAfter() {
//
//}
//
//void PlaylistNode::SetNext() {
//
//}
//
//string PlaylistNode::GetID() {
//
//}
//
//string PlaylistNode::GetSongName() {
//
//}
//
//string PlaylistNode::GetArtistName() {
//
//}
//
//int PlaylistNode::GetSongLength() {
//
//}
//
//PlaylistNode PlaylistNode::GetNext() {
//
//}
//
//void PlaylistNode::PrintPlaylistNode() {
//
//}
//