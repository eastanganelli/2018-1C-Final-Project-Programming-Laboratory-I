#include "cVendedor.h"

cVendedor::~cVendedor() {  }
bool cVendedor::RealizarCompra(cCMHMRed* Servidor , cComprador* Comprador, cArticulo* SellArticulo, vector<cEmpleado*> lista) {
	cDespachante* Despachador = nullptr;
	if (SellArticulo->Stock >= 5) {
		for (int i = 0; i < (int)lista.size(); i++) {
			if ((dynamic_cast<cDespachante*>(lista[i])) != NULL) {
				Despachador = (cDespachante*)lista[i];
				bool AuxTest = Despachador->TestItem(SellArticulo);
				//cout << "Prueba Item: " << AuxTest << endl;
				if (AuxTest == true) {
					cCMHMRed::CantVendido++;
					cCMHMRed::Recaudacion = cCMHMRed::Recaudacion + SellArticulo->Precio;
					SellArticulo->Stock--;
					*Servidor = SellArticulo;
					Despachador->EntregaItem(SellArticulo, Comprador);
					Comprador->Pago = true;
					Comprador->ComprasFinalizadas = true;
					return true;
				}
			} else  break;
		}
	} return false;
}