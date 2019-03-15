#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

bool moveRight(sf::Vector2f *playerPos, std::string map)
{
    playerPos->y = (playerPos->y / 32) * 32;
    playerPos->x = (playerPos->x / 32) * 32;

    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[cell_y * 19 + cell_x + 1] == '1') {
        return false;
    }
    return true;
}

bool moveLeft(sf::Vector2f *playerPos, std::string map)
{
    playerPos->y = (playerPos->y / 32) * 32;
    playerPos->x = (playerPos->x / 32) * 32;

    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[cell_y * 19 + cell_x - 1] == '1') {
        return false;
    }
    return true;
}

bool moveUp(sf::Vector2f *playerPos, std::string map)
{
    playerPos->y = (playerPos->y / 32) * 32;
    playerPos->x = (playerPos->x / 32) * 32;

    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[(cell_y - 1) * 19 + cell_x] == '1') {
        return false;
    }
    return true;
}

bool moveDown(sf::Vector2f *playerPos, std::string map)
{
    playerPos->y = (playerPos->y / 32) * 32;
    playerPos->x = (playerPos->x / 32) * 32;

    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[(cell_y + 1) * 19 + cell_x] == '1') {
        return false;
    }
    return true;
}

void drawMap(sf::RenderWindow *window, sf::Sprite *wallSprite, std::string map)
{
    int mapLength = 19;
    int mapHeight = 21;
    int wallSpriteSize = 32;

    for (int ith = 0; ith < mapHeight; ith++) {
        for (int itl = 0; itl < mapLength; itl++) {
            if (map[ith * mapLength + itl] == '1') {
                wallSprite->setPosition(itl * wallSpriteSize + 32, ith * wallSpriteSize + 32);
                window->draw(*wallSprite);
            }
        }
    }
}

int main()
{
    // INIT WINDOW
    std::string map = "111111111111111111112222222222222222211311211121211121131122222222222222222112112121111121211211222212221222122221111121110101112111100012100000001210001111210110110121111000020010001002000011112101111101211110001210000000121000111121011111012111112222222212222222211211211121211121121132122222222222123111212121111121212111222212221222122221121111112121111112112222222222222222211111111111111111111";
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML - Pacman");
    sf::Event event;
    sf::Texture ghostText;
    sf::Texture pacmanText;
    sf::Texture wallText;
    sf::Sprite ghostSprite;
    sf::Sprite pacmanSprite;
    sf::Sprite wallSprite;

    sf::Vector2f pos;

    // PLAYER MOVEMENT
    bool move_right = false;
    bool move_left = false;
    bool move_up = false;
    bool move_down = false;
    bool is_moving = false;

    // SPRITE INIT
    ghostText.loadFromFile("../assets/ghost.png");
    ghostSprite.setTexture(ghostText, true);
    ghostSprite.setPosition(300, 15);
    ghostSprite.setScale(0.5, 0.5);

    pacmanText.loadFromFile("../assets/pacman.png");
    pacmanSprite.setTexture(pacmanText, true);
    pacmanSprite.setPosition(9 * 32 + 32, 10 * 32 + 32 + 32); // map center
    pacmanSprite.setOrigin(16, 16);

    wallText.loadFromFile("../assets/wall.png");
    wallSprite.setTexture(wallText, true);
    wallSprite.setOrigin(16, 16);

    // SOUND INIT
    sf::SoundBuffer walkSound;
    if (!walkSound.loadFromFile("../assets/pacman_chomp.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(walkSound);
    sound.setLoop(true);
    sound.play();

    // GAME LOOP
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                // KEYBOARD INPUT
                case sf::Event::KeyPressed:
                    if (is_moving)
                        break;
                    move_right = false;
                    move_left = false;
                    move_up = false;
                    move_down = false;
                    if (event.key.code == sf::Keyboard::Right)
                        move_right = true;
                    if (event.key.code == sf::Keyboard::Left)
                        move_left = true;
                    if (event.key.code == sf::Keyboard::Up)
                        move_up = true;
                    if (event.key.code == sf::Keyboard::Down)
                        move_down = true;
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }
        // MOVE PLAYER
        pos = pacmanSprite.getPosition();
        if (move_right && moveRight(&pos, map)) {
            pacmanSprite.setRotation(0);
            pacmanSprite.move(32, 0);
        } else if (move_left && moveLeft(&pos, map)) {
            pacmanSprite.setRotation(180);
            pacmanSprite.move(-32, 0);
        } else if (move_up && moveUp(&pos, map)) {
            pacmanSprite.setRotation(270);
            pacmanSprite.move(0, -32);
        } else if (move_down && moveDown(&pos, map)) {
            pacmanSprite.setRotation(90);
            pacmanSprite.move(0, 32);
        }
        move_right = false;
        move_left = false;
        move_up = false;
        move_down = false;

        std::cout << "[" << (pos.x / 32) - 1 << ", " << (pos.y / 32) - 1 << "]" << std::endl;

        // DRAW / REFRESH
        window.clear();
        // window.draw(ghostSprite);
        window.draw(pacmanSprite);
        // window.draw(wallSprite);
        drawMap(&window, &wallSprite, map);
        window.display();
    }
    return 0;
}