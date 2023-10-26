#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Container.hpp>
#include <GameConfig.hpp>
#include <Colors.hpp>
#include <Ui/Clickable.hpp>

int main() {
    GameConfig::Initialize();

    sf::RenderWindow window(sf::VideoMode(GameConfig::GetWindowWidth(), GameConfig::GetWindowHeight()), "OutScal Assignment - Ivory");
    window.setVerticalSyncEnabled(true);

    sf::Image image;
    image.create(50, 50, sf::Color::White);

    Container inventory(4, 6, "Inventory"); inventory.SetPosition({100, 100});
    Container equipped(1, 8, "Equipped"); equipped.SetPosition({400, 400});

    while(window.isOpen()) {
        sf::Event wevent;
        while(window.pollEvent(wevent)) {
            switch(wevent.type) {
                case sf::Event::EventType::Closed: {
                    window.close(); break;
                }
                case sf::Event::EventType::MouseButtonPressed : {
                    sf::Vector2i pos = {wevent.mouseButton.x, wevent.mouseButton.y};
                    if(inventory.IsClicked(pos)) {
                        inventory.OnClick(pos);
                    } else if(equipped.IsClicked(pos)) {
                        equipped.OnClick(pos);
                    }
                }
                default: break;
            }
        }

        window.clear(IV_WINDOW_CLEAR_COLOR);

        inventory.DrawSelf(window);
        equipped.DrawSelf(window);

        window.display();
    }

    return 0;
}
