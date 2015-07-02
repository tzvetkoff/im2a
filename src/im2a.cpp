/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
 * ----------------------------------------------------------------------------
 */

/* im2a.cpp */

#include "config.h"

#include <iostream>
#include <Magick++.h>

#include "options.h"
#include "term_info.h"
#include "asciifier.h"

/* mine */
int main(int argc, char *const *argv)
{
    /* command line options */
    im2a::Options options(argc, argv);

    /* terminal info */
    im2a::TermInfo term_info;

    /* initialize magic */
    Magick::InitializeMagick(argv[0]);

    /* image instance */
    Magick::Image image;

    /* load image */
    try {
        image.read(options.source());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -2;
    }

    /* asciifier instance */
    im2a::Asciifier asciifier(&options, &term_info, &image);

    /* do some real job */
    asciifier.asciify();

    /* return true */
    return 0;
}
