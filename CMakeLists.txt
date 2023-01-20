cmake_minimum_required(VERSION 3.0)

enable_language(CXX C)

project(relearn)

add_subdirectory(udemy1)
add_subdirectory(relearn_dl)
add_subdirectory(relearn_sl)
add_subdirectory(relearn)
add_subdirectory(unittest-relearn)

add_dependencies(relearn udemy1 relearn_sl relearn_dl )
add_dependencies(unittest-relearn udemy1)
