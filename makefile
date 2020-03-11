APP=server
TESTAPP=serveroptions_test
MAIN=src/main.cpp
SERVEROPTTEST=test/serveroptions_test.cpp
HANDLERSRC = src/handler.cpp
SERVERSRC = src/server.cpp
SERVEROPTSRC = src/serveroptions.cpp
SERVERLIB = $(HANDLERSRC) $(SEVERSRC) $(SERVEROPTSRC)

C++STD=-std=c++17
WARNINGLVL = -Wall
OPTS = $(C++STD) $(WARNINGLVL)

build:
	c++ -std=c++17 src/main.cpp src/handler.cpp src/server.cpp src/serveroptions.cpp -o $(APP)

clean:
	rm $(APP)

rebuild:
	clean
	build

test-serveroptions:
	c++ $(OPTS) $(SERVEROPTSRC) $(SERVEROPTTEST) -o $(TESTAPP)
