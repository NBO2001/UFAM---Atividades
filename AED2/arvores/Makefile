PRJ = $(shell basename $(CURDIR))

all: $(PRJ)

$(PRJ): *.cpp
	-@g++ $(file).cpp -o ./build/$(PRJ) -Wall -static -O2 -std=c++17

run:
	-@./build/$(PRJ)


testa:
	-@clear
	-@./build/$(PRJ) < ./test/$(f)

.PHONY: clean

jud:
	-@clear
	-@python3 ./judge/judge.py ./test/$(f) $(code) $(f)
	-@rm -f judge_tem*

clean:
	echo "Limpando.."
	-@rm -f $(PRJ) *.o *~

