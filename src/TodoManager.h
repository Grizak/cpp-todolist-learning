#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include <vector>
#include "Todo.h"
using namespace std;

class TodoManager
{
private:
  vector<Todo> todos;

public:
  void addTodo(string title);
  void markComplete(int idx);
  void deleteTodo(int idx);
  bool printTodos();
};

#endif