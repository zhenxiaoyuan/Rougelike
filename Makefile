game:
	clang++ -std=c++17 \
					   src/components/Position.cpp \
					   src/components/Sprite.cpp \
					   src/systems/RenderSystem.cpp \
					   src/core/Window.cpp \
					   src/core/Game.cpp \
					   src/main.cpp \
	-o play -I include -lSDL2 -lSDL2main -lSDL2_image