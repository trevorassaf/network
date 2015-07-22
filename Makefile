CXX = g++

S_PATH = cpp
O_PATH = bits

NETWORK_OBJS = \
		$(S_PATH)/main.o

NETWORK_HEADERS =

NETWORK_EXE = nwk

CXXFLAGS = -Wall -Wno-deprecated -std=c++11 -ggdb

LFLAGS = $(CXXFLAGS)
DEBUG_LFLAGS = $(LFLAGS) -ggdb

nwk: $(NETWORK_OBJS)
	$(CXX) $(LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

main.o: $(S_PATH)/main.cpp $(NETWORK_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/main.cpp -o $(O_PATH)/main.o

clean:
	\rm -rf $(O_PATH)/*.o $(NETWORK_EXE)
