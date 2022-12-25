#include "main.h"

class vec2
{
public:
    float x = 0.f, y = 0.f;
    float length() { return sqrt(pow(x, 2.f) + pow(y, 2.f)); }
    vec2() {}
    vec2(float _x, float _y) : x(_x), y(_y) {}
    void operator() (float _x, float _y) { x = _x; y = _y; }
    vec2 norm()
    {
        float old_length = length();
        if (old_length == 1.f) {}
        else if (old_length) { x /= old_length; y /= old_length; }
        return vec2{ x, y };
    }
};

vec2 operator+ (vec2 a, float val) { return vec2{ a.x + val, a.y + val }; }
vec2 operator+ (float val, vec2 a) { return vec2{ a.x + val, a.y + val }; }
vec2 operator+ (vec2 a, vec2 b) { return vec2{ a.x + b.x, a.y + b.y }; }

vec2 operator- (vec2 a, float val) { return vec2{ a.x - val, a.y - val }; }
vec2 operator- (float val, vec2 a) { return vec2{ a.x - val, a.y - val }; }
vec2 operator- (vec2 a, vec2 b) { return vec2{ a.x - b.x, a.y - b.y }; }

vec2 operator* (vec2 a, float val) { return vec2{ a.x * val, a.y * val }; }
vec2 operator* (float val, vec2 a) { return vec2{ a.x * val, a.y * val }; }
vec2 operator* (vec2 a, vec2 b) { return vec2{ a.x * b.x, a.y * b.y }; }

int main(int argc, const char *argv[])
{
    vec2 vector(4.f, 3.f);
    vec2 surface[2];
    surface[0](10.f, 0.f);
    surface[1](10.f, -10.f);
    
    vec2 reflected = vector * surface[0].norm() * 2.f - vector;
    
    cout << reflected.x << "  " << reflected.y << "  " << reflected.length() << endl;
    reflected.norm();
    cout << reflected.x << "  " << reflected.y << "  " << reflected.length() << endl;
    
    return 0;
}
