cmake_minimum_required(VERSION 3.20)
project(Es01 C)

set(CMAKE_C_STANDARD 99)

add_executable(Es01 main.c listaTitoli.c listaTitoli.h titolo.c titolo.h data.c data.h BST.c BST.h quotazione.c quotazione.h)
