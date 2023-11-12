# CMakeList.txt : CMake project for 32-2-movie-data-analysis, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("32-2-movie-data-analysis")

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann_json/include)

# Add source to this project's executable.
add_executable (32-2-movie-data-analysis "main.cpp" "movie.h" "functions.h" "functions.cpp")

target_link_libraries(32-2-movie-data-analysis PRIVATE nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 32-2-movie-data-analysis PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
