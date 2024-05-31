cmake_minimum_required(VERSION 3.0)
project(RassberryPiFirstProject)

# set(EXECUTED_CLEAN_ALL_ONCE FALSE CACHE INTERNAL "Flag to indicate the section has been executed" FORCE)

# add_subdirectory(Include)
# add_subdirectory(Source)
# # Add your source files here
# set(SOURCES
#     Source/Add.cpp
    
#     # Add more files if needed
# )

# # Add your header files here
# set(HEADERS
#     Include/Add.h
#     # Add more files if needed
# )

# # Include directories
# include_directories(Include)

# # Create an executable target
# add_executable(YourExecutable ${SOURCES} ${HEADERS})


# Set common compiler options and C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for your project's "include" folder
include_directories(${CMAKE_SOURCE_DIR}/Include)

# Specify the source folder
set(SOURCE_FOLDER ${CMAKE_SOURCE_DIR}/Source)

# Use file(GLOB ...) to collect all source files in the folder
file(GLOB SOURCE_FILES "${SOURCE_FOLDER}/*.cpp")

list(REMOVE_ITEM SOURCE_FILES "${SOURCE_FOLDER}/main.cpp")
message(${SOURCE_FOLDER})

# Create the main project target
add_executable(RassberryPiFirstProject ${SOURCE_FILES} main.cpp)

target_include_directories(RassberryPiFirstProject PRIVATE Include/)


# //////////////////

# cmake_minimum_required(VERSION 3.16)
# project(MyProject LANGUAGES CXX)

# add_executable(my_program program.cpp)




# cmake_minimum_required(VERSION 3.16)
# project(MyProject LANGUAGES CXX)

# add_subdirectory(other_directory)

# add_executable(my_program main.cpp)
# target_link_libraries(my_program other_directory_target)

