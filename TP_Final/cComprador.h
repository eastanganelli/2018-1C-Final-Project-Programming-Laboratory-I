#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "cArticulo.h"

using namespace std;

class cComprador {
	public:
		cComprador(string Nombre_) {
			ListArticulos = (cArticulo**)malloc(1 * sizeof(cArticulo*));
			Nombre = Nombre_;
			Edad = ((rand() % 100) + 18);
			ItemCant = 0;
		}
		~cComprador();
		//vector<cArticulo*> get_ListaArticulos(void) { return (ListaArticulos); }
		//void set_ListaArticuos(vector<cArticulo*> Lista_) { ListaArticulos = Lista_; }
		int get_Cant() { return ItemCant; }
		void set_Cant(int Cant_) { ItemCant = Cant_;  }
		void operator+(cArticulo* Articulo) { 
			/* ListArticulos.push_back(Articulo); */ 
			ListArticulos = (cArticulo**)realloc(ListArticulos, (ItemCant) * sizeof(cArticulo*));
			ListArticulos[ItemCant - 1] = Articulo;
		}
		void push__back(cArticulo* Articulo) { 
			ListArticulos = (cArticulo**)realloc(ListArticulos, (ItemCant)*sizeof(cArticulo*));
			ListArticulos[ItemCant] = Articulo;
		}
		void Print_ListaArt() {
			cout << "Codigo\t\tMarca\t\tPrecio\t\tTamanio[HxWxD]" << endl;
			for (int i = 0; i < ItemCant; i++) {
				cArticulo* Aux_ = ListArticulos[i];
				cout << Aux_->get_Code() << "\t\t" << Aux_->get_Nombre() << "\t\t" << Aux_->Precio << "\t\t" << Aux_->Tamanio[0] << "x" << Aux_->Tamanio[1] << "x" << Aux_->Tamanio[2] << endl;
			}
		}
		friend class cVendedor;
	private:
		vector<cArticulo*> _ListaArticulos;
		cArticulo** ListArticulos;
		int Edad;
		int ItemCant;
		string Nombre;
		bool Pago;
		bool ComprasFinalizadas;
};