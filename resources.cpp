#include <iostream>
#include <math.h>
#include <functional> 
#include "resources.h"

enum dim {
    x = 0,
    y = 1,
    z = 2,
    w = 3
};


namespace vo {
    using namespace std;

    void print(vector<float> vec) {
        if (vec.size() == 3) {
            cout << "Incomplete vector size (x,y,z): ";
            for (int i=0; i<vec.size(); i++)
                cout << vec[i] << ", ";
                cout << endl;
            return;
        }

        switch (static_cast<int>(vec[dim::w])) {
        case 1:
            cout << "Point (x,y,z): "; break;
        case 0:
            cout << "Vector (x,y,z): "; break;
        default:
            cout << "Undefined type (x,y,z): "; break;
        }

        for (int i=0; i<vec.size()-1; i++)
            cout << vec[i] << ", ";
        cout << endl;
    }

    vector<float> createPoint(float x, float y, float z) {
        vector<float> vec = vector<float>(0);
        vec.push_back(x);
        vec.push_back(y);
        vec.push_back(z);
        vec.push_back(1.0);

        return vec;
    }

    vector<float> createVector(float x, float y, float z) {
        vector<float> vec = vector<float>(0);
        vec.push_back(x);
        vec.push_back(y);
        vec.push_back(z);
        vec.push_back(0.0);

        return vec;
    }

    vector<float> add(vector<float> a, vector<float> b) {
        // PointA + vectorAB = pointB.
        // Move forward!
        if (a.size() != b.size())
            cout << "Cannot add vectors of different sizes" << endl;
        
        vector<float> vec = vector<float>(0);
        for (int i=0; i<a.size(); i++)
            vec.push_back(a[i] + b[i]);
        
        return vec;
    }

    vector<float> subtract(vector<float> a, vector<float> b) {
        // PointA - pointB = vectorBA. Finds you the vector that points to our
        // light source!
        // PointB - vectorBA = pointA. Move backward!
        if (a.size() != b.size())
            cout << "Cannot subtract vectors of different sizes" << endl;
        
        vector<float> vec = vector<float>(0);
        for (int i=0; i<a.size(); i++)
            vec.push_back(a[i] - b[i]);
        
        return vec;
    }

    vector<float> negate(vector<float> vec) {
        // Get the vector with same length but opposite direction    
        std::transform(
            vec.cbegin(),vec.cend(),
            vec.begin(),
            std::negate<float>()
        );

        return vec;
    }

    vector<float> scale(float s, vector<float> vec) {
        // Scale a vector by the scaler s  
        for (int i=0; i<vec.size(); i++)
            vec[i] = s * vec[i];

        return vec;
    }

    float getMagnitude(vector<float> vec) {
        // The magnitude is extracted via the Pythagoras' Thorem  
        return sqrt(vec[0]*vec[0] + vec[1]*vec[1] 
                    + vec[2]*vec[2] + vec[3]*vec[3]);
    }

    vector<float> normalize(vector<float> vec) {
        float magnitude = getMagnitude(vec);
        for (int i=0; i<vec.size(); i++)
            vec[i] = vec[i] / magnitude;
        
        return vec;
    }

    float dot(vector<float> a, vector<float> b) {
        // Gives the cosine between two vectors.
        return a[0] * b[0]
                + a[1] * b[1]
                + a[2] * b[2]
                + a[3] * b[3];
    }

    vector<float> cross(vector<float> a, vector<float> b) {
        // Gives the cosine between two vectors.
        vector<float> vec = vector<float>(0);

        vec.push_back(a[dim::y] * b[dim::z] - a[dim::z] * b[dim::y]);
        vec.push_back(a[dim::z] * b[dim::x] - a[dim::x] * b[dim::z]);
        vec.push_back(a[dim::x] * b[dim::y] - a[dim::y] * b[dim::x]);

        return vec;
    }
}