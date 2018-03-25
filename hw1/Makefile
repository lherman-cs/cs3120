PROG= main
SRC= main.c
OBJECTS= main.o
CC= gcc
CFLAGS= 

$(PROG): $(OBJECTS)
	$(CC) -o $@ $?

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $? 

test: $(PROG)
	@echo "$(shell read -p "Give a word: " word; ./$(PROG) $$word)"

clean:
	rm -f $(PROG) $(OBJECTS)
