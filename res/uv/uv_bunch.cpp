
#include <iostream>
#include <fstream>
#include <ostream>

class uv_bunch {

    public :

    void order ( ) {
        
        float temp[4];
        
        temp[3] = u[0];
        temp[2] = u[1];
        temp[0] = u[2];
        temp[1] = u[3];
        
        u[0] = temp[0];
        u[1] = temp[1];
        u[2] = temp[2];
        u[3] = temp[3];
        
        temp[3] = v[0];
        temp[2] = v[1];
        temp[0] = v[2];
        temp[1] = u[3];
        
        v[0] = temp[0];
        v[1] = temp[1];
        v[2] = temp[2];
        v[3] = temp[3];
    }

    float u[4];
    float v[4];
};

int main ( ) {

    std::string filename;

    std::ifstream ifile;
    std::ofstream ofile;

    int32_t num_bunches = 0;

    do {
        std::cout << "Enter uv.round filename : " << std::endl;
        std::cin >> filename;
        ifile.open(filename);
    } while(!ifile.is_open());

    ofile.open(filename + ".bunch");

    std::cout << "Enter the number of uv's the file has : " << std::endl;
    std::cin >> num_bunches;
    num_bunches = num_bunches / 8;

    uv_bunch bunch;

    for ( unsigned int i = 0; i < num_bunches; i++ ) {
        ifile >> bunch.u[0] >> bunch.v[0] >> bunch.u[1] >> bunch.v[1] >> bunch.u[2] >> bunch.v[2] >> bunch.u[3] >> bunch.v[3];
        bunch.order();
        ofile << std::fixed << bunch.u[0] << ' ' << bunch.v[0] << ' ' << bunch.u[1] << ' ' << bunch.v[1] << ' ' << bunch.u[2] << ' ' << bunch.v[2] << ' ' << bunch.u[3] << ' ' << bunch.v[3] << std::endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}