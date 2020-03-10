APP=server

build:
	c++ -std=c++17 src/main.cpp src/handler.cpp src/server.cpp src/serveroptions.cpp -o $(APP)

clean:
	rm $(APP)

rebuild:
	clean
	build
