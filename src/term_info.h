/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
 * ----------------------------------------------------------------------------
 */

/* term_info.h */

#ifndef __im2a__term_info__
#define __im2a__term_info__

namespace im2a
{

    class TermInfo
    {

    private:
        int _columns;
        int _lines;

    public:
        TermInfo();

        int columns() const;
        int lines() const;

    };

}

#endif /* defined(__im2a__term_info__) */
