
#include <iostream>
#include <fstream>
#include <cmath>

int main ( ) {

    int width = 0;
    int height = 0;
    std::string filename;

    std::ifstream ifile;
    std::ofstream ofile;

    do {
        std::cout << "Enter UV filename : " << std::endl;
        std::cin >> filename;
        ifile.open(filename);
    } while(!ifile.is_open());

    ofile.open(filename + ".round");

    std::cout << "Enter texture width : " << std::endl;
    std::cin >> width;
    std::cout << "Enter texture height : " << std::endl;
    std::cin >> height;

    float const wepsilon = 1.0f / width;
    float const hepsilon = 1.0f / height;


    std::cout << "W Epsilon : " << wepsilon << std::endl;
    std::cout << "W Epsilon : " << hepsilon << std::endl;

    float tempu, tempv;
    ifile >> tempu >> tempv;

    do {
        ofile << tempu - fmod(tempu,wepsilon) << ' '
              << tempv - fmod(tempv,hepsilon) << std::endl;
        ifile >> tempu >> tempv;
    } while(!ifile.eof());

    ifile.close();
    ofile.close();

    return 0;
}