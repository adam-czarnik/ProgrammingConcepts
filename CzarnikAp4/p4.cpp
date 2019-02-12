/// p4.cpp
/// Adam Czarnik
/// October 29, 2018
///
/// This file runs through the various funcitons of the SocialNetwork class,
/// each function either processing data on friend recommendations or displaying
/// it.

#include <iostream>
#include <string>
using namespace std;

#include "SocialNetwork.h"

int main() {
    
    SocialNetwork notFacebook;
    //netty.open_file();
    notFacebook.readFile();
    notFacebook.calc_Similarity_Scores();
    
    //ask for user_id to give recommendation until quit
    bool run = true;
    
    //preliminary check
//    cout << "Would you like a recommendation? ('no' quits program)" << endl;
//    std::string tmp;
//    cin >> tmp;
//    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
//    if (tmp == "no") run = false;
    
    //if preliminary check passes, prompt for user to recommend until quit
    while (run) {
        //check for quit case
        cout << "Would you like a recommendation? ('no' quits program)" << endl;
        std::string tmp;
        cin >> tmp;
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if (tmp == "no") break;
        
        cout << "What user_id would you like a recommendation for?" << endl;
        cout << "Valid range of users is between 0 and "
        << notFacebook.getSize()-1 << endl;
        
        //prompt user to enter choice
        int uid;
        cin >> uid;
        
        //case user entered non-integers, and verify choice before proceeding
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (uid >= notFacebook.getSize()) {
            cout << "That's not in the range of user numbers. Try again."
            << endl;
        } else {
            cout << "Friend recommended for user " << uid << ": " <<
            notFacebook.recommend(uid) << endl;
        }
    }
    
    return 0;
}
