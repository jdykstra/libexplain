#!/bin/sh
# Build libexplain on MacOS with Homebrew (Apple Silicon: /opt/homebrew).
# Prerequisites: brew install bison groff gawk make gettext
# Usage: ./build-macos.sh [make-target ...]     (default target: all)
set -e
cd "$(dirname "$0")"

BREW=${HOMEBREW_PREFIX:-/opt/homebrew}
# Apple's bison is 2.3 (too old), and Apple's make is 3.81.
PATH=$BREW/opt/bison/bin:$BREW/opt/make/libexec/gnubin:$PATH
export PATH

# Apple's /usr/bin/libtool is not GNU libtool; Homebrew installs it as glibtool.
if [ ! -f Makefile ]; then
    LIBTOOL=glibtool ./configure
fi
make -j"$(sysctl -n hw.ncpu)" "$@"
