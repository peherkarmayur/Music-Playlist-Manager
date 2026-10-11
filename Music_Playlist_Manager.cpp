#include <iostream>
#include <string>

using namespace std;

// Node class modified to represent a song
class Node {
public:
    string songTitle;
    string artistName;
    Node* prev; // prev pointer to navigate to the previous song
    Node* next; // next pointer to navigate to the next song

    Node(string title, string artist) {
        songTitle = title;
        artistName = artist;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylistManager {
private:
    Node* head;    // head points to the first node (first song) in the playlist
    Node* current; // current points to the currently selected/playing song

public:
    MusicPlaylistManager() {
        head = nullptr;
        current = nullptr;
    }
