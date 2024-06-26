export PREFIX="$CONDA_PREFIX"
export CFLAGS="$CFLAGS"
export CPPFLAGS="$CPPFLAGS -D_LIBCPP_DISABLE_AVAILABILITY -Wall -Wextra -Wno-deprecated-builtins"
export CXXFLAGS="$CXXFLAGS $CPPFLAGS"
export LDFLAGS="$LDFLAGS -L$PREFIX/lib"
export PKG_CONFIG_PATH="$PREFIX/lib/pkgconfig"
export ROQ_BUILD_TYPE="Release"
