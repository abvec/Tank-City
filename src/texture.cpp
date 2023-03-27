
#include "SDL_opengl.h"

#include "texture.hpp"
#include "image.hpp"

namespace src {

    Texture::CreateError Texture::create ( Image const & img ) {
        
        glGenTextures(1, &(this)->texture);
        glBindTexture(GL_TEXTURE_2D, (this)->texture);

        if(img.bpp == 24) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_BGR, GL_UNSIGNED_BYTE, img.pixels);
        }

        else if(img.bpp == 32) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img.pixels);
        }
        
        else {
            glDeleteTextures(1,&(this)->texture);
            
        }
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        
        (this)->width = img.width;
        (this)->height = img.height;

        return Texture::CreateError::OK;
    }

    void Texture::destroy ( ) {
        
        glDeleteTextures(1,&(this)->texture);
    }

}; /* namespace src */
