CXX = g++

H_PATH = headers
S_PATH = source

NETWORK_OBJS = \
	main.o \
	network_except.o \
	ipv4.o	\
	ipv6.o \
	port.o \
	host.o \
	packet.o \
	packet_writer.o \
	packet_reader.o

NETWORK_HEADERS = \
	$(H_PATH)/network.h \
	$(H_PATH)/network_except.h	\
	$(H_PATH)/ipv4.h	\
	$(H_PATH)/ipv6.h	\
	$(H_PATH)/port.h \
	$(H_PATH)/host.h \
	$(H_PATH)/packet.h \
	$(H_PATH)/packet_writer.h \
	$(H_PATH)/packet_reader.h

NETWORK_EXE = nwk

CXXFLAGS = -Wall -Wno-deprecated -std=c++11 -ggdb

LFLAGS = $(CXXFLAGS)
DEBUG_LFLAGS = $(LFLAGS) -ggdb

nwk: $(NETWORK_OBJS)
	$(CXX) $(LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

debug: $(NETWORK_OBJS)
	$(CXX) $(DEBUG_LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

main.o: $(S_PATH)/main.cpp $(NETWORK_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/main.cpp

network_except.o: \
		$(H_PATH)/network_except.h \
		$(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/network_except.cpp

ipv4.o: \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/port.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv4.cpp

ipv6.o: \
		$(H_PATH)/ipv6.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv6.cpp

port.o: \
		$(H_PATH)/port.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/port.cpp

host.o: \
		$(H_PATH)/host.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/ipv6.h \
		$(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/host.cpp

packet.o: \
		$(H_PATH)/network.h \
		$(H_PATH)/packet_writer.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet.cpp

packet_writer.o: \
		$(H_PATH)/network.h \
		$(H_PATH)/packet.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet_writer.cpp

packet_reader.o: \
		$(H_PATH)/network.h \
		$(H_PATH)/packet.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet_reader.cpp

clean:
	\rm *.o $(NETWORK_EXE)
