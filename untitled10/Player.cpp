#include "Player.h"
#include "Platform.h"

extern Platform map;

std::string Player::path(const std::string &text) {
    std::string PathRes = R"(C:\Users\ParsRayaneh\CLionProjects\untitled10\res\)";
    std::string filePath = PathRes + text + ".png";
    return filePath;
}
Player::Player(sf::Vector2f pos)
    : speed(300), jumpVelocity(-650) ,verticalVelocity(0),gravity(1000),
    isGrounded(false) ,facingLeft(false), runAnimation(0.45f)
    {
    rect = sf::FloatRect (pos.x,pos.y,70,60);
    }

void Player::init() {

    textures[0].loadFromFile(path("sprit"));
    textures[1].loadFromFile(path("run1"));
    textures[2].loadFromFile(path("run2"));
    textures[3].loadFromFile(path("run3"));
    textures[4].loadFromFile(path("jump"));


    runAnimation.addFrame(Frame(&textures[1], 0.15f));
    runAnimation.addFrame(Frame(&textures[2], 0.30f));
    runAnimation.addFrame(Frame(&textures[3], 0.45f));
}

void Player::Update(float deltaTime) {

    float velocity = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity =  -speed * deltaTime;
        facingLeft = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity = speed * deltaTime;
        facingLeft = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isGrounded)
        verticalVelocity = jumpVelocity;


    verticalVelocity += gravity * deltaTime;

    if(map.CheckCollision(rect.left + velocity, rect.top, rect.width, rect.height))
        velocity = 0;

    if(map.CheckCollision(rect.left,rect.top + verticalVelocity * deltaTime , rect.width,rect.height)) {
        verticalVelocity = 0;
        isGrounded = true;
    } else
        isGrounded = false;

    rect.left += velocity;
    rect.top += verticalVelocity * deltaTime;

    if(!isGrounded)
        sprite.setTexture(textures[4]);
    else if (std::abs(velocity) > 0.02f)
        sprite.setTexture(*runAnimation.update(deltaTime));
    else
        sprite.setTexture(textures[0]);
}

void Player::Draw(sf::RenderWindow& window) {

    sprite.setPosition(rect.left,rect.top);
    sprite.setScale(rect.width / textures[0].getSize().x,rect.height / textures[0].getSize().y);
    sprite.setTextureRect(sf::IntRect(textures[0].getSize().x * (facingLeft ? 1 : 0), 0,
                                      textures[0].getSize().x * (facingLeft ? -1 : 1), textures[0].getSize().y));

    window.draw(sprite);
}



