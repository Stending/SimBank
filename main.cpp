#include <iostream>
#include "Bank.h"
int main(int argc, char **argv)
{
    int cashiersNbr = 5;

	Bank bank(10, 1000, 5);
	bank.execute();

	cout << endl << "########################################################################" << endl;
	cout << "Temps réel d'éxécution : " << bank.realTime() << endl;
	cout << "Nombre de clients servis : " << bank.customersNbr() << endl << endl;
	for(int i = 0; i < 5; i++)
	{
        cout << "Le caissier " << i+1 << " a servi " << bank.iemeCashier(i).customersNbr()
        << " clients pour un taux d'occupation de " << bank.iemeCashier(i).occupationRate()<< "%" << endl;
	}
	cout << "########################################################################" << endl;
}
