cmake_minimum_required(VERSION 3.10)
project(lab01)

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


# Добавление директории с заголовочными файлами
include_directories(include)

# Добавление исходных файлов
add_executable(lab01 1lab.cpp perevodik.cpp)

# Добавление тестов
enable_testing()

add_executable(tests tests/lab1_tests.cpp  perevodik.cpp)
target_link_libraries(tests gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME MyProjectTests COMMAND tests)