#include "cDespachante.h"

cDespachante::~cDespachante() {  }
bool cDespachante::TestItem(cArticulo* Item) {
	if (Item->Probabilidad(Probabilidad()) == false) { return true; }
	return false;
}
#pragma region Probailidades
int Probabilidad() { return (rand() % 101); }
#pragma endregion