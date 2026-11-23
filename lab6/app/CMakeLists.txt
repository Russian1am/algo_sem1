cmake_minimum_required(VERSION 3.28)

project(lib_program)

add_executable(lib_program
    src/main.cpp
    src/functions.cpp
    src/class.cpp
    src/menu.cpp
    
)

target_include_directories(lib_program PRIVATE include)
target_compile_features(lib_program PRIVATE cxx_std_11)


# cmake_minimum_required(VERSION 3.28)

# project(lib_program)

# include(FetchContent)

# FetchContent_Declare(json
#     URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
# )

# FetchContent_MakeAvailable(json)

# add_executable(lib_program
#     src/main.cpp
#     src/functions.cpp
#     src/class.cpp
#     src/menu.cpp
# )

# target_include_directories(lib_program PRIVATE include)
# target_compile_features(lib_program PRIVATE cxx_std_11)
# target_link_libraries(lib_program PRIVATE nlohmann_json::nlohmann_json)