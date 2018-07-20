#pragma once
#include <time.h>
#include <string>
#pragma region My_Classes
#include "cEmpleado.h"
#include "cVendedor.h"
#include "cArticulo.h"
#include "cHeladera.h"
#include "cTV.h"
#include "cMicroondas.h"
#pragma endregion

using namespace std;

class cDespachante: public cEmpleado {
	public:
		cDespachante(string _nombre, int _edad, string Tipo_) : cEmpleado(_nombre, _edad, Tipo_) {  }
		~cDespachante();
		void EntregaItem(cArticulo* Item, cComprador* Cliente) {
			Cliente->set_Cant(Cliente->get_Cant() + 1);
			cArticulo* Aux_ = new cArticulo(Item->get_Code(), Item->get_Nombre(), Item->Precio, 1, Item->Tamanio[0], Item->Tamanio[1], Item->Tamanio[3]);
			for (int i = 0; i < 3; i++) { Aux_->Tamanio[i] = Item->Tamanio[i]; }
			*Cliente + Aux_;
		}
		bool TestItem(cArticulo* Item);
		string get_Tipo(void) { return Tipo; }
};
int Probabilidad();