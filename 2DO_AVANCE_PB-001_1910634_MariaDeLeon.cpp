/**************************************/
/******SIMULADOR DE CITAS DENTALES*****/
/**************************************/

//María Alexsandra De León Aguilera

#include <iostream>
#include <string.h>

using namespace std;

int main() {

	int num_cit = 0, num_cita_modificar;
	int opcion_1, opcion_m, opcion_2;

	struct datos
	{
		char nombre[50];
		int hora;
		char tratamiento[20];
		char descripcion[100];
		float precio_tratamiento;
		int cantidad_tratamiento;
		float precio_total;
		float precio_unitario;

	};

	datos cita [3];

	do {
		/*MENÚ DE OPCIONES*/
		cout << endl << "*****BIENVENIDO A DENTALIA*****" << endl <<
			"Seleccione" << endl <<
			"1. Agendar citas." << endl <<
			"2. Modificar cita." << endl <<
			"3. Cancelar cita." << endl <<
			"4. Listado de citas vigentes." << endl <<
			"5. Limpiar pantalla." << endl <<
			"6. Salir." << endl <<
			"Su opcion: ";
		cin >> opcion_m; //Variable para la opcion de menú

		switch (opcion_m) {

			//*SELECCIÓN 1*//
		case 1:
			do {
				//NUMERO DE CITA: se agrega un numero mas al recuento de citas original:
				num_cit = num_cit + 1;
				cout << endl << "Numero de cita: " << num_cit << endl;	//Se muestra en pantalla el numero de cita correspondiente
				//NOMBRE: se pide el nombre al usuario:
				cout << "Nombre de paciente: ";
				cin.ignore(); //funcion para ignorar el buffer de la línea anterior y no entrometa con la siguiente función.
				cin.getline(cita[num_cit].nombre, 50, '\n'); /*funcion que permite la entrada de cadena de caracteres :
																primero la variable que se leerá, la cantidad limitada de
																caracteres permitidos y que terminará cuando el usuario ingrese un enter*/
				//HORA: en un formato de 24, se pide al usuario la hora de la cita:
				cout << "Hora (24h): ";
				cin >> cita[num_cit].hora;
				//TRATAMIENTO: De acuerdo al listado, el usuario deberá elegir una opción
				cout << "Ingrese nombre de tratamiento: ";
				cin.ignore();
				cin.getline(cita[num_cit].tratamiento, 20, '\n');
				//DESCRIPCIÓN: breve explicación del tratamiento
				cout << "Descripcion: " << endl;
				cin.getline(cita[num_cit].descripcion, 100, '\n');
				//PRECIO UNITARIO DE TRATAMIENTO
				cout << "Ingrese precio del tratamiento $";
				cin >> cita[num_cit].precio_tratamiento;
				//CANTIDAD DE TRATAMIENTO
				cout << "Ingrese cantidad de tratamiento: ";
				cin >> cita[num_cit].cantidad_tratamiento;
				//PRECIO UNITARIO: El precio según el tipo y la cantidad de tratamientos previamente.
				cita[num_cit].precio_unitario = cita[num_cit].precio_tratamiento * cita[num_cit].cantidad_tratamiento;
				cout << "Coste unitario $" << cita[num_cit].precio_unitario << endl;
				//PRECIO TOTAL: El precio total del tratamiento más los impuestos.
				cita[num_cit].precio_total = cita[num_cit].precio_unitario * .16 + cita[num_cit].precio_unitario;
				cout << "Coste total $" << cita[num_cit].precio_total << endl;
				//AGENDAR CITA NUEVA
				cout << "¿Desea agendar una cita nueva?" << endl << "Ingrese 1 para si y 2 para no: ";
				cin >> opcion_1;

			} while (opcion_1 == 1);
			//REGRESAR AL MENÚ (1) O SALIR (2)
			cout << "Ingrese 1 para volver al menu principal y 2 para salir del programa: ";
			cin >> opcion_m;
			break;



			//*SELECCIÓN 2*//
		case 2:
			do {
				cout << endl << "Ingrese el dato que desea modificar:" << endl <<
					"1. Nombre de paciente." << endl <<
					"2. Hora de la cita." << endl <<
					"3. Tratamiento." << endl <<
					"4. Descripcion." << endl <<
					"5. Precio del tratamiento." << endl <<
					"6. Cantidad del tratamiento." << endl <<
					"7. Todas las anteriores." << endl <<
					"Su opcion: " << endl;
				cin >> opcion_2;

				cout << "Ingrese el numero de cita: #";
				cin >> num_cita_modificar;

				switch (opcion_2) {
				
				case 1: //MODIFICAR NOMBRE DEL PACIENTE
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual nombre: " << cita[i].nombre << endl;
						cout << "Ingrese nuevo nombre: ";
						cin.ignore();
						cin.getline(cita[i].nombre, 50, '\n');
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 2: //MODIFICAR HORA
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual hora: " << cita[i].hora << endl;
						cout << "Ingrese nueva hora: ";
						cin >> cita[i].hora;
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 3: //MODIFICAR TRATAMIENTO
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual tratamiento: " << cita[i].tratamiento << endl;
						cout << "Ingrese nuevo tratamiento: ";
						cin.ignore();
						cin.getline(cita[i].tratamiento, 50, '\n');
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 4: //MODIFICAR DESCRIPCION
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual descripcion: " << cita[i].descripcion << endl;
						cout << "Ingrese nueva descripcion: " << endl;
						cin.ignore();
						cin.getline(cita[i].descripcion, 100, '\n');
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 5: //MODIFICAR PRECIO DEL TRATAMIENTO
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual precio: " << cita[i].precio_tratamiento << endl;
						cout << "Ingrese nuevo precio: $";
						cin >> cita[i].precio_tratamiento;
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 6: //MODIFICAR CANTIDAD DE TRATAMIENTO
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						cout << "Actual cantidad de tratamiento: " << cita[i].cantidad_tratamiento << endl;
						cout << "Ingrese nueva cantidad de tratamiento";
						cin >> cita[i].cantidad_tratamiento;
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				case 7: //MODIFICAR TODO LO ANTERIOR
					for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
						//MODIFICAR NOMBRE
						cout << "Actual nombre: " << cita[i].nombre << endl;
						cout << "Ingrese nuevo nombre: ";
						cin.ignore();
						cin.getline(cita[i].nombre, 50, '\n');
						//MODIFICAR HORA
						cout << "Actual hora: " << cita[i].hora << endl;
						cout << "Ingrese nueva hora: ";
						cin >> cita[i].hora;
						//MODIFICAR TRATAMIENTO
						cout << "Actual tratamiento: " << cita[i].tratamiento << endl;
						cout << "Ingrese nuevo tratamiento: ";
						cin.ignore();
						cin.getline(cita[i].tratamiento, 50, '\n');
						//MODIFICAR DESCRIPCION
						cout << "Actual descripcion: " << cita[i].descripcion << endl;
						cout << "Ingrese nueva descripcion: " << endl;
						cin.ignore();
						cin.getline(cita[i].descripcion, 100, '\n');
						//MODIFICAR PRECIO DEL TRATAMIENTO
						cout << "Actual precio: " << cita[i].precio_tratamiento << endl;
						cout << "Ingrese nuevo precio: $";
						cin >> cita[i].precio_tratamiento;
						//MODIFICAR CANTIDAD DE TRATAMIENTO
						cout << "Actual cantidad de tratamiento: " << cita[i].cantidad_tratamiento << endl;
						cout << "Ingrese nueva cantidad de tratamiento: ";
						cin >> cita[i].cantidad_tratamiento;
						//AL CAMBIAR ESTOS DATOS, SE ALTERA EL PRECIO:
						cita[num_cit].precio_unitario = cita[num_cit].precio_tratamiento * cita[num_cit].cantidad_tratamiento;
						cout << "Coste unitario nuevo $" << cita[num_cit].precio_unitario << endl;
						cita[num_cit].precio_total = cita[num_cit].precio_unitario * .16 + cita[num_cit].precio_unitario;
						cout << "Coste total nuevo $" << cita[num_cit].precio_total << endl;
					}
					cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
					cin >> opcion_2;
					break;
				}

			} while (opcion_2==1);
			//REGRESAR AL MENÚ (1) O SALIR (2)
			cout << "Ingrese 1 para volver al menu principal y 2 para salir del programa: ";
			cin >> opcion_m;
			break;


			//*SELECCIÓN 3*//
		case 3:
			cout << "Escogio la opcion 3" << endl;

			//REGRESAR AL MENÚ (1) O SALIR (2)
			cout << "Ingrese 1 para volver al menu principal y 2 para salir del programa: ";
			cin >> opcion_m;
			break;


			//*SELECCIÓN 4*//
		case 4:
			cout << endl << "Listado de citas vigentes" << endl;
			for (int i = 1; i <= num_cit; i++) {
				cout << endl << "Cita #" << i << endl;
				cout << "Nombre del paciente: " << cita[i].nombre << endl;
				cout << "Hora de cita: " << cita[i].hora << endl;
				cout << "Tratamiento a realizar: " << cita[i].tratamiento << endl;
				cout << "Descripcion: " << cita[i].descripcion << endl;
				cout << "Precio unitario del tratamiento $" << cita[i].precio_tratamiento << endl;
				cout << "Cantidad del tratamiento: " << cita[i].cantidad_tratamiento << endl;
				cout << "Precio unitario $" << cita[i].precio_unitario << endl;
				cout << "Precio total $" << cita[i].precio_total << endl;
			}

			//REGRESAR AL MENÚ (1) O SALIR (2)
			cout << "Ingrese 1 para volver al menu principal y 2 para salir del programa: ";
			cin >> opcion_m;
			break;


			//*SELECCIÓN 5*//
		case 5:
			cout << "Escogio la opcion 5" << endl;

			//REGRESAR AL MENÚ (1) O SALIR (2)
			cout << "Ingrese 1 para volver al menu principal y 2 para salir del programa: ";
			cin >> opcion_m;
			break;


			//*SELECCIÓN 6*//
		case 6:
			cout << "¿Seguro que desea salir? Ingrese 1 para volver al menu principal y 2 para salir: ";
			cin >> opcion_m;
			break;



		default:
			cout << "Su seleccion no existe. Volvera al menu principal." << endl;
			opcion_m = 1;
			break;

		}
	} while (opcion_m == 1);


}