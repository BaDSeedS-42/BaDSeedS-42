cmake_minimum_required(VERSION 3.20)
project(Es03 C)

set(CMAKE_C_STANDARD 99)

add_executable(Es03 main.c inventario.c inventario.h invArray.c invArray.h listaPersonaggi.c listaPersonaggi.h personaggi.c personaggi.h equipArray.c equipArray.h)
