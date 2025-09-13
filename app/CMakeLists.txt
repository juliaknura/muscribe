add_executable(app
    app.cpp
)

add_library(
    appLib
    flagParser.cpp
)

target_include_directories(
    appLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
    app
    appLib
)