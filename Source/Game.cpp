#include <Game.hpp>
#include <GameConfig.hpp>

void Game::Initialize() {
    GameConfig::Initialize();
    if(!is_loaded) {
        item_loader.LoadFromFile(IV_ITEM_ICONS_PATH + std::string("Load.conf"));

        inventory = Container(IV_INVENTORY_ROWS, IV_INVENTORY_COLS, IV_INVENTORY_NAME);
        inventory.SetPosition({100, 100});

        equipped = Container(IV_EQUIPPED_ROWS, IV_EQUIPPED_COLS, IV_EQUIPPED_NAME);
        equipped.SetPosition({400, 400});

        is_loaded = true;
    }
}
