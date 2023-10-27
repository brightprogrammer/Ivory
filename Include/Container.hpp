#ifndef IVORY_CONTAINER_HPP
#define IVORY_CONTAINER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include <Compartment.hpp>
#include <Ui/Clickable.hpp>

/**
 * A container has multiple compartments and a title.
 * There will be two types of containers in the inventory :
 * - Inventory
 * - Equipped
 *
 * Each container has different shape and has different purpose.
 * */
class Container : public Clickable {
    public:
        Container() = default;
        Container(size_t nrows, size_t ncols, const std::string& name);

        void DrawSelf(sf::RenderWindow& win);
        bool OnClick(const sf::Vector2i& pos, bool left_click) override;

        inline const sf::Vector2f& GetPosition() { return m_position; }
        void SetPosition(const sf::Vector2f& pos);
    private:
        size_t ComputeContainerWidth();
        size_t ComputeContainerHeight();
        size_t ComputeTitleBgWidth();
        size_t ComputeTitleBgHeight();

        sf::Vector2f ComputeTitleBgPosition();
        sf::Vector2f ComputeTitleTextPosition();
        sf::Vector2f ComputeCompartmentPosition(size_t r, size_t c);

        size_t m_rows;
        size_t m_cols;
        std::vector<Compartment> m_compartments;

        sf::Text m_title_text;
        sf::Sprite m_body; /* background sprite for compartments */
        sf::Sprite m_title_bg; /* background for heading sprite */

        sf::Vector2f m_position;
};

#endif // IVORY_CONTAINER_HPP
