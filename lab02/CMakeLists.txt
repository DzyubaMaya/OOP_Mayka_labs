cmake_minimum_required(VERSION 3.10)
project(ThreeProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

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

# Добавляем директорию с заголовочными файлами
include_directories(include)

# Добавляем исходные файлы
add_executable(ThreeProject src/laba2.cpp src/three.cpp)

# Добавление тестов
enable_testing()

add_executable(tests02 tests/lab2_tests.cpp src/laba2.cpp)
target_link_libraries(tests02 gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME ThreeProjectTests COMMAND tests)