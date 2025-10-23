CXX = clang++
SOURCE_CXX = src/main.cpp
TARGET = bloom_filter
LDFLAGS_COMMON = -std=c++2a

all:
	$(CXX) $(SOURCE_CXX) $(OBJECTS_CPP) $(LDFLAGS_COMMON) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
