//MusicPlayer.h

#include "CircleDLinkedList.h"
#include <iostream>
 
class MusicPlayer {
    private:
        std::string type;               
        CircleDLinkedList playlist;     
 
    public:
        MusicPlayer(std::string t) : type(t) {
        }
 
        virtual ~MusicPlayer() {
        }
 
        void play() {
            std::cout << "Now Playing: " << playlist.getCurrentSong();
            std::cout << std::endl;
        }
 
        void next() {
            playlist.advance();
            play();
        }
 
        void previous() {
            playlist.retreat();
            play();
        }

        void addSong(const Song& e) {
            playlist.add(e);
        }

        void removeSong() {
            playlist.remove();
        }

        int size() const {
            return playlist.size();
        }

        bool empty() const {
            return playlist.empty();
        }
 
        Song getCurrentSong() const {
            return playlist.getCurrentSong();
        }
 
        void print(bool forward = true, int count = -1) {
            if (empty()) {
                std::cout << "Playlist is empty." << std::endl;
                return;
            }
            if (count == -1) {
                count = size();
            }
            if (count == 0) {
                std::cout << std::endl;
                return;
            }
            std::cout << playlist.getCurrentSong();
            if (forward) {
                playlist.advance();
            } else {
                playlist.retreat();
            }
            print(forward, count - 1);
            if (forward) {
                playlist.retreat();
            } else {
                playlist.advance();
            }
        }
};