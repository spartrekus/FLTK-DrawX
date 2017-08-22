
all:
	g++ -L/usr/local/lib -lfltk -lXext -lX11 -lm  "fldrawx.cxx"  -o file.out 


