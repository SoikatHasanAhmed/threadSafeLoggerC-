dependency for gtest lib

for ubuntu install step by step :
            sudo apt-get install libgtest-dev

            sudo apt-get install cmake # install cmake
            cd /usr/src/gtest
            sudo cmake CMakeLists.txt
            sudo make

            # copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
            sudo cp *.a /usr/lib