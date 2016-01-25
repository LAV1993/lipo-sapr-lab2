#include <cstdlib>
#include <iostream>
#include <fstream>
#include "VMKMacrosFinder.h"
#include "VMKMacrosFinderTest.h"

using namespace std;

int main(int argc, char** argv) {

    VMKMacrosFinder macrosFinder;
    VMKMacrosFinderTest tester;
    ifstream inStream;
    
    bool test = tester.startTest(inStream, macrosFinder, "test.log");
    
    if (test) {
        cout << "Success" << endl;
    }
    else {
        cout << "Error" << endl;
    }
    
    return 0;
}

