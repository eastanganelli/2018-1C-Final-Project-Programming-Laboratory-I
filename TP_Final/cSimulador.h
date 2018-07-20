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
		cSimulador() {
			CompuMundoServer = new cCMHMRed();
			load_File();
			{
				vector<cArticulo*> AuxArticulos = CompuMundoServer->get_ListaArt();
				cout << "Marca\tPrecio\tTamanio [HxWxD]\tTipo" << endl;
				for (int i = 0; i < CompuMundoServer->get_ListaArt_Tam(); i++) {
					cout << AuxArticulos[i] << endl;
				}
			}
			while (!(Clientes_ < 0) || (Clientes_ != 0)) {
				cout << endl << endl << "Loading: ";
				while (Clientes_ > 0) {
					cout << ". ";
					int pos = get_Cliente();
					string NombreAux = Clientes_[pos];
					if (CompraOMira() == true) {
						cComprador* AuxCliente = new cComprador(NombreAux);
						cEmpleado* AuxVendedor = get_Empleado();
						cArticulo* AuxArticulo = get_Articulo();
						bool AuxBool = ((cVendedor*)AuxVendedor)->RealizarCompra(CompuMundoServer, AuxCliente, AuxArticulo, ListaEmpleados);
						if (AuxBool == true) {
							ListaCompradores.push_back(AuxCliente);
						}
						else { ListaNoClient.push_back(Clientes_[pos]); }
					}
					else { ListaNoClient.push_back(NombreAux); }
					Clientes_ - NombreAux;
					Sleep(500);
				}
			} cout << "!" << endl << endl;
			{
				cout << "Cantidad Vendido: " << cCMHMRed::CantVendido << " - Recaudacion: $ " << cCMHMRed::Recaudacion << endl << endl;
				vector<cArticulo*> ListaItemComprar = CompuMundoServer->get_ListaComprar();
				CompuMundoServer->CheckStock();
				if (calculate_minStock(ListaItemComprar) == true) {
					for (int i = 0; i < (int)ListaItemComprar.size(); i++) { cout << "Codigo: " << ListaItemComprar[i]->get_Code() << " - Marca: " << ListaItemComprar[i]->get_Nombre() << " - Stock: " << ListaItemComprar[i]->Stock << " - Precio: " << ListaItemComprar[i]->Precio << endl; }
				} ListaItemComprar.clear();
			}
			{
				int Aux_ = 0;
				cout << endl << "Señeccionar tipo de producto:\n1-> TV\n2-> Heladera\n3-> Microondas" << endl; cin >> Aux_;
				vector<cArticulo*> ListaArt = CompuMundoServer->get_ListaArt();
				cout << "Agregar un producto:\nCodigo: ";
				switch (Aux_) {
				case 1: {
					string Code_;
					cin >> Code_;
					cout << "Marca\tPrecio\tStock\tTamanio [WxHxD]\tProbabilidad De Falla" << endl;
					cTV *AuxH_ = new cTV(Code_);
					cin >> AuxH_;
					ListaArt.push_back(AuxH_);
					break;
				}
				case 2: {
					string Code_;
					cin >> Code_;
					cout << "Marca\tPrecio\tStock\tTamanio [WxHxD]\tProbabilidad De Falla" << endl;
					cHeladera *AuxH_ = new cHeladera(Code_);
					cin >> AuxH_;
					ListaArt.push_back(AuxH_);
					break;
				}
				case 3: {
					string Code_;
					cin >> Code_;
					cout << "Marca\tPrecio\tStock\tTamanio [WxHxD]\tProbabilidad De Falla" << endl;
					cMicroondas *AuxH_ = new cMicroondas(Code_);
					cin >> AuxH_;
					ListaArt.push_back(AuxH_);
					break;
				}
				} CompuMundoServer->set_Lista(ListaArt);
				ListaArt.clear();
				{
					vector<cArticulo*> AuxArticulos = CompuMundoServer->get_ListaArt();
					cout << endl << "Marca\tPrecio\tTamanio [HxWxD]\tTipo" << endl;
					for (int i = 0; i < CompuMundoServer->get_ListaArt_Tam(); i++) {
						cout << AuxArticulos[i] << endl;
					}
				}
			}
		}
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