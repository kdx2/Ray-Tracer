#include <iostream>
#include <vector>
#include <iomanip>
#include "resources.h"
using namespace std;
using namespace vo;

int main() {

    std::cout << "Welcome to Ray-Tracer" << endl;
    
    cout << "Creating a vector:" << endl;
    auto v1 = vo::create(1.2,2.5,3.0);
    vo::print(v1);

    cout << "Creating a point:" << endl;
    auto v2 = vo::createPoint(2.5,4.13,10);
    vo::print(v2);

    cout << endl;
    cout << "Adding vectors:" << endl;
    auto rezAdd = vo::add(v1, v2);
    vo::print(rezAdd);

    cout << endl;
    cout << "Subtracting vectors:" << endl;
    auto rezSub = vo::subtract(v1, v2);
    vo::print(rezSub);

    cout << endl;
    cout << "Negate vectors:" << endl;
    auto rezNeg = vo::negate(v1);
    vo::print(rezNeg);  
    
    cout << endl;
    cout << "Scale vectors:" << endl;
    auto rezScaled = vo::scale(3.5, v1);
    vo::print(rezScaled);

    cout << endl;
    cout << "Get vector's magnitude:" << endl;
    auto rezMag = vo::getMagnitude(v1);
    cout << rezMag << endl;

    cout << endl;
    cout << "Normalize vector:" << endl;
    auto rezNorm = vo::normalize(v1);
    vo::print(rezNorm);

    cout << endl;
    cout << "Dot product vector:" << endl;
    auto rezDot = vo::dot(v1, v2);
    cout << rezDot << endl;

    cout << endl;
    cout << "Cross product vector:" << endl;
    auto rezCross = vo::cross(v1, v2);
    vo::print(rezCross);
}