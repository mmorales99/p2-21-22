CC=D:\MinGW\bin\g++.exe
FLAGS= -std=c++11
FILES=main.cc comun.h error.h menu.h book.h bookStore.h binBook.h binBookStore.h funcionesMain.h

debug: ${FILES}
	${CC} -g -o a.exe ${FLAGS} ${FILES}
release: ${FILES}
	${CC} -o prac2.exe ${FLAGS} ${FILES}
dos: main2.cc
	${CC} main2.cc error.h bookStore.h
2: dos


clean:
	rm *.exe
	rm *.gch