all:
	g++ -std=c++11 -o RunApp main.cpp -framework OpenGL -lglfw

run:
	g++ -std=c++11 -o RunApp main.cpp -framework OpenGL -lglfw
	./RunApp

git:
	git add -A
	git commit -m "auto commit from makefile"
	git push
