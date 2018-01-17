UNAME = $(shell uname)

all:
ifeq ($(UNAME), "Linux")
	g++ -std=c++11 `pkg-config --cflags --libs glfw3 glu` -o RunApp main.cpp
else
	g++ -std=c++11 -o RunApp main.cpp -framework OpenGL -lglfw
endif

run:
ifeq ($(UNAME), "Linux")
	g++ -std=c++11 `pkg-config --cflags --libs glfw3 glu` -o RunApp main.cpp
	./RunApp
else
	g++ -std=c++11 -o RunApp main.cpp -framework OpenGL -lglfw
	./RunApp
endif

git:
	git add -A
	git commit -m "auto commit from makefile"
	git push
