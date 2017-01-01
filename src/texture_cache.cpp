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

#include <iostream>
#include "../texture_cache.h"
#include "../image_loader.h"

JOGL::GLTexture JOGL::Texture_Cache::get_texture ( std::string texturePath )
{
    auto mit = _textureMap.find( texturePath );
    if ( mit == _textureMap.end() )
    {
        JOGL::GLTexture newTexture = Image_Loader::loadPNG( texturePath );
        _textureMap.insert( std::make_pair( texturePath, newTexture ) );

        return newTexture;
    }
    return mit->second;
}
