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

#include <fstream>
#include <vector>
#include "../glsl_compiler.h"
#include "../error.h"
#include "../logger.h"


JOGL::GLSLCompiler::GLSLCompiler ()
    : _programID ( 0 )
      , _vertexShaderID ( 0 )
      , _fragmentShaderID ( 0 )
      , _numAttributes ( 0 )
{

}

void JOGL::GLSLCompiler::compileShaders ( const std::string& vertexShaderFilePath
                                 , const std::string& fragmentShaderFilePath )
{
    _vertexShaderID = glCreateShader( GL_VERTEX_SHADER );

    if ( _vertexShaderID == 0 )
    {
        throw JOAGLL_ERROR ( "Could not create vertex shader!" );
    }

    _fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );

    if ( _fragmentShaderID == 0 )
    {
        throw JOAGLL_ERROR ( "Could not create fragment shader!" );
    }

    compileShader( vertexShaderFilePath, _vertexShaderID );
    compileShader( fragmentShaderFilePath, _fragmentShaderID );

    JOGL::Logger::log( "Shaders were compiled successfully.", LogLevel::LOG_INFO );
}

void JOGL::GLSLCompiler::linkShaders ()
{
    //Attach our shaders to our program
    glAttachShader( _programID, _vertexShaderID );
    glAttachShader( _programID, _fragmentShaderID );

    //Link our program
    glLinkProgram( _programID );

    //Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv( _programID, GL_LINK_STATUS, &isLinked );
    if( isLinked == GL_FALSE )
    {
        GLint maxLength = 0;
        glGetProgramiv( _programID, GL_INFO_LOG_LENGTH, &maxLength );

        //The maxLength includes the NULL character
        std::vector<char> errorLog( (unsigned)maxLength );
        glGetProgramInfoLog( _programID, maxLength, &maxLength, &errorLog[0] );

        //We don't need the program anymore.
        glDeleteProgram( _programID) ;
        //Don't leak shaders either.
        glDeleteShader( _vertexShaderID );
        glDeleteShader( _fragmentShaderID );

        //Use the infoLog as you see fit.

        //In this simple program, we'll just leave
        throw JOAGLL_ERROR ( "Linking of shaders was unsuccessful: " + std::string ( &(errorLog[0]) ) );
    }

    //Always detach shaders after a successful link.
    glDetachShader( _programID, _vertexShaderID );
    glDetachShader( _programID, _fragmentShaderID );
    glDeleteShader( _vertexShaderID );
    glDeleteShader( _fragmentShaderID );

    JOGL::Logger::log( "Shaders were linked successfully.", LogLevel::LOG_INFO );
}

void JOGL::GLSLCompiler::addAttribute ( const std::string& attributeName )
{
    //glBindFragDataLocation( _programID, _numAttributes++, attributeName.c_str() );
    glBindAttribLocation( _programID, _numAttributes++, attributeName.c_str() );
}

GLint JOGL::GLSLCompiler::get_attrLocation ( const std::string& attributeName ) const
{
    return glGetAttribLocation( _programID, attributeName.c_str() );
}

GLint JOGL::GLSLCompiler::get_uniformLocation ( const std::string& uniformName )
{
    GLint location = glGetUniformLocation( _programID, uniformName.c_str() );
    if ( location == GL_INVALID_INDEX )
    {
       fprintf( stderr, "Uniform '%s' not found!", uniformName.c_str() );
    }
    return location;
}

void JOGL::GLSLCompiler::use ()
{
    glUseProgram( _programID );
    for ( GLuint i = 0; i < _numAttributes; ++i )
    {
        glEnableVertexAttribArray( i );
    }
}

void JOGL::GLSLCompiler::unuse ()
{
    glUseProgram( 0 );
    for ( GLuint i = 0; i < _numAttributes; ++i )
    {
        glDisableVertexAttribArray( i );
    }
}

JOGL::GLSLCompiler::~GLSLCompiler ()
{
    glDeleteProgram( _programID );
}

void JOGL::GLSLCompiler::compileShader ( const std::string& compilePath, const GLuint id )
{
    //Now time to link them together into a program.
    //Get a program object.
    _programID = glCreateProgram();

    std::ifstream file ( compilePath );

    if ( file.fail() )
    {
        throw JOAGLL_ERROR ( "Failed to open '" + compilePath + "'!" );
    }

    std::string fileContents = "";
    std::string line;

    // read file into fileContents
    while ( std::getline( file, line ) )
    {
        fileContents += line + "\n";
    }

    file.close();

    const char* contentsPtr = fileContents.c_str();
    glShaderSource( id, 1, &contentsPtr, nullptr );
    glCompileShader( id );

    GLint success;
    glGetShaderiv( id, GL_COMPILE_STATUS, &success );
    if ( success == GL_FALSE )
    {
        GLint maxLength = 0;
        glGetShaderiv( id, GL_INFO_LOG_LENGTH, &maxLength );

        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog ( (unsigned)maxLength );
        glGetShaderInfoLog( id, maxLength, &maxLength, &errorLog[0] );

        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader( id ); // Don't leak the shader.

        throw JOAGLL_ERROR ( "Compilation of shader " + compilePath + "was unsuccessful: "
                            + std::string( &(errorLog[0]) ) );
    }
}
