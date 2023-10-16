#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int size;
    // Get command line input
    if (argc > 1) {
        size = stoi(argv[1]);
    } else {
        size = 10000;
    }
    cout << "Looking for size: " << size << endl;
    // TODO: Declare a vector of longs to store the numbers
    vector <long> vec;
    // TODO: Read size numbers from numbers.txt
    ifstream infile("../numbers.txt");
    long lng;
    while (infile >> lng) {
        vec.push_back(lng);
    }
    // TODO: Print the vector size (to make sure it matches the size printed above)
    cout << vec.size();
    // TODO: Bubble Sort the vector
    int read = 0;
    int write = 0;
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                read +=2;
                temp = vec[i];
                read +=1;
                write+=1;
                vec[i] = vec[i+1];
                read+=2;
                write+=2;
                vec[i+1] = temp;
                read+=1;
                write+=1;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
        //printVec(vec);
    }
    cout << "Bubble Sort      Reads: " << read << " Writes: " << write << endl;
    // TODO: Print the first and last ten numbers from the vector to the console

    return 0;
}
