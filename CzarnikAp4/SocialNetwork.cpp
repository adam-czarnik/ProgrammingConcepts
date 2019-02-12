/// SocialNetwork.cpp
/// Adam Czarnik
/// October 29, 2018
///
/// Contains the constructor and various functions for the SocialNetwork class.
/// Processes friend relationship data from a given file and recommends friends
/// for a given user.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "SocialNetwork.h"

//function prototypes
/*void setSize(int);
int getSize();
void readFile();
void display();
void init_matrix();
void calc_Similarity_Scores();
int num_In_Common_Between_Vectors(vector<int>, vector<int>);
int recommend(int);*/


// constructor function, also processes opening the file
SocialNetwork::SocialNetwork() {
    
    //temporary variable to run while loop, represents if file opened
    int tmp = 1;
    while (tmp) {
        //welcome message with formatting, then prompt to open file
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Welcome to the friend recommendation algorithm." << endl;
        cout << endl;
        cout << "Enter filename to open: "
            << endl;
        string filename;
        cin >> filename;
        infile.open((filename), ios::in);
        cout << "Loading file..." << endl;
        if (!infile.is_open()) {
            cout << "Could not open " << filename << ".txt" << endl;
        } else {
            tmp = 0;
        }
    }
    
    infile >> size;
    
    // this creates an array of size number of vectors
    network_data = new vector<int>[size];
    
    init_matrix();
    
}

// basic function to customize the size of the social network
void SocialNetwork::setSize(int s) {
    size = s;
}

// basic function to return size of the social network, int of users
int SocialNetwork::getSize() {
    return size;
}

// basic funciton to read the social network data from a file
void SocialNetwork::readFile() {
    while (!infile.eof()) {
        //two temp integers to hold reading from file
        int tmp1, tmp2;
        infile >> tmp1;
        infile >> tmp2;
        
        //put data from file into matrix
        network_data[tmp1].push_back(tmp2);
        network_data[tmp2].push_back(tmp1);
    }
}

// displays the network_data matrix, showing the relationships of all the people
void SocialNetwork::display() {
    cout << "Displaying data of " << size << " people: " << endl;
    // for loop to run through all data
    for (int r=0; r<size; r++) {
        cout << r << ": (";
        for (int c=0; c<network_data[r].size()-1; c++) {
            cout << network_data[r][c] << ", ";
        }
        //this part was written seperately for formatting
        cout << network_data[r][network_data[r].size()-1] << ")";
        cout << endl;
    }
}

void SocialNetwork::init_matrix()
    { similarity_matrix = new int*[size];
        for (int i=0; i < size; i++)
            similarity_matrix[i]= new int[size];
        int j;
        for (int i=0; i < size; i++)
        { for ( j =0; j < size; j++)
            { similarity_matrix[i][j] = 0;}
        }
    }

void SocialNetwork::calc_Similarity_Scores() {
    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            //calculate similarity score given two users
            int sre;
            sre=num_In_Common_Between_Vectors(network_data[r], network_data[c]);
            //put that score in the similarity_matrix
            similarity_matrix[r][c] = sre;
            similarity_matrix[c][r] = sre;
        }
    }
}

// caluclates the number of friends in common between two given users, returns
// the int of friends in common
int SocialNetwork::num_In_Common_Between_Vectors(vector<int> a, vector<int> b) {
    //score = number of friends in common
    int score = 0;
    
    //run through each and compare friends
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            if (a[i] == b[j]) score++;
        }
    }
    //return number of friends in common
    return score;
}

// for a given user_id, makes a friend recommendation and returns int user_id
// for that recommendation.
int SocialNetwork::recommend(int user_id) {
    //variable is highest similarity score, idx is placeholder
    int idx = 0;
    int max = 0;
    bool tmp;
    for (int i=0; i<size; i++) {
        for (int j=0; j<network_data[user_id].size(); j++) {
            if (network_data[user_id][j] != i) {
                tmp = true;
            } else {
                tmp = false;
                break;
            }
        }
        // verifies that the recommendation is a valid one
        for (int k=0; k<network_data[user_id].size(); k++) {
            if (i != user_id && similarity_matrix[user_id][i] > idx && tmp) {
                idx = similarity_matrix[user_id][i];
                max = i;
            }
        }
    }
    return max;
}
