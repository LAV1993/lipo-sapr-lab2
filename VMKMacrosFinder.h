#include <string>
#include <set>

using namespace std;

#ifndef VMKMACROSFINDER_H
#define	VMKMACROSFINDER_H


class VMKMacrosFinder {
public:
    VMKMacrosFinder();
    VMKMacrosFinder(const VMKMacrosFinder& orig);
    virtual ~VMKMacrosFinder();
    set<string> GetSetOfMacrosNamesFromLog();
private:
    string GetMacrosNameFromString(string currentString);

};

#endif	/* VMKMACROSFINDER_H */

