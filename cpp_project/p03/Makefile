srcs = $(wildcard ./*.cpp)
objects = $(patsubst %.cpp, %.o, $(srcs))
app = hello

ALL: $(app)

$(app): $(objects)
	g++ $^ -o $@

.PHONY:clean run ALL
clean:
	-rm $(app) $(objects)
run: $(app)
	./hello
