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

#define SFML_WINDOW_NAME "Google Chrome"
#define SFML_WINDOW_WIDTH 700
#define SFML_WINDOW_HEIGHT 650
#define SFML_WINDOW_FRAMERATE 60

#if defined(__APPLE__)
#include <TargetConditionals.h>
#if defined(TARGET_OS_MAC)
#define SFML_IS_OPEN true
#else
#define SFML_IS_OPEN this->_window->isOpen()
#endif
#endif

class SfmlModule : public IDisplayModule, public IRender {
 public:
  SfmlModule();
  virtual ~SfmlModule();

 public:
  Events getInputs() final;
  bool displayEntity(AEntity &) final;
  void displayMap(GameMap) final;
  bool renderTextEntity(AEntity &) const final;
  bool renderGameEntity(AEntity &) const final;
  void destructor() final;
  bool isOpen() const final;
  int animateEntity(AEntity &) noexcept;
  const std::string &getLibraryName() const noexcept final;
  void refreshWindow() const noexcept final;
  void smoothlyMove(AEntity &);
  void moveRandom(AEntity *);

 private:
  const std::string _name = "sfml";
  void initGraphics(GameMap &);
  void initGameEntity(AEntity &);
  std::unique_ptr<sf::RenderWindow> _window = nullptr;
  void matchInputs(Events &inputs, sf::Keyboard::Key key);
  std::unordered_map<int, std::pair<sf::Sprite, sf::Texture>> _sprites = {};
  sf::Event eventSFML;
};

#endif /* !SFMLMODULE_HPP_ */
