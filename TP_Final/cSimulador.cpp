#include "cSimulador.h"

cSimulador::cSimulador() {
	CompuMundoServer = new cCMHMRed();
	load_File();
	{
		vector<cArticulo*> AuxArticulos = CompuMundoServer->get_ListaArt();
		cout << "Marca\tPrecio\tTamanio [HxWxD]\tTipo" << endl;
		for (int i = 0; i < CompuMundoServer->get_ListaArt_Tam(); i++) {
			cout << AuxArticulos[i] << endl;
		}
	}
	while(!(Clientes_ < 0) || (Clientes_ != 0)) {
		cout << endl << endl << "Loading: ";
		while(Clientes_ > 0) {
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
					//AuxCliente->Print_ListaArt();
				} else { ListaNoClient.push_back(Clientes_[pos]); }
			} else {  ListaNoClient.push_back(NombreAux); }
			Clientes_ - NombreAux;

			Sleep(500);
		}
	} cout << "!" << endl << endl;
	{
		cout << "Cantidad Vendido: " << cCMHMRed::CantVendido << " - Recaudacion: $ " << cCMHMRed::Recaudacion << endl << endl;
		vector<cArticulo*> ListaItemComprar = CompuMundoServer->get_ListaComprar();
		CompuMundoServer->CheckStock();
		if(calculate_minStock(ListaItemComprar) == true) {
			for (int i = 0; i < (int)ListaItemComprar.size(); i++) { cout << "Codigo: " << ListaItemComprar[i]->get_Code() << " - Marca: " << ListaItemComprar[i]->get_Nombre() << " - Stock: " << ListaItemComprar[i]->Stock << " - Precio: " << ListaItemComprar[i]->Precio << endl; }
		} ListaItemComprar.clear();
	}
	{
		int Aux_ = 0;
		cout << endl << "Señeccionar tipo de producto:\n1-> TV\n2-> Heladera\n3-> Microondas" << endl; cin >> Aux_;
		vector<cArticulo*> ListaArt = CompuMundoServer->get_ListaArt();
		cout << "Agregar un producto:\nCodigo" << endl;
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
cSimulador::~cSimulador() {
	ListaCompradores.clear();
	ListaEmpleados.clear();
	ListaMaybeClient.clear();
	ListaNoClient.clear();
}
bool cSimulador::CompraOMira() {
	int compra = rand() % 2;
	if (compra == 1) { return true; }
	return false;
}
int cSimulador::get_Cliente() { return rand() % Clientes_.get_CantClientes(); }
cEmpleado* cSimulador::get_Empleado() {
	int pos = 0;
	do {
		pos = rand() % ListaEmpleados.size();
		if ((dynamic_cast<cVendedor*>(ListaEmpleados[pos])) != NULL) { return (ListaEmpleados[pos]); }
	} while ((dynamic_cast<cVendedor*>(ListaEmpleados[pos])) == NULL);
	return nullptr;
}
cArticulo* cSimulador::get_Articulo() { 
	int pos = rand() % ((unsigned int)(CompuMundoServer->get_ListaArt().size()));
	vector<cArticulo*> AuxLista = CompuMundoServer->get_ListaArt();
	return (AuxLista[pos]);
}
void cSimulador::load_File() {
	try {
		FILE*Clientes = fopen("Lista_Nombres_Compradores.txt", "r");
		{
			if (Clientes != NULL) {
				while (!feof(Clientes)) {
					char aux1[30] = {'\0'}, aux2[30] = {'\0'};
					fscanf(Clientes, "%s %s", &aux1, &aux2);
					string Aux_ = (string(aux1) + " " + string(aux2));
					if ((Clientes_ == Aux_) != true) {
						Clientes_++;
						Clientes_ + Aux_;
					}
				}
			} else throw true;
		} fclose(Clientes);
	} catch (bool) { printf("\nFILE ERROR"); system("pause");  exit(0); }
	try {
		FILE*Personal = fopen("Lista_Nombres_Personal.txt", "r");
		{
			if (Personal != NULL) {
				while (!feof(Personal)) {
					char aux1[99] = {'\0'}, aux2[99] = {'\0'}, auxTipo[50] = {'\0'}; int edad = 0;
					fscanf(Personal, "%s %s %d %s", &aux1, &aux2, &edad, &auxTipo);
					if (string(auxTipo) == "Vendedor") { ListaEmpleados.push_back((new cVendedor((string(aux1) + " " + string(aux2)), edad, string(auxTipo)))); }
					else if (string(auxTipo) == "Despachador") { ListaEmpleados.push_back((new cDespachante((string(aux1) + " " + string(aux2)), edad, string(auxTipo)))); }
				}
			} else throw true;
		} fclose(Personal);
	} catch (bool) { printf("\nFILE ERROR"); system("pause");  exit(0); }
	try {
		vector<cArticulo*> listaArt;
		FILE*Productos = fopen("Lista_Nombres_Productos.txt", "r");
		{
			if (Productos != NULL) {
				while (!feof(Productos)) {
					char auxCode[30] = { '\0' }, auxNombre[30] = { '\0' }, auxTipo[20] = {'\0'};
					float precio = 0, sH = 0, sW = 0, sD = 0; int stock = 0;
					fscanf(Productos, "%s %s %s %f %d %f %f %f", &auxCode, &auxNombre, &auxTipo, &precio, &stock, &sH, &sW, &sD);
					if (string(auxTipo) == "Heladera") {
						listaArt.push_back(new cHeladera(string(auxCode), string(auxNombre), precio, stock, sH, sW, sD));
					}
					else if (string(auxTipo) == "Televisor") {
						listaArt.push_back(new cTV(string(auxCode), string(auxNombre), precio, stock, sH, sW, sD));
					}
					else if (string(auxTipo) == "Microondas") {
						listaArt.push_back(new cMicroondas(string(auxCode), string(auxNombre), precio, stock, sH, sW, sD));
					}
				} CompuMundoServer->set_Lista(listaArt);
				listaArt.clear();
			} else throw true;
		} fclose(Productos);
	} catch (bool) { printf("\nFILE ERROR"); system("pause");  exit(0); }
}
bool cSimulador::calculate_minStock(vector<cArticulo*> Lista) {
	int val = 0;
	for (int i = 0; i < (int)Lista.size(); i++) { val = val + Lista[i]->Stock; }
	if (val > 20) return true;
	return false;
}