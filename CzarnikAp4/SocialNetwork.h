#ifndef SocialNetwork_h
#define SocialNetwork_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class SocialNetwork {
public:
    SocialNetwork();
    void setSize(int);
    int getSize();
    void readFile();
    void display();
    void init_matrix();
    void calc_Similarity_Scores();
    int num_In_Common_Between_Vectors(vector<int>, vector<int>);
    int recommend(int);
    
private:
    ifstream infile;
    vector<int> *network_data;
    int **similarity_matrix;
    int size;
};


#endif
