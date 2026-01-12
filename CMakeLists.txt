cmake_minimum_required(VERSION 3.10)
project(TodoApp)

add_executable(todolist 
    src/main.cpp
    src/Todo.cpp
    src/TodoManager.cpp
)

target_include_directories(todolist PRIVATE src)