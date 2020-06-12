#
# im2a
#

cmake_minimum_required(VERSION 3.10)
project(im2a
        LANGUAGES CXX
        VERSION 0.6.2
        HOMEPAGE_URL https://github.com/tzvetkoff/im2a)
set(BUGREPORT_URL https://github.com/tzvetkoff/im2a/issues)

#
# dependencies
#

find_package(Curses)

find_package(ImageMagick COMPONENTS Magick++)
add_compile_options("${PC_Magick++_STATIC_CFLAGS}")
string(REGEX REPLACE "[.-]" ";" ImageMagick_VERSION_LIST "${ImageMagick_VERSION_STRING}")
list(GET ImageMagick_VERSION_LIST 0 IMAGEMAGICK_VERSION_MAJOR)
list(GET ImageMagick_VERSION_LIST 1 IMAGEMAGICK_VERSION_MINOR)
list(GET ImageMagick_VERSION_LIST 2 IMAGEMAGICK_VERSION_PATCH)

#
# config.h
#

configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_BINARY_DIR}/config.h)
add_compile_definitions(HAVE_CONFIG_H)

#
# src
#

add_subdirectory(src)
