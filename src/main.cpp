#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <fstream>
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

  return commands;
}

int main()
{
  TodoManager manager;
  ifstream inFile("todos.txt");
  if (inFile)
  {
    string line;
    while (getline(inFile, line))
    {
      if (line.empty())
        continue;
      bool completed = line[0] == '1';
      string title = line.substr(2);
      manager.addTodo(title, false);
      if (completed)
      {
        size_t last = manager.getTodoCount(); // Get last added todo index (1-based for markComplete)
        if (last > 0)
          manager.markComplete(static_cast<int>(last));
      }
    }
    inFile.close();
  }

  auto commands = initialiseCommands();
  int choice;

  while (true)
  {
    for (auto &[key, cmd] : commands)
    {
      cout << key << ". " << cmd.description << endl;
    }
    cout << "5. Exit" << endl;
    cout << "Choose an option:" << endl;
    cin >> choice;
    cin.ignore();

    // Break on last option (Exit)
    if (choice == (commands.size() + 1))
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

  // Write todos to file
  ofstream outFile("todos.txt");
  for (size_t i = 0; i < manager.getTodoCount(); ++i)
  {
    // Assuming TodoManager has a method to get todo by index
    Todo todo = manager.getTodoByIndex(static_cast<int>(i));
    outFile << (!todo.completed ? "0" : "1") << " " << todo.title << endl;
  }
  outFile.close();

  return 0;
}
