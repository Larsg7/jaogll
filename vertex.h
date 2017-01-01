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

#ifndef SNAKE_VERTEX_H
#define SNAKE_VERTEX_H

#include <GL/gl.h>


namespace JOGL
{
    /**
     * \brief Struct holding information about a specific color.
     */
    struct Color
    {
        Color ()
        {}

        Color ( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha )
                : red( red ), green( green ), blue( blue ), alpha( alpha )
        {}

        GLubyte red;
        GLubyte green;
        GLubyte blue;
        GLubyte alpha;
    };

    struct Position
    {
        Position ()
        {}

        Position ( float x, float y )
                : x( x ), y( y )
        {}

        float x;
        float y;
    };

    /**
     * \brief Position of the texture
     */
    struct UV
    {
        UV ()
        {}

        UV ( float u, float v )
                : u( u ), v( v )
        {}

        float u;
        float v;
    };

    /**
     * \brief Struct holding information about a vertex
     * Needs to be multiple of 4 bytes in size
     */
    struct Vertex
    {
        Vertex ()
        {}

        Vertex ( const Position& position, const Color& color, const UV& uv )
                : position( position ), color( color ), uv( uv )
        {}

        Position position;

        Color color;

        UV uv;

        void setColor ( GLubyte r, GLubyte g, GLubyte b, GLubyte a )
        {
            color.red = r;
            color.green = g;
            color.blue = b;
            color.alpha = a;
        }

        void setPosition ( float x, float y )
        {
            position.x = x;
            position.y = y;
        }

        void setUV ( float u, float v )
        {
            uv.u = u;
            uv.v = v;
        }
    };
}

#endif //SNAKE_VERTEX_H
