#include <iostream>
#include <string>
using namespace std;

struct DATOS{
	int edad;
	string nombre;
};

DATOS DEPO[100];  //arreglo de datos principal
int m = 0;  //contador de pacientes totales registrados

void agregar(DATOS A[], int &m, int b);
void mostrarPorEdades (DATOS A[], int m);
void mostrarUsuarios (DATOS A[], int m);
void buscarUsuario (DATOS A[], int m);
void eliminarUsuarios (DATOS A[], int &m);


void agregar(DATOS A[], int &m, int b){
	for (int i = m; i < (b + m); i++){  //desde m hasta b+m para que no se sobrescriban los datos
		cout<<"\nIngrese nombre del usuario "<<i+1<<": ";
		cin>>A[i].nombre;
		cout<<"Ingrese edad del usuario "<<i+1<<": ";
		cin>>A[i].edad;
	}
	m = m + b;
}

void mostrarPorEdades (DATOS A[], int m){
	
}

void mostrarUsuarios (DATOS A[], int m){
	cout<<"Lista de usuarios registrados:\n";
	for (int i=0; i<m; i++){
		cout<<i+1<<". Nombre: "<<DEPO[i].nombre;
		cout<<"\n   Edad: "<<DEPO[i].edad<<" anios\n\n";
	}
	system("pause");
}

void buscarUsuario (DATOS A[], int m){
	system("cls");
	int buscar;
	cout<<"        BUSCAR USUARIO\n";
	cout<<"1. Buscar por nombre\n";
	cout<<"2. Buscar por edad\n";
	cout<<"0. Salir\n\n";
	cout<<"Ingrese su opcion: ";
	cin>>buscar;
	
}

void eliminarUsuarios (DATOS A[], int &m){
	system("cls");
	cout<<"        ELIMINAR USUARIO\n";
	
}

int main(){
	int opcion;
	do{
		system("cls");
		cout << "=====================================================" << endl;
		cout <<"                         MENU" << endl;
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
				int cant;
				system("cls");
				cout<<"        AGREGAR USUARIO\n";
				cout<<"Ingrese cantidad de usuarios: "; 
				cin>>cant;
				agregar(DEPO, m, cant);
			break;
			case 2:
				int op;
				system("cls");
				cout<<"        USUARIOS REGISTRADOS\n";
				cout<<"1. Grupos por edades\n";
				cout<<"2. Todos los usuarios\n";
				cout<<"0. Regresar al menu\n\n";
				cout<<"Ingrese opcion: ";
				cin>>op;
				switch (op){
					case 1:
						mostrarPorEdades (DEPO, m);
					break;
					case 2:
						mostrarUsuarios (DEPO, m);
					break;
					case 0:
						cout<<"Regresando al menu...";
					break;
				}
			break;
			case 3:
				buscarUsuario (DEPO, m);
			case 4:
				eliminarUsuarios (DEPO, m);
			break;
			case 0:
				cout<<"\nSaliendo . . .\n";
			break;
			default:
				cout<<"\nOpcion no valida. Intentelo de nuevo.\n";
				system("pause");
			break;
		}
	} while(opcion!=0);
	
	
	
	return 0;
}