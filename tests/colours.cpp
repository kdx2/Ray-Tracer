#include <iostream>
#include <vector>
#include <iomanip>
#include "../resources.h"
using namespace std;
using namespace vo;

void logErr(string assertType, vector<float> expected, vector<float> actual) {
        cout << "Assertion error:" << endl;
        cout << "  [";
        for (auto c : expected)
            cout << " " << c << " ";
        cout << "]"<<endl;
                cout << "  [";
        for (auto c : actual)
            cout << " " << c << " ";
        cout << "]"<<endl;
        cout << "Vectors must be " << assertType << endl << endl;
}

bool assertEqual(vector<float> expected, vector<float> actual) {
    if (expected.size() != actual.size()) {
        logErr("equal", expected, actual);
    }

    for (int i=0; i<expected.size(); i++) {
        if (expected[i] != actual[i]) {
            logErr("equal", expected, actual);
            return false;
        }
    }

    return true;
}


void testAddingColours() {
    vector<float> expectedColour = vector<float>(0);
    expectedColour = vo::createColour(1.6, 0.7, 1.0);

    auto c1 = vo::createColour(0.9, 0.6, 0.75);
    auto c2 = vo::createColour(0.7, 0.1, 0.25);
    
    assertEqual(expectedColour, vo::add(c1, c2));
}
