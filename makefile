APP=server

build:
	c++ -std=c++17 src/main.cpp -o $(APP)

clean:
	rm $(APP)

rebuild:
	clean
	build
