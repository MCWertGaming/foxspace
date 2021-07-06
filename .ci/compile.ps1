git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Debug

git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Release
