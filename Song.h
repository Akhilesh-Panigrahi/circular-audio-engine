//Song.h

#include <iostream>
#include <string>

class Song {
    private:
        std::string songTitle;      
        std::string singerName;     

    public:
        Song(std::string sTitle = "", std::string sName = "")
            : songTitle(sTitle), singerName(sName) {
        }

        ~Song() {
        }

        std::string getSongTitle() {
            return songTitle;
        }

        std::string getSingerName() {
            return singerName;
        }

        void setSongTitle(std::string a) {
            songTitle = a;
        }

        void setSingerName(std::string b) {
            singerName = b;
        }

        friend std::ostream& operator<<(std::ostream& os, const Song& song) {
            os << std::endl << "{" << song.songTitle << " ; " << song.singerName << "}";
            return os;
        }
};