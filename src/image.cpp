
#include <string>
#include <fstream>

#include "image.hpp"
#include <iostream>

namespace src {

    /* Only loads bmp files with 40 byte dib headers, no safety checks are performed... Good luck! */
    Image::LoadError Image::load_bmp ( std::string const & filename ) {

        std::ifstream file(filename,std::ios::binary);

        if(!file) {
            return Image::LoadError::NO_FILE;
        }

        char header[54];
        file.read(header,54);

        uint32_t offset = *(uint32_t*)(header + 10);
        (this)->width  = *(int32_t*)(header+18);
        (this)->height = *(int32_t*)(header+22);
        (this)->bpp    = *(int16_t*)(header+28);

        if(((this)->bpp != 24) && ((this)->bpp != 32)) {
            return Image::LoadError::BAD_BPP;
        }

        (this)->pixels = new char[num_pixels];

        std::cout << num_pixels << std::endl;

        file.seekg(offset,file.beg);
        file.read((this)->pixels,num_pixels);
        file.close();

        return Image::LoadError::OK;
    }

    void Image::destroy ( ) {

        delete [] (this)->pixels;
        (this)->pixels = 0;
        (this)->bpp = 0;
    }

}; /* namespace src */
