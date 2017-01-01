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

#ifndef SNAKE_LOGGING_H
#define SNAKE_LOGGING_H

#include <string>

namespace JOGL
{
    enum class LogLevel {
        LOG_ERROR
        , LOG_Warning
        , LOG_INFO
        , LOG_DEBUG
    };

    class Logger
    {
    public:
        static void log ( const std::string& msg, LogLevel logLevel )
        {
            if ( logLevel <= current_log_level )
            {
                switch ( logLevel )
                {
                    case LogLevel::LOG_ERROR:
                        fprintf( stderr, "ERROR: %s\n", msg.c_str() );
                        break;
                    case LogLevel::LOG_Warning:
                        fprintf( stderr, "WARNING: %s\n", msg.c_str() );
                        break;
                    case LogLevel::LOG_INFO:
                        printf( "INFO: %s\n", msg.c_str() );
                        break;
                    default:
                        printf( "LOG: %s\n", msg.c_str() );
                        break;
                }
            }
        }

        static LogLevel current_log_level;
    };
}

#endif //SNAKE_LOGGING_H
