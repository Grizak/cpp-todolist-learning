#include "TodoManager.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void TodoManager::addTodo(string title, bool printMessage)
{
  todos.push_back(Todo(title));
  if (printMessage)
  {
    cout << "Added todo: " << title << endl;
  }
}
void TodoManager::markComplete(int idx)
{
  if (idx > 0 && idx <= todos.size())
  {
    todos[idx - 1].completed = true;
    cout << "Todo: " << todos[idx - 1].title << " marked completed" << endl;
  }
}

void TodoManager::deleteTodo(int idx)
{
  if (idx > 0 && idx <= todos.size())
  {
    Todo todo = todos[idx - 1];
    todos.erase(todos.begin() + idx - 1);
    cout << "Deleted todo: " << todo.title << endl;
  }
}

bool TodoManager::printTodos()
{
  if (todos.size() == 0)
  {
    cout << "No todos found" << endl;
    return false;
  }
  cout << "Your todos:" << endl;
  for (size_t i = 0; i < todos.size(); i++)
  {
    Todo todo = todos[i];
    cout << i + 1 << ". " << todo.title << ". Status: " << (todo.completed ? "Done" : "Todo") << endl;
  }
  return true;
}

Todo TodoManager::getTodoByIndex(int idx)
{
  if (idx >= 0 && idx < todos.size())
  {
    return todos[idx];
  }
  throw out_of_range("Index out of range");
}

size_t TodoManager::getTodoCount()
{
  return todos.size();
}