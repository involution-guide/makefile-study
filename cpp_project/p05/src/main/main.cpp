#include "hello/person/person.h"
#include <iostream>
#include <memory>

int main() {
  auto person = std::make_unique<Person>("laolang", 28);
  std::cout << person->sayHello() << std::endl;
  return 0;
}
