SRCFILES := todo.cpp

build:
	g++ -o todo ${SRCFILES}

install:
	cp todo /usr/bin/

clean:
	rm -rf todo
	rm -rf ~/.config/todo

uninstall:
	rm /usr/bin/todo
