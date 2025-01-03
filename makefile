debug-linux:
	gcc src/main.c src/source.c -I include -o bin/debug/md2html -g

debug-windows:
	x86_64-w64-mingw32-gcc src/main.c src/source.c -I include -o bin/debug/md2html.exe -lmingw32
