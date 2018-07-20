#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

#include "cSimulador.h"

using namespace std;

float cCMHMRed::Recaudacion = 0;
int cCMHMRed::CantVendido = 0;

int main() {
	/* TP FINAL */
	//Constanza Vazquez 
	//Ezequiel Stanganelli

	srand((unsigned)time(NULL));
	cSimulador* My_simulator = new cSimulador();
	system("pause");
	My_simulator->~cSimulador();
	return 0;
}