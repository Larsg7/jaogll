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

#ifndef SNAKE_SNAKE_ERROR_H
#define SNAKE_SNAKE_ERROR_H

#include <stdexcept>

namespace JOGL
{
#define JOAGLL_ERROR( m ) (JOGL::Jaogll_Error((m), __LINE__, __FILE__))

    /**
     * \brief Custom error class.
     * Reports line number and file.
     */
    class Jaogll_Error : public std::runtime_error
    {
    public:
        Jaogll_Error ( const std::string& msg, const int line, const char* file )
                : runtime_error( msg ), _line( line ), _file( file )
        {}

        const int get_line () const;

        const char* get_file () const;

    private:
        const int _line;
        const char* _file;
    };
}

#endif //SNAKE_SNAKE_ERROR_H
