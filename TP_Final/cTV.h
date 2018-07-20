#pragma once
#include "cArticulo.h"

using namespace std;

class cTV: public cArticulo {
	public:
		cTV(string Code_) : cArticulo(Code_) {  }
		cTV(string Code_, string Nombre_, float Precio_, int Stock_, float H_, float W_, float D_) : cArticulo(Code_, Nombre_, Precio_, Stock_, H_, W_, D_) {  }
		~cTV();
		cArticulo* get_Articulo() { return nullptr; }
		virtual ostream& output(ostream& out) const {
			cArticulo::output(out);
			return out << " - Televisor";
		}
		virtual istream& input(istream& in) {
			cArticulo::input(in);
			return in >> Probabilidades;
		}
		int get_Stock() { return Stock; }
		void set_Stock(int Stock_) { Stock = Stock_; }
		bool Probabilidad(int numero) { 
			if (numero > 90) return true;
			else return false;
		}
	private:
		int Probabilidades;
};