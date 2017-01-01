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

#ifndef SNAKE_IOMANAGER_H
#define SNAKE_IOMANAGER_H

#include <vector>
#include <string>

namespace JOGL
{
    class IOManager
    {
    public:
        /**
         * \brief Read contents of a file into a buffer.
         * \param buffer   Vector of chars.
         * \param filePath File to read.
         * \return Bool if successful.
         */
        static bool read_file_to_buffer ( std::vector<unsigned char>& buffer, const std::string filePath );

        /**
         * \brief Read contents of a file into a buffer placing each line into a separate vector.
         * \param buffer   Vector of vector of chars.
         * \param filePath File to read.
         * \return Bool if successful.
         */
        static bool read_file_to_buffer_line ( std::vector<std::vector<unsigned char>>& buffer, const std::string filePath );
    };
}

#endif //SNAKE_IOMANAGER_H
