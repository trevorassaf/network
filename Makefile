##########################
######## Commands ########
##########################
MKDIR_P = mkdir -p
RM_R = rm -rf

##########################
####### Directories ######
##########################
SOURCE_DIR = cpp
OBJECT_DIR = bits
MAIN_SOURCE_DIR = $(SOURCE_DIR)/main

##########################
####### Main Files #######
##########################
SERVER_SOURCE = $(MAIN_SOURCE_DIR)/server.cpp
CLIENT_SOURCE = $(MAIN_SOURCE_DIR)/client.cpp

##########################
######### Recipes ########
##########################

# Scan for source files 
SOURCE_FILES := $(shell find $(SOURCE_DIR) ! -path '$(MAIN_SOURCE_DIR)/*' -name '*.cpp')

# Server object paths
SERVER_SOURCE_FILES = $(SOURCE_FILES) + $(SERVER_SOURCE) 
SERVER_OBJECT_FILES_WITH_ROOT = $(addprefix $(OBJECT_DIR)/,$(SOURCE_FILES:%.cpp=%.o))
SERVER_OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)

# Client object paths
CLIENT_SOURCE_FILES = $(SOURCE_FILES) + $(CLIENT_SOURCE) 
CLIENT_OBJECT_FILES_WITH_ROOT = $(addprefix $(OBJECT_DIR)/,$(SOURCE_FILES:%.cpp=%.o))
CLIENT_OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)

#Declaration of variables
CC = g++
CC_FLAGS = -w -I$(SOURCE_DIR) -std=c++11

# Binaries
CLIENT_EXEC = client
SERVER_EXEC = server

# Removed files
FILES_TO_REMOVE = \
		$(SERVER_EXEC) \
		$(CLIENT_EXEC) \
		$(OBJECT_DIR)/ \
		$(CLIENT_EXEC).dSYM \
		$(SERVER_EXEC).dSYM

# Compile server binary
$(SERVER_EXEC): $(SERVER_OBJECT_FILES)
	@$(CC) $(SERVER_OBJECT_FILES_WITH_ROOT) -o $(SERVER_EXEC)

# Compile client binary
$(CLIENT_EXEC): $(CLIENT_OBJECT_FILES) 
	@$(CC) $(CLIENT_OBJECT_FILES_WITH_ROOT) -o $(CLIENT_EXEC)

# Compile source
%.o: %.cpp
	@echo $(OBJECT_DIR)/$@
	@if [ -e $(dir $@) ] ; \
		then \
			${MKDIR_P} $(OBJECT_DIR)/$(dir $@) ; \
	fi;
	@$(CC) -c $(CC_FLAGS) $< -o $(OBJECT_DIR)/$@ 

# To remove generated files
clean:
	rm -rf $(FILES_TO_REMOVE) 
