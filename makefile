CC=gcc

main: main.o dataUtils.o network.o trainNetwork.o
	@${CC} -o main main.o dataUtils.o network.o trainNetwork.o
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

trainNetwork.o: src/trainNetwork.c
	@echo "\nCompiling trainNetwork.c\n"
	@${CC} -c src/trainNetwork.c