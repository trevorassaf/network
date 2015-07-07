CXX = g++

H_PATH = headers
S_PATH = source

NETWORK_OBJS = main.o \
							 network_except.o \
							 ipv4.o	\
							 ipv6.o \
							 port.o \
							 host.o \
							 client_config.o \
							 server_config.o

NETWORK_HEADERS = $(H_PATH)/network.h \
							 $(H_PATH)/network_except.h	\
							 $(H_PATH)/ipv4.h	\
							 $(H_PATH)/ipv6.h	\
							 $(H_PATH)/port.h \
							 $(H_PATH)/host.h \
							 $(H_PATH)/client_config.h \
							 $(H_PATH)/server_config.h

NETWORK_EXE = nwk

CXXFLAGS = -Wall -Wno-deprecated -std=c++11
LFLAGS = $(CXXFLAGS)

nwk: $(NETWORK_OBJS)
	$(CXX) $(LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

main.o: $(S_PATH)/main.cpp $(NETWORK_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/main.cpp

network_except.o: $(H_PATH)/network_except.h $(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/network_except.cpp

ipv4.o: $(H_PATH)/ipv4.h $(H_PATH)/network.h $(H_PATH)/network_except.h $(H_PATH)/port.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv4.cpp

ipv6.o: $(H_PATH)/ipv6.h $(H_PATH)/network.h $(H_PATH)/network_except.h $(H_PATH)/ipv4.h $(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv6.cpp

port.o: $(H_PATH)/port.h $(H_PATH)/network.h $(H_PATH)/network_except.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/port.cpp

host.o: $(H_PATH)/host.h $(H_PATH)/network.h $(H_PATH)/network_except.h $(H_PATH)/ipv4.h $(H_PATH)/ipv6.h $(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/host.cpp

client_config.o: $(H_PATH)/client_config.h $(H_PATH)/network.h $(H_PATH)/network_except.h $(H_PATH)/ipv4.h $(H_PATH)/ipv6.h $(H_PATH)/port.h $(H_PATH)/host.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/client_config.cpp

server_config.o: $(H_PATH)/server_config.h $(H_PATH)/network.h $(H_PATH)/network_except.h $(H_PATH)/ipv4.h $(H_PATH)/ipv6.h $(H_PATH)/port.h $(H_PATH)/host.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/server_config.cpp

clean:
	\rm *.o $(NETWORK_EXE)
