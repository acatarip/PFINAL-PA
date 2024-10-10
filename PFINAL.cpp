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

<<<<<<< HEAD
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
=======
void Ordenacion();
void agregarProducto(INFORMACION producto[], int &m, int b);
void mostrarProducto (INFORMACION producto[], int m);
int buscarProducto (INFORMACION producto[], int &Indice);
void eliminarProducto (INFORMACION producto[], int &Indice);

void agregarProducto(INFORMACION producto[], int &m, int b)
{
	
>>>>>>> dd8cf6c9ac46099991ec7f7e9c115ba6b0f8a149
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

int BusquedaBinaria(INFORMACION producto[], string nom, int bajo, int alto)
{
	bool encontrado = false;
	int medio;
	while (bajo <= alto && !encontrado)
	{
		medio = (bajo + alto) / 2;
		if (producto[medio].nombre == nom)
		{
			encontrado = true;
		}
		else if (producto[medio].nombre > nom)
		{
			alto = medio - 1;
		}
		else
		{
			bajo = medio + 1;
		}
	}
	if (encontrado)
	return medio;
	else 
	return -1;
}

int buscarProducto (INFORMACION producto[], int &Indice)
{
	int opcion;
	do 
	{
		system("cls");
		cout << "================= BUSCAR PRODUCTO ===================" << endl;
		cout << " 1. Buscar por nombre " << endl;
		cout << " 2. Buscar por ID " << endl;
		cout << " 0. Salir " << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion)
		{
			case 1:
				string nom;
				cout << "================= BUSCAR POR NOMBRE ===================" << endl;
				cout << " Ingrese el nombre del producto: ";
				cin >> nom;
				cout << "-----------------------------------------------------" << endl;
				int indice = BusquedaBinaria(producto, nom, 0, Indice);
				if (indice != -1)
				{
					cout << "Producto encontrado." << endl;
					cout << "Nombre: " << producto[indice].nombre << endl;
					cout << "Descripcion: " << producto[indice].descripcion << endl;
					cout << "Precio: " << producto[indice].precio << endl;
					cout << "Cantidad: " << producto[indice].cantidad << endl;
				}
				else
				{
					cout << "Producto no encontrado." << endl;
				}
				
			break;
			case 2:

			break;
			case 0:
				cout << "Saliendo . . ." << endl;
			break;
			default:
				cout << "Opcion no valida. Intentelo de nuevo." << endl;
				system("pause");
			break;
		}
	} while (opcion != 0);
}

void eliminarProducto (INFORMACION producto[], int &Indice)
{
	int posicion;
	cout << "================= ELIMINAR PRODUCTO ===================" << endl;
	cout << "Ingrese la poscion del producto que desea eliminar: ";
	cin >> posicion;
	if (posicion > 0 && posicion <= Indice)
	{
		Indice--;
		for (int i = posicion; i < Indice; i++)
		{
			producto[i] = producto[i + 1];
		}
	}
	else
	{
		cout << "Posicion invalida. Intentelo de nuevo." << endl;
	}
}

int main(){
	int opcion;
	do {
		system("cls");
		cout << "=====================================================" << endl;
		cout << "                        MENU" << endl;
		cout << "=====================================================" << endl;
		cout << " 1. Agregar producto" << endl;
<<<<<<< HEAD
		cout << " 2. Mostrar productos" << endl;
		cout << " 3. Buscar usuario" << endl;
		cout << " 4. Eliminar usuario" << endl;
=======
		cout << " 2. Mostar producto" << endl;
		cout << " 3. Buscar producto" << endl;
		cout << " 4. Eliminar producto" << endl;
>>>>>>> dd8cf6c9ac46099991ec7f7e9c115ba6b0f8a149
		cout << " 0. Salir" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion){
			case 1:
<<<<<<< HEAD
				agregarProducto(producto, Indice);
			break;
			case 2:
				mostrarProducto (producto, Indice);

=======
				agregarProducto();
			break;
			case 2:
				mostrarProducto();
>>>>>>> dd8cf6c9ac46099991ec7f7e9c115ba6b0f8a149
			break;
			case 3:
				buscarProducto(producto, Indice);
				break;
			case 4:
				eliminarProducto(producto, Indice);
				break;
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