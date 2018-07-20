#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define  N 1

using namespace std;

class cClientes {
	public:
		cClientes() { CantClientes = 0; }
		~cClientes();
		cClientes(int Cant, vector<string> Nombres) {
			_Nombre = Nombres;
			CantClientes = Cant + CantClientes;
		}
		string operator[] (int i) {
			string Aux_;
			if(i < CantClientes) {
				Aux_ = _Nombre[i];
				return Aux_;
			} cout << "Out of range";
			return Aux_;
		}
		void operator+ (string Nombre_) {
			_Nombre.push_back(Nombre_);
			//CantClientes++;
		}
		void operator- (string Nombre_) {
			for (int i = 0; i < CantClientes; i++) {
				if (_Nombre[i] == Nombre_) {
					string Aux_ = _Nombre[i];
					_Nombre.erase(_Nombre.begin() + i);
					CantClientes--;
				}
			}
		}
		bool operator< (int i) {
			if (CantClientes <= i) { return true; }
			return false;
		}
		bool operator> (int i) {
			if (CantClientes > i) { return true; }
			return false;
		}
		bool operator!= (int i) {
			if (CantClientes != i) { return true; }
			return false;
		}
		bool operator== (string Nombre_In) {
			for (int i = 0; i < CantClientes; i++) {
				if (_Nombre[i] == Nombre_In) { return true; }
			} return false;
		}
		cClientes operator++ (int) {
			CantClientes++;
			cClientes T(CantClientes, _Nombre);
			return T;
		}
		int get_CantClientes(void) { return CantClientes; }
	private:
		int CantClientes;
		vector<string> _Nombre;
};