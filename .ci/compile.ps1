git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Debug -j 10

git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Release -j 10
