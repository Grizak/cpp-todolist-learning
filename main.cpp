#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Todo
{
private:
public:
  string title;
  bool completed;

  Todo(string t) : title(t), completed(false) {};
};

void printTodos(vector<Todo> todos) {
  for (size_t i = 0; i < todos.size(); i++) {
    Todo todo = todos[i];
    cout << i + 1 << ". " << todo.title << ". Status: " << (todo.completed ? "Done" : "Todo") << endl;
  }
}

int main()
{
  vector<Todo> todos;

  int choice;
  while (true)
  {
    cout << "1. Add todo" << endl
         << "2. Mark complete" << endl
         << "3. View all" << endl
         << "4. Delete a todo" << endl
         << "5. Exit" << endl;
    cin >> choice;
    cin.ignore(); // Clear the newline from input buffer

    if (choice == 1)
    {
      cout << "Name the new todo:" << endl;
      string todoName;
      getline(cin, todoName);
      if (todoName.empty())
      {
        cout << "Invalid todo name" << endl;
        continue;
      }
      todos.push_back(Todo(todoName));
      cout << "Added todo: " << todoName << endl;
    }
    if (choice == 2) {
      printTodos(todos);
      cout << "Choose a todo to mark complete" << endl;
      int todoIdx;
      cin >> todoIdx;
      cin.ignore();
      if (todoIdx > 0 && todoIdx <= todos.size()) {
        Todo& todo = todos[todoIdx - 1];
        todo.completed = true;
        cout << "Todo: " << todo.title << " marked completed" << endl;
      }
    }
    if (choice == 3) {
      printTodos(todos);
    }
    if (choice == 4) {
      printTodos(todos);
      cout << "Choose a todo to delete" << endl;
      int todoIdx;
      cin >> todoIdx;
      cin.ignore();
      if (todoIdx > 0 && todoIdx <= todos.size()) {
        Todo todo = todos[todoIdx - 1];
        todos.erase(todos.begin() + todoIdx - 1);
        cout << "Deleted todo: " << todo.title << endl;
      };
    }
    if (choice == 5)
      break;
  }
};