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

#include "../input_manager.h"

JOGL::Input_Manager::Input_Manager ()
        : _mouseCoords( 0, 0 )
{}

void JOGL::Input_Manager::press_key ( unsigned int keyID )
{
    _keyMap[keyID] = true;
}

void JOGL::Input_Manager::release_key ( unsigned int keyID )
{
    _keyMap[keyID] = false;
}

void JOGL::Input_Manager::set_mouse_coords ( float x, float y )
{
    _mouseCoords.x = x;
    _mouseCoords.y = y;
}

bool JOGL::Input_Manager::is_key_presses ( unsigned int keyID )
{
    if ( _keyMap.find( keyID ) != _keyMap.end() )
    {
        return _keyMap[keyID];
    }
    return false;
}

const glm::vec2& JOGL::Input_Manager::get_mouse_coords () const
{
    return _mouseCoords;
}
