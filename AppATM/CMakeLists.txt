cmake_minimum_required(VERSION 3.10) 

# Название проекта
project(AppATM)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указание исходников
add_executable(AppATM
    src/main.cpp
)
