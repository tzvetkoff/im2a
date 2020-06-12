dnl
dnl Check for ImageMagick, based on version found at libdbi-drivers.sf.net (GPLv2-licensed)
dnl

AC_DEFUN([AC_FIND_FILE], [
  $3=no
  for i in $2; do
    for j in $1; do
      if test -r "$i/$j"; then
        $3=$i
        break 2
      fi
    done
  done
])

AC_DEFUN([AX_CHECK_IMAGEMAGICK], [
  # Local variables
  ac_imagemagick="no"

  # Exported variables
  IMAGEMAGICK_CPPFLAGS=""
  IMAGEMAGICK_CXXFLAGS=""
  IMAGEMAGICK_LDFLAGS=""
  IMAGEMAGICK_LDADD=""
  IMAGEMAGICK_VERSION=""

  AC_ARG_WITH([magick++-config], AS_HELP_STRING([--with-magick++-config=path], [Provide path to Magick++-config.]), [
    ac_imagemagick_config="${withval}"
  ], [
    ac_imagemagick_config="auto"
  ])

  AC_MSG_CHECKING([for ImageMagick++])

  # Try to find Magick++-config in common directories
  if test "x${ac_imagemagick_config}" = "xauto"; then
    ac_imagemagick_config_dirs="/usr/bin /usr/local/bin /usr/local/imagemagick/bin /opt/imagemagick/bin"
    AC_FIND_FILE(Magick++-config, ${ac_imagemagick_config_dirs}, ac_imagemagick_config_dir)

    if test "x${ac_imagemagick_config_dir}" = "xno"; then
      ac_imagemagick="no"
    else
      IMAGEMAGICK_CPPFLAGS="`${ac_imagemagick_config_dir}/Magick++-config --cppflags 2>/dev/null`"
      IMAGEMAGICK_CXXFLAGS="`${ac_imagemagick_config_dir}/Magick++-config --cxxflags 2>/dev/null`"
      IMAGEMAGICK_LDFLAGS="`${ac_imagemagick_config_dir}/Magick++-config --ldflags 2>/dev/null`"
      IMAGEMAGICK_LDADD="`${ac_imagemagick_config_dir}/Magick++-config --libs 2>/dev/null`"
      IMAGEMAGICK_VERSION="`${ac_imagemagick_config_dir}/Magick++-config --version 2>/dev/null`"

      if test "x${IMAGEMAGICK_VERSION}" = "x"; then
        ac_imagemagick="no"
      else
        ac_imagemagick="yes"
      fi
    fi
  else
    IMAGEMAGICK_CPPFLAGS="`${ac_imagemagick_config} --cxxflags 2>/dev/null`"
    IMAGEMAGICK_CXXFLAGS="`${ac_imagemagick_config} --cxxflags 2>/dev/null`"
    IMAGEMAGICK_LDFLAGS="`${ac_imagemagick_config} --ldflags 2>/dev/null`"
    IMAGEMAGICK_LDADD="`${ac_imagemagick_config} --libs 2>/dev/null`"
    IMAGEMAGICK_VERSION="`${ac_imagemagick_config} --version 2>/dev/null`"

    if test "x${IMAGEMAGICK_VERSION}" = "x"; then
      ac_imagemagick="no"
    else
      ac_imagemagick="yes"
    fi
  fi

  IMAGEMAGICK_VERSION="${IMAGEMAGICK_VERSION%%.*}"

  AC_MSG_RESULT([${ac_imagemagick}])
])
