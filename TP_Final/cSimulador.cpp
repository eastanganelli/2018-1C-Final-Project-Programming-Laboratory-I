#include "cSimulador.h"

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