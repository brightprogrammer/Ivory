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

#ifndef IVORY_GAME_CONFIG_HPP
#define IVORY_GAME_CONFIG_HPP

#include "Colors.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>

#include <Colors.hpp>

/**
 * @c GameConfig is responsible for storing and loading game configuration (settings).
 * This is (kind of) singleton class. There is only one instance of each of it's member.
 * */
class GameConfig {
    public:
        /**
         * Initialize the GameConfig object.
         * This must be called only once at the startup phase..
         * Any follow up calls is redundant and this function will simply make an early exit.
         * */
        static void Initialize();

        /**
         * Get last set window width.
         *
         * @return Window width in pixels.
         * */
        static inline size_t GetWindowWidth() { return m_window_width; }

        /**
         * Set a new window width.
         *
         * @param w Window width in pixels.
         * */
        static inline void SetWindowWidth(size_t w) {
            if(w) m_window_width = w;
        }

        /**
         * Get last set window height.
         *
         * @return Window height in pixels.
         * */
        static inline size_t GetWindowHeight() { return m_window_height; }

        /**
         * Set a new window height.
         *
         * @return Window height in pixels.
         * */
        static inline void SetWindowHeight(size_t h) {
            if(h) m_window_height = h;
        }

        /**
         * Get compartment size.
         * A compartment is a box where items are displayed.
         * This size depends on the size of items in pixels..
         *
         * @return Compartment size in pixels.
         * */
        static inline size_t GetCompartmentSize() { return m_compartment_size; }

        /**
         * Set compartment size.
         * A compartment is a box where items are displayed.
         * This size depends on the size of items in pixels..
         *
         * @param sz Compartment size in pixels.
         * */
        static inline void SetCompartmentSize(size_t sz) {
            if(sz && sz < m_window_width && sz < m_window_height) {
                m_compartment_size = sz;
            } else {
                std::cerr << "[ERR] Invalid compartment size provided to GameConfig\n"
                          << "Compartment size mustn't be zero or greater than window size" << std::endl;
            }
        }

        /**
         * Get compartment spacing used in game.
         * Compartment spacing is spacing between any two compartments.
         *
         * @return Compartment spacing in pixels
         * */
        static inline size_t GetCompartmentSpacing() { return m_compartment_spacing; }

        /**
         * Set compartment spacing to be used in game.
         * Compartment spacing is spacing between any two compartments.
         *
         * @param sz Compartment spacing in pixels
         * */
        static inline void SetCompartmentSpacing(size_t sz) {
            if(sz < m_window_width &&
               sz < m_window_height) {
               m_compartment_spacing = sz;
            } else {
                std::cerr << "[ERR] Invalid compartment spacing provided to GameConfig\n"
                          << "Spacing mustn't be zero or greater than window size" << std::endl;
            }
        }

        /**
         * Get wall spacing used in game.
         * Wall spacing is spacing between compartments and container walls.
         *
         * @return Wall spacing in pixels
         * */
        static inline size_t GetWallSpacing() { return m_wall_spacing; }

        /**
         * Set wall spacing to be used in game.
         * Wall spacing is spacing between compartments and container walls.
         *
         * @param sz Wall spacing in pixels
         * */
        static inline void SetWallSpacing(size_t sz) {
            if(sz < m_window_width &&
               sz < m_window_height) {
                m_wall_spacing = sz;
            } else {
                std::cerr << "[ERR] Invalid wall spacing provided to GameConfig\n"
                          << "Spacing mustn't be zero or greater than window size" << std::endl;
            }
        }

        /**
         * Get title string character size in pixels.
         * This will be used for sizing text in container titles.
         *
         * @return Character size in pixels
         * */
        static inline size_t GetTitleCharacterSize() { return m_title_character_size; }

        /**
         * Set a new character size in pixels.
         *
         * @param sz Character size in pixels.
         * */
        static inline void SetTitleCharacterSize(size_t sz) {
            if(sz) m_title_character_size = sz;
        }

        /**
         * Get vertical spacing in pixels.
         * Vertical spacing is space left on top and bottom of title text
         * when being placed at the title box on top of a @c Container.
         *
         * @return size_t Vertical spoacing in pixels.
         * */
        static inline size_t GetTitleVerticalSpacing() { return m_title_vertical_spacing; }

        /**
         * Set a new title vertical spacing.
         *
         * @param sz Spacing size in pixels.
         * */
        static inline void SetTitleVerticalSpacing(size_t sz) { if(sz) m_title_vertical_spacing = sz; }

        /**
         * Get horizontal spacing in pixels.
         * Horizontal spacing is space left on top and bottom of title text
         * when being placed at the title box on top of a @c Container.
         *
         * @return size_t Horizontal spoacing in pixels.
         * */
        static inline size_t GetTitleHorizontalSpacing() { return m_title_horizontal_spacing; }

        /**
         * Set a new title horizontal spacing.
         *
         * @param sz Spacing size in pixels.
         * */
        static inline void SetTitleHorizontalSpacing(size_t sz) { if(sz) m_title_horizontal_spacing = sz; }

        /**
         * Get currently loaded font.
         * A basic font is loaded by default.
         *
         * @return @c sf::Font object.
         * */
        static inline const sf::Font& GetFont() { return m_font; }

        /**
         * Load a new font from given file.
         * A default font is already loaded. This will override the previous
         * font if loaded successfully.
         *
         * @param font_path Path of font.
         * */
        static inline void SetFont(const std::string& font_path) {
            sf::Font tmpfont;
            if(tmpfont.loadFromFile(font_path)) m_font = tmpfont;
        }

        /**
         * Get compartment color.
         *
         * @return A const reference to internal @c sf::Color object.
         * */
        static inline const sf::Color& GetCompartmentColor() { return m_compartment_color; }

        /**
         * Set a new compartment color.
         *
         * @param color
         * */
        static inline void SetCompartmentColor(const sf::Color& color) { m_compartment_color = color; }

        /**
         * Get container color.
         *
         * @return A const reference to internal @c sf::Color object.
         * */
        static inline const sf::Color& GetContainerColor() { return m_container_color; }

        /**
         * Set a new container color.
         *
         * @param color
         * */
        static inline void SetContainerColor(const sf::Color& color) { m_container_color = color; }

        /**
         * Get title text color.
         *
         * @return A const reference to internal @c sf::Color object.
         * */
        static inline const sf::Color& GetTitleTextColor() { return m_title_text_color; }

        /**
         * Set a new title text color.
         *
         * @param color
         * */
        static inline void SetTitleTextColor(const sf::Color& color) { m_title_text_color = color; }

        /**
         * Get title bg color.
         *
         * @return A const reference to internal @c sf::Color object.
         * */
        static inline const sf::Color& GetTitleBgColor() { return m_title_bg_color; }

        /**
         * Set a new title bg color.
         *
         * @param color
         * */
        static inline void SetTitleBgColor(const sf::Color& color) { m_title_bg_color = color; }

    private:
        GameConfig() = delete;

        /* game config is initialized only once when this variable is false */
        static inline bool m_is_initialized = false;

        static inline size_t m_window_width = 960;
        static inline size_t m_window_height = 540;
        static inline size_t m_compartment_size = 50;
        static inline size_t m_compartment_spacing = 6;
        static inline size_t m_wall_spacing = 8;
        static inline size_t m_title_character_size = 20;
        static inline size_t m_title_vertical_spacing = 5;
        static inline size_t m_title_horizontal_spacing = 5;

        static inline sf::Font m_font;

        static inline sf::Color m_compartment_color = IV_COMPARTMENT_COLOR;
        static inline sf::Color m_container_color = IV_CONTAINER_COLOR;
        static inline sf::Color m_title_text_color = IV_TITLE_TEXT_COLOR;
        static inline sf::Color m_title_bg_color = IV_TITLE_BG_COLOR;
};

#endif // IVORY_GAME_CONFIG_HPP
