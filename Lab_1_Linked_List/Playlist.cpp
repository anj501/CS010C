#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    this->uniqueID = "none";
    this->songName = "none";
    this->artistName = "none";
    this->songLength = 0;
    nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string uID, string songN, string artistN, int songL) {
    this->uniqueID = uID;
    this->songName = songN;
    this->artistName = artistN;
    this->songLength = songL;
    nextNodePtr = nullptr;
}
void PlaylistNode::InsertAfter(PlaylistNode* node) {
    PlaylistNode* tmpNext = nullptr;
    tmpNext = nextNodePtr;
    nextNodePtr = node;
    node->nextNodePtr = tmpNext;
}
void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
}
string PlaylistNode::GetID() {
    return this->uniqueID;
}
string PlaylistNode::GetSongName() {
    return this->songName;
}
string PlaylistNode::GetArtistName() {
    return this->artistName;
}
int PlaylistNode::GetSongLength() {
    return this->songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this ->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}



