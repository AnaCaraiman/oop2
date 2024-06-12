cmake_minimum_required(VERSION 3.24)
project(oop2)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop2 main.cpp Flori.h Depozit.h Buchete.h Client.h Client.cpp Comanda.h
        Comanda.tpp
        Depozit.tpp)
