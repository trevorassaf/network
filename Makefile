CXX = g++

H_PATH = headers
S_PATH = source
O_PATH = bits
O_IP_PATH = $(O_PATH)/ip
O_TCP_IP_PATH = $(O_IP_PATH)/tcp

NETWORK_OBJS = \
	main.o \
	network_except.o \
	ipv4.o	\
	ipv6.o \
	port.o \
	host.o \
	packet.o \
	packet_writer.o \
	packet_reader.o \
	socket_config.o \
	socket.o \
	socket_builder.o \
	time.o \
	ip_socket.o \
	ip_socket_builder.o \
	tcp_socket.o \
	tcp_socket_builder.o \
	tcp_connection.o \
	tcp_connection_builder.o \
	tcp_service.o \
	tcp_service_builder.o

H_IP_PATH = $(H_PATH)/ip
S_IP_PATH = $(S_PATH)/ip

H_TCP_IP_PATH = $(H_IP_PATH)/tcp
S_TCP_IP_PATH = $(S_IP_PATH)/tcp

NETWORK_HEADERS = \
	$(H_PATH)/network.h \
	$(H_PATH)/network_except.h	\
	$(H_PATH)/ipv4.h	\
	$(H_PATH)/ipv6.h	\
	$(H_PATH)/port.h \
	$(H_PATH)/host.h \
	$(H_PATH)/packet.h \
	$(H_PATH)/packet_writer.h \
	$(H_PATH)/packet_reader.h \
	$(H_PATH)/socket_config.h \
	$(H_PATH)/socket.h \
	$(H_PATH)/socket_builder.h \
	$(H_PATH)/socket_config.h \
	$(H_PATH)/time.h \
	$(H_IP_PATH)/socket_config.h \
	$(H_IP_PATH)/socket.h \
	$(H_IP_PATH)/socket_builder.h \
	$(H_TCP_IP_PATH)/socket_config.h \
	$(H_TCP_IP_PATH)/socket.h \
	$(H_TCP_IP_PATH)/socket_builder.h \
	$(H_TCP_IP_PATH)/connection.h \
	$(H_TCP_IP_PATH)/connection_builder.h \
	$(H_TCP_IP_PATH)/service.h \
	$(H_TCP_IP_PATH)/service_builder.h

NETWORK_EXE = nwk

CXXFLAGS = -Wall -Wno-deprecated -std=c++11 -ggdb

LFLAGS = $(CXXFLAGS)
DEBUG_LFLAGS = $(LFLAGS) -ggdb

nwk: $(NETWORK_OBJS)
	$(CXX) $(LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

debug: $(NETWORK_OBJS)
	$(CXX) $(DEBUG_LFLAGS) -o $(NETWORK_EXE) $(NETWORK_OBJS)

main.o: $(S_PATH)/main.cpp $(NETWORK_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/main.cpp -o $(O_PATH)/main.o

network_except.o: \
		$(H_PATH)/network_except.h \
		$(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/network_except.cpp -o $(O_PATH)/network_except.o

ipv4.o: \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/port.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv4.cpp -o $(O_PATH)/ipv4.o

ipv6.o: \
		$(H_PATH)/ipv6.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/ipv6.cpp -o $(O_PATH)/ipv6.o

port.o: \
		$(H_PATH)/port.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/port.cpp -o $(O_PATH)/port.o

host.o: \
		$(H_PATH)/host.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/ipv4.h \
		$(H_PATH)/ipv6.h \
		$(H_PATH)/port.h 
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/host.cpp -o $(O_PATH)/host.o

packet.o: \
		$(H_PATH)/packet.h \
		$(H_PATH)/network.h \
		$(H_PATH)/packet_writer.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet.cpp -o $(O_PATH)/packet.o

packet_writer.o: \
		$(H_PATH)/packet_writer.h \
		$(H_PATH)/network.h \
		$(H_PATH)/packet.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet_writer.cpp -o $(O_PATH)/packet_writer.o

packet_reader.o: \
		$(H_PATH)/packet_reader.h \
		$(H_PATH)/network.h \
		$(H_PATH)/packet.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/packet_reader.cpp -o $(O_PATH)/packet_reader.o

socket_config.o: \
		$(H_PATH)/socket_config.h \
		$(H_PATH)/socket.h \
		$(H_PATH)/socket_builder.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/time.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/socket_config.cpp -o $(O_PATH)/socket_config.o

socket_builder.o: \
		$(H_PATH)/network.h \
		$(H_PATH)/socket_config.h \
		$(H_PATH)/socket.h \
		$(H_PATH)/socket_builder.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/time.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/socket_builder.cpp -o $(O_PATH)/socket_builder.o

socket.o: \
		$(H_PATH)/socket.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/socket_builder.h \
		$(H_PATH)/socket_config.h \
		$(H_PATH)/time.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/socket.cpp -o $(O_PATH)/socket.o

time.o: \
		$(H_PATH)/time.h \
		$(H_PATH)/network.h
	$(CXX) $(CXXFLAGS) -c $(S_PATH)/time.cpp -o $(O_PATH)/time.o

ip_socket_builder.o: \
		$(H_IP_PATH)/socket_builder.h \
		$(H_IP_PATH)/socket_config.h \
		$(H_IP_PATH)/socket.h \
		$(H_PATH)/socket.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/socket_builder.h \
		$(H_PATH)/socket_config.h \
		$(H_PATH)/time.h
	$(CXX) $(CXXFLAGS) -c $(S_IP_PATH)/socket_builder.cpp -o $(O_IP_PATH)/socket_builder.o

ip_socket.o: \
		$(H_IP_PATH)/socket.h \
		$(H_IP_PATH)/socket_config.h \
		$(H_IP_PATH)/socket_builder.h \
		$(H_PATH)/socket.h \
		$(H_PATH)/network.h \
		$(H_PATH)/network_except.h \
		$(H_PATH)/socket_builder.h \
		$(H_PATH)/socket_config.h \
		$(H_PATH)/time.h
	$(CXX) $(CXXFLAGS) -c $(S_IP_PATH)/socket.cpp -o $(O_IP_PATH)/socket.o

tcp_socket.o: \
		$(H_TCP_IP_PATH)/socket.h \
		$(H_TCP_IP_PATH)/socket_config.h \
		$(H_IP_PATH)/socket.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/socket.cpp -o $(O_TCP_IP_PATH)/socket.o

tcp_socket_builder.o: \
		$(H_TCP_IP_PATH)/socket_builder.h \
		$(H_TCP_IP_PATH)/socket.h \
		$(H_TCP_IP_PATH)/socket_config.h \
		$(H_IP_PATH)/socket.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/socket_builder.cpp -o $(O_TCP_IP_PATH)/socket_builder.o

tcp_connection_builder.o: \
		$(H_TCP_IP_PATH)/connection_builder.h \
		$(H_TCP_IP_PATH)/connection.h \
		$(H_TCP_IP_PATH)/socket_builder.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/connection_builder.cpp -o $(O_TCP_IP_PATH)/connection_builder.o

tcp_connection.o: \
		$(H_TCP_IP_PATH)/connection.h \
		$(H_TCP_IP_PATH)/connection_builder.h \
		$(H_TCP_IP_PATH)/socket.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/connection.cpp -o $(O_TCP_IP_PATH)/connection.o

tcp_service.o: \
		$(H_TCP_IP_PATH)/service.h \
		$(H_TCP_IP_PATH)/service_builder.h \
		$(H_TCP_IP_PATH)/connection.h \
		$(H_TCP_IP_PATH)/connection_builder.h \
		$(H_TCP_IP_PATH)/socket.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/service.cpp -o $(O_TCP_IP_PATH)/service.o

tcp_service_builder.o: \
		$(H_TCP_IP_PATH)/service_builder.h \
		$(H_TCP_IP_PATH)/service.h \
		$(H_TCP_IP_PATH)/socket.h
	$(CXX) $(CXXFLAGS) -c $(S_TCP_IP_PATH)/service_builder.cpp -o $(O_TCP_IP_PATH)/service_builder.o

clean:
	\rm -rf $(O_PATH)/*.o $(NETWORK_EXE)
