
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

struct UVCoord {

    float u;
    float v;
};

struct UVQuad {

    UVCoord a;
    UVCoord b;
    UVCoord c;
    UVCoord d;
};

UVQuad swap_coords ( UVQuad const & uv ) {
    return UVQuad{uv.d,uv.c,uv.a,uv.b};
}

class UVProc {
    public :

    UVCoord round ( UVCoord const & uv );
    void sort ( );

    void read ( std::string const & filename );
    void write ( std::string const & filename );

    int32_t width;
    int32_t height;
    float width_epsilon;
    float height_epsilon;
    std::vector<UVQuad> quads;
};

UVCoord UVProc::round ( UVCoord const & uv ) {
    return UVCoord{uv.u - remainder(uv.u,width_epsilon),uv.v - remainder(uv.v,height_epsilon)};
}

int main ( ) {

    return 0;
}