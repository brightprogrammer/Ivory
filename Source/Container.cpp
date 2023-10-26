#include <Container.hpp>
#include <GameConfig.hpp>
#include <cassert>

/**
 * Create a new container.
 * A container forms a matrix of compartments.
 *
 * @param nrows Number of rows for compartments.
 * @param ncols Number of cols for compartments.
 * @param name Title/Name of this container..
 * */
Container::Container(size_t nrows, size_t ncols, const std::string& name) :
    m_rows(nrows), m_cols(ncols)
{
    assert(nrows && ncols);

    m_title_text.setFont(GameConfig::GetFont());
    m_title_text.setString(name);
    m_title_text.setFillColor(GameConfig::GetTitleTextColor());
    m_title_text.setCharacterSize(GameConfig::GetTitleCharacterSize());
    m_title_text.setPosition(ComputeTitleTextPosition());

    /* compute total size of container */
    width = ComputeContainerWidth();
    height = ComputeContainerHeight();

    sf::Image img;
    sf::Texture texture;

    /* create sprite for title background*/
    img.create(ComputeTitleBgWidth(), ComputeTitleBgHeight(), sf::Color::White);
    texture.loadFromImage(img);
    m_title_bg.setTexture(texture);
    m_title_bg.setPosition(ComputeTitleBgPosition());
    m_title_bg.setColor(GameConfig::GetTitleBgColor());

    /* create sprite for container background */
    img.create(width, height, sf::Color::White);
    texture.loadFromImage(img);
    m_body.setTexture(texture);
    m_body.setPosition(m_position);
    m_body.setColor(GameConfig::GetContainerColor());

    /* create compartments and position them */
    m_compartments.resize(nrows*ncols, Compartment());
    for(size_t r = 0; r < nrows; r++) {
        for(size_t c = 0; c < ncols; c++) {
            Compartment& ref = m_compartments[r*ncols + c];
            ref.SetPosition(ComputeCompartmentPosition(r, c));

            /* add this compartment event handler to this event handler */
            AddChild(ref);
        }
    }
}

/**
 * Draw this container to screen.
 *
 * @param win Window to draw self to.
 * */
void Container::DrawSelf(sf::RenderWindow& win) {
    /* draw title bg sprite */
    win.draw(m_title_bg);
    win.draw(m_title_text);

    /* draw background sprite */
    win.draw(m_body);

    /* draw all compartments */
    for(size_t r = 0; r < m_rows; r++) {
        for(size_t c = 0; c < m_cols; c++) {
            m_compartments[r*m_cols + c].DrawSelf(win);
        }
    }
}

bool Container::OnClick(const sf::Vector2i& pos) {
    if(!DispatchEventToChildren(pos)) {
        std::cout << m_title_text.getString().toAnsiString() << " was clicked!!" << std::endl;
    }

    return false;
}

void Container::SetPosition(const sf::Vector2f& pos) {
    m_position = pos;

    /* set position of button */
    left = pos.x;
    top = pos.y;

    m_title_text.setPosition(ComputeTitleTextPosition());
    m_title_bg.setPosition(ComputeTitleBgPosition());
    m_body.setPosition(m_position);

    for(size_t r = 0; r < m_rows; r++) {
        for(size_t c = 0; c < m_cols; c++) {
            m_compartments[r*m_cols + c].SetPosition(ComputeCompartmentPosition(r, c));
        }
    }
}

size_t Container::ComputeContainerWidth() {
    /* container width */
    size_t w1 = m_cols * GameConfig::GetCompartmentSize() +
        (m_cols-1) * GameConfig::GetCompartmentSpacing() +
        2 * GameConfig::GetWallSpacing();

    /* title width */
    size_t w2 = m_title_text.getLocalBounds().width + GameConfig::GetTitleHorizontalSpacing()*2;

    /* return maxm of these two */
    return w2 > w1 ? w2 : w1;
}

size_t Container::ComputeContainerHeight() {
    return m_rows * GameConfig::GetCompartmentSize() +
        (m_rows-1) * GameConfig::GetCompartmentSpacing() +
        2 * GameConfig::GetWallSpacing();
}

sf::Vector2f Container::ComputeCompartmentPosition(size_t r, size_t c) {
    sf::Vector2f pos = m_position + sf::Vector2f(GameConfig::GetWallSpacing(), GameConfig::GetWallSpacing());

    if(c) {
        pos.x += c * (GameConfig::GetCompartmentSize() + GameConfig::GetCompartmentSpacing());
    }

    if(r) {
        pos.y += r * (GameConfig::GetCompartmentSize() + GameConfig::GetCompartmentSpacing());
    }

    return pos;
}

size_t Container::ComputeTitleBgWidth() {
    return ComputeContainerWidth();
}

size_t Container::ComputeTitleBgHeight() {
    return m_title_text.getLocalBounds().height + 2*GameConfig::GetTitleVerticalSpacing();
}

sf::Vector2f Container::ComputeTitleBgPosition() {
    return m_position - sf::Vector2f(0, ComputeTitleBgHeight());
}

sf::Vector2f Container::ComputeTitleTextPosition() {
    return sf::Vector2f(m_position.x + 2*GameConfig::GetTitleHorizontalSpacing(),
                        m_position.y - m_title_text.getLocalBounds().height - 2*GameConfig::GetTitleVerticalSpacing());
}
