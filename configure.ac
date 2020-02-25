# Run `./bootstrap` to generate the "configure" script.

# Define the package version numbers, bug reporting link, project homepage.
m4_define([IM2A_VERSION_MAJOR_], [0])
m4_define([IM2A_VERSION_MINOR_], [6])
m4_define([IM2A_VERSION_PATCH_], [1])
m4_define([IM2A_VERSION_STRING_], [IM2A_VERSION_MAJOR_.IM2A_VERSION_MINOR_.IM2A_VERSION_PATCH_])
m4_define([IM2A_BUGREPORT_URL_], [https://github.com/tzvetkoff/im2a/issues])
m4_define([IM2A_PROJECT_URL_], [https://github.com/tzvetkoff/im2a])

# Initialize autoconf & automake.
AC_PREREQ(2.59)
AC_INIT([im2a], [IM2A_VERSION_STRING_], [IM2A_BUGREPORT_URL_], [im2a], [IM2A_PROJECT_URL_])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config.h])
# AC_CONFIG_LIBOBJ_DIR([lib])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.9 foreign])

# Define macro variables for the package version numbers.
AC_DEFINE([IM2A_VERSION_MAJOR], [IM2A_VERSION_MAJOR_], [Define the major version number.])
AC_DEFINE([IM2A_VERSION_MINOR], [IM2A_VERSION_MINOR_], [Define the minor version number.])
AC_DEFINE([IM2A_VERSION_PATCH], [IM2A_VERSION_PATCH_], [Define the patch version number.])
AC_DEFINE([IM2A_VERSION_STRING], ["IM2A_VERSION_STRING_"], [Define the version string.])
AC_DEFINE([IM2A_BUGREPORT_URL], ["IM2A_BUGREPORT_URL_"], [Bug reporting url])
AC_DEFINE([IM2A_PROJECT_URL], ["IM2A_PROJECT_URL_"], [Project homepage])

# Checks for programs.
AC_PROG_CXX()
AC_PROG_INSTALL()
AC_PROG_LN_S()
AC_PROG_MAKE_SET()

# Debug.
AC_ARG_ENABLE([debug], AS_HELP_STRING([--enable-debug], [Enable debugging @<:@default=no@:>@.]), [
  case "${enableval}" in
    yes) IM2A_DEBUG="1"; CXXFLAGS="${CXXFLAGS} -g -fsanitize=address -fno-omit-frame-pointer";;
    no)  IM2A_DEBUG="0";;
    *)   AC_MSG_ERROR(["bad value ${enableval} for feature --enable-debug"]);;
  esac
], [
  IM2A_DEBUG="0"
])
AM_CONDITIONAL([DEBUG], [test "x${IM2A_DEBUG}" = "x1"])
AC_DEFINE_UNQUOTED([DEBUG], [${IM2A_DEBUG}], [Debug mode.])

# Check for curses.
AC_CHECK_LIB([ncurses], [tgetent],, [
  AC_MSG_ERROR([tgetent() not found in -lncurses.])
])
AC_CHECK_LIB([ncurses], [tgetnum],, [
  AC_MSG_ERROR([tgetnum() not found in -lncurses.])
])

# Check for ImageMagick C++ bindings.
AX_CHECK_IMAGEMAGICK()

if test x"$ac_imagemagick" != "xyes"; then
  AC_MSG_ERROR([ImageMagick C++ bindings not found. Please install ImageMagick with C++ bindings or use --with-magick++-config=path.])
fi

AC_SUBST([IMAGEMAGICK_CXXFLAGS])
AC_SUBST([IMAGEMAGICK_LDFLAGS])

# Makefiles.
AC_CONFIG_FILES([Makefile src/Makefile])

# Le grand finale.
AC_OUTPUT()

echo
echo "Configuration complete."
echo
echo "Now, run make and pray."
echo
