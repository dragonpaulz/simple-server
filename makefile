APP=server

build:
	c++ src/main.cpp -o $(APP)

clean:
	rm $(APP)

rebuild:
	clean
	build
