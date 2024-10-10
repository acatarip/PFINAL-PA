#include <iostream>
using namespace std;

struct DATOS{
	int edad;
	string nombre;
};

void agregar(DATOS A[], int &m, int b);
void mostrarPorEdades (DATOS A[], int m);
void mostrarUsuarios (DATOS A[], int m);
void buscarUsuario (DATOS A[], int m);
void eliminarUsuarios (DATOS A[], int &m);

DATOS DEPO[100];  //arreglo de datos principal
int m = 0;  //contador de pacientes totales registrados

int main(){
	int n;
	do{
		system("cls");
		cout<<"        MENU\n";
		cout<<"1. Agregar usuario\n";
		cout<<"2. Usuarios registrados\n";
		cout<<"3. Buscar usuario\n";
		cout<<"4. Eliminar usuario\n";
		cout<<"0. Salir\n\n";
		cout<<"Ingrese su opcion: ";
		cin>>n;
		
		switch (n){
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
	} while(n!=0);
	
	
	
	return 0;
}


void agregar(DATOS A[], int &m, int b){
	for (int i=m; i<(b+m); i++){  //desde m hasta b+m para que no se sobrescriban los datos
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
