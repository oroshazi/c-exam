#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

// #ifndef SONG_H
// #define SONG_H
// #include "song.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "playlist.h"
using namespace std;


int main() {
  vector<Song> sl;
  try {
    sl.push_back({"Still loving you",386});
    sl.push_back({"",20});
    sl.push_back({"I hate everything about you",231,Stimmung::Aggressiv});
  }
  catch (runtime_error&) {
    cout<<"catch 1 "<<sl.size()<<'\n';
  }
  try {
    sl.push_back({"I hate everything about you",231,Stimmung::Aggressiv});
    sl.push_back({"Just for fun",0});
    sl.push_back({"Still loving you",386});
  }
  catch (runtime_error&) {
    cout<<"catch 2 "<<sl.size()<<'\n';
  }
  try {
    sl.push_back({"Still got the blues",372,Stimmung::Traurig});
    sl.push_back({"Just for fun",1200});
    sl.push_back({"Still got the blues",372,Stimmung::Traurig});
  }
  catch (runtime_error&) {
    cout << "catch 3 " << sl.size() << '\n';
  }
  sl.push_back({"Still got the blues",372,Stimmung::Traurig});
  for (const auto& s : sl)
    cout << s.getDauer() << ' ';
  cout << '\n'; 
  for (const auto& s : sl)
    cout << s << ' ';
  cout << '\n';
  cerr << sl.at(0) << '\n';

  Playlist p1{"Favoriten"};
  cout << p1 << '\n';
  cerr << p1 << '\n';
  try {
    Playlist p2("Mehr",{{"Space Truckin",254,Stimmung::Aggressiv},{"Still loving you",386}});
    p1.dazu(p2);
    Playlist p3{""};
    p1.dazu({"Whiskey in the jar",362,Stimmung::Froehlich});
  }
  catch (runtime_error&) {
    cout << "catch 4 " << '\n';
  }
  p1.dazu({"Whiskey in the jar",362,Stimmung::Froehlich});
  cout << p1 << '\n';
  cerr << p1 << '\n';

  Playlist p2("Mehr",{{"Space Truckin",254,Stimmung::Aggressiv},{"Still loving you",386}});
  p1.dazu(p2);
  p1.dazu({"Whiskey in the jar",362,Stimmung::Froehlich});
  cout<< p1 << '\n';
  
  //Dekommentieren fuer Zusatzaufgabe ausgewogen
  /*
  cout << "\nZusatz dazu erweitern:\n";
  p1.dazu(p2,true);
  p1.dazu({"Whiskey in the jar",362,Stimmung::Froehlich},true);
  cout<< p1 << '\n';
  */

  //Dekommentieren fuer Zusatzaufgabe mischen
  /*
  cout << "\nZusatz mischen:\n";
  p1.mischen(p1);
  cout << p1 << "\n\n";
  Playlist p3{"p3"};
  p1.mischen(p3);
  cout << p1 << '\n' << p3 << "\n\n";
  p3.mischen(p1);
  cout << p1 << '\n' << p3 << "\n\n";
  p3.dazu(Playlist{"more",{{"Still loving you",386,Stimmung::Froehlich},{"a",240,Stimmung::Traurig},{"b",360}}},true);
  p3.dazu(Playlist{"more",{{"c",200,Stimmung::Froehlich},{"d",300,Stimmung::Aggressiv},{"e",100,Stimmung::Froehlich}}});
  p1.mischen(p3);
  cout << p1 << '\n' << p3 << '\n';
  */

  return 0;
}

/*** Erwartete Ausgabe:
catch 1 1
catch 2 2
catch 3 3
386 231 372 372
[Still loving you: 386 s, verliebt] [I hate everything about you: 231 s, aggressiv] [Still got the blues: 372 s, traurig] [Still got the blues: 372 s, traurig]
[Still loving you: 386 s, verliebt]
[Favoriten, 0 s {}]
[Favoriten, 0 s {}]
catch 4
[Favoriten, 1002 s {[Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]
[Favoriten, 1002 s {[Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]
[Favoriten, 2004 s {[Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]

Zusatz dazu erweitern:
[Favoriten, 3006 s {[Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]

Zusatz mischen:
[Favoriten, 3006 s {[Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]

[Favoriten, 3006 s {[Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]
[p3, 0 s {}]

[Favoriten, 3006 s {[Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]
[p3, 3006 s {[Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]

[Favoriten, 4592 s {[Whiskey in the jar: 362 s, froehlich], [Still loving you: 386 s, froehlich], [Space Truckin: 254 s, aggressiv], [a: 240 s, traurig], [Still loving you: 386 s, verliebt], [b: 360 s, verliebt], [Space Truckin: 254 s, aggressiv], [c: 200 s, froehlich], [Still loving you: 386 s, verliebt], [d: 300 s, aggressiv], [Whiskey in the jar: 362 s, froehlich], [e: 100 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich]}]
[p3, 4592 s {[Still loving you: 386 s, froehlich], [a: 240 s, traurig], [b: 360 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [Space Truckin: 254 s, aggressiv], [Still loving you: 386 s, verliebt], [Whiskey in the jar: 362 s, froehlich], [c: 200 s, froehlich], [d: 300 s, aggressiv], [e: 100 s, froehlich]}]
*/
#endif
