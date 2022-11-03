all : stats.exe intarray.exe
	echo "Compilation done."

stats.exe : stats.o intarray.o tools.o
	gcc -Wall -Wextra -Werror stats.o intarray.o tools.o -o stats.exe

intarray.exe : test_array.o intarray.o tools.o
	gcc -Wall -Wextra -Werror test_array.o intarray.o tools.o -o intarray.exe

intarray.o : intarray.c intarray.h
	gcc -Wall -Wextra -Werror -c intarray.c

test_array.o : test_array.c intarray.h tools.h
	gcc -Wall -Wextra -Werror -c test_array.c

stats.o : stats.c intarray.h tools.h
	gcc -Wall -Wextra -Werror -c stats.c

tools.o : tools.c tools.h
	gcc -Wall -Wextra -Werror -c tools.c