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
// 1. Add Song
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist); // p is used to point to a newly allocated node
        
        if (head == nullptr) {
            head = p;
            current = head; 
        } else {
            Node* q = head; // q is used as the navigation/traversal pointer
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
        cout << "Added: " << title << " by " << artist << "\n";
    }

    // 2. Delete Song
    void deleteSong(string title) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head; // q is used as the navigation pointer
        
        // Deleting the first song
        if (q->songTitle == title) {
            Node* p = head; // p is used for the node to be deleted
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            if (current == p) {
                current = head; // Reassign current if it was pointing to the deleted song
            }
            delete p;
            cout << "Deleted: " << title << "\n";
            return;
        }

        // Deleting from middle or end
        while (q->next != nullptr) {
            if (q->next->songTitle == title) {
                Node* p = q->next; // p points to the node to be deleted
                q->next = p->next;
                if (p->next != nullptr) {
                    p->next->prev = q;
                }
                if (current == p) {
                    current = q; // Reassign current if deleted
                }
                delete p;
                cout << "Deleted: " << title << "\n";
                return;
            }
            q = q->next;
        }
        cout << "Song '" << title << "' not found in the playlist.\n";
    }
