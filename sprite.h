/*
 * JAOGLL - a small OpenGl library and game engine.
 * Copyright (C) 2017  Lars Gröber
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
        Sprite () {}

        Sprite ( float x, float y, float width, float height, const Color& image_color, const std::string& image_path, float sprite_depth );

        glm::vec4 pos;
        glm::vec4 uv;
        Color color;
        GLTexture texture;
        float depth;
    };
}

#endif //SNAKE_SPRITE_H
