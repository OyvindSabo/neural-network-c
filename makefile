CC=gcc

main: main.o consoleUtils.o dataUtils.o network.o networkUtils.o trainNetwork.o
	@${CC} -o main main.o consoleUtils.o dataUtils.o network.o networkUtils.o trainNetwork.o -lm
	@echo "Executing main\n"
	@./main

demo: demo.o dataUtils.o network.o networkUtils.o runNetwork.o
	@${CC} -o demo demo.o dataUtils.o network.o networkUtils.o runNetwork.o -lm
	@echo "Executing demo\n"
	@./demo

test: test.o dataUtils.o network.o networkUtils.o trainNetwork.o
	@${CC} -o test test.o dataUtils.o network.o networkUtils.o trainNetwork.o runNetwork.o -lm
	@echo "Executing test\n"
	@./test

main.o: main.c
	@echo "\nCompiling main.c\n"
	@${CC} -c main.c

consoleUtils.o: src/consoleUtils.c
	@echo "\nCompiling consoleUtils.c\n"
	@${CC} -c src/consoleUtils.c

dataUtils.o: src/dataUtils.c
	@echo "\nCompiling dataUtils.c\n"
	@${CC} -c src/dataUtils.c

network.o: src/network.c
	@echo "\nCompiling network.c\n"
	@${CC} -c src/network.c

networkUtils.o: src/networkUtils.c
	@echo "\nCompiling networkUtils.c\n"
	@${CC} -c src/networkUtils.c

runNetwork.o: src/runNetwork.c
	@echo "\nCompiling runNetwork.c\n"
	@${CC} -c src/runNetwork.c

trainNetwork.o: src/trainNetwork.c
	@echo "\nCompiling trainNetwork.c\n"
	@${CC} -c src/trainNetwork.c