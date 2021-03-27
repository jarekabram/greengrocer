cmake_minimum_required (VERSION 3.2)
project (greengrocer)

# SOURCES
set(SOURCES src/Fruit.cc
			src/Vegetable.cc
			src/Scale.cc
			src/FileManager.cc
			src/main.cc)

# HEADERS
include_directories(inc)
set(HEADERS inc/Item.h
			inc/Fruit.h
			inc/Vegetable.h
			inc/Scale.h
			inc/FileManager.h)

add_executable(greengrocer ${SOURCES} ${HEADERS})

