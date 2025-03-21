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

    const string inputFilename = "wheel_template.txt";
    Wheel* wheel1 = nullptr;

    readFile(inputFilename, wheel1);

    const string outputFilename = "output.txt";
    ofstream output("../" + outputFilename);

    //Prompt for total number of iterations (integers only)
    int totalIterations;
    cout << "Enter total iterations: ";
    cin >> totalIterations;

    int numIterations = 1; //number of times
    int numSpins = 1; //number of spins before winning
    int topSpins = 1; //tracker for highest number of spins before winning

    Number* temp = nullptr;

    while (numIterations <= totalIterations) {
        temp = wheel1->spin();
        output << *temp;

        //End if black
        if (temp->getColor() != "red") {

            numSpins++; //increment the number of spins
        }
        else {

            //Check if there is a new highest number of spins
            if (numSpins > topSpins) {
                topSpins = numSpins;
                cout << "Top number of spins: " << topSpins << endl;
            }

            output << "Number of iterations: " << numIterations << endl;
            output << "Number of spins: " << numSpins << endl;
            output << "Top number of spins: " << topSpins << endl;
            output << "Chance: 1/" << pow(2, numSpins) << endl;
            output << endl;
            numIterations++; //increment the number of iterations
            numSpins = 1; //reset the number of spins
        }
    }

    //Mark end of the simulation
    output << "Simulation complete!";
    cout << "Simulation complete!";

    output.close();

    delete temp;
    delete wheel1;

    return 1;
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
