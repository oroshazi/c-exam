#include <iostream>
#include <vector>

#ifndef SONG_H
#define SONG_H
#include "song.h"

using namespace std;


class Playlist {
    string bez;
    vector<Song> list;
public: 
    Playlist(string b);
    Playlist(string b, vector<Song> l);
    void dazu(const Song& s) const ;
    void dazu(const Playlist& pl);
    int gesamtdauer() const;
    string getBez() const; 
    vector<Song> getList() const;
    friend ostream& operator << (ostream& o, Playlist& pl);
    void printList();

};
Playlist::Playlist(string b) {
    bez = (b.length()>0) ? b : throw runtime_error("bez muss mind 1 char sein");
}

Playlist::Playlist(string b, vector<Song> l) {
    bez = (b.length()>0) ? b : throw runtime_error("bez muss mind 1 char sein");
    for (int i = 0; i < l.size(); i++) {
        list.push_back(l.at(i));
    }    
}

void Playlist::printList() {
     for (int i = 0; i < this->getList().size(); i++) {
       cout << this->getList().at(i);

    }
}

void Playlist::dazu (const Song &s) const {    
    this->getList().push_back((s));
    //cout << "THISSS S:"<< s;
}

void Playlist::dazu(const Playlist& pl) {
    for ( int i = 0; i < pl.list.size(); i++) {
        this->list.push_back(pl.list.at(i));        
    }     
}
int Playlist::gesamtdauer() const {
    int gsmtd = 0;
    for (int i = 0 ; i < this->list.size(); i++) {
            gsmtd += + this->list.at(i).getDauer();
        }   
        //  cout << "test:  " <<list.size(); 
    return gsmtd;
    }

string Playlist::getBez() const {
    return bez;
}

vector<Song> Playlist::getList() const{
    return this->list;
}

ostream& operator << (ostream& o, Playlist& pl) {
  o << "[" << pl.getBez() <<", "<<pl.gesamtdauer() << " s " << "{";    
 for (int i = 0; i < pl.getList().size(); i++) {
       o  <<pl.getList().at(i) ;       
    }
    o << "}]";
    return o;
}
//: [Kinderlieder, 324 s {[Alle meine Entlein: 124 s, froehlich], [Haensel und Gretel: 200 s, traurig]}].
#endif
