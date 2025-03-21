//
// Created by johnsimpsen on 3/15/2025.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Wheel.h"
#include "Number.h"

using namespace std;

//Prototypes
void readFile(const string& filename, Wheel*& w);
void readLine(const string& line, Number*& n);

int main() {

    string filename = "wheel_template.txt";
    Wheel* wheel1 = nullptr;

    readFile(filename, wheel1);

    Number* temp;



    int numSpins = 1;
    int iterations = 1;
    int topIterations = 1;

    while (true) {
        temp = wheel1->spin();
        cout << *temp;

        //End if black
        if (temp->getColor() != "red") {

            iterations++;
        }
        else {

            if (iterations > topIterations) {
                topIterations = iterations;
            }

            cout << "Number of spins: " << numSpins << endl;
            cout << "Number of iterations: " << iterations << endl;
            cout << "Top iterations: " << topIterations << endl;
            cout << "Chance: 1/" << pow(2, iterations) << endl;
            cout << endl;
            numSpins++;
            iterations = 1;
        }

    }


    delete temp;
    delete wheel1;

    return 0;

}

void readFile(const string& filename, Wheel*& w) {
    ifstream input("../" + filename);

    if (!input.is_open()) {
        cout << "Error: Could not open file: " << filename << endl;
        exit(1);
    }

    //parse each line
    vector<Number*> nums;
    string line;
    int i = 0;
    while(getline(input, line)) {

        //Check for end of file
        if(line.size() < 1)
            break;

        Number* temp = nullptr;
        readLine(line, temp);
        nums.push_back(temp);

        i+=1;
    }

    //Close file
    input.close();

    w = new Wheel(nums);

}

void readLine(const string& line, Number*& n) {

    int index = line.find(" ");
    string value = line.substr(0, index);
    string color = line.substr(index + 1);

    n = new Number(value, color);


}