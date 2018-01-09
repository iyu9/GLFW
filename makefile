all:
	g++ -o RunApp main.cpp -framework OpenGL -lglfw

run:
	g++ -o RunApp main.cpp -framework OpenGL -lglfw
	./RunApp

git:
	git add -A
	git commit -m "auto commit from makefile"
	git push
