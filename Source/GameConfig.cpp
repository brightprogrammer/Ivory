#include <GameConfig.hpp>

/**
 * Create a new game config.
 * This will create a new @c sf::RenderWindow of given size
 * and will automatically set up some default config settings
 *
 * @param win_width
 * */
void GameConfig::Initialize(){
    if(!m_is_initialized) {
        /* load a default font for basic usage
         * if loading fails then mission abort!!
         * */
        if(!m_font.loadFromFile("bin/Assets/Fonts/minecrafter/Minecrafter.Reg.ttf")) {
                    /* show error message on top of that shown by SFML */
            std::cerr << "[ERR] Failed to load default font for GameConfig" << std::endl;
            abort();
        }
        m_is_initialized = true;
    }
}
