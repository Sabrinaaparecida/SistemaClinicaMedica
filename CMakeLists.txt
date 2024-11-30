cmake_minimum_required(VERSION 3.28)
project(Agendamento_de_Consultas C)

set(CMAKE_C_STANDARD 11)

add_executable(Agendamento_de_Consultas main.c
        agendamento.c
        agendamento.h
)
