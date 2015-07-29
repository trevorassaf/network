CXX = g++

SOURCE_DIR = cpp2
HEADER_DIR = $(SOURCE_DIR)
SOURCE_FILES := $(shell find $(SOURCE_DIR) -name '*.cpp')

BINARY = nwk

LDFLAGS = 
CXXFLAGS = -Wall -Wno-deprecated -std=c++11 -ggdb

DEBUG_LFLAGS = $(LFLAGS) -ggdb

OBJECT_FILES_ROOT = bits

OBJECT_FILES := $(addprefix $(OBJECT_FILES_ROOT)/,$(SOURCE_FILES:%.cpp=%.o))

all: 
	$(OBJECT_FILES)
	$(BINARY)
	@echo $(OBJECT_FILES)
	@echo $(SOURCE_FILES)

# Compile binary (no smart dependency checks)
$(BINARY): $(SOURCES_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECT_FILES) -o $(BINARY)

$(OBJECT_FILES): $(SOURCE_FILES) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -I$(HEADER_DIR) -c $< -o $@

# $(OBJECT_FILES_ROOT)/%.o: %.cpp 
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	\rm -rf $(OBJECT_FILES_ROOT)/*.o $(BINARY)
