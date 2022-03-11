#pragma once

#include "circle.hpp"

class Cylinder {
 public:
  Cylinder(double radius, double height) : m_base{radius}, m_height{height} {}

  double volume() const { return m_base.area() * m_height; }

 private:
  Circle m_base   = {1};
  double m_height = {};
};
