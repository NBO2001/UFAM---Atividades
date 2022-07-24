PRJ = $(shell basename $(CURDIR))

all: $(PRJ)

$(PRJ): *.c
	-@gcc $(file).c  -std=c17 -o ./build/$(PRJ)

run:
	-@clear
	-@gcc $(code)  -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ)

testa:
	-@clear
	-@gcc $(code)  -std=c17 -o ./build/$(PRJ)
	-@./build/$(PRJ) < ./test/$(f)

.PHONY: clean

clean:
	echo "Limpando.."
	-@rm -f $(PRJ) *.o *~
