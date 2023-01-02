#ifndef VEC2_TYPE_H
#define VEC2_TYPE_H

#include <iostream>
#include <math.h>

struct vec2
{
    float x, y;
    
    vec2(float _x = 0.f, float _y = 0.f) : x(_x), y(_y) { std::cout << "con" << std::endl; }
    vec2(const vec2 &a) : x(a.x), y(a.y) { std::cout << "con of copy" << std::endl; }
    ~vec2() { std::cout << "des" << std::endl; }
    void operator() (float _x, float _y);
    float length();
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

std::ostream &operator<< (std::ostream &stream, vec2 a);

#endif
