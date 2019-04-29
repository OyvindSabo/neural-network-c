CC=gcc

main: main.o dataUtils.o network.o networkUtils.o trainNetwork.o
	@${CC} -o main main.o dataUtils.o network.o networkUtils.o trainNetwork.o -lm
	@echo "Executing main\n"
	@./main

main.o: main.c
	@echo "\nCompiling main.c\n"
	@${CC} -c main.c

dataUtils.o: src/dataUtils.c
	@echo "\nCompiling dataUtils.c\n"
	@${CC} -c src/dataUtils.c

network.o: src/network.c
	@echo "\nCompiling network.c\n"
	@${CC} -c src/network.c

networkUtils.o: src/networkUtils.c
	@echo "\nCompiling networkUtils.c\n"
	@${CC} -c src/networkUtils.c

trainNetwork.o: src/trainNetwork.c
	@echo "\nCompiling trainNetwork.c\n"
	@${CC} -c src/trainNetwork.c