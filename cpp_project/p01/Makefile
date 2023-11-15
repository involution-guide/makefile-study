objects = hello.o Person.o
app = hello

ALL: $(app)

$(app): $(objects)
	g++ -o $(app) $(objects)

hello.o: hello.cpp
	g++ -c hello.cpp -I.

Person.o: Person.cpp
	g++ -c Person.cpp -I.

.PHONY:clean run ALL
clean:
	-rm $(app) $(objects)
run: $(app)
	./hello

