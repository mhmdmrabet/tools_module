intarray.exe : test_array.o intarray.o
	gcc -Wall -Wextra -Werror test_array.o intarray.o -o intarray.exe

intarray.o : intarray.c intarray.h
	gcc -Wall -Wextra -Werror -c intarray.c

test_array.o : test_array.c intarray.h
	gcc -Wall -Wextra -Werror -c test_array.c