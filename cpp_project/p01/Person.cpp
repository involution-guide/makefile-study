#include <sstream>

#include "Person.h"

Person::Person() {}
Person::Person(std::string name, int age) : _name(name), _age(age) {}
Person::~Person() {}

std::string Person::sayHello() {
  std::stringstream ss;
  ss << "Hi, My name is ";
  ss << this->_name;
  ss << ". I'm ";
  ss << this->_age;
  ss << " old.";
  return ss.str();
}