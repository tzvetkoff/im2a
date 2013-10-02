/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
 * ----------------------------------------------------------------------------
 */

/* options.cpp */

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "version.h"
#include "options.h"

im2a::Options::Options(int argc, const char **argv) {
	// set default options
	_invert = false;
	_width = 0;
	_height = 0;
	_charset = NULL;
	_grayscale = false;
	_red_weight = 0.2989f;
	_green_weight = 0.5866f;
	_blue_weight = 0.1145;
	_source = NULL;

	bool stop_parsing_options = false;

	for (int i = 1; i < argc; ) {
		const char *argument = argv[i];

		if (!stop_parsing_options) {
			if (strcmp(argument, "--") == 0) {
				stop_parsing_options = true;

				++i;
				continue;
			}

			if (strcmp(argument, "--help") == 0) {
				help();
				exit(0);
			}

			if (strcmp(argument, "--html") == 0) {
				_html = true;

				++i;
				continue;
			}

			if (strcmp(argument, "--invert") == 0) {
				_invert = true;

				++i;
				continue;
			}

			if (strncmp(argument, "--width=", 8) == 0) {
				_width = atoi(argument + 8);

				++i;
				continue;
			}

			if (strncmp(argument, "--height=", 9) == 0) {
				_height = atoi(argument + 9);

				++i;
				continue;
			}

			if (strncmp(argument, "--charset=", 10) == 0) {
				_charset = strdup(argument + 10);

				++i;
				continue;
			}

			if (strcmp(argument, "--grayscale") == 0) {
				_grayscale = true;

				++i;
				continue;
			}

			if (strncmp(argument, "--red-weight=", 13) == 0) {
				_red_weight = atof(argument + 13);

				++i;
				continue;
			}

			if (strncmp(argument, "--green-weight=", 15) == 0) {
				_green_weight = atof(argument + 15);

				++i;
				continue;
			}

			if (strncmp(argument, "--blue-weight=", 14) == 0) {
				_blue_weight = atof(argument + 14);

				++i;
				continue;
			}

			if (argument[0] == '-' && argument[1] == '-') {
				std::cerr << argv[0] << ": invalid option: `" << argument << "'" << std::endl;
				std::cerr << std::endl;
				help();
				exit(1);
			}
		}

		if (!_source) {
			_source = strdup(argument);

			++i;
			continue;
		} else {
			std::cerr << argv[0] << ": too many input files specified" << std::endl;
			std::cerr << std::endl;
			help();
			exit(1);
		}
	}

	if (_width < 0 || _height < 0) {
		std::cerr << argv[0] << ": invalid width/height" << std::endl;
		std::cerr << std::endl;
		help();
		exit(1);
	}

	if (!_charset) {
		_charset = strdup(" M   ...',;:clodxkO0KXNWMM");
	} else if (strlen(_charset) < 2) {
		std::cerr << argv[0] << ": charset should be at least 2 symbols long" << std::endl;
		std::cerr << std::endl;
		help();
		exit(1);
	}

	if (!_source) {
		std::cerr << argv[0] << ": no input file specified" << std::endl;
		std::cerr << std::endl;
		help();
		exit(1);
	}
}

im2a::Options::~Options() {
	if (_charset) {
		free(_charset);
	}
	if (_source) {
		free(_source);
	}
}

void im2a::Options::help() {
	std::cerr << "im2a " VERSION << std::endl;
	std::cerr << "Convert image files to ASCII art" << std::endl;
	std::cerr << "Copyright (C) 2013 Latchezar Tzvetkoff" << std::endl;
	std::cerr << "Distributed under the beerware license" << std::endl;
	std::cerr << std::endl;
	std::cerr << "Usage: im2a [options] <file>" << std::endl;
	std::cerr << std::endl;
	std::cerr << "OPTIONS" << std::endl;
	std::cerr << "  --help                  Prints this message" << std::endl;
	std::cerr << "  --html                  Output HTML" << std::endl;
	std::cerr << "  --invert                Invert the image" << std::endl;
	std::cerr << "  --width=N               Set output width" << std::endl;
	std::cerr << "  --height=M              Set output height" << std::endl;
	std::cerr << "  --charset=CHARSET       Set output charset" << std::endl;
	std::cerr << "  --grayscale             Grayscale output instead of 256-color" << std::endl;
	std::cerr << "  --red-weight=RW         Set red component weight (default: 0.2989)" << std::endl;
	std::cerr << "  --green-weight=GW       Set green component weight (default: 0.5866)" << std::endl;
	std::cerr << "  --blue-weight=BW        Set blue component weight (default: 0.1145)" << std::endl;
	std::cerr << std::endl;
	std::cerr << "Project homepage: https://github.com/tzvetkoff/im2a" << std::endl;
	std::cerr << "Report bugs to https://github.com/tzvetkoff/im2a/issues" << std::endl;
}

bool im2a::Options::html() const {
	return _html;
}

bool im2a::Options::invert() const {
	return _invert;
}

int im2a::Options::width() const {
	return _width;
}

int im2a::Options::height() const {
	return _height;
}

char *im2a::Options::charset() const {
	return _charset;
}

bool im2a::Options::grayscale() const {
	return _grayscale;
}

double im2a::Options::red_weight() const {
	return _red_weight;
}

double im2a::Options::green_weight() const {
	return _green_weight;
}

double im2a::Options::blue_weight() const {
	return _blue_weight;
}

char *im2a::Options::source() const {
	return _source;
}

