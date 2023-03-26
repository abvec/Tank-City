
#include <string>
#include <fstream>

#include "image.hpp"
#include <iostream>

namespace src {

    /* Only loads bmp files with 40 byte dib headers, no safety checks are performed... Good luck! ;) */
    Image::LoadError Image::load_bmp ( std::string const & filename ) {

        std::ifstream file(filename,std::ios::binary);

        if(!file) {
            return Image::LoadError::NO_FILE;
        }

        char header[54];
        file.read(header,54);

        (this)->width = *(int32_t*)(header+18);
        (this)->height = *(int32_t*)(header+22);

        (this)->bpp = *(int16_t*)(header+28);

        if(((this)->bpp != 24) && ((this)->bpp != 32)) {
            return Image::LoadError::BAD_BPP;
        }

        uint32_t const num_pixels = (this)->bpp / 8 * (this)->width * (this)->height;
        (this)->pixels = new char[num_pixels];

        file.seekg(54,file.beg);
        file.read((this)->pixels,num_pixels);
        file.close();

        return Image::LoadError::OK;
    }

    void Image::destroy ( ) {

        delete [] (this)->pixels;
        (this)->bpp = 0;
    }

}; /* namespace src */
