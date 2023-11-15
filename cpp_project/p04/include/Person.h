#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

class Person {
public:
    Person();
    Person(std::string name, int age);
    ~Person();
  inline std::string name() { return this->_name; }
  inline void name(std::string name) { this->_name = name; }

  inline int age() { return this->_age; }
  inline void age(int age) { this->_age = age; }

  std::string sayHello();

private:
  std::string _name;
  int _age;
};

#endif