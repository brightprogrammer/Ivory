/**
 * @file AssetManager.hpp
 * @author Siddharth Mishra (admin@brightprogrammer.in)
 * @copyright All rights reserved (c) 2023
 * @date October, 26th 2023
 *
 * Asset Manager is responsible for providing
 * preloaded access to assets. This includes
 * things like fonts, textures, sound effects etc...
 * */

#ifndef IVORY_ASSET_MANAGER_HPP
#define IVORY_ASSET_MANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class AssetManager {
public:
    AssetManager();

    void AddTexture(const std::string& texname, const sf::Texture& texture);
    void AddColor(const std::string& colname, const sf::Color& color);

    const sf::Font& GetFont();
    const sf::Texture& GetTexture(const std::string& texname);
    const sf::Color& GetColor(const std::string& colname);
private:
    sf::Font m_font;
    std::unordered_map<std::string, sf::Texture> m_textures;
    std::unordered_map<std::string, sf::Color> m_colors;
};

#endif // IVORY_ASSET_MANAGER_HPP
