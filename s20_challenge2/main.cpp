#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
private:
    friend std::ostream& operator<<(std::ostream& os, const Song& obj);
    std::string name;
    std::string artist;
    int rating;
public:
    // Constructors
    Song() = default;

    Song(std::string name, std::string artist, int rating)
        : name(std::move(name)), artist(std::move(artist)), rating(rating) {}
    //Getters
    const std::string& getName() const {
        return name;
    }
    const std::string& getArtist() const {
        return artist;
    }
    int getRating() const {
        return rating;
    }

    //Overload Operators
    bool operator<(const Song& other) const {
        return this->name < other.name;
    }

    bool operator==(const Song& other) const {
        return this->name == other.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& obj) {
    os << std::setw(20) << std::left <<  obj.getName()
    << std::setw(20) << std::left <<  obj.getArtist()
    << std::setw(20) << std::left <<  obj.getRating();
    return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and Play new Song" << std::endl;
    std::cout << "L - List Playlist" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Enter a selection [Q to Quit]:";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song;
}


void play_first_song(const Song &song) {
    std::cout << "Playing first song: " << std::endl;
    play_current_song(song);
}


void play_next_song(std::list<Song>::iterator& current_song, std::list<Song>& playlist) {
    ++current_song;
    if (current_song == playlist.end()) {
        current_song = playlist.begin();
    }
    play_current_song(*current_song);
}

void play_previous_song(std::list<Song>::iterator& current_song, std::list<Song>& playlist) {
    if (current_song == playlist.begin()) {
        current_song = std::prev(playlist.end());
    } else {
        --current_song;
    }
    play_current_song(*current_song);
}

void add_new_song(std::list<Song>::iterator& it, std::list<Song>& playlist) {
    std::string name;
    std::string artist;
    int rating;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "=== Adding New Song === " << std::endl;
    std::cout << "Enter song name: ";
  //  std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter artist: ";
    std::getline(std::cin, artist);

    std::cout << "Enter rating (1-5): ";
    std::cin >> rating;

    Song new_song {name, artist, rating};

    // insert() places the new song *before* the iterator passed in,
    // and returns an iterator pointing to the newly inserted element.
    it = playlist.insert(it, new_song);

    play_current_song(*it);
}

void display_playlist(const std::list<Song>& playlist, const Song &current_song) {
    for (const Song& song : playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "Current Song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main() {
    std::list<Song> playlist {
            { "song1", "artist1", 1},
            { "song2", "artist2", 2},
            { "song3", "artist3", 3},
            { "song4", "artist4", 4},
            { "song5", "artist5", 5},
        };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection {};
    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);

        switch (selection) {
            case 'F':
                current_song = playlist.begin();
                play_first_song(*current_song);
                break;
            case 'N':
                play_next_song(current_song, playlist);
                break;
            case 'P':
                play_previous_song(current_song, playlist);
                break;
            case 'A':
                add_new_song(current_song, playlist);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            default:
                std::cout << "Invalid selection, try again" << std::endl;
                break;
        }
    } while (selection != 'Q');

    return 0;
}