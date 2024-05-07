#include <iostream>
#include <vector>
#include <string>

class Track {
public:
    std::string species; 
    int time;
    int level_of_hard;

    Track(std::string species, int time, int level_of_hard) : species(species), time(time), level_of_hard(level_of_hard) {}
};

class Playlist { 
public:
    std::string type;
    int KolichisTrackov;

    Playlist(std::string type, int KolichisTrackov) : type(type), KolichisTrackov(KolichisTrackov) {}
};

class Music { 
public:
    std::vector<Track> tracks;
    std::vector<Playlist> playlist;

    void addTrack(Track Track) {
        tracks.push_back(Track);
    }

    void addPlaylist(Playlist ply) {
        playlist.push_back(ply);
    }

    void interact() {
        srand(time(0)); 
        int playlistIndex = rand() % playlist.size();
        int trackIndex = rand() % tracks.size();
        std::cout << "Playing track " << tracks[trackIndex].species << " from playlist " << playlist[playlistIndex].type << std::endl;
    }

    void displayState() {
        std::cout << "Current state:" << std::endl;
        for (const auto& track : tracks) {
            std::cout << "Track: " << track.species << " Time: " << track.time << " Level of Hard: " << track.level_of_hard << std::endl;
        }
        for (const auto& ply : playlist) {
            std::cout << "Playlist: " << ply.type << " Number of Tracks: " << ply.KolichisTrackov << std::endl;
        }
    }
};

int main() {
    Track dekma("Я ХОЧУ СПАТЬ", 72, 7);
    Track PHUNDRAW("Juzo", 102, 7);
    Track LAZZY2WICE("Akira", 104, 9);

    Playlist Playlist1("AAAAAA", 23);
    Playlist Playlist2("Hatred", 12);

    Music myMusic;

    myMusic.addTrack(dekma);
    myMusic.addTrack(PHUNDRAW);
    myMusic.addTrack(LAZZY2WICE);

    myMusic.addPlaylist(Playlist1);
    myMusic.addPlaylist(Playlist2);

    myMusic.interact();

    myMusic.displayState();

    return 0;
}