#include "VMKMacrosFinder.h"
#include <iostream>
#include <string>
#include <set>
#include <pcrecpp.h>

using namespace std;
using namespace pcrecpp;

VMKMacrosFinder::VMKMacrosFinder() {
}

VMKMacrosFinder::VMKMacrosFinder(const VMKMacrosFinder& orig) {
}

VMKMacrosFinder::~VMKMacrosFinder() {
}

set<string> VMKMacrosFinder::GetSetOfMacrosNamesFromLog() {
    RE re(".*#define.*");
    string currentString = "";
    string macrosName = "";
    
    set <string> setOfMacrosNames;
    
    while( getline (cin,currentString) ) {
        // если строка удволетворяет регулярному выражению достаём из неё имя и засовываем его в множество
        if(re.FullMatch(currentString)) {
            macrosName = GetMacrosNameFromString(currentString);
            setOfMacrosNames.insert(macrosName);
        }
    }
    // возврат множества
    return setOfMacrosNames;
}

// жутко кривая реализация доставания имени макроса из всей строки
string VMKMacrosFinder::GetMacrosNameFromString(string currentString) {
    currentString.erase(0,(currentString.find("#define"))+8);
    if (currentString.find(" ") < currentString.length())
        currentString.erase(currentString.find(" "),currentString.length());
    return currentString;
}

