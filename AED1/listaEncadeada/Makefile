PRJ = $(shell basename $(CURDIR))

all: $(PRJ)

$(PRJ): *.c
	-@gcc $(file).c  -std=c17 -o ./build/$(PRJ)

run:
	-@gcc $(code)  -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ)

testa:
	-@gcc $(code)  -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ) < ./test/$(f)

.PHONY: clean

clean:
	echo "Limpando.."
	-@rm -f $(PRJ) *.o *~
