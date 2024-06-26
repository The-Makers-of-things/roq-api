export PREFIX="$CONDA_PREFIX"
export CFLAGS="$DEBUG_CFLAGS"
export CPPFLAGS="$DEBUG_CPPFLAGS -D_LIBCPP_DISABLE_AVAILABILITY -Wall -Wextra -Wno-deprecated-builtins"
export CXXFLAGS="$DEBUG_CXXFLAGS $CPPFLAGS"
export LDFLAGS="$LDFLAGS -L$PREFIX/lib"
export PKG_CONFIG_PATH="$PREFIX/lib/pkgconfig"
export ROQ_BUILD_TYPE="Debug"
export ASAN_OPTIONS="strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1:detect_leaks=1"
