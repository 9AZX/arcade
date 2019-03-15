#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

bool moveRight(sf::Vector2f *playerPos, std::string map)
{
    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[cell_y * 19 + cell_x + 1] == '1') {
        return false;
    }
    return true;
}

bool moveLeft(sf::Vector2f *playerPos, std::string map)
{
    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[cell_y * 19 + cell_x - 1] == '1') {
        return false;
    }
    return true;
}

bool moveUp(sf::Vector2f *playerPos, std::string map)
{
    int cell_x = playerPos->x / 32 - 1;
    int cell_y = playerPos->y / 32 - 1;

    if (map[(cell_y - 1) * 19 + cell_x] == '1') {
        return false;
    }
    return true;
}

bool moveDown(sf::Vector2f *playerPos, std::string map)
{
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
    sf::RenderWindow window(sf::VideoMode(650, 700), "SFML - Pacman");
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

    bool move_right1 = false;
    bool move_left1 = false;
    bool move_up1 = false;
    bool move_down1 = false;

    bool is_moving = false;
    bool is_moving1 = false;
    int it = 0;
    int it1 = 0;

    // SPRITE INIT
    ghostText.loadFromFile("../assets/ghost.png");
    ghostSprite.setTexture(ghostText, true);
    ghostSprite.setPosition(9 * 32 + 32, 10 * 32);
    ghostSprite.setOrigin(16, 16);

    pacmanText.loadFromFile("../assets/pacman.png");
    pacmanSprite.setTexture(pacmanText, true);
    pacmanSprite.setPosition(9 * 32 + 32, 10 * 32 + 32 + 32); // map center
    pacmanSprite.setOrigin(16, 16);

    wallText.loadFromFile("../assets/wall.png");
    wallSprite.setTexture(wallText, true);
    wallSprite.setOrigin(16, 16);

    // MUSIC INIT
    sf::Music intro;
    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();;
    if (!intro.openFromFile("../assets/pacman_beginning.wav"))
        return -1;
    
    intro.play();
        window.draw(pacmanSprite);
        window.display();

    while (elapsed.asSeconds() <= 4) {
        elapsed = clock.getElapsedTime();
    }

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
            is_moving = true;
        } else if (move_left && moveLeft(&pos, map)) {
            pacmanSprite.setRotation(180);
            is_moving = true;
        } else if (move_up && moveUp(&pos, map)) {
            pacmanSprite.setRotation(270);
            is_moving = true;
        } else if (move_down && moveDown(&pos, map)) {
            pacmanSprite.setRotation(90);
            is_moving = true;
        }

        if (is_moving == true) {
            if (it < 64) {
                if (move_right) {
                    pacmanSprite.move(0.5, 0);
                } else if (move_left) {
                    pacmanSprite.move(-0.5, 0);
                } else if (move_up) {
                    pacmanSprite.move(0, -0.5);
                } else if (move_down) {
                    pacmanSprite.move(0, 0.5);
                }
                it++;                
            } else {
                it = 0;
                is_moving = false;
                move_right = false;
                move_left = false;
                move_up = false;
                move_down = false;
            }
        }

        // MOVE GHOST
        int random = rand() % 4;

        pos = ghostSprite.getPosition();
        switch (random) {
            case 0:
                if (moveRight(&pos, map) && !is_moving1)
                    // ghostSprite.move(32, 0);
                    move_right1 = true;
                    is_moving1 = true;
                break;
            case 1:
                if (moveLeft(&pos, map) && !is_moving1)
                    // ghostSprite.move(-32, 0);
                    move_left1 = true;
                    is_moving1 = true;
                break;
            case 2:
                if (moveUp(&pos, map) && !is_moving1)
                    // ghostSprite.move(0, -32);
                    move_up1 = true;
                    is_moving1 = true;
                break;
            case 3:
                if (moveDown(&pos, map) && !is_moving1)
                    // ghostSprite.move(0, 32);
                    move_down1 = true;
                    is_moving1 = true;
                break;
            default:
                break;
        }
        if (is_moving1 == true) {
            if (it1 < 128) {
                if (move_right1) {
                    ghostSprite.move(0.25, 0);
                } else if (move_left1) {
                    ghostSprite.move(-0.25, 0);
                } else if (move_up1) {
                    ghostSprite.move(0, -0.25);
                } else if (move_down1) {
                    ghostSprite.move(0, 0.25);
                }
                it1++;
            } else {
                it1 = 0;
                is_moving1 = false;
                move_right1 = false;
                move_left1 = false;
                move_up1 = false;
                move_down1 = false;
            }
        }

        // std::cout << "[" << (pos.x / 32) - 1 << ", " << (pos.y / 32) - 1 << "]" << std::endl;

        // DRAW / REFRESH
        window.clear();
        window.draw(ghostSprite);
        window.draw(pacmanSprite);
        drawMap(&window, &wallSprite, map);
        window.display();
    }
    return 0;
}