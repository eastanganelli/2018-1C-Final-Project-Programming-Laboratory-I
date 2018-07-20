#pragma once
#include "string"
#pragma region My_Classes
#include "cEmpleado.h"
#include "cComprador.h"
#include "cArticulo.h"
#include "cDespachante.h"
#include "cCMHMRed.h"
#pragma endregion

using namespace std;

class cVendedor: public cEmpleado {
	public:
		cVendedor(string nombreyApe, int _edad, string Tipo_) : cEmpleado(nombreyApe, _edad, Tipo_) {  }
		~cVendedor();
		bool RealizarCompra(cCMHMRed* Servidor, cComprador* Comprador, cArticulo* SellArticulo, vector<cEmpleado*> lista);
		string get_Tipo(void) { return Tipo; }
};