#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "TodoManager.h"
using namespace std;

struct Command
{
  string description;
  function<void(TodoManager &manager)> execute;
};

map<int, Command> initialiseCommands()
{
  map<int, Command> commands;
  commands[1] = {
      "Add todo", [](TodoManager &manager)
      {
        cout << "Name the new todo:" << endl;
        string todoName;
        getline(cin, todoName);
        if (todoName.empty())
        {
          cout << "Invalid todo name" << endl;
          return;
        }
        manager.addTodo(todoName);
      }};
  commands[2] = {
      "Mark complete", [](TodoManager &manager)
      {
        if (!manager.printTodos())
          return;
        cout << "Choose a todo to mark complete:" << endl;
        int todoIdx;
        cin >> todoIdx;
        cin.ignore();
        manager.markComplete(todoIdx);
      }};
  commands[3] = {
      "View all", [](TodoManager &manager)
      { manager.printTodos(); }};
  commands[4] = {
      "Delete a todo", [](TodoManager &manager)
      {
        if (!manager.printTodos())
          return;
        cout << "Choose a todo to delete:" << endl;
        int todoIdx;
        cin >> todoIdx;
        cin.ignore();
        manager.deleteTodo(todoIdx);
      }};
  commands[5] = {"Exit", nullptr};

  return commands;
}

int main()
{
  auto commands = initialiseCommands();
  TodoManager manager;
  int choice;

  while (true)
  {
    for (auto &[key, cmd] : commands)
    {
      cout << key << ". " << cmd.description << endl;
    }
    cin >> choice;
    cin.ignore();

    // Break on last option
    if (choice == commands.size())
      break;

    if (commands.find(choice) == commands.end())
    {
      cout << "Invalid choice, try again." << endl;
      continue;
    }
    if (!commands[choice].execute)
    {
      cout << "No action defined for this choice." << endl;
      continue;
    }
    commands[choice].execute(manager);
    cout << endl;
  }

  return 0;
}