#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

void PrintMenu(string playlist) {
    cout << playlist << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
}
void addsong(PlaylistNode*& current, int &size) {
    string uID;
    string sName;
    string aName;
    int sLength;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline (cin, uID);
    cout << "Enter song's name:" << endl;
    getline (cin, sName); 
    cout << "Enter artist's name:" << endl;
    getline (cin, aName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> sLength;
    cin.ignore();
    cout << endl;
    current = new PlaylistNode(uID, sName, aName, sLength);
    size++;
}
void removesong(PlaylistNode*& head, string idtoremove, int &size) {
    PlaylistNode* temp = nullptr;
    if (head->GetID() == idtoremove) {
        cout << "\"" << head->GetSongName() << "\" removed" << endl;
        temp = head;
        head = head->GetNext();
        delete temp;
        size--;
    }
    else {
        PlaylistNode* curr = head;
        while (curr->GetNext() != nullptr) {
            if (curr->GetNext()->GetID() == idtoremove) {
                cout << "\"" << curr->GetNext()->GetSongName() << "\" removed." << endl;
                cout << endl;
                temp = curr->GetNext();
                curr->SetNext(curr->GetNext()->GetNext());
                delete temp;
                temp = nullptr;
                size--;
                break; 
            }
            else {
                curr = curr->GetNext();
            }
        }
    }
}

void changeposition (PlaylistNode*& head, int position, int newposition, int &size) {
    PlaylistNode* oldNode = nullptr;
    PlaylistNode* switchNode = head;
    PlaylistNode* current = head;
    int currhelper = 1;
    if ((newposition == 1) && (position != 1)) {
        PlaylistNode* temp = nullptr;
        while ((currhelper < position) && (current != nullptr)) {
            oldNode = current;
            current = current->GetNext();
            currhelper++;
        }
        oldNode->SetNext(oldNode->GetNext()->GetNext());
        temp = head;
        head = current;
        current->SetNext(temp);
        cout << current->GetSongName() << " moved to position " << newposition << endl;
    }
    else if ((position > newposition) && (newposition != 1) && (position != 1)) {
        while ((currhelper < position) && (current != nullptr)) {
            oldNode = current;
            current = current->GetNext();
            currhelper++;
        }
        int newhelper = 1;
        while ((newhelper < newposition - 1) && (switchNode != nullptr)) {
            switchNode = switchNode->GetNext();
            newhelper++;
        }
        oldNode->SetNext(oldNode->GetNext()->GetNext());
        switchNode->InsertAfter(current); 
        cout << "\"" << current->GetSongName() << "\" moved to position " << newposition << endl;
        cout << endl;
    }
    else if ((position < newposition) && (newposition != 1) && (position != 1)) {
        while ((currhelper < position) && (current != nullptr)) {
            oldNode = current;
            current = current->GetNext();
            currhelper++;
        }
        int newhelper = 1;
        while ((newhelper < newposition) && (switchNode != nullptr)) {
            switchNode = switchNode->GetNext();
            newhelper++;
        }
        oldNode->SetNext(oldNode->GetNext()->GetNext());
        switchNode->InsertAfter(current); 
        cout << "\"" << current->GetSongName() << "\" moved to position " << newposition << endl;
        cout << endl;
    }
    else {
        PlaylistNode* newhead = current->GetNext();
        int newhelper= 1;
        while ((newhelper < newposition) && (switchNode != nullptr)) {
            switchNode = switchNode->GetNext();
            newhelper++;
        }
        switchNode->InsertAfter(current); 
        head = newhead;
        cout << "\"" << current->GetSongName() << "\" moved to position " << newposition << endl;
        cout << endl;
    }
}

void outputplaylist(PlaylistNode* head) {
    PlaylistNode* curr = head;
    int number = 1;
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        cout << endl;
    }
    else {
        while (curr != nullptr) {
            cout << number << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
            curr = curr->GetNext();
            number = number + 1;
        }
    }
}

void outputsongs(PlaylistNode* head, string artistName) {
    PlaylistNode* curr = nullptr;
    curr = head;
    int number = 1;
    while (curr != nullptr) {
        if (curr->GetArtistName() == artistName) {
            cout << number << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
        }
        number = number + 1;
        curr = curr->GetNext();
    }
}

void totaltime(PlaylistNode* head) {
    PlaylistNode* curr = nullptr;
    curr = head;
    int total = 0;
    while (curr != nullptr) {
        total = total + curr->GetSongLength();
        curr = curr->GetNext();
    }
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << total << " seconds" << endl;
    cout << endl;
}

int main() {
    string playlist;
    string option;
    string idtoremove;
    int position;
    int newposition;
    int size = 0;
    bool help = false;

    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    PlaylistNode* curr = nullptr;

    cout << "Enter playlist's title:" << endl;
    getline (cin, playlist);
    cout << endl;
    while (option != "q") {
        PrintMenu(playlist);
        cout << endl;
        cout << "Choose an option:" << endl;
        getline (cin, option);
        if (option == "a") {
            if (!help) {
                addsong(head, size);
                tail = head;
                help = true;
            }
            else {
                addsong(curr, size);
                tail->InsertAfter(curr);
                tail = curr;
            }
        }
        else if (option == "d") {
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline (cin, idtoremove);
            removesong(head, idtoremove, size);
        }
        else if (option == "c") { 
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> position;
            cout << "Enter new position for song:" << endl;
            cin >> newposition;
            cin.ignore();
            changeposition(head, position, newposition, size);
        }
        else if (option == "s") {
            string artistname;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cout << endl;
            getline (cin, artistname);
            outputsongs(head, artistname);
        }
        else if (option == "t") {
            totaltime(head);
        }
        else if (option == "o") {
            cout << playlist << " - OUTPUT FULL PLAYLIST" << endl;
            outputplaylist(head);
        }

    }

}