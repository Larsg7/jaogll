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

#ifndef SNAKE_INPUT_MANAGER_H
#define SNAKE_INPUT_MANAGER_H

#include <unordered_map>
#include <glm/glm.hpp>

namespace JOGL
{
    /**
     * \brief Class to keep track of which key is pressed and where the mouse is.
     */
    class Input_Manager
    {
    public:
        Input_Manager ();

        void press_key ( unsigned int keyID );
        void release_key ( unsigned int keyID );

        void set_mouse_coords( float x, float y );

        const glm::vec2& get_mouse_coords () const;

        bool is_key_presses ( unsigned int keyID );

    private:
        std::unordered_map<unsigned int, bool> _keyMap;
        glm::vec2 _mouseCoords;
    };
}

#endif //SNAKE_INPUT_MANAGER_H