CC=g++
FLAGS= -std=c++11
FILES=main.cc comun.h error.h menu.h menu2.h book.h bookStore.h binBook.h binBookStore.h funcionesMain.h funcionesImExport.h
ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    RM=del
else
    RM=rm
endif

debug: files
	${CC} -g -o prac2.exe main.cc
release: ${FILES}
	${CC} -o prac2.exe ${FLAGS} ${FILES}
dos: main2.cc
	${CC} main2.cc error.h bookStore.h
2: dos

files: ${FILES}
	${CC} -c comun.h
	${CC} -c error.h
	${CC} -c book.h
	${CC} -c bookStore.h
	${CC} -c binBook.h
	${CC} -c binBookStore.h
	${CC} -c menu.h
	${CC} -c funcionesMain.h
	${CC} -c menu2.h
	${CC} -c funcionesImExport.h
#comun.h.gch error.h.gch book.h.gch bookStore.h.gch binBook.h.gch binBookStore.h.gch menu.h.gch funcionesMain.h.gch menu2.h.gch funcionesImExport.h.gch

sync:
	git add . & git commit -a & git pull & git push

clean:
	${RM} *.exe , *.gch