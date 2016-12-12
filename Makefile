project=life
cc=gcc
cflags=-Wall --std=c11
lflags=-Wall --std=c11

objects=main.o

%.o: %.c
	$(cc) -c $(cflags) -o $@ $^

$(project): $(objects)
	$(cc) $(objects) -o $(project) $(lflags)

clean:
	rm -f $(objects)
	rm -f $(project)
