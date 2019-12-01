#include <iostream>
#include <vector>
#include <iomanip>
#include "resources.h"
using namespace std;
using namespace vo;

int main() {

    std::cout << "Welcome to Ray-Tracer" << endl;
    
    cout << "Creating a vector:" << endl;
    auto v = vo::createVector(1.2,2.5,3.0);
    vo::print(v);

    cout << "Creating a point:" << endl;
    auto p = vo::createPoint(2.5,4.13,10);
    vo::print(p);

    cout << endl;
    cout << "Adding vector and point:" << endl;
    auto rezAdd = vo::add(v, p);
    vo::print(rezAdd);

    cout << endl;
    cout << "Subtracting vectors:" << endl;
    auto rezSub = vo::subtract(v, p);
    vo::print(rezSub);

    cout << endl;
    cout << "Negate vectors:" << endl;
    auto rezNeg = vo::negate(v);
    vo::print(rezNeg);  
    
    cout << endl;
    cout << "Scale vectors:" << endl;
    auto rezScaled = vo::scale(3.5, v);
    vo::print(rezScaled);

    cout << endl;
    cout << "Get vector's magnitude:" << endl;
    auto rezMag = vo::getMagnitude(v);
    cout << rezMag << endl;

    cout << endl;
    cout << "Normalize vector:" << endl;
    auto rezNorm = vo::normalize(v);
    vo::print(rezNorm);

    cout << endl;
    cout << "Dot product vector:" << endl;
    auto rezDot = vo::dot(v, p);
    cout << rezDot << endl;

    cout << endl;
    cout << "Cross product vector:" << endl;
    auto rezCross = vo::cross(v, p);
    vo::print(rezCross);
}