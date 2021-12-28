#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Train.h"

using namespace std;

void processFile(char *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <file name>" << endl;
    }

    processFile(argv[1]);

    return 0;
}

void processFile(char *filename) {
    ifstream inFile;
    inFile.open(filename);

    string nextLine;
    Train *train = new Train();

    while (getline(inFile, nextLine)) {
        istringstream iss(nextLine);
        string stuff;

        vector<string> line;
        while (iss >> stuff) {
            line.push_back(stuff);
        }

        cout << "Processing command:  " << nextLine << endl;
        if (line.size() > 1) {
            if (strcmp(line[0].c_str(), "PICKUP") == 0) {
                int numCargo = 0;
                int numEngine = 0;
                int num = atoi(line[1].c_str());

                for (int i = 0; i < num; i++) {
                    getline(inFile, nextLine);
                    istringstream iss(nextLine);
                    string stuff;

                    vector<string> line;
                    while (iss >> stuff) {
                        line.push_back(stuff);
                    }
                    int value = atoi(line[1].c_str());
                    if (strcmp(line[0].c_str(), "engine") == 0) {
                        train->addCar(line[0].c_str(), value);
                        numEngine++;
                    } else {
                        train->addCar(line[0].c_str(), value);
                        numCargo++;
                    }
                }
                cout << to_string(numEngine) + " engine and " << numCargo << " cars added to train" << endl;
            }//end PICKUP
            else if (strcmp(line[0].c_str(), "DROPLAST")==0) {
                int num = atoi(line[1].c_str());
                int value = train->dropLast(num);
                cout << value << " cars dropped from train" << endl;
            }//end DROPLAST
            else if(strcmp(line[0].c_str(),"DROPFIRST")==0){
                int num = atoi(line[1].c_str());
                int value =  train->dropFirst(num);
                cout << value << " cars dropped from train" << endl;
            }//end DROPFIRST
            else if(strcmp(line[0].c_str(),"DROP")==0){
                string type = line[1].c_str();
                int num = atoi(line[2].c_str());
                int value = train->drop(type,num);
               cout << value << " cars dropped from train" << endl;
            }
        } else {
            // PRINT
            train->printTrainInfo();
        }

    }

    inFile.close();
}

