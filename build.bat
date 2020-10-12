g++ -c src/*.cpp -std=c++17 -Wall -Iinclude/x64
g++ *.o -o build/app.exe -Llib/x64 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image