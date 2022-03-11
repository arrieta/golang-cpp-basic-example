#pragma once

#include <cmath>

class Circle {
 public:
  Circle(double radius) : m_radius{radius} {}

  double area() const { return M_PI * std::pow(m_radius, 2); }

 private:
  double m_radius = {};
};
