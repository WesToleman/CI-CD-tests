#!/bin/sh
set -ex
if cd /tmp/Catch2/build; then return; fi
cd /tmp/
git clone --branch v2.4.2 --depth 1 https://github.com/catchorg/Catch2.git
mkdir Catch2/build
cd Catch2/build
cmake -DCMAKE_BUILD_TYPE=Release \
-DCATCH_BUILD_TESTING=OFF -DCATCH_ENABLE_WERROR=OFF \
-DCATCH_INSTALL_DOCS=OFF -DCATCH_INSTALL_HELPERS=OFF \
.. && sudo make install
