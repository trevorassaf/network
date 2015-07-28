CXX = g++

SOURCE_DIR = cpp2
HEADER_DIR = $(SOURCE_DIR)
SOURCE_FILES := $(shell find $(SOURCE_DIR) -name '*.cpp')

BINARY = nwk

LDFLAGS = 
CXXFLAGS = -Wall -Wno-deprecated -std=c++11 -ggdb

DEBUG_LFLAGS = $(LFLAGS) -ggdb

OBJECT_FILES_ROOT = bits
OBJECT_FILES := $(addprefix $(OBJECT_FILES_ROOT)/,$(SOURCE_FILES:%.c=%.o))

# Compile binary (no smart dependency checks)
$(BINARY): $(OBJECTS)
	    $(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECT_FILES) -o $(BINARY)

$(OBJECT_FILES_ROOT)/%.o: %.c
	    $(CXX) $(CXXFLAGS) $(LDFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	\rm -rf $(OBJECT_PATH)/*.o $(NETWORK_EXE)
