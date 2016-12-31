#include "../sprite.h"
#include "../resource_manager.h"

JOGL::Sprite::Sprite ( float x, float y, float width, float height, const Color& image_color, const std::string& image_path )
{
    texture = JOGL::ResourceManager::getTexture( image_path );
    pos = glm::vec4 ( x, y, width, height );
    uv = glm::vec4 ( 0.0f, 0.0f, 1.0f, 1.0f );
    color = image_color;
}