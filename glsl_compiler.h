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

#ifndef SNAKE_GLSLPROGRAM_H
#define SNAKE_GLSLPROGRAM_H

#include <string>
#include <GL/glew.h>

namespace JOGL
{
/**
 * \brief Class to Compile and Link GLSL code
 * Supports vertex and fragment shaders.
 */
    class GLSLCompiler
    {
    public:
        GLSLCompiler ();

        virtual ~GLSLCompiler ();

        /**
         * \brief Method to compile a vertex and a fragment shader
         * \param vertexShaderFilePath
         * \param fragmentShaderFilePath
         */
        void compileShaders ( const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath );

        void linkShaders ();

        void addAttribute ( const std::string& attributeName );

        GLint get_attrLocation ( const std::string& attributeName ) const;

        GLint get_uniformLocation ( const std::string& uniformName );

        void use ();

        void unuse ();

    private:
        GLuint _programID;
        GLuint _vertexShaderID;
        GLuint _fragmentShaderID;

        GLuint _numAttributes;

        /**
         * \brief Method to compile one shader
         * \param compilePath
         * \param id
         */
        void compileShader ( const std::string& compilePath, const GLuint id );
    };
}

#endif //SNAKE_GLSLPROGRAM_H
