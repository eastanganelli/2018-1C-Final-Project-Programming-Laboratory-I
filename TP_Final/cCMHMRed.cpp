#include "cCMHMRed.h"

cCMHMRed::cCMHMRed() {
	StockMin = 5;
	Recaudacion = 0.0f;
}
cCMHMRed::~cCMHMRed() {  }
void cCMHMRed::CheckStock() {
	unsigned int i = 0;
	cArticulo* Aux_Stock = new cArticulo("StockMin", "StockMin", 0, 5, 0, 0, 0);
	while (i < ListaArticulos.size()) {
		cArticulo* Aux_Art = ListaArticulos[i];
		if (((Aux_Art->Stock) < (Aux_Stock->Stock))) {
			ListaItemsReponer.push_back(ListaArticulos[i]); 
		} i++;
	} delete Aux_Stock;
}