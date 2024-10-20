#include <iostream>
#include <iomanip>
#include <limits>
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

void modificarCantidad(INFORMACION producto[], int &Indice);
int BusquedaBinaria(INFORMACION producto[], string nom, int bajo, int alto);
void ordenacion(INFORMACION producto[], int Indice);
void agregarProducto(INFORMACION producto[], int &Indice);
void mostrarProducto (INFORMACION producto[], int &Indice);
void buscarProducto (INFORMACION producto[], int Indice);
void eliminarProducto (INFORMACION producto[], int &Indice);

void agregarProducto(INFORMACION producto[], int &Indice)
{
	int cant;
	system("cls");
	cout << "================= AGREGAR PRODUCTO ===================" << endl;
	cout << " Cuantos productos (diferentes) desea agregar?: ";

	while (!(cin >> cant) || cant <= 0)
	{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "-----------------------------------------------------" << endl;
        cout << " <<< Entrada invalida. Intentelo de nuevo. >>>" << endl;
    }
	
	for (int i = 0; i < cant; i++)
	{
		string nombreTemp;
		cout << "-----------------------------------------------------" << endl;
		cout << " Ingrese nombre del producto "<< i + 1 << ": ";
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
				while (!(cin >> cantidadTemp) || cantidadTemp <= 0) 
				{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida. Ingrese una cantidad válida: ";
                }
				producto[j].cantidad += cantidadTemp; // cambie i por j 
			}
		}
		
		if (!encontrado)
		{
			Indice++;
			producto[Indice - 1].nombre = nombreTemp;

			cout << " Ingrese una descripcion: ";
			getline(cin, producto[Indice - 1].descripcion);
			
			cout << " Ingrese una ID: ";
			while (!(cin >> producto[Indice - 1].ID) || producto[Indice - 1].ID <= 0) 
			{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << " <<< Entrada invalida. Ingrese una ID valida: >>> ";
            }

			cout << " Ingrese cantidad: ";
			while (!(cin >> cantidadTemp) || cantidadTemp <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << " <<< Entrada invalida. Ingrese una cantidad valida: >>> ";
            }
            producto[Indice - 1].cantidad = cantidadTemp;
		}
	}
}

void modificarCantidad(INFORMACION producto[], int &Indice) {
    system("cls");
    string nomtemp;
    cout << "================ MODIFICAR CANTIDAD =================" << endl;
    cout << " Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, nomtemp);

    int encontrado = -1;
    for (int i = 0; i < Indice; i++) 
	{
        if (producto[i].nombre == nomtemp) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) 
	{
        int opcion;
		cout << "-----------------------------------------------------" << endl;
        cout << " Desea aumentar (1) o disminuir (2) la cantidad?: ";
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " <<< Entrada invalida. Ingrese 1 para aumentar o 2 para disminuir: >>>";
        }

        int cantidadMod;
        cout << " Ingrese la cantidad a modificar: ";
        while (!(cin >> cantidadMod) || cantidadMod <= 0) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " <<< Entrada invalida. Ingrese un numero valido mayor a 0: >>>";
        }

        if (opcion == 1) 
		{
            producto[encontrado].cantidad += cantidadMod;
			cout << "-----------------------------------------------------" << endl;
            cout << " <<< La cantidad se ha aumentado correctamente. >>>" << endl;
        } else if (opcion == 2) 
		{
            if (producto[encontrado].cantidad >= cantidadMod) 
			{
                producto[encontrado].cantidad -= cantidadMod;
				cout << "-----------------------------------------------------" << endl;
                cout << " <<< La cantidad se ha disminuido correctamente. >>>" << endl;
            } else 
			{
				cout << "-----------------------------------------------------" << endl;
                cout << " <<< No se puede disminuir mas de lo que hay en stock. >>>" << endl;
            }
        }
    } else 
	{
		cout << "-----------------------------------------------------" << endl;
        cout << " <<< Producto no encontrado. >>>" << endl;
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
		int opcion;
		cout << "================================================================================================" << endl;
		cout << "                    Lista de productos" << endl;
		cout << "================================================================================================" << endl;

		cout << left;
		cout << setw(5) << "Nro" << setw(10) << "ID" << setw(20) << "Nombre" << setw(30) << "Descripcion" << setw(10) << "Cantidad" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < Indice; i++)
		{
			cout << setw(5) << i + 1 << setw(10) << producto[i].ID << setw(20) << producto[i].nombre << setw(30) << producto[i].descripcion << setw(10) << producto[i].cantidad << endl;
		}
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << " Desea modificar la cantidad de un producto? (1/0): ";
		cin >> opcion;
		if (opcion == 1) {
			modificarCantidad(producto, Indice);
		}
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
	return -1;
}

void buscarProducto (INFORMACION producto[], int Indice)
{
    system("cls");
	cout << "================= BUSCAR PRODUCTO ===================" << endl;
	if (Indice == 0)
	{
		cout << " <<< Aun no se registraron productos. >>>" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "Ingrese el nombre del producto: ";
		string nomtemp;
		cin.ignore();
		getline(cin, nomtemp);
		
		ordenacion(producto, Indice); // Ordenar los productos antes de la búsqueda
		int encontrado = BusquedaBinaria(producto, nomtemp, 0, Indice - 1);
		
		if (encontrado != -1) 
		{
			cout << "-----------------------------------------------------" << endl;
			cout << " <<< Producto encontrado. >>>" << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << left;
			cout << setw(15) << " Nombre: " << producto[encontrado].nombre << endl;
			cout << setw(15) << " Descripcion: " << producto[encontrado].descripcion << endl;
			cout << setw(15) << " ID: " << producto[encontrado].ID << endl;
			cout << setw(15) << " Cantidad: " << producto[encontrado].cantidad << endl;
			cout << "-----------------------------------------------------" << endl;
		} 
		else 
		{
			cout << "-----------------------------------------------------" << endl;
			cout << " <<< Producto no encontrado. >>>" << endl;
		}
		system("pause");
	}
}

void eliminarProducto (INFORMACION producto[], int &Indice)
{
	cout << "================= ELIMINAR PRODUCTO ===================" << endl;
	if (Indice == 0)
	{
		cout << " <<< Aun no se registraron productos. >>>" << endl;
		system("pause");
		return;
	}
	else
	{
		system("cls");
		int posicion;
		cout << "Ingrese la posicion del producto que desea eliminar (1 a " << Indice << "): ";
		cin >> posicion;
		posicion--;

		if (posicion >= 0 && posicion < Indice)
		{
			for (int i = posicion; i < Indice - 1; i++)
			{
				producto[i] = producto[i + 1];
			}
			Indice--;
			cout << "-----------------------------------------------------" << endl;
			cout << " <<< Producto eliminado con exito. >>>" << endl;
		}
		else
		{
			cout << "-----------------------------------------------------" << endl;
			cout << " <<< Posicion invalida >>>" << endl;
		}
		system("pause");
	}
}

void ordenacion(INFORMACION producto[], int Indice)
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