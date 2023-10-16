cmake_minimum_required(VERSION 3.15)
project(oop_1)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
add_compile_options(-Wall -Werror -pedantic -Wextra)

include_directories(/users/local/include)
link_directories(/users/local/lib)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(oop_1 main.cpp mainwindow.cpp model_manager.cpp model.cpp coordinates.cpp adjacency_matrix.cpp file.cpp
        size.cpp coordinates_memory.cpp adjacency_matrix_memory.cpp draw.cpp line.cpp dot.cpp action.cpp my_math.cpp
        check_size.cpp scene.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)