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

#ifndef SNAKE_CAMERA2D_H
#define SNAKE_CAMERA2D_H

#include <glm/gtc/matrix_transform.hpp>

namespace JOGL
{
    /**
     * \brief 2D camera class.
     * Used to move the camera and translate to screen/world coords.
     */
    class Camera2D
    {
    public:
        Camera2D ();

        void init ( int screen_width, int screen_height );

        void update ();

        void setScale ( float scale );

        void setPosition ( const glm::vec2& position );

        const glm::vec2& getPosition () const;

        float getScale () const;

        const glm::mat4& getCameraMatrix () const;

        const glm::vec2 convert_screen_to_world ( glm::vec2& screenCoords );

    private:
        int _screen_width;
        int _screen_height;
        bool _needsChange;
        float _scale;
        glm::vec2 _position;
        glm::mat4 _cameraMatrix;
        glm::mat4 _orthoMatrix;
    };
}

#endif //SNAKE_CAMERA2D_H
