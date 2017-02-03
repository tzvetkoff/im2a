/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
 * ----------------------------------------------------------------------------
 */

/* term_info.cpp */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

/* these stupid macros shit all over the house */
#ifdef columns
#undef columns
#endif
#ifdef lines
#undef lines
#endif

#include "term_info.h"

im2a::TermInfo::TermInfo()
{
    /* try to parse bash options */
    char *bash_columns = getenv("COLUMNS"), *bash_lines = getenv("LINES");
    if (bash_columns && bash_lines) {
        _columns = atoi(bash_columns);
        _lines = atoi(bash_lines);
        return;
    }

    /* try to get ncurses information */
    char *term_type = getenv("TERM"), term_buffer[2048];
    if (term_type && tgetent(term_buffer, term_type) > 0) {
        _columns = tgetnum((char *)"co");
        _lines = tgetnum((char *)"li");
        return;
    }

    /* fallback */
    _columns = 40;
    _lines = 25;
}

int im2a::TermInfo::columns() const
{
    return _columns;
}

int im2a::TermInfo::lines() const
{
    return _lines;
}
