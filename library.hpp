#pragma once

class Foo {
 public:
  Foo(int value);
  ~Foo();
  int value() const;

 private:
  int m_value;
};
