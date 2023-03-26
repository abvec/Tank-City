
#ifndef _IMAGE_HPP_

    #define _IMAGE_HPP_

    #include <string>

    #include "vector.hpp"

    namespace src {

        class Image {

            public :

            enum class LoadError {

                OK = 0,

                NO_FILE,
                BAD_BPP,
            };

            /* Load image from file */
            LoadError load_bmp( std::string const & filename );

            /* Destroy image */
            void destroy ( );

            /* Pixel data */
            char * pixels;

            /* Image width and height */
            int width, height;

            /* Image bits per pixel, only 24 and 32 bpp is supported */
            int32_t bpp;
        };

    }; /* namespace src */

#endif /* _IMAGE_HPP_ */
