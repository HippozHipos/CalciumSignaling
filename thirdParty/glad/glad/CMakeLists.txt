cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)
project(glad LANGUAGES C)

add_library(glad include/glad/glad.h src/glad.c)
target_include_directories(glad PUBLIC include/)