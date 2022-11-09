CFLAGS = -Wall

app: main.o bstree.o hashtab.o
		$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

libbstree.a: bstree.o
		ar rcs $@ $^

bstree.o: bstree.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

libhashtab.a: hashtab.o
		ar rcs $@ $^

hashtab.o: hashtab.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
