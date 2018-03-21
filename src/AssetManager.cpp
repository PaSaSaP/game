#include "AssetManager.h"


void AssetManager::loadTexture(std::string const& name, std::string const& filePath)
{
    sf::Texture texture;

    if (texture.loadFromFile(filePath))
    {
        this->_textures[name] = texture;
    }
}

sf::Texture &AssetManager::getTexture(std::string const& name)
{
    return this->_textures.at(name);
}

void AssetManager::loadFont(std::string const& name, std::string const& filePath, bool overwrite)
{
    if (!overwrite && doesFontExists(name))
    {
        return;
    }

    sf::Font font;

    if (font.loadFromFile(filePath))
    {
        this->_fonts[name] = font;
    }
}

bool AssetManager::doesFontExists(std::string const &name) const
{
    return (_fonts.find(name) != _fonts.end());
}

sf::Font &AssetManager::getFont(std::string const& name)
{
    return this->_fonts.at(name);
}
