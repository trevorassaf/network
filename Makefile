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

##########################
######### Recipes ########
##########################

# Source files 
SOURCE_FILES := $(shell find $(SOURCE_DIR) -name '*.cpp')

# Object files
OBJECT_FILES_WITH_ROOT = $(addprefix $(OBJECT_DIR)/,$(SOURCE_FILES:%.cpp=%.o))
OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)

#Declaration of variables
CC = g++
CC_FLAGS = -w -I$(SOURCE_DIR) -std=c++11

# Binaries
NETWORK_EXEC = nwk

# Removed files
FILES_TO_REMOVE = $(NETWORK_EXEC) $(OBJECT_DIR)/ $(NETWORK_EXEC).dSYM

# Link for network binary 
$(NETWORK_EXEC): $(OBJECT_FILES) 
	@$(CC) $(OBJECT_FILES_WITH_ROOT) -o $(NETWORK_EXEC)

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
