/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
 * ----------------------------------------------------------------------------
 */

/* asciifier.h */

#ifndef __im2a__colorizer__
#define __im2a__colorizer__

#include <Magick++.h>

#include "options.h"
#include "term_info.h"

namespace im2a {

	class Asciifier {

	private:
		Options *_options;
		TermInfo *_term_info;
		Magick::Image *_image;

	public:
		Asciifier(Options *options, TermInfo *term_info, Magick::Image *image);
		void asciify();

	};

}

#endif /* defined(__im2a__colorizer__) */
