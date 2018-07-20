#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class cArticulo {
	public:
		cArticulo(string Code_): Codigo(Code_) {  }
		cArticulo(string Code_, string Nombre_, float Precio_, int Stock_, float H_, float W_, float D_) : Codigo(Code_) { 
			Marca = Nombre_;
			Tamanio[0] = H_;
			Tamanio[1] = W_;
			Tamanio[2] = D_;
			Precio = Precio_;
			Stock = Stock_;
		}
		~cArticulo();
		virtual bool Probabilidad(int) { return false; }
		virtual ostream& output(ostream& out) const {
			return out << Marca << " " << Precio << " " << Tamanio[0] << "x" << Tamanio[1] << "x" << Tamanio[2];
		}
		virtual istream& input(istream& in) {
			return in >> Marca >> Precio >> Stock >> Tamanio[0] >> Tamanio[1] >> Tamanio[2];
		}
		string get_Code() { return Codigo; }
		string get_Nombre() { return Marca; }
		void set_Nombre(string Nom_) { Marca = Nom_; }
		float Precio;
		int Stock;
		float Tamanio[3];
	protected:
		const string Codigo;
		string Marca;
};
inline ostream& operator<< (ostream& out, const cArticulo* b) {
	return b->output(out);
}
inline istream& operator>> (istream& in, cArticulo* b) {
	return b->input(in);
}