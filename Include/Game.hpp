#ifndef IVORY_GAME_HPP
#define IVORY_GAME_HPP

#include <ItemLoader.hpp>
#include <Container.hpp>
#include <Compartment.hpp>
#include <GameStaticSettings.hpp>

/**
 * Represents the whole state of game application.
 * Contains everything that major components require.
 * This is basically the connection between items, containers, components etc...
 * */
class Game {
    public:
        static void Initialize();
        static inline ItemLoader item_loader;
        static inline Container inventory;
        static inline Container equipped;
    private:
        Game() = default;
        static inline bool is_loaded = false;
};

#endif // IVORY_GAME_HPP
