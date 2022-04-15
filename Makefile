CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
DEPS = file-loader.h
OBJ = main.o file-loader.o


%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm main *.o