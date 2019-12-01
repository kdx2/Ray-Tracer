#ifndef _VECTOR_INCLUDED_
#define _VECTOR_INCLUDED_

#include <vector>

namespace vo { // vector operations
    using namespace std;
    
    void print(vector<float>);

    float getMagnitude(vector<float>);
    float dot(vector<float>, vector<float>);

    vector<float> createPoint(float x, float y, float z);
    vector<float> create(float x, float y, float z);

    vector<float> add(vector<float>, vector<float>);
    vector<float> subtract(vector<float>, vector<float>);
    vector<float> negate(vector<float>);
    vector<float> scale(float, vector<float>);
    vector<float> normalize(vector<float>);
    vector<float> cross(vector<float>, vector<float>);
}
#endif