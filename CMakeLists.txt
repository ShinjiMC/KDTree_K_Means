cmake_minimum_required(VERSION 3.10)
project(KDTree)
set(CMAKE_CXX_STANDARD 14)
enable_testing()
## List of options:
option(BUILD_EXAMPLE "Builds the example" OFF)
option(SILENCE_DEBUG_OUTPUT "Silence debugs" OFF)
# Include directories for header files
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/KDTree")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/Reader")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/Vec2D")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/Tester")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/include")

# List source files for KDTree
file(GLOB_RECURSE KDTREE_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/KDTree/*.cpp")
file(GLOB_RECURSE KDTREE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/KDTree/*.hpp")

# List source files for Direct
file(GLOB_RECURSE DIRECT_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Direct/*.cpp")
file(GLOB_RECURSE DIRECT_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Direct/*.hpp")

# List source files for Reader
file(GLOB_RECURSE READER_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Reader/*.cpp")
file(GLOB_RECURSE READER_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Reader/*.hpp")

# List source files for Vec2D
file(GLOB_RECURSE VEC2D_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Vec2D/*.cpp")
file(GLOB_RECURSE VEC2D_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Vec2D/*.hpp")

# List source files for Tester
file(GLOB_RECURSE TESTER_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/Tester/*.cpp")

# Add Google Test libraries
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/lib/libgtest.a" # Ruta a la biblioteca estática de Google Test
)

add_library(gmock STATIC IMPORTED)
set_target_properties(gmock PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/lib/libgmock.a" # Ruta a la biblioteca estática de Google Mock
)

# Create libraries for KDTree, Direct, Reader, Vec3D and Tester
add_library(KDTree ${KDTREE_SRC} ${KDTREE_HEADERS})
add_library(Direct ${DIRECT_SRC} ${DIRECT_HEADERS})
add_library(Reader ${READER_SRC} ${READER_HEADERS})
add_library(Vec2D ${VEC2D_SRC} ${VEC2D_HEADERS})
add_library(Tester ${TESTER_SRC})

# Set compile definitions
if(SILENCE_DEBUG_OUTPUT)
    target_compile_definitions(KDTree PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Direct PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Reader PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Vec2D PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Tester PRIVATE "SILENCE_DEBUG")
endif()

# Link libraries as needed
if(BUILD_EXAMPLE)
    add_executable(example "${CMAKE_CURRENT_LIST_DIR}/main.cpp")
    target_link_libraries(example PRIVATE KDTree Direct Reader Vec2D Tester gtest gmock )
    set_target_properties(example PROPERTIES OUTPUT_NAME "program")
endif()