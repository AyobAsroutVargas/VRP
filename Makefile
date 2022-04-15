CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
DEPS = file-loader.h greedy-vrp.h vehicle.h grasp-vrp.h
OBJ = main.o file-loader.o greedy-vrp.o grasp-vrp.o


%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm main *.o