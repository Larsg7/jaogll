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

#ifndef SNAKE_TEXTURECACHE_H
#define SNAKE_TEXTURECACHE_H


#include <map>
#include <string>
#include "gl_texture.h"

namespace JOGL
{
    class Texture_Cache
    {
    public:
        /**
         * \brief Returns a GLTexture if one corresponding to the path is found in _textureMap
         *        or creates a new one and stores it in _textureMap.
         * \param texturePath Path to the image.
         * \return GLTexture
         */
        GLTexture get_texture ( std::string texturePath );

    private:
        std::map<std::string, GLTexture> _textureMap;
    };
}

#endif //SNAKE_TEXTURECACHE_H
