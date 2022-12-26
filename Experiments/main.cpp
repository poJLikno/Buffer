#include "main.h"

int main(int argc, const char *argv[])
{
    vec2 vector(4.f, 3.f);
    vec2 normale[6];
    normale[0] = normalize(vec2{ 0.f, -1.f });
    normale[1] = normalize(vec2{ 0.f, 1.f });
    normale[2] = normalize(vec2{ -1.f, 0.f });
    normale[3] = normalize(vec2{ 1.f, 0.f });
    normale[4] = normalize(vec2{ -1.f, -1.f });
    normale[5] = normalize(vec2{ 1.f, 1.f });
    
    unsigned short i = 5;
    
    vec2 reflected = vector - 2.f * dot(vector, normale[i]) * normale[i];
    
    cout << reflected.x << "  " << reflected.y << "  " << reflected.length() << endl;
    reflected = normalize(reflected);
    cout << reflected.x << "  " << reflected.y << "  " << reflected.length() << endl;
    
    return 0;
}
