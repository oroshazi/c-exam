#include <iostream>
#include <vector>
#include<string>

using namespace std;

enum Stimmung {Traurig, Froehlich, Aggressiv, Verliebt};

class Song {
        string title;
        int dauer; 
        Stimmung stmmg;
    public:
        Song();
        Song(string t, int d, Stimmung s = Stimmung::Verliebt);
        int getDauer() const;
        string getTitle() const; 
        Stimmung getStmmg() const;
        //friend ostream operator << (ostream o, Song& s);
};

Song::Song(){
   
}
Song::Song(string t, int d, Stimmung s) {
    this->title = (t.length()>0) ? t : throw runtime_error("title muss mindestens 1 char sein");
    this->dauer = (d > 0 && d< 1200) ? d : throw runtime_error("dauer ist entw zu kurz od zu lang");
    this->stmmg = s;

}

int Song::getDauer() const {
    return dauer;
}
string Song::getTitle () const {
    return title;
}

Stimmung Song::getStmmg () const {
    return stmmg;
}
//[Titel: Dauer s, Stimmung]

ostream&  operator<< (ostream& o, const Song& s) {
    switch (s.getStmmg()) {
        case 0:  return o << "[" << s.getTitle() << ": " << s.getDauer() << "s, " << "Traurig" << "]" ;
        break;
        case 1:  return o << "[" << s.getTitle() << ": " << s.getDauer() << "s, " << "Froehlich" << "]" ;
        break;
        case 2:  return o << "[" << s.getTitle() << ": " << s.getDauer() << "s, " << "Aggressiv" << "]" ;
        break;
        case 3:  return o << "[" << s.getTitle() << ": " << s.getDauer() << "s, " << "Verliebt" << "]" ;
        break;

    }
}

