
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

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
    return UVQuad{uv.a,uv.b,uv.c,uv.d};
}

class UVProc {
    public :

    UVCoord round ( UVCoord const & uv );
    void sort ( );

    void read ( std::string const & filename );
    void write ( std::string const & filename );

    void proc ( );

    int32_t width;
    int32_t height;
    float width_epsilon;
    float height_epsilon;
    std::vector<UVQuad> quads;
};

UVCoord UVProc::round ( UVCoord const & uv ) {
    return UVCoord{uv.u - remainder(uv.u,width_epsilon),uv.v - remainder(uv.v,height_epsilon)};
}

void UVProc::sort ( ) {
    std::sort((this)->quads.begin(),(this)->quads.end(),[](UVQuad a, UVQuad b) { return a.a.u > b.a.u; });
    std::sort((this)->quads.begin(),(this)->quads.end(),[](UVQuad a, UVQuad b) { return a.a.v > b.a.v; });
}

void UVProc::read ( std::string const & filename ) {

    std::ifstream ifile(filename);
    UVQuad quad;

    do{
        ifile >> quad.a.u >> quad.a.v >> quad.b.u >> quad.b.v >> quad.c.u >> quad.c.v >> quad.d.u >> quad.d.v;
        (this)->quads.push_back(quad);
    } while(!ifile.eof());
    ifile.close();
}

void UVProc::write ( std::string const & filename ) {
    std::ofstream ofile(filename);
    for ( unsigned int i = 0; i < (this)->quads.size(); i++ ) {
        ofile << std::fixed << (this)->quads[i].a.u << ' ' << (this)->quads[i].a.v << ' ' << (this)->quads[i].b.u << ' ' << (this)->quads[i].b.v << ' '
                            << (this)->quads[i].c.u << ' ' << (this)->quads[i].c.v << ' ' << (this)->quads[i].d.u << ' ' << (this)->quads[i].d.v << std::endl;
    }
    ofile.close();
}

void UVProc::proc ( ) {

    for ( unsigned int i = 0; i < (this)->quads.size(); i++ ) {
        swap_coords((this)->quads[i]);
        (this)->quads[i].a = ((this)->quads[i].a);
        (this)->quads[i].b = ((this)->quads[i].b);
        (this)->quads[i].c = ((this)->quads[i].c);
        (this)->quads[i].d = ((this)->quads[i].d);
    }
    (this)->sort();
}

int main ( ) {

    std::string filename;
    UVProc proc;
    
    std::cin >> filename;
    std::cin >> proc.width;
    std::cin >> proc.height;
    proc.width_epsilon = 1.0f / proc.width;
    proc.height_epsilon = 1.0f / proc.height;
    
    proc.read(filename);
    proc.proc();
    proc.write(filename + ".proc");
    return 0;
}