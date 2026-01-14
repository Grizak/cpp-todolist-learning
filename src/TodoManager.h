#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include <vector>
#include <cstddef>
#include "Todo.h"
using namespace std;

class TodoManager
{
private:
  vector<Todo> todos;

public:
  void addTodo(string title, bool printMessage = true);
  void markComplete(int idx);
  void deleteTodo(int idx);
  bool printTodos();
  Todo getTodoByIndex(int idx);
  size_t getTodoCount();
};

#endif