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

#include <SDL2/SDL.h>
#include <vector>
#include <numeric>
#include "../jaogll.h"
#include "../error.h"

int JOGL::init ()
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::string error ( SDL_GetError() );
        throw JOAGLL_ERROR( "Error initializing SDL: " + error );
    }

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
//    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
//    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    return 0;
}
