#pragma once
#include <string>
#include <vector>
#pragma region My_Class
#include "cArticulo.h"
#include "cHeladera.h"
#include "cTV.h"
#include "cMicroondas.h"
#pragma endregion

using namespace std;

class cCMHMRed {
	public:
		static int CantVendido;
		static float Recaudacion;
		cCMHMRed();
		cCMHMRed(int i, vector<cArticulo*> ListaArt, vector<cArticulo*> ) { CantVendido += i; }
		~cCMHMRed();
		void CheckStock();
		void set_Lista(vector<cArticulo*> ListArt) { ListaArticulos = ListArt; }
		vector<cArticulo*> get_ListaArt(void) { return ListaArticulos; }
		vector<cArticulo*> get_ListaComprar(void) { return ListaItemsReponer; }
		void operator= (cArticulo* Art) {
			for (int i = 0; i < (int)ListaArticulos.size(); i++) {
				if (ListaArticulos[i] == Art) { ListaArticulos[i] = Art;  break; }
			}
		}
		int get_ListaArt_Tam(void) { return ListaArticulos.size(); }
		int get_ListaRep_Tam(void) { return ListaItemsReponer.size(); }
		friend class cVendedor;
	private:
		int StockMin;
		vector<cArticulo*> ListaArticulos;
		vector<cArticulo*> ListaItemsReponer;
};

