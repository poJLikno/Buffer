#ifndef VEC2_TYPE_H
#define VEC2_TYPE_H

#include <math.h>

class vec2
{
public:
    float x, y;
    float length();
    vec2(float _x = 0.f, float _y = 0.f) : x(_x), y(_y) {}
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
vec2 reflect(vec2 a, vec2 normale);
float dot(vec2 a, vec2 b);


#endif
