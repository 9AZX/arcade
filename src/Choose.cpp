/*
** EPITECH PROJECT, 2019
** Choose
** File description:
** Choose class functions.
** @Author: Cédric Hennequin
** @Date:   30-03-2019 18:21:10
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 31-03-2019 22:19:04
*/

#include <memory>
#include <iostream>
#include "Choose.hpp"
#include "Exception.hpp"

static const std::string paths[]{"ncurses", "sfml", "sdl2"};

void Choose::launchLibraries(Application &app, const std::string &path) {
  try {
    for (const auto &e : paths) {
      std::size_t found = path.find(e);
      if (found != std::string::npos) {
		this->init(app, e);
		return;
      }
    }
  } catch (...) {
    throw;
  }
}

void Choose::init(Application &app, const std::string &defaultInit)
{
	std::string lib = defaultInit;

	while (this->_global_loop) {
		if (lib == "ncurses") {
			this->ncurses_init(app, lib);
		}
		else if (lib == "sfml") {
			this->sfml_init(app, lib);
		}
    else if (lib == "sdl2") {
      this->sdl2_init(app, lib);
    }
	}
}

void Choose::sdl2_init(Application &app, std::string &lib)
{
  std::cout << "sdl2 init" << std::endl;
  app._choose = 0;
  this->_global_loop = false;
}

void Choose::sfml_init(Application &app, std::string &lib) {
  int choose = 0;
  std::unique_ptr<sf::RenderWindow> window(
      new sf::RenderWindow(sf::VideoMode(800, 600), "Arcade - Select a game"));
  sf::Font font;
  sf::Text text[2];

  if (!font.loadFromFile("./assets/no-continue.regular.ttf")) {
    throw Exception("Error while loading text font.");
  }
  window->setFramerateLimit(30);
  window->setKeyRepeatEnabled(false);
  text[0].setString("PAC-MAN  -->");
  text[1].setString("<-- Nibbler");
  text[0].setFont(font);
  text[1].setFont(font);
  text[0].setCharacterSize(50);
  text[1].setCharacterSize(50);
  text[0].setFillColor(sf::Color::White);
  text[1].setFillColor(sf::Color::White);
  while (window->isOpen()) {
    sf::Event event;

    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
        this->_global_loop = false;
      }
      if (sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choose < 2) {
          ++choose;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                   choose > 0) {
          --choose;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
          this->_global_loop = false;
          window->close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
          app._choose = (choose >= 2 ? 1 : choose);
          this->_global_loop = false;
          window->close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			lib = "ncurses";
			app._lib = 2;
			window->close();
			window.reset(nullptr);
			return;
        }
      }
    }
    if (choose >= 2) {
      choose = 1;
    }
    else if (choose < 0) {
      choose = 0;
    }
    window->clear(sf::Color(0, 0, 0));
    if (choose == 0) {
      window->draw(text[0]);
    } else if (choose == 1) {
      window->draw(text[1]);
    }
    window->display();
  }
}

void Choose::ncurses_init(Application &app, std::string &lib) noexcept {
  initscr();
  noecho();
  cbreak();
  this->_windowLeft = subwin(stdscr, LINES, COLS / 2, 0, 0);
  this->_windowRight = subwin(stdscr, LINES, COLS / 2, 0, (COLS / 2) - 1);
  wborder(this->_windowLeft, '|', '|', '-', '-', '+', '+', '+', '+');
  wborder(this->_windowRight, '|', '|', '-', '-', '+', '+', '+', '+');
  refresh();
  wrefresh(this->_windowLeft);
  wrefresh(this->_windowRight);
  keypad(this->_windowLeft, true);
  curs_set(0);
  while (this->_loop) {
    this->print_name();
    this->print_menu(app, lib);
  }
  endwin();
}

void Choose::print_name() noexcept {
  wattron(this->_windowLeft, A_UNDERLINE | A_BOLD);
  mvwprintw(this->_windowLeft, 1, (COLS / 2) - ((COLS / 4) + 4),
            "Arcade - Select a game");
  wattroff(this->_windowLeft, A_UNDERLINE | A_BOLD);
}

void Choose::print_menu(Application &app, std::string &lib) noexcept {
  int interval = 1;
  static int highlight = 0;
  std::string disp = "";
  std::string module_name[4] = {"PAC-MAN", "Nibbler"};
  static bool module_state[4] = {true, true};

  for (int i = 0; i < 2; ++i) {
    if (i == highlight) {
      wattron(this->_windowLeft, A_REVERSE);
    }
    disp += module_name[i].c_str();
    mvwprintw(this->_windowLeft, (LINES / 2) - 4 + i,
              (COLS / 2) - ((COLS / 4) + 4), disp.c_str());
    wattroff(this->_windowLeft, A_REVERSE);
    disp.clear();
    switch (i) {
      case 0:
        if (module_state[i]) {
          this->print_game_pacman(interval);
        }
        break;
      case 1:
        if (module_state[i]) {
          this->print_game_nibbler(interval);
        }
        break;
      default:
        break;
    }
  }
  wrefresh(this->_windowRight);
  this->setKey(wgetch(this->_windowLeft));
  interval = 1;
  switch (this->getKey()) {
    case KEY_UP:
      --highlight;
      if (highlight == -1) {
        highlight = 0;
      }
      break;
    case KEY_DOWN:
      ++highlight;
      if (highlight == 2) {
        highlight = 1;
      }
      break;
    case KEY_RIGHT:
      break;
    case 10:
      app._choose = highlight;
      this->setLoop(false);
      this->_global_loop = false;
      break;
    case 27:
      this->setLoop(false);
      this->_global_loop = false;
      break;
    case KEY_F(2):
    	lib = "sfml";
    	app._lib = 3;
    	this->setLoop(false);
    	break;
    default:
      break;
  }
}

void Choose::print_game_pacman(int &interval) noexcept {
  std::string msg = "";

  wattron(this->_windowRight, A_STANDOUT);
  mvwprintw(this->_windowRight, interval, (COLS / 2) - ((COLS / 4) + 4),
            "PAC-MAN");
  wattroff(this->_windowRight, A_STANDOUT);
  interval += 2;
  msg += "Pac-Man (stylized in all capitals as PAC-MAN)";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "is an arcade game designed by Toru Iwatani (1955-)";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "of Namco, and released in Japan as PUCKMAN in May 1980.";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "Licensed for distribution in the United States";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "by Midway Games, it was released in October 1980, ";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "at a time when the top arcade games were \"stark\"";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "space shooters such as Galaxian and Asteroids";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "Pac-Man established the conventions of the maze chase";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "genre and is considered to be one of the classics";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "in video game, history and";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "an icon of 1980s popular culture.";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  interval += 2;
}

void Choose::print_game_nibbler(int &interval) noexcept {
  std::string msg = "";

  wattron(this->_windowRight, A_STANDOUT);
  mvwprintw(this->_windowRight, interval, (COLS / 2) - ((COLS / 4) + 4),
            "Nibbler");
  wattroff(this->_windowRight, A_STANDOUT);
  interval += 2;
  msg.clear();
  msg += "Nibbler is an arcade snake game released in 1982";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "by Chicago-based developer Rock-Ola.";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "The player navigates a long snake through";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "an enclosed maze consuming food";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "along the way, while the length of";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
  ++interval;
  msg.clear();
  msg += "the snake increases with each object consumed.";
  mvwprintw(this->_windowRight, interval, 3, msg.c_str());
}

int Choose::getKey() const noexcept { return this->_key; }

void Choose::setLoop(const bool status) noexcept { this->_loop = status; }

void Choose::setKey(const int key) noexcept { this->_key = key; }
