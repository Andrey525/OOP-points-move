
rez: main.cpp point.cpp
	g++ -Wall -o rez main.cpp point.cpp -lglut -lX11 -lGL -lGLU

clean:
	rm -rf rez