#ifndef VMKMACROSFINDERTEST_H
#define	VMKMACROSFINDERTEST_H

class VMKMacrosFinderTest {
public:
    VMKMacrosFinderTest();
    VMKMacrosFinderTest(const VMKMacrosFinderTest& orig);
    virtual ~VMKMacrosFinderTest();
    bool startTest(ifstream& aInStream, VMKMacrosFinder& macrosFinder, const char* cFilename);
private:

};

#endif	/* VMKMACROSFINDERTEST_H */

