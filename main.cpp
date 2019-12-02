#include <iostream>
#include <vector>
#include <iomanip>
#include "resources.h"

#include "tests/colours.h"
using namespace std;
using namespace vo;


struct projectile {
    vector<float> position; // point
    vector<float> velocity; // vector
} ;

struct environment {
    vector<float> gravity; // vector
    vector<float> wind; // vector
} ;

projectile tick(projectile proj, environment env) {
    vector<float> pos = vo::add(proj.position, proj.velocity);
    vector<float> vel = vo::add(
                                vo::add(proj.velocity, env.gravity),
                                env.wind);
    return projectile{
        position: pos,
        velocity: vel
    };
}


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

    // Make projectile
    cout << "Shooting a projectile" << endl;
    auto pro = projectile{
        position: vo::createPoint(0.0, 1.0, 0.0), 
        velocity: vo::normalize(createVector(1.0, 1.0, 0.0))
    };
    auto env = environment{
        gravity: vo::createVector(0.0, -0.1, 0.0),
        wind: vo::createVector(-0.01, 0, 0)
    };
    int count = 0;
    while (pro.position[dim::y] > 0) {
        pro = tick(pro, env);
        ++count;
        cout << count << ". ";
        cout << "p: (pos) ";
            vo::print(pro.position); 
        cout << "   p: (vel) "; 
            vo::print(pro.velocity); 
        cout << endl;
    }

    // Canvas
}