#ifndef TODO_H
#define TODO_H

#include <string>
using namespace std;

class Todo
{
private:
public:
  string title;
  bool completed;

  Todo(string t);
};

#endif // TODO_H