cmake_minimum_required(VERSION 4.0)
project(Student_Data_Management_System C)

set(CMAKE_C_STANDARD 11)

add_executable(Student_Data_Management_System main.c
        Stack.c
        Queue.c
        Queue.h
        Stack.c
        Stack.h
        Globals.h
        Utilities.c
        Utilities.h
        CSV_Handler.c
        CSV_Handler.h
        Student_Handler.c
        Student_Handler.h
        Birthday_Event_Handler.c
        Birthday_Event_Handler.h)
