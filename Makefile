game:
	clang++ -std=c++17 src/main.cpp src/core/game.cpp -o play -I include -lSDL2 -lSDL2main -lSDL2_image