#include <Game.hpp>
#include <GameConfig.hpp>

void Game::Initialize() {
    GameConfig::Initialize();
    if(!is_loaded) {
        item_loader.LoadFromFile(IV_ITEM_ICONS_PATH + std::string("Load.conf"));
        inventory = Container(IV_INVENTORY_ROWS, IV_INVENTORY_COLS, IV_INVENTORY_NAME);
        equipped = Container(IV_EQUIPPED_ROWS, IV_EQUIPPED_COLS, IV_EQUIPPED_NAME);
        is_loaded = true;
    }
}
