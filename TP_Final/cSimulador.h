#pragma once
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#pragma region Myclasses
#include "cArticulo.h"
#include "cComprador.h"
#include "cCMHMRed.h"
#include "cEmpleado.h"
#include "cVendedor.h"
#include "cDespachante.h"
#include "cClientes.h"
#pragma endregion

using namespace std;

class cSimulador {
	public:
		cSimulador();
		~cSimulador();
		bool CompraOMira();
		int get_Cliente();
		cEmpleado* get_Empleado();
		cArticulo* get_Articulo();
		void load_File();
		bool calculate_minStock(vector<cArticulo*> Lista);
	private:
		cClientes Clientes_;
		vector<string> ListaNoClient;
		vector<string> ListaMaybeClient;
		vector<cEmpleado*> ListaEmpleados;
		vector<cComprador*> ListaCompradores;
		cCMHMRed* CompuMundoServer;
};