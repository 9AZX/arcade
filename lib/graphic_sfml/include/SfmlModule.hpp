/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#ifndef SFMLMODULE_HPP_
#define SFMLMODULE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "IDisplayModule.hpp"
#include "IRender.hpp"

#define SFML_WINDOW_NAME "Pacman"
#define SFML_WINDOW_WIDTH 700
#define SFML_WINDOW_HEIGHT 650
#define SFML_WINDOW_FRAMERATE 60

class SfmlModule : public IDisplayModule, public IRender {
 public:
  SfmlModule();
  virtual ~SfmlModule();

 public:
  void initGraphics(GameMap);
  std::vector<enum gameInputs> getInputs() final;
  void displayEntity(AEntity&) final;
  void displayMap(GameMap) final;
  void renderTextEntity(AEntity&) const final;
  void renderGameEntity(AEntity&) const final;
  void destructor() final;
  bool isOpen() const final;

 private:
  std::unique_ptr<sf::RenderWindow> _window;
  void matchInputs(std::vector<enum gameInputs>& inputs, sf::Keyboard::Key key);
  std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>> _sprites =
      {};
};

#endif /* !SFMLMODULE_HPP_ */
