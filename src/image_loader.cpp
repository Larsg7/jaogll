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

#include "../image_loader.h"
#include "../external/picoPNG.h"
#include "../iomanager.h"
#include "../error.h"

JOGL::GLTexture JOGL::Image_Loader::loadPNG ( std::string filePath )
{
    JOGL::GLTexture texture;

    std::vector<unsigned char> in;
    std::vector<unsigned char> out;

    unsigned long width, height;

    try
    {
        IOManager::read_file_to_buffer( in, filePath );
    }
    catch ( const Jaogll_Error& e )
    {
        fprintf( stderr, "Error reading image '%s'\n", filePath.c_str() );
        throw e;
    }

    int error = decodePNG( out, width, height, &(in[0]), in.size(), true );

    if ( error != 0 )
    {
        throw JOAGLL_ERROR ( "decodePNG failed with error '" + std::to_string( error ) + "'!" );
    }

    glGenTextures( 1, &(texture.id) );

    glBindTexture( GL_TEXTURE_2D, texture.id );

    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, static_cast<int>(width), static_cast<int>(height)
            , 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]) );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    glGenerateMipmap( GL_TEXTURE_2D );

    glBindTexture( GL_TEXTURE_2D, 0 );

    texture.width = static_cast<int>(width);
    texture.height = static_cast<int>(height);

    return texture;
}
