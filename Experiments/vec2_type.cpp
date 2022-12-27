#include "vec2_type.h"

float vec2::length() { return sqrt(pow(x, 2.f) + pow(y, 2.f)); }

void vec2::operator() (float _x, float _y) { x = _x; y = _y; }

vec2 operator+ (vec2 a, float val) { return vec2(a.x + val, a.y + val); }
vec2 operator+ (float val, vec2 a) { return vec2(a.x + val, a.y + val); }
vec2 operator+ (vec2 a, vec2 b) { return vec2(a.x + b.x, a.y + b.y); }

vec2 operator- (vec2 a, float val) { return vec2(a.x - val, a.y - val); }
vec2 operator- (float val, vec2 a) { return vec2(a.x - val, a.y - val); }
vec2 operator- (vec2 a, vec2 b) { return vec2(a.x - b.x, a.y - b.y); }

vec2 operator* (vec2 a, float val) { return vec2(a.x * val, a.y * val); }
vec2 operator* (float val, vec2 a) { return vec2(a.x * val, a.y * val); }
vec2 operator* (vec2 a, vec2 b) { return vec2(a.x * b.x, a.y * b.y); }

vec2 normalize(vec2 a)
{
    float old_length = a.length();
    if (old_length && old_length != 1.f) { a.x /= old_length; a.y /= old_length; }
    return vec2(a.x, a.y);
}

float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }

vec2 reflect(vec2 a, vec2 normale) { return vec2(a - 2.f * dot(a, normale) * normale); }
