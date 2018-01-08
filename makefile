all:
	g++ -o RunApp main.cpp -framework OpenGL -lglfw

run:
	g++ -o RunApp main.cpp -framework OpenGL -lglfw
	./RunApp
