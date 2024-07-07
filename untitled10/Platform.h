#ifndef UNTITLED10_PLATFORM_H
#define UNTITLED10_PLATFORM_H
#include <vector>
#include <SFML//Graphics.hpp>
#include "Global.h"

typedef std::vector<bool> Column;
typedef std::vector<Column> Grid;

class Platform {

public:
    Platform();
    sf::Vector2f LoadFromImageFile(std::basic_string<char> fileName);
    void Draw(sf::RenderWindow& window);
    bool CheckCollision(float x,float y, float width, float height);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    Grid grid;
};
#endif
