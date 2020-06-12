#
# im2a executable
#

add_executable(im2a asciifier.cpp im2a.cpp options.cpp term_info.cpp)
target_include_directories(im2a PUBLIC ${CURSES_INCLUDE_DIRS} ${PROJECT_BINARY_DIR} ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(im2a PUBLIC ${CURSES_LIBRARIES} ${ImageMagick_LIBRARIES})
