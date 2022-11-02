PRJ = $(shell basename $(CURDIR))

all: $(PRJ)

$(PRJ): *.c *.o
	-@make clean
	-@clear
	-@gcc -c ./modules/*.c 
	-@gcc $(code) *.o -Wall -std=c17 -o ./build/$(PRJ)
	

run:
	-@clear
	-@gcc -c modules/*.c 
	-@gcc $(code) *.o -Wall -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ)

testa:
	-@clear
	-@gcc -c modules/*.c 
	-@gcc $(code) *.o -Wall -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ) < ./test/$(f)

.PHONY: clean

clean:
	-@rm -f $(PRJ) *.o *~

