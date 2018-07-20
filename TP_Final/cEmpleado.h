#pragma once
#include <string>

using namespace std;

class cEmpleado {
	public:
		cEmpleado(string nombreyApe, int _edad, string Tipo_) {
			Edad = _edad;
			Nombre = nombreyApe;
			Tipo = Tipo_;
		}
		~cEmpleado();
		virtual string get_Tipo(void) { return NULL;  }
	protected:
		int Edad;
		string Nombre;
		string Tipo;
};