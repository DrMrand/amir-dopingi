

#ifndef UNTITLED10_BODYOBJECT_H
#define UNTITLED10_BODYOBJECT_H
#include <SFML/Graphics.hpp>

class BodyObject {

public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void Update(float deltaTime) = 0;

    sf::FloatRect rect;
};


#endif
