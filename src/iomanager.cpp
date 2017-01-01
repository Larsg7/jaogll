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

#include "../iomanager.h"
#include "../error.h"

#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <iterator>

bool JOGL::IOManager::read_file_to_buffer ( std::vector<unsigned char>& buffer, const std::string filePath )
{
    std::fstream file ( filePath, std::ios::binary | std::ios::in );

    if ( file.fail() )
    {
        throw JOAGLL_ERROR ( "Could not open file '" + filePath + "'!" );
    }

    file.seekg( 0, std::ios::end );

    long fileSize = file.tellg();

    file.seekg( 0, std::ios::beg );

    // Reduce by header size
    fileSize -= file.tellg();

    buffer.resize( fileSize );

    file.read( (char*)&(buffer[0]), fileSize );

    file.close();

    return true;
}

bool JOGL::IOManager::read_file_to_buffer_line ( std::vector<std::vector<unsigned char>>& buffer,
                                                 const std::string filePath )
{
    std::fstream file ( filePath, std::ios::in );

    if ( file.fail() )
    {
        throw JOAGLL_ERROR ( "Could not open file '" + filePath + "'!" );
    }

    std::string s;

    int lc = 0;

    while ( getline( file, s ) )
    {
        std::stringstream ss ( s );

        unsigned char c;

        std::vector<unsigned char> v ( s.size() );

        int cc = 0;

        while ( ss >> c )
        {
            assert( cc < v.size() );
            v[cc++] = c;
        }

        buffer.push_back( v );
    }

    file.close();

    return true;
}
