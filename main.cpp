#include <cstdlib>
#include "VMKMacrosFinder.h"
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    VMKMacrosFinder macrosFinder;
    set<string> setOfMacrosNames = macrosFinder.GetSetOfMacrosNamesFromLog();
    //вывод множества
    while (!setOfMacrosNames.empty()) {
        cout << *setOfMacrosNames.begin() << endl;
        setOfMacrosNames.erase(setOfMacrosNames.begin());
    }
    return 0;
}

