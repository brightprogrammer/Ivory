#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <SFML/Graphics.hpp>

#include <Container.hpp>
#include <GameConfig.hpp>
#include <Colors.hpp>
#include <Ui/Clickable.hpp>

#include <Game.hpp>

int main() {
    Game::Initialize();

    sf::RenderWindow window(sf::VideoMode(GameConfig::GetWindowWidth(), GameConfig::GetWindowHeight()), "OutScal Assignment - Ivory");
    window.setVerticalSyncEnabled(true);

    sf::Image image;
    image.create(50, 50, sf::Color::White);

    sf::Text bottom_menu_text;
    bottom_menu_text.setFont(GameConfig::GetFont());
    bottom_menu_text.setCharacterSize(GameConfig::GetTitleCharacterSize()/2);
    bottom_menu_text.setString("Press (E - Equip) (C - Consume) (M - Move) (D - Drop)");
    bottom_menu_text.setPosition(GameConfig::GetWallSpacing(), GameConfig::GetWindowHeight() - bottom_menu_text.getLocalBounds().height - GameConfig::GetWallSpacing());

    while(window.isOpen()) {
        sf::Event wevent;
        while(window.pollEvent(wevent)) {
            switch(wevent.type) {
                case sf::Event::EventType::Closed: {
                    window.close(); break;
                }
                case sf::Event::EventType::MouseButtonPressed : {
                    sf::Vector2i pos = {wevent.mouseButton.x, wevent.mouseButton.y};
                    if(Game::inventory.IsClicked(pos)) {
                        Game::inventory.OnClick(pos);
                        Game::equipped.ResetSelection();
                    } else if(Game::equipped.IsClicked(pos)) {
                        Game::equipped.OnClick(pos);
                        Game::inventory.ResetSelection();
                    } else {
                        Game::inventory.ResetSelection();
                        Game::equipped.ResetSelection();
                    }
                }
                case sf::Event::EventType::KeyPressed : {
                    switch(wevent.key.code) {
                        case sf::Keyboard::E:
                            if(Game::inventory.IsSelected()) Game::inventory.EquipSelection();
                            if(Game::equipped.IsSelected()) {
                                std::cerr << "Why would you want to do something that's already done????" << std::endl;
                            }
                            break;
                        case sf::Keyboard::D:
                            if(Game::inventory.IsSelected()) Game::inventory.DropSelection();
                            else if(Game::equipped.IsSelected()) Game::equipped.DropSelection();
                            break;
                        case sf::Keyboard::M:
                            if(Game::inventory.IsSelected()) Game::inventory.MoveSelection();
                            else if(Game::equipped.IsSelected()) Game::equipped.MoveSelection();
                            break;
                        case sf::Keyboard::C:
                            if(Game::inventory.IsSelected()) Game::inventory.ConsumeSelection();
                            else if(Game::equipped.IsSelected()) Game::equipped.ConsumeSelection();
                            break;
                        default: break;
                    }
                }
                default: break;
            }
        }

        window.clear(IV_WINDOW_CLEAR_COLOR);

        Game::inventory.DrawSelf(window);
        Game::equipped.DrawSelf(window);

        if(Game::inventory.IsSelected() || Game::equipped.IsSelected()) {
            window.draw(bottom_menu_text);
        }

        window.display();
    }

    return 0;
}
