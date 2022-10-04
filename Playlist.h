#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

class PlaylistNode {
    public: 
        PlaylistNode();
        PlaylistNode(string uID, string songN, string artistN, int songL);
        void InsertAfter(PlaylistNode* node);
        void SetNext(PlaylistNode* next); //Mutator
        string GetID(); //Accessor
        string GetSongName(); //Accessor
        string GetArtistName(); //Accessor
        int GetSongLength(); //Accessor
        PlaylistNode* GetNext(); //Accessor
        void PrintPlaylistNode();
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

#endif