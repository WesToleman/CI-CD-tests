Push-Location -Path $env:temp
git clone --branch v2.4.2 --depth 1 https://github.com/catchorg/Catch2.git
mkdir Catch2\build
cd Catch2\build
cmake -DCATCH_BUILD_TESTING=OFF -DCATCH_ENABLE_WERROR=OFF -DCATCH_INSTALL_DOCS=OFF -DCATCH_INSTALL_HELPERS=OFF -G "Visual Studio 15 2017" -A x64 ..
cmake --build . --target install --config release
Pop-Location
