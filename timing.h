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

#ifndef SNAKE_TIMING_H
#define SNAKE_TIMING_H

namespace JOGL
{
    // TODO: Limiting does not work!
    class Fps_Limiter
    {
    public:

        void init ( unsigned int targetFPS );

        void begin_frame ();

        float end_frame ();

        void set_targetFPS ( unsigned int targetFPS );

        void limit ();

    private:
        unsigned int _maxFPS;
        unsigned int _prevTicks;
    };
}

#endif //SNAKE_TIMING_H
