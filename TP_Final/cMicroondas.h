#pragma once
#include "cArticulo.h"

using namespace std;

class cMicroondas: public cArticulo {
	public:
		cMicroondas(string Code_) : cArticulo(Code_) {  }
		cMicroondas(string Code_, string Nombre_, float Precio_, int Stock_, float H_, float W_, float D_) : cArticulo(Code_, Nombre_, Precio_, Stock_, H_, W_, D_) {  }
		~cMicroondas();
		cArticulo* get_Articulo() { return nullptr; }
		virtual ostream& output(ostream& out) const {
			cArticulo::output(out);
			return out << " - Microondas";
		}
		virtual istream& input(istream& in) {
			cArticulo::input(in);
			return in >> Probabilidades;
		}
		int get_Stock() { return Stock; }
		void set_Stock(int Stock_) { Stock = Stock_; }
		bool Probabilidad(int numero) {
			if (numero > 93) return true;
			else return false;
		}
	private:
		int Probabilidades;
};