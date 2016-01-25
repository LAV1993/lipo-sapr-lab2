#include "VMKMacrosFinder.h"
#include "VMKMacrosFinderTest.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

VMKMacrosFinderTest::VMKMacrosFinderTest() {
}

VMKMacrosFinderTest::VMKMacrosFinderTest(const VMKMacrosFinderTest& orig) {
}

VMKMacrosFinderTest::~VMKMacrosFinderTest() {
}

bool VMKMacrosFinderTest::startTest(ifstream& aInStream, VMKMacrosFinder& macrosFinder, const char* cFilename)
{
	aInStream.open(cFilename);
	cin.rdbuf(aInStream.rdbuf());
    set<string> testMacrosNames = macrosFinder.GetSetOfMacrosNamesFromLog();
	aInStream.close();
	set<string> exceptedMacrosNames;
	exceptedMacrosNames.insert("TestMacrosName");
        if (testMacrosNames == exceptedMacrosNames) {
            return true;
        }
        else {
            return false;
        }
}

