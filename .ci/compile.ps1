git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Debug --target all -j 10

git reset --hard
git clean -fdx
cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Release --target all -j 10
