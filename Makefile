CXX = g++

H_PATH = headers
S_PATH = source

NETWORK_OBJS = main.o \
							 ipv4.o	\
							 port.o

NETWORK_HEADERS = $(H_PATH)/network.h \
							 $(H_PATH)/ipv4.h	\
							 $(H_PATH)/port.h

NETWORK_EXE = nwk

CXX_FLAGS = -Wall -Wno-deprecate -std=c++11
LFLAGS = $(CXXFLAGS)

all: $(NETWORK_EXE)

nwk: $(NETWORK_OBJS)
	$(CXX) $(LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

main.o: $(S_PATH)/main.cpp $(NETWORK_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/main.cpp

ipv4.o: $(H_PATH)/ipv4.h $(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv4.cpp

port.o: $(H_PATH)/port.h $(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/port.cpp

clean:
	\rm *.o $(NETWORK_EXE)
