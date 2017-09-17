#include <iostream>
#include "Bank.h"
int main(int argc, char **argv)
{

    int cashiersNbr = 5;
    double arriveTime = 10;
    double simulationTime = 1000;

	Bank bank(arriveTime, simulationTime, cashiersNbr);

    bank.addCashier(40);
    bank.addCashier(40);
    bank.addCashier(40);
    bank.addCashier(40);
    bank.addCashier(40);

	bank.execute();

	cout << endl << "########################################################################" << endl;
	cout << "Temps réel d'éxécution : " << bank.realTime() << endl;

	cout << "Longueur maximum de la queue : " << bank.waitingQueue().maxLength() << endl;
	cout << "Longueur moyenne de la queue : " << bank.waitingQueue().averageLength()/bank.time() << endl;
	cout << "Temps moyen d'attente : " << bank.waitingQueue().averageWaitingTime()/bank.customersNbr() << endl << endl;

	cout << "Nombre de clients servis : " << bank.customersNbr() << endl << endl;
	for(int i = 0; i < 5; i++)
	{
        cout << "Le caissier " << i+1 << " a servi " << bank.iemeCashier(i).customersNbr()
        << " clients pour un taux d'occupation de " << bank.iemeCashier(i).occupationRate()*100<< "%" << endl;
	}
	cout << "########################################################################" << endl;
}
