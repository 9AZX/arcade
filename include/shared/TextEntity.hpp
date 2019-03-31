/*
** EPITECH PROJECT, 2019
** TextEntity
** File description:
** Text entity
*/

#ifndef TEXT_ENTITY
#define TEXT_ENTITY

#include "Entity.hpp"

class TextEntity : public AEntity {
 public:
  enum TextColor { WHITE, RED, GREEN, BLUE };

 public:
  TextEntity() = delete;
  TextEntity(int id, std::string text, enum TextColor color,
             std::pair<int, int> pos, bool anim)
      : AEntity(id, pos, anim), _text(text), _color(color) {
    _type = TextEntity::TEXT;
  }
  ~TextEntity() = default;

  const std::string &getText() const noexcept { return _text; }
  enum TextColor getColor() const noexcept { return _color; }
  void setText(std::string str) noexcept { _text = str; }

 private:
  std::string _text;
  enum TextColor _color;
};

#endif /* ifndef TEXT_ENTITY */