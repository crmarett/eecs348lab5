all: sales football

football: lab5_fb.c
	gcc -o football lab5_fb.c

sales: lab5_sales.c
	gcc -o sales lab5_sales.c

clean:
	rm *.o sales football
