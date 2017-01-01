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

#ifndef SNAKE_RESOURCEMANAGER_H
#define SNAKE_RESOURCEMANAGER_H

#include <string>
#include "texture_cache.h"


namespace JOGL
{
    class ResourceManager
    {
    public:
        /**
         * \brief Returns a texture if inside the texture cache or creates a new one.
         * Actually just a wrapper for Texture_Cache::getTexture.
         * \param texturePath Path to the image file.
         * \return GLTexture
         */
        static GLTexture getTexture ( std::string texturePath );

    private:
        static Texture_Cache _textureCache;
    };
}

#endif //SNAKE_RESOURCEMANAGER_H
