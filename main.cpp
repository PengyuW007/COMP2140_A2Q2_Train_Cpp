#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void processFile(char*);

int main(int argc, char *argv[]) {
    if(argc < 2){
        cout << "Usage: " << argv[0] << " <file name>" << endl;
    }

    processFile(argv[1]);

    return 0;
}

void processFile(char*filename){
    ifstream inFile;
    inFile.open(filename);

    string line;

    while(getline(inFile,line)){
        istringstream iss(line);
    }
}