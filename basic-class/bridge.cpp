#include "bridge.h"
#include "circle.hpp"
#include "cylinder.hpp"

void* DEMO_CircleNew(double radius) { return new Circle(radius); }

void DEMO_CircleDestroy(void* circle) {
  auto ptr = reinterpret_cast<Circle*>(circle);
  delete ptr;
}

double DEMO_CircleArea(const void* circle) {
  return reinterpret_cast<const Circle*>(circle)->area();
};

void* DEMO_CylinderNew(double radius, double height) {
  return new Cylinder(radius, height);
}

void DEMO_CylinderDestroy(void* cylinder) {
  auto ptr = reinterpret_cast<Cylinder*>(cylinder);
  delete ptr;
}

double DEMO_CylinderVolume(const void* cylinder) {
  return reinterpret_cast<const Cylinder*>(cylinder)->volume();
}
