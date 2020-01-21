#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

//0 is down, 1 is left, 2 is up, 3 is right
int direction = 0;

int main()
{
    // setup window
    sf::Vector2i screenDimensions(576,324);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Game205-Homework8");
    window.setFramerateLimit(60);

     // Create background
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    sf::Sprite background(backgroundTexture); // 1280 x 720
    background.setOrigin(background.getLocalBounds().width/2, background.getLocalBounds().height/2);
    background.setPosition(window.getSize().x/2, window.getSize().y/2);
    background.scale(0.45f, 0.45f);

    // load ken's texture (spritesheet)
    sf::Texture kentexture;
    if (!kentexture.loadFromFile("ken.png"))
    {
        std::cout << "Failed to load ken spritesheet!" << std::endl;
        return 1;
    }

    sf::Texture ryutexture;
    if (!ryutexture.loadFromFile("ryu.png"))
    {
        std::cout << "Failed to load ryu spritesheet!" << std::endl;
        return 1;
    }

    // set up ken's texture
    Animation idleAnimationKen;
    idleAnimationKen.setSpriteSheet(kentexture);
    idleAnimationKen.addFrame(sf::IntRect(0, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(101, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(202, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(303, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(404, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(505, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(606, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(707, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(808, 0, 101, 120));
    idleAnimationKen.addFrame(sf::IntRect(909, 0, 101, 120));

    // set up ryu's texture
    Animation idleAnimationRyu;
    idleAnimationRyu.setSpriteSheet(ryutexture);
   // idleAnimationRyu.addFrame(sf::IntRect(0, 0, 77.71f, 114));
  //idleAnimationRyu.addFrame(sf::IntRect(77.71f, 0, 77.71f, 114));
    idleAnimationRyu.addFrame(sf::IntRect(155.42f, 0, 77.71f, 114));
    idleAnimationRyu.addFrame(sf::IntRect(233.14f, 0, 77.71f, 114));
    idleAnimationRyu.addFrame(sf::IntRect(310.85f, 0, 77.71f, 114));
    idleAnimationRyu.addFrame(sf::IntRect(388.57f, 0, 77.71f, 114));
    idleAnimationRyu.addFrame(sf::IntRect(466.28f, 0, 77.71f, 114));


    Animation* kenAnimation = &idleAnimationKen;

    Animation* ryuAnimation = &idleAnimationRyu;

    // set up kenAnimatedSprite
    AnimatedSprite kenAnimatedSprite(sf::seconds(0.15), false, true);
    kenAnimatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
    kenAnimatedSprite.move(60, 11);

    // set up ryuAnimatedSprite
    AnimatedSprite ryuAnimatedSprite(sf::seconds(0.13), false, true);
    ryuAnimatedSprite.setPosition(sf::Vector2f(screenDimensions/2));
    ryuAnimatedSprite.move(-145, 0);
    ryuAnimatedSprite.scale(1.13f, 1.13f);

    sf::Clock frameClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        kenAnimation = &idleAnimationKen;
        kenAnimatedSprite.play(*kenAnimation);
        kenAnimatedSprite.update(frameTime);

        ryuAnimation = &idleAnimationRyu;
        ryuAnimatedSprite.play(*ryuAnimation);
        ryuAnimatedSprite.update(frameTime);



        // draw
        window.clear();
        window.draw(background);
        window.draw(kenAnimatedSprite);
        window.draw(ryuAnimatedSprite);
        window.display();
    }

    return 0;
}
