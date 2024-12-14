cmake_minimum_required(VERSION 3.10)
project(FightProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Добавляем заголовочные файлы Google Test в путь поиска компилятора
include_directories(${googletest_SOURCE_DIR}/googletest/include)

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем заголовочные файлы Google Test в путь поиска компилятора
include_directories(${googletest_SOURCE_DIR}/googletest/include)

# Добавляем директорию с заголовочными файлами
include_directories(include)

# Добавляем исходные файлы
# src/pentagon.cpp src/hexagon.cpp 
add_executable(FightProject  src/elf.cpp src/NPC.cpp src/knight.cpp src/robber.cpp  src/main.cpp )

# Добавление тестов
#enable_testing()


#add_executable(tests04 tests/test.cpp)
#target_link_libraries(tests04 gtest gtest_main)

# Добавление тестов в тестовый набор
#add_test(NAME FigureProject2Tests COMMAND tests04)