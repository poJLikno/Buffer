#ifndef VEC2_TYPE_H_
#define VEC2_TYPE_H_

#include <math.h>

class vec2
{
public:
    float x = 0.f, y = 0.f;
    float length();
    vec2() {}
    vec2(float _x, float _y) : x(_x), y(_y) {}
    void operator() (float _x, float _y);
};

vec2 operator+ (vec2 a, float val);
vec2 operator+ (float val, vec2 a);
vec2 operator+ (vec2 a, vec2 b);

vec2 operator- (vec2 a, float val);
vec2 operator- (float val, vec2 a);
vec2 operator- (vec2 a, vec2 b);

vec2 operator* (vec2 a, float val);
vec2 operator* (float val, vec2 a);
vec2 operator* (vec2 a, vec2 b);

vec2 normalize(vec2 a);

float dot(vec2 a, vec2 b);

vec2 reflect(vec2 a, vec2 normale);

#endif
