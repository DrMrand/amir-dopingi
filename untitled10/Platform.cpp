#include "Platform.h"
#include "Player.h"

Player player;
Platform::Platform() {

    texture.loadFromFile(Player::path("tile"));
    sprite.setTexture(texture);
    sprite.setScale((double)CELL_SIZE / texture.getSize().x,
                    (double)CELL_SIZE / texture.getSize().y);
}
sf::Vector2f Platform::LoadFromImageFile(std::basic_string<char> fileName) {
    sf::Vector2f marioPosition(50,50);

    sf::Image image;
    image.loadFromFile(fileName);

    for (int x = 0; x < image.getSize().x; x++) {
        Column column;
        for (int y = 0; y < image.getSize().y; y++) {
            sf::Color pixel = image.getPixel(x,y);
            if(pixel == sf::Color::Red)
                marioPosition = sf::Vector2f (x * CELL_SIZE, y * CELL_SIZE);

            column.push_back(image.getPixel(x,y) == sf::Color::Black);
        }
        grid.push_back(column);
    }
    return marioPosition;
}

bool Platform::CheckCollision(float x, float y, float width, float height) {

    int tileColumnStart = (int)(x / CELL_SIZE);
    int tileColumnEnd = (int)((x + width) / CELL_SIZE) + 1;
    int tileRowStart = (int)(y / CELL_SIZE);
    int tileRowEnd = (int)((y + height) / CELL_SIZE) + 1;

    for (int column = tileColumnStart; column < tileColumnEnd; column++)
        for (int row = tileRowStart; row < tileRowEnd; row++) {
            if(grid[column][row]) {
                return true;
            }
        }
    return false;
}

void Platform::Draw(sf::RenderWindow& window) {
    int x = 0;
    for (const Column& column : grid) {
        int y = 0;
        for(const bool& draw : column) {
            if(draw) {
                sprite.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(sprite);
            }
            y++;
        }
        x++;
    }
}
