#ifndef UNTITLED10_PLAYER_H
#define UNTITLED10_PLAYER_H
#include "BodyObject.h"
#include "Animation.h"

class Player :
        public BodyObject {
public:
    Player(sf::Vector2f pos = sf:: Vector2f(50, 50));
    void init();
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;
    static std::string path(const std::string& text);

private:
    Animation runAnimation;

    float speed;
    float verticalVelocity;
    float jumpVelocity;
    float gravity;
    bool facingLeft;
    bool isGrounded;
    sf::Sprite sprite;
    sf::Texture textures[20];
};


#endif
