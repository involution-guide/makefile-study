objects = hello.o Person.o
app = hello

ALL: $(app)

$(app): $(objects)
	g++ -o $(app) $(objects)

hello.o: Person.h
Person.o: Person.h

.PHONY:clean run ALL
clean:
	-rm $(app) $(objects)
run: $(app)
	./hello

