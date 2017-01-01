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

#include <algorithm>
#include "../sprite_batch.h"
#include "../logger.h"

JOGL::Render_Batch::Render_Batch ( GLuint offset, GLuint numVertices, GLuint texture )
        : offset ( offset ), numVertices ( numVertices ), texture ( texture )
{}

JOGL::Sprite_Batch::Sprite_Batch ()
        : _vbo( 0 ), _vao( 0 )
{}

void JOGL::Sprite_Batch::init ()
{
    createVertexArray();
}

void JOGL::Sprite_Batch::begin ( GlyphSortType sortType /* GlyphSortType::TEXTURE */ )
{
    _sortType = sortType;
    _renderBatches.clear();

    // no need to delete entries in _glyphs because their are smart pointers

    _glyphs.clear();
}

void JOGL::Sprite_Batch::end ()
{
    switch ( _sortType )
    {
        case GlyphSortType::FRONT_TO_BACK:
            std::stable_sort( _glyphs.begin(), _glyphs.end(), []( glyph_ptr A, glyph_ptr B ) {
                return A->depth < B->depth;
            });
            break;
        case GlyphSortType::BACK_TO_FRONT:
            std::stable_sort( _glyphs.begin(), _glyphs.end(), []( glyph_ptr A, glyph_ptr B ) {
                return A->depth > B->depth;
            });
            break;
        case GlyphSortType::TEXTURE:
            std::stable_sort( _glyphs.begin(), _glyphs.end(), []( glyph_ptr A, glyph_ptr B ) {
                return A->texture < B->texture;
            });
            break;
        default:
            JOGL::Logger::log( "Sort type unknown in class Sprite_Batch!", JOGL::LogLevel::LOG_Warning );
            break;
    }
    //printf( "First glyph: %f\n", _glyphs.front()->bottomLeft.position.x );

    createRenderBatches();
}

void JOGL::Sprite_Batch::add_sprite ( JOGL::Sprite sprite )
{
    /*  -destRect.z->
     * TL----------TR  ^
     * |            |  |
     * |            | destRect.w
     * |            |  |
     * BL----------BR
     */

    glm::vec4 destRect = sprite.pos;
    glm::vec4 uvRect = sprite.uv;


    glyph_ptr newGlyph ( new JOGL::Glyph );

    newGlyph->texture = sprite.texture.id;
    newGlyph->depth = sprite.depth;

    newGlyph->topLeft.color = sprite.color;
    newGlyph->topLeft.setPosition( destRect.x, destRect.y + destRect.w );
    newGlyph->topLeft.setUV( uvRect.x, uvRect.y + uvRect.w );

    newGlyph->bottomLeft.color = sprite.color;
    newGlyph->bottomLeft.setPosition( destRect.x, destRect.y );
    newGlyph->bottomLeft.setUV( uvRect.x, uvRect.y );

    newGlyph->topRight.color = sprite.color;
    newGlyph->topRight.setPosition( destRect.x + destRect.z, destRect.y + destRect.w );
    newGlyph->topRight.setUV( uvRect.x + uvRect.z, uvRect.y + uvRect.w);

    newGlyph->bottomRight.color = sprite.color;
    newGlyph->bottomRight.setPosition( destRect.x + destRect.z, destRect.y );
    newGlyph->bottomRight.setUV( uvRect.x + uvRect.z, uvRect.y );

    _glyphs.push_back( newGlyph );
}

void JOGL::Sprite_Batch::render_batch ()
{
    glBindVertexArray( _vao );

    for ( auto& r : _renderBatches )
    {
        //printf( "Texture: %d, offset: %d, vertices: %d\n", r.texture, r.offset, r.numVertices );
        glBindTexture( GL_TEXTURE_2D, r.texture );
        glDrawArrays( GL_TRIANGLES, r.offset, r.numVertices );
    }

    glBindVertexArray( 0 );
}

void JOGL::Sprite_Batch::createRenderBatches ()
{
    std::vector<Vertex> vertices ( _glyphs.size() * 6 );

    if ( _glyphs.empty() )
    {
        return;
    }

    int offset = 0;
    int cv = 0; // current vertex
    _renderBatches.emplace_back( offset, 6, _glyphs[0]->texture );
    vertices[cv++] = _glyphs[0]->topLeft;
    vertices[cv++] = _glyphs[0]->bottomLeft;
    vertices[cv++] = _glyphs[0]->bottomRight;
    vertices[cv++] = _glyphs[0]->bottomRight;
    vertices[cv++] = _glyphs[0]->topRight;
    vertices[cv++] = _glyphs[0]->topLeft;
    offset += 6;

    for ( int cg = 1; cg < _glyphs.size(); ++cg, offset += 6 ) // current glyph
    {
        if ( _glyphs[cg]->texture != _glyphs[cg-1]->texture )
        {
            _renderBatches.emplace_back( offset, 6, _glyphs[cg]->texture );
        }
        else
        {
            _renderBatches.back().numVertices += 6;
        }
        vertices[cv++] = _glyphs[cg]->topLeft;
        vertices[cv++] = _glyphs[cg]->bottomLeft;
        vertices[cv++] = _glyphs[cg]->bottomRight;
        vertices[cv++] = _glyphs[cg]->bottomRight;
        vertices[cv++] = _glyphs[cg]->topRight;
        vertices[cv++] = _glyphs[cg]->topLeft;
    }

    glBindBuffer( GL_ARRAY_BUFFER, _vbo );
    // orphan the buffer
    glBufferData( GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW );
    // upload data
    glBufferSubData( GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data() );

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void JOGL::Sprite_Batch::createVertexArray ()
{
    if ( _vao == 0)
    {
        glGenVertexArrays( 1, &_vao );
    }
    glBindVertexArray( _vao );

    if ( _vbo == 0 )
    {
        glGenBuffers( 1, &_vbo );
    }
    glBindBuffer( GL_ARRAY_BUFFER, _vbo );

    glEnableVertexAttribArray( 0 );
    glEnableVertexAttribArray( 1 );
    glEnableVertexAttribArray( 2 );

    // This is the position attribute pointer
    glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)offsetof( Vertex, position ) );
    // This is the color attribute pointer
    glVertexAttribPointer( 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof( Vertex ), (void*)offsetof( Vertex, color ) );
    // This is the UV attribute pointer
    glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)offsetof( Vertex, uv ) );

    glBindVertexArray( 0 );
}

JOGL::Sprite_Batch::~Sprite_Batch ()
{

}
