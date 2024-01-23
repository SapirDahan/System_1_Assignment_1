cmake_minimum_required(VERSION 3.27)
project(systems1 C)

set(CMAKE_C_STANDARD 11)

add_executable(systems1 main.c
        basicClassification.c
        advancedClassificationLoop.c
        advancedClassificationRecursion.c)
