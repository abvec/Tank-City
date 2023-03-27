
#ifndef _TEXTURE_HPP_

    #define _TEXTURE_HPP_

    #include "vector.hpp"
    #include "image.hpp"

    namespace src {

        class Texture {

            public :

            enum class CreateError {

                OK = 0,
            };

            /* Create texture from image */
            CreateError create ( Image const & img );

            /* Destroy texture */
            void destroy ( );

            /* Opengl texture id */
            uint32_t texture;

            /* Save image width and height information for later calculations */
            int32_t width, height;
        };

    }; /* namespace src */

#endif /* _TEXTURE_HPP_ */
