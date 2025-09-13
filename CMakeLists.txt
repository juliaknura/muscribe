cmake_minimum_required(VERSION 3.28)
project(muscribe VERSION 1.0)

include(FetchContent)

# G-TEST
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.16.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_subdirectory(app)
add_subdirectory(tests)