#ifndef SNAKE_SPRITE_H
#define SNAKE_SPRITE_H

#include <GL/glew.h>
#include <string>

#include "sprite.h"
#include "gl_texture.h"
#include <glm/glm.hpp>
#include "vertex.h"

namespace JOGL
{
    /**
     * \brief Sprite struct, keeps track of the position and texture.
     */
    struct Sprite
    {
        Sprite ( float x, float y, float width, float height, const Color& image_color, const std::string& image_path );

        glm::vec4 pos;
        glm::vec4 uv;
        Color color;
        GLTexture texture;
    };
}

#endif //SNAKE_SPRITE_H
