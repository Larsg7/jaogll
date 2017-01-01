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

#ifndef SNAKE_SPRITE_BATCH_H
#define SNAKE_SPRITE_BATCH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include "vertex.h"

namespace JOGL
{
    /**
     * \brief Different sorting types for the textures in render_batch.
     */
    enum class GlyphSortType
    {
        NONE,
        FRONT_TO_BACK,
        BACK_TO_FRONT,
        TEXTURE
    };

    /**
     * \brief Struct holding information about a texture.
     */
    struct Glyph
    {
        GLuint texture;
        float depth;

        Vertex topLeft;
        Vertex bottomLeft;
        Vertex topRight;
        Vertex bottomRight;
    };

    typedef std::shared_ptr<Glyph> glyph_ptr;

    /**
     * \brief Struct holding information about a render batch.
     */
    struct Render_Batch
    {
        Render_Batch ( GLuint offset, GLuint numVertices, GLuint texture );

        GLuint offset;
        GLuint numVertices;
        GLuint texture;
    };

    class Sprite_Batch
    {
    public:
        Sprite_Batch ();

        virtual ~Sprite_Batch ();

        /**
         * \brief Calls createVertexArray.
         */
        void init ();

        /**
         * \brief Clears the vectors and sets sort type.
         * \param sortType
         */
        void begin ( GlyphSortType sortType = GlyphSortType::TEXTURE );

        /**
         * \brief Sorts _glyphs and calls createRenderBatches.
         */
        void end ();

        /**
         * \brief Creates a Glyph based on the arguments and stores it in _glyphs.
         * \param destRect Destination rectangle. x and y are the pos of the bottom left corner, z is the width and
         *                 w the height of the rectangle.
         * \param uvRect   UV coordinates, same as for destRect.
         * \param texture  Texture of the sprite.
         * \param color    Color of the sprite.
         * \param depth    Depth of the sprite.
         */
        void add_sprite ( const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, const Color& color,
                          float depth );

        /**
         * \brief Binds _vao and draws Render_Batches.
         */
        void render_batch ();

    private:
        void createRenderBatches ();
        void createVertexArray ();

        GLuint _vbo;
        GLuint _vao;

        GlyphSortType _sortType;

        std::vector<glyph_ptr> _glyphs;
        std::vector<Render_Batch> _renderBatches;
    };
}

#endif //SNAKE_SPRITE_BATCH_H
