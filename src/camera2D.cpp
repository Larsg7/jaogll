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

#include "../camera2D.h"

JOGL::Camera2D::Camera2D ()
    : _position ( 0, 0 )
      , _cameraMatrix ( 1.0f )
      , _scale ( 1 )
      , _needsChange ( true )
      , _screen_height ( 0 )
      , _screen_width ( 0 )
      , _orthoMatrix ( 0 )
{
}

void JOGL::Camera2D::init ( int screen_width, int screen_height )
{
    _screen_width = screen_width;
    _screen_height = screen_height;
    _orthoMatrix = glm::ortho( 0.0f, (float)_screen_width, 0.0f, (float)_screen_height );
}

void JOGL::Camera2D::update ()
{
    if ( _needsChange )
    {
        glm::vec3 translate ( -_position.x + _screen_width / 2, - _position.y + _screen_height / 2, 0.0f );
        _cameraMatrix = glm::translate( _orthoMatrix, translate );

        glm::vec3 scale ( _scale, _scale, 0.0f );
        _cameraMatrix = glm::scale( glm::mat4(1.0f), scale ) * _cameraMatrix;

        _needsChange = false;
    }
}

void JOGL::Camera2D::setPosition ( const glm::vec2& position )
{
    Camera2D::_position = position;
    _needsChange = true;
}

const glm::vec2& JOGL::Camera2D::getPosition () const
{
    return _position;
}

void JOGL::Camera2D::setScale ( float scale )
{
    Camera2D::_scale = scale;
    _needsChange = true;
}

float JOGL::Camera2D::getScale () const
{
    return _scale;
}

const glm::mat4& JOGL::Camera2D::getCameraMatrix () const
{
    return _cameraMatrix;
}

const glm::vec2 JOGL::Camera2D::convert_screen_to_world ( glm::vec2& screenCoords )
{
    // zero is center
    screenCoords -= glm::vec2 ( _screen_width / 2, _screen_height / 2 );
    // scale the coordinates
    screenCoords /= _scale;
    // translate
    screenCoords += _position;

    return screenCoords;
}
