#include <iostream>
#include <string>
using namespace std;

struct INFORMACION{
	string nombre;
	string descripcion;
	int ID;
	int cantidad;
};

INFORMACION producto[100];
int Indice = 0;

int BusquedaBinaria(INFORMACION producto[], string nom, int bajo, int alto);
void ordenacion(INFORMACION producto[], int &Indice);
void agregarProducto(INFORMACION producto[], int &Indice);
void mostrarProducto (INFORMACION producto[], int &Indice);
void buscarProducto (INFORMACION producto[], int &Indice);
void eliminarProducto (INFORMACION producto[], int &Indice);

void agregarProducto(INFORMACION producto[], int &Indice)
{
	int cant;
	system("cls");
	cout << "================= AGREGAR PRODUCTO ===================" << endl;
	cout << " Cuantos productos (diferentes) desea agregar?: ";
	cin >> cant;
	
	for (int i = 0; i <cant; i++)
	{
		string nombreTemp;
		cout << "-----------------------------------------------------" << endl;
		cout << "Ingrese nombre del producto "<< i + 1 << ": ";
		cin.ignore();
		getline(cin, nombreTemp);
		
		bool encontrado = false;
		int cantidadTemp;
		
		//Funcion para verificar si se REPITE el NOMBRE del producto precio
		for (int j = 0; j < Indice; j++)
		{
			if (nombreTemp == producto[j].nombre)
			{
				encontrado = true;
				cout << " Ingrese cantidad: ";  //Si se repite, solo ingresa cantidad.
				cin >> cantidadTemp;
				producto[j].cantidad += cantidadTemp; // cambie i por j 
			}
		}
		
		if (!encontrado)
		{
			cout << " Ingrese una descripcion: ";
			cin.ignore();
			getline(cin, producto[Indice].descripcion);
			
			cout<<" Ingrese una ID: ";
			cin >> producto[Indice].ID;
			
			cout<<" Ingrese cantidad: ";
			cin >> cantidadTemp;
			producto[i].cantidad = producto[i].cantidad + cantidadTemp;
			Indice++;
		}
	}
}	

void mostrarProducto (INFORMACION producto[], int &Indice)
{
	system("cls");
	cout << "================ MOSTRAR PRODUCTO ===================" << endl;
	if (Indice == 0)
	{
		cout << " <<< Aun no se registraron productos. >>>" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "                    Lista de productos" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " ID | Nombre | Descripcion | Cantidad | Precio" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Indice; i++)
		{
			cout << producto[i].ID << " | " << producto[i].nombre << " | " << producto[i].descripcion << " | " << producto[i].cantidad << " | " << producto[i].ID << endl;
		}
		cout << "-----------------------------------------------------" << endl;
	}
	system("pause");
}

int BusquedaBinaria(INFORMACION producto[], string nom, int bajo, int alto)
{
	int medio;
	while (bajo <= alto)
	{
		medio = (bajo + alto) / 2;
		if (producto[medio].nombre == nom)
		{
			return medio;
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
}

void buscarProducto (INFORMACION producto[], int &Indice)
{
    system("cls");
    cout << "================= BUSCAR PRODUCTO ===================" << endl;
    cout << "Ingrese el nombre del producto: ";
    string nomtemp;
    cin.ignore();
    getline(cin, nomtemp);
    
    ordenacion(producto, Indice); // Ordenar los productos antes de la búsqueda
    int encontrado = BusquedaBinaria(producto, nomtemp, 0, Indice - 1);
    
    if (encontrado != -1) 
	{
        cout << "Producto encontrado." << endl;
        cout << "Nombre: " << producto[encontrado].nombre << endl;
        cout << "Descripcion: " << producto[encontrado].descripcion << endl;
        cout << "ID: " << producto[encontrado].ID << endl;
        cout << "Cantidad: " << producto[encontrado].cantidad << endl;
    } 
	else 
	{
        cout << " <<< Producto no encontrado. >>>" << endl;
    }
    system("pause");
}

void eliminarProducto (INFORMACION producto[], int &Indice)
{
	int posicion;
	system("cls");
	cout << "================= ELIMINAR PRODUCTO ===================" << endl;
	cout << "Ingrese la poscion del producto que desea eliminar (1 a " << Indice << "): ";
	cin >> posicion;
	posicion--;

	if (posicion >= 0 && posicion < Indice)
	{
		for (int i = posicion; i < Indice - 1; i++)
		{
			producto[i] = producto[i + 1];
		}
		Indice--;
		cout << "Producto eliminado con exito." << endl;
	}
	else
	{
		cout << " <<< Posicion invalida >>>" << endl;
	}
	system("pause");
}

void ordenacion(INFORMACION producto[], int &Indice)
{
	for (int i = 0; i < Indice - 1; i++)
	{
		for (int j = i + 1; j < Indice; j++)
		{
			if (producto[i].nombre > producto[j].nombre)
			{
				INFORMACION temp = producto[i];
				producto[i] = producto[j];
				producto[j] = temp;
			}
		}
	}
}

int main(){
	int opcion;
	do 
	{
		system("cls");
		cout << "=====================================================" << endl;
		cout << "                        MENU" << endl;
		cout << "=====================================================" << endl;
		cout << " 1. Agregar producto" << endl;
		cout << " 2. Mostrar producto" << endl;
		cout << " 3. Buscar producto" << endl;
		cout << " 4. Eliminar producto" << endl;
		cout << " 0. Salir" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion)
		{
			case 1:
				agregarProducto(producto, Indice);
			break;
			case 2:
				mostrarProducto (producto, Indice);
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
				cout << " <<< Opcion no valida. Intentelo de nuevo. >>>" << endl;
				system("pause");
			break;
		}
	} while(opcion != 0);
	
	return 0;
}