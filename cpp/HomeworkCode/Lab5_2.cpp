#include<bits/stdc++.h>
using namespace std;
enum Color { red, blue, yellow, orange, white };

string colorToString(Color c) {
    switch (c) {
        case red:    return "Red";
        case blue:   return "Blue";
        case yellow: return "Yellow";
        case orange: return "Orange";
        case white:  return "White";
        default:     return "unknown";
    }
}

struct Flower {
    string name;
    Color color;
    string info;
};

int main() {
    Flower rose;
    rose.name = "Rose";
    rose.color = yellow;
    rose.info = "Friendship, joy, and positive energy.";

    cout << colorToString(rose.color) << " " << rose.name 
         << " meaning: " << rose.info << endl;

    return 0;
}
