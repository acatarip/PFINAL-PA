#include <iostream>
#include <string>
using namespace std;

struct INFORMACION{
	string nombre;
	string descripcion;
	float precio;
	int cantidad;
};

INFORMACION producto[100];  //arreglo de datos principal
int m = 0;  //contador de pacientes totales registrados

void agregarProducto(INFORMACION producto[], int &m, int b);
void mostrarProducto (INFORMACION producto[], int m);
void buscarProducto (INFORMACION producto[], int m);
void eliminarProducto (INFORMACION producto[], int &m);


void agregarProducto(INFORMACION producto[], int &m, int b)
{

}

void mostrarProducto (INFORMACION producto[], int m)
{

}

void buscarProducto (INFORMACION producto[], int m)
{

}


void buscarProducto (INFORMACION producto[], int m){
	system("cls");
	int buscar;
	cout<<"        BUSCAR USUARIO\n";
	cout<<"1. Buscar por nombre\n";
	cout<<"2. Buscar por edad\n";
	cout<<"0. Salir\n\n";
	cout<<"Ingrese su opcion: ";
	cin>>buscar;
	
}

void eliminarProducto (INFORMACION producto[], int &m){
	
}

int main(){
	int opcion;
	do {
		system("cls");
		cout << "=====================================================" << endl;
		cout << "                        MENU" << endl;
		cout << "=====================================================" << endl;
		cout << " 1. Agregar usuario" << endl;
		cout << " 2. Usuarios registrados" << endl;
		cout << " 3. Buscar usuario" << endl;
		cout << " 4. Eliminar usuario" << endl;
		cout << " 0. Salir" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion){
			case 1:
				
			break;
			case 2:

			break;
			case 3:

			case 4:

			break;
			case 0:
				cout << "Saliendo . . ." << endl;
			break;
			default:
				cout << "Opcion no valida. Intentelo de nuevo." << endl;
				system("pause");
			break;
		}
	} while(opcion != 0);
	return 0;
}
