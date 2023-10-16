#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void bubbleSort(vector<long>& vec);


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
    for (int i = 0; i < size; i++) {
        infile >> lng;
        vec.push_back(lng);
    }
    // TODO: Print the vector size (to make sure it matches the size printed above)
    cout << vec.size() << endl;
    // TODO: Bubble Sort the vector
    bubbleSort(vec);
    // TODO: Print the first and last ten numbers from the vector to the console

    for (int i = vec.size() - 10; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    for (int i = 0; i < 10; i++){
        cout << vec[i] << endl;
    }
    return 0;
}

void bubbleSort(vector<long>& vec) {

    int numPasses = 0, i;
    long temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
        //printVec(vec);
    }

}
