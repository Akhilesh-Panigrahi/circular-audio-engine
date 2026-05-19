//main.cpp

#include "MusicPlayer.h"
 
int DNode::activeNodes = 0;
 
int main() {
 
    MusicPlayer mp("Music Player");
    mp.addSong(Song("Bohemian Rhapsody", "Queen"));
    mp.addSong(Song("Hotel California", "Eagles"));
    mp.addSong(Song("Stairway to Heaven", "Led Zeppelin"));

    std::cout << "--- Play Current Song ---";
    mp.play();
 
    std::cout << "\n--- Next Songs Playback ---";
    mp.next();
    mp.next();
    mp.next();
 
    std::cout << "\n--- Previous Song Playback ---";
    mp.previous();

    std::cout << "\n--- Print Forward ---";
    mp.print(true);
 
    std::cout << "\n--- Print Reverse ---";
    mp.print(false);

    std::cout << "\n--- Remove Current Song ---";
    mp.removeSong();
 
    std::cout << "\n--- Play Current Song After Removal ---";
    mp.play();
 
    std::cout << "\n--- Next Songs Playback After Removal ---";
    mp.next();
    mp.next();
    mp.next();

    std::cout << "\n--- Final Print Forward ---";
    mp.print(true);
 
    std::cout << "\n--- Final Print Reverse ---";
    mp.print(false);
 
    return 0;
}