#Makefile

OBJ = Customer.o Cashier.o WaitingQueue.o Bank.o Simulaion.o

poste: $(OBJ)
	c++ -o poste $(OBJ)

depend:
	sed '/#DEP/q' Makefile > mk.tmp
	c++ -M *.C >> mk.tmp
	mv mk.tmp Makefile

#DEPENDENCIES : don't remove that line
