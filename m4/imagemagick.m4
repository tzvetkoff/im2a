dnl Check for ImageMagick, based on version found at libdbi-drivers.sf.net (GPLv2-licensed)

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

AC_DEFUN([AC_CHECK_IMAGEMAGICK], [
  # Local variables
  ac_imagemagick="no"

  # Exported variables
  IMAGEMAGICK_LDFLAGS=""
  IMAGEMAGICK_CXXFLAGS=""

  AC_ARG_WITH([imagemagick-config], AC_HELP_STRING([--with-imagemagick-config], [Provide path to Magick++-config.]), [
    ac_imagemagick="${withval}"
    if test "x${withval}" != "xno" -a "x${withval}" != "xyes"; then
      ac_imagemagick="yes"
    fi
  ], [
    ac_imagemagick="auto"
  ])

  AC_MSG_CHECKING([for ImageMagick++])

  # Try to find Magick++-config in common directories.
  if test "x$ac_imagemagick" = "xauto"; then
    imagemagick_config_dirs="/usr/bin /usr/local/bin /usr/local/imagemagick/bin /opt/imagemagick/bin"
    AC_FIND_FILE(Magick++-config, ${imagemagick_config_dirs}, ac_imagemagick_config_dir)

    if test "${ac_imagemagick_config_dir}" = "no"; then
      ac_imagemagick="no"
    else
      IMAGEMAGICK_LDFLAGS=`${ac_imagemagick_config_dir}/Magick++-config --ldflags 2>/dev/null`
      IMAGEMAGICK_CXXFLAGS=`${ac_imagemagick_config_dir}/Magick++-config --cxxflags 2>/dev/null`

      if test "x$IMAGEMAGICK_LDFLAGS" = "x" -a "x$IMAGEMAGICK_CXXFLAGS" = "x"; then
        ac_imagemagick="no"
      else
        ac_imagemagick="yes"
      fi
    fi
  else
    IMAGEMAGICK_LDFLAGS=`${ac_imagemagick} --ldflags 2>/dev/null`
    IMAGEMAGICK_CXXFLAGS=`${ac_imagemagick} --cxxflags 2>/dev/null`

    if test "x$IMAGEMAGICK_LDFLAGS" = "x" -a "x$IMAGEMAGICK_CXXFLAGS" = "x"; then
      ac_imagemagick="no"
    else
      ac_imagemagick="yes"
    fi
  fi

  AC_MSG_RESULT([$ac_imagemagick])
])
