file(GLOB IVORY_SRCS ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(Ivory ${IVORY_SRCS})
target_link_libraries(Ivory PRIVATE sfml-graphics)
target_compile_features(Ivory PRIVATE cxx_std_17)

# copy assets from source to Build/bin folder
add_custom_command(TARGET Ivory PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/Assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Assets)

# create symlink for compile_commands.json
add_custom_command(TARGET Ivory PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${CMAKE_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}/compile_commands.json)
