#include <iostream>
#include <string>
using namespace std;

struct INFORMACION{
	string nombre;
	string descripcion;
	float precio;
	int cantidad;
};

INFORMACION producto[100];
int Indice = 0;

void ordenacion();
void agregarProducto(INFORMACION producto[], int &Indice);
void mostrarProducto (INFORMACION producto[], int Indice);
void buscarProducto (INFORMACION producto[], int m);
void eliminarProducto (INFORMACION producto[], int &m);

void agregarProducto(INFORMACION producto[], int &Indice)
{
	int cant;
	system("cls");
	cout << "        AGREGAR PRODUCTO\n";
	cout << "Cuantos productos (diferentes) desea agregar: ";
	cin >> cant;
	
	for (int i=0; i<cant; i++){
		string nombreTemp;
		system("cls");
		cout << "        AGREGAR PRODUCTO\n";
		cout<<"Ingrese nombre del producto "<< i+1 <<": ";
		cin.ignore();
		getline(cin, nombreTemp);  //AGREGA getline PARA OVBIAR ESPACIADO !!!!!!!!!!!!
		
		bool encontrado = false;
		int cantidadTemp;
		
		//Funcion para verificar si se REPITE el NOMBRE del producto
		for (int j=0; j<Indice; j++){
			if (nombreTemp == producto[j].nombre){
				encontrado = true;
				cout<<"Ingrese cantidad: ";  //Si se repite, solo ingresa cantidad.
				cin>> cantidadTemp;
				producto[i].cantidad = producto[i].cantidad + cantidadTemp;
			}
		}
		
		if (!encontrado){
			Indice = Indice + 1;
			cout<<"Ingrese una descripcion: ";
			cin.ignore();
			getline(cin, producto[i].descripcion);
			
			cout<<"Ingrese un precio: ";
			cin>>producto[i].precio;
			
			cout<<"Ingrese cantidad: ";
			cin>> cantidadTemp;
			producto[i].cantidad = producto[i].cantidad + cantidadTemp;
		}
		
		
		
	}
	
	
	
	ordenacion();
}

void mostrarProducto (INFORMACION producto[], int Indice)
{
	system("cls");
	cout<<"         MOSTRAR PRODUCTO\n";
	if (Indice == 0){
		cout<<"\nAun no se registraron productos.\n";
		system("pause");
		return;
	}
	
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
		cout << " 1. Agregar producto" << endl;
		cout << " 2. Mostrar productos" << endl;
		cout << " 3. Buscar usuario" << endl;
		cout << " 4. Eliminar usuario" << endl;
		cout << " 0. Salir" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion){
			case 1:
				agregarProducto(producto, Indice);
			break;
			case 2:
				mostrarProducto (producto, Indice);

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