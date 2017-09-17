#Makefile

OBJ = Customer.o Bank.o WaitingQueue.o Cashier.o Event.o SortedEventQueue.o Simulation.o Arrive.o Release.o main.o

simulation: $(OBJ)
	c++ -o simulation $(OBJ)

depend:
	sed '/#DEP/q' Makefile > mk.tmp
