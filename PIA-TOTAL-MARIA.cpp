/**************************************/
/******SIMULADOR DE CITAS DENTALES*****/
/**************************************/

//María Alexsandra De León Aguilera

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>// funcione new y delete
#include <vector>
#include <ctype.h>

using namespace std;

//FUNCIONES
void alta();
void listas();
void archivos();
void eliminar();
void modificar();

int num_cit = 0, * hora, * minutos, * cantidad_tratamiento, valor_especial = 0;
float* precio_tratamiento, * precio_total, * precio_unitario;
string* nombre, * tratamiento, * descripcion;


int main()
{
	int opcion_m;

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

		//OPCION 1: AGENDAR CITAS
	case 1:
		alta();
		return main();
		break;

		//OPCION 2: MODIFICAR CITAS
	case 2:
		modificar();
		return main();
		break;

		//OPCION 3: CANCELAR CITA
	case 3:
		eliminar();
		return main();
		break;

		//OPCION 4: LISTADO DE CITAS VIGENTES
	case 4:
		listas();
		return main();
		break;

		//OPCION 5:LIMPIAR PANTALLA
	case 5:
		system("cls");
		return main();
		break;

		//OPCION 6: SALIR DEL PROGRAMA
	case 6:
		archivos();
		break;
	}
}

void alta()
{
	cout << endl << "Ingrese la cantidad de citas a registrar: ";
	cin >> num_cit;

	//ARREGLOS DE ALTA
	hora = new int[num_cit];
	minutos = new int[num_cit];
	precio_tratamiento = new float[num_cit];
	cantidad_tratamiento = new int[num_cit];
	precio_total = new float[num_cit];
	precio_unitario = new float[num_cit];
	nombre = new string[num_cit];
	tratamiento = new string[num_cit];
	descripcion = new string[num_cit];


	for (int i = 0; i < num_cit; i++)
	{
		cout << endl << "Cita #" << i + 1 << endl;
		//NOMBRE DEL PACIENTE
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		do {
			valor_especial = 0;
			cout << "Nombre del paciente: ";
			getline(cin, nombre[i]); //permite los espacios en el nombre
			for (auto c = begin(nombre[i]); c != end(nombre[i]); c++) {
				if (isalpha(*c) || *c == ' ') {
					valor_especial = valor_especial + 0;
				}
				else {
					valor_especial = valor_especial + 1;
				}
			}
		} while (valor_especial != 0);
		//HORA: con validación que se encuentre el rango de un horario
		do {
			cout << "Hora de cita" << endl;
			cout << "Hora (1-24): ";
			cin >> hora[i];
		} while (hora[i] <= 0 || hora[i] > 24); //Horario de atención: 8 a 20 horas.
			
		do {
			cout << "Minutos (0-59): ";
			cin >> minutos[i];
		} while (minutos[i] < 0 || minutos[i]>59); //Horario de atención: 8 a 20 horas.
		if (hora[i] < 10 && minutos[i]<10) { //Ej: 9:05
			cout << "Hora ingresada: " << "0" << hora[i] << ":" << "0" << minutos[i] << endl;
		}
		else {
			if (hora[i] < 10 && minutos[i]>10) { //Ej: 8:10
				cout << "Hora ingresada: " << "0" << hora[i] << ":" << minutos[i] << endl;
			}
			else
			{
				if (hora[i]>=10 && minutos[i]<10) //Ej: 11:04
				{
					cout << "Hora ingresada: " << hora[i] << ":" << "0" << minutos[i] << endl;
				}
				else
				{
					cout << "Hora ingresada: " << hora[i] << ":" << minutos[i] << endl;
				}
			}
		}
		//TRATAMIENTO
		while (getchar() != '\n');
		do {
			valor_especial = 0;
			cout << "Nombre del tratamiento: ";
			getline(cin, tratamiento[i]);
			for (auto c = begin(tratamiento[i]); c != end(tratamiento[i]); c++) {
				if (isalpha(*c) || *c == ' ') {
					valor_especial = valor_especial + 0;
				}
				else {
					valor_especial = valor_especial + 1;
				}
			}
		} while (valor_especial != 0);
		//DESCRIPCION
		do {
			valor_especial = 0;
			cout << "Descripcion: ";
			getline(cin, descripcion[i]);;
			for (auto c = begin(descripcion[i]); c != end(descripcion[i]); c++) {
				if (isalpha(*c) || *c == ' ') {
					valor_especial = valor_especial + 0;
				}
				else {
					valor_especial = valor_especial + 1;
				}
			}
		} while (valor_especial != 0);
		//PRECIO UNITARIO DEL TRATAMIENTO
		cout << "Ingrese precio del tratamiento $";
		cin >> precio_tratamiento[i];
		//CANTIDAD DEL TRATAMIENTO
		cout << "Ingrese cantidad del tratamiento: ";
		cin >> cantidad_tratamiento[i];
		//PRECIO UNITARIO: El precio según el tipo y la cantidad de tratamientos previamente ingresados.
		precio_unitario[i] = precio_tratamiento[i] * cantidad_tratamiento[i];
		cout << "Coste unitario (subtotal): $" << precio_unitario[i] << endl;
		//PRECIO TOTAL: El precio total del tratamiento más impuestos.
		precio_total[i] = precio_unitario[i] + precio_unitario[i] * .16;
		cout << "Coste total: $" << precio_total[i] << endl;
	}
}

void listas()
{
	cout << endl << "Listado de listas vigentes" << endl;
	for (int i = 0; i < num_cit; i++) {
		if (precio_total[i] == 0)
		{
			cout << endl << "Cita #" << i + 1 << " eliminada" << endl;
		}
		else
		{
			cout << endl << "Cita #" << i + 1 << endl;
			cout << "Nombre del paciente: " << nombre[i] << endl;
			//HORA
			if (hora[i] < 10 && minutos[i] < 10) { //Ej: 9:05
				cout << "Hora: " << "0" << hora[i] << ":" << "0" << minutos[i] << endl;
			}
			else {
				if (hora[i] < 10 && minutos[i]>10) { //Ej: 8:10
					cout << "Hora: " << "0" << hora[i] << ":" << minutos[i] << endl;
				}
				else
				{
					if (hora[i] >= 10 && minutos[i] < 10) //Ej: 11:04
					{
						cout << "Hora: " << hora[i] << ":" << "0" << minutos[i] << endl;
					}
					else
					{
						cout << "Hora: " << hora[i] << ":" << minutos[i] << endl;
					}
				}
			}
			cout << "Tratamiento a realizar: " << tratamiento[i] << endl;
			cout << "Descripcion: " << descripcion[i] << endl;
			cout << "Precio unitario del tratamiento $" << precio_tratamiento[i] << endl;
			cout << "Cantidad del tratamiento: " << cantidad_tratamiento[i] << endl;
			cout << "Precio unitario (subtotal): $" << precio_unitario[i] << endl;
			cout << "Precio total: $" << precio_total[i] << endl;
		}
	}

}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int numeros;
	int numeros2;
	string letras;

	nombrearchivo = "info_citas.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "Error al abrir el archivo.";
		exit(1);
	}



	for (int i = 0; i < num_cit; i++)
	{
		if (precio_total[i] == 0) //numero de cita
		{
			numeros = 0;
			archivo << "CITA " << numeros << " (eliminada)" << endl;
		}
		else {
			numeros = i + 1;
			archivo << "CITA #" << numeros << endl;
		}
		letras = nombre[i]; //nombre
		archivo << "PACIENTE: " << letras << endl;
		if (hora[i] < 10 && minutos[i] < 10) { //Ej: 09:05
			numeros = hora[i];
			numeros2 = minutos[i];
			archivo << "HORA: " << "0" << numeros << ":" << "0" << numeros2<<endl;
		}
		else {
			if (hora[i] < 10 && minutos[i]>10) { //Ej: 8:10
				numeros = hora[i];
				numeros2 = minutos[i];
				archivo << "HORA: " << "0" << numeros << ":" << numeros2 << endl;
			}
			else
			{
				if (hora[i] >= 10 && minutos[i] < 10) //Ej: 11:04
				{
					numeros = hora[i];
					numeros2 = minutos[i];
					archivo << "HORA: " << numeros << ":" << "0" << numeros2 << endl;
				}
				else
				{
					numeros = hora[i];
					numeros2 = minutos[i];
					archivo << "HORA: " << numeros << ":" << numeros2 << endl;
				}
			}
		}
		letras = tratamiento[i];//tratamiento
		archivo << "TRATAMIENTO: " << letras << endl;
		letras = descripcion[i];//descripcion
		archivo << "DESCRIPCION: " << letras << endl;
		numeros = precio_tratamiento[i];//precio de tratamiento
		archivo << "PRECIO DEL TRATAMIENTO $" << numeros << endl;
		numeros = cantidad_tratamiento[i];//cantidad de tratamiento
		archivo << "CANTIDAD DE TRATAMIENTO: " << numeros << endl;
		numeros = precio_unitario[i];//precio unitario
		archivo << "PRECIO UNITARIO (SUBTOTAL): $" << numeros << endl;
		numeros = precio_total[i];//precio total
		archivo << "PRECIO TOTAL: $" << numeros << endl;
		archivo << "~~~~~~~~~~~~~~~~~~~~" << endl;
	}


	archivo.close();
}

void eliminar()
{
	int cita_eliminar;
	cout << "Ingrese el numero de cita a eliminar: ";
	cin >> cita_eliminar;
	cita_eliminar = cita_eliminar - 1;
	for (int i = cita_eliminar; i == cita_eliminar; i++) {
		cout << "Eliminando cita #" << cita_eliminar + 1 << endl;

		nombre[i] = "              ";
		hora[i] = 0;
		minutos[i] = 0;
		tratamiento[i] = "              ";
		descripcion[i] = "              ";
		precio_tratamiento[i] = 0;
		cantidad_tratamiento[i] = 00000;
		precio_unitario[i] = 0;
		precio_total[i] = 0;
	}
}

void modificar()
{
	int opcion_2, num_cita_modificar;

	do {
		cout << endl << "Ingrese el dato que desea modificar:" << endl <<
			"1. Nombre de paciente." << endl <<
			"2. Hora de la cita." << endl <<
			"3. Tratamiento." << endl <<
			"4. Descripcion." << endl <<
			"5. Precio del tratamiento." << endl <<
			"6. Cantidad del tratamiento." << endl <<
			"7. Todas las anteriores." << endl <<
			"Su opcion: ";
		cin >> opcion_2;

		cout << "Ingrese el numero de cita: #";
		cin >> num_cita_modificar;
		num_cita_modificar = num_cita_modificar - 1;

		switch (opcion_2) {

		case 1: //MODIFICAR NOMBRE DEL PACIENTE
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual nombre: " << nombre[i] << endl;
				while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
				do {
					valor_especial = 0;
					cout << "Nombre del paciente: ";
					getline(cin, nombre[i]); //permite los espacios en el nombre
					for (auto c = begin(nombre[i]); c != end(nombre[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		case 2: //MODIFICAR HORA
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual hora: " << hora[i] << ":" << minutos[i] << endl;
				do {
					cout << "Hora de cita" << endl;
					cout << "Hora (1-24): ";
					cin >> hora[i];
				} while (hora[i] <= 0 || hora[i] > 24); //Horario de atención: 8 a 20 horas.

				do {
					cout << "Minutos (0-59): ";
					cin >> minutos[i];
				} while (minutos[i] < 0 || minutos[i]>59); //Horario de atención: 8 a 20 horas.
				if (hora[i] < 10 && minutos[i] < 10) { //Ej: 9:05
					cout << "Hora ingresada: " << "0" << hora[i] << ":" << "0" << minutos[i] << endl;
				}
				else {
					if (hora[i] < 10 && minutos[i]>10) { //Ej: 8:10
						cout << "Hora ingresada: " << "0" << hora[i] << ":" << minutos[i] << endl;
					}
					else
					{
						if (hora[i] >= 10 && minutos[i] < 10) //Ej: 11:04
						{
							cout << "Hora ingresada: " << hora[i] << ":" << "0" << minutos[i] << endl;
						}
						else
						{
							cout << "Hora ingresada: " << hora[i] << ":" << minutos[i] << endl;
						}
					}
				}
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		case 3: //MODIFICAR TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual tratamiento: " << tratamiento[i] << endl;
				while (getchar() != '\n');
				do {
					valor_especial = 0;
					cout << "Nombre del tratamiento: ";
					getline(cin, tratamiento[i]);
					for (auto c = begin(tratamiento[i]); c != end(tratamiento[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		case 4: //MODIFICAR DESCRIPCION
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual descripcion: " << descripcion[i] << endl;
				while (getchar() != '\n');
				do {
					valor_especial = 0;
					cout << "Descripcion: ";
					getline(cin, descripcion[i]);
					for (auto c = begin(descripcion[i]); c != end(descripcion[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		case 5: //MODIFICAR PRECIO DEL TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual precio: " << precio_tratamiento[i] << endl;
				cout << "Ingrese nuevo precio: $";
				cin >> precio_tratamiento[i];
				//AL CAMBIAR ESTE DATO, SE ALTERA EL PRECIO:
				precio_unitario[i] = precio_tratamiento[i] * cantidad_tratamiento[i];
				cout << "Coste unitario (subtotal) nuevo: $" << precio_unitario[i] << endl;
				precio_total[i] = precio_unitario[i] * .16 + precio_unitario[i];
				cout << "Coste total nuevo: $" << precio_total[i] << endl;
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		case 6: //MODIFICAR CANTIDAD DE TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual cantidad de tratamiento: " << cantidad_tratamiento[i] << endl;
				cout << "Ingrese nueva cantidad de tratamiento: ";
				cin >> cantidad_tratamiento[i];
				//AL CAMBIAR ESTE DATO, SE ALTERA EL PRECIO:
				precio_unitario[i] = precio_tratamiento[i] * cantidad_tratamiento[i];
				cout << "Coste unitario nuevo: $" << precio_unitario[i] << endl;
				precio_total[i] = precio_unitario[i] * .16 + precio_unitario[i];
				cout << "Coste total nuevo: $" << precio_total[i] << endl;
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;

		case 7: //MODIFICAR TODAS LAS OPCIONES
			//MODIFICAR NOMBRE DEL PACIENTE
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual nombre: " << nombre[i] << endl;
				while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
				do {
					valor_especial = 0;
					cout << "Nombre del paciente: ";
					getline(cin, nombre[i]); //permite los espacios en el nombre
					for (auto c = begin(nombre[i]); c != end(nombre[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			//MODIFICAR HORA
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual hora: " << hora[i] << ":" << minutos[i] << endl;
				do {
					cout << "Hora de cita" << endl;
					cout << "Hora (1-24): ";
					cin >> hora[i];
				} while (hora[i] <= 0 || hora[i] > 24); //Horario de atención: 8 a 20 horas.

				do {
					cout << "Minutos (0-59): ";
					cin >> minutos[i];
				} while (minutos[i] < 0 || minutos[i]>59); //Horario de atención: 8 a 20 horas.
				if (hora[i] < 10 && minutos[i] < 10) { //Ej: 9:05
					cout << "Hora ingresada: " << "0" << hora[i] << ":" << "0" << minutos[i] << endl;
				}
				else {
					if (hora[i] < 10 && minutos[i]>10) { //Ej: 8:10
						cout << "Hora ingresada: " << "0" << hora[i] << ":" << minutos[i] << endl;
					}
					else
					{
						if (hora[i] >= 10 && minutos[i] < 10) //Ej: 11:04
						{
							cout << "Hora ingresada: " << hora[i] << ":" << "0" << minutos[i] << endl;
						}
						else
						{
							cout << "Hora ingresada: " << hora[i] << ":" << minutos[i] << endl;
						}
					}
				}
			}
			//MODIFICAR TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual tratamiento: " << tratamiento[i] << endl;
				while (getchar() != '\n');
				do {
					valor_especial = 0;
					cout << "Nombre del tratamiento: ";
					getline(cin, tratamiento[i]);
					for (auto c = begin(tratamiento[i]); c != end(tratamiento[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			//MODIFICAR DESCRIPCION
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual descripcion: " << descripcion[i] << endl;
				do {
					valor_especial = 0;
					cout << "Descripcion: ";
					getline(cin, descripcion[i]);;
					for (auto c = begin(descripcion[i]); c != end(descripcion[i]); c++) {
						if (isalpha(*c) || *c == ' ') {
							valor_especial = valor_especial + 0;
						}
						else {
							valor_especial = valor_especial + 1;
						}
					}
				} while (valor_especial != 0);
			}
			//MODIFICAR PRECIO DEL TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual precio: " << precio_tratamiento[i] << endl;
				cout << "Ingrese nuevo precio: $";
				cin >> precio_tratamiento[i];
			}
			//MODIFICAR CANTIDAD DE TRATAMIENTO
			for (int i = num_cita_modificar; i <= num_cita_modificar; i++) {
				cout << "Actual cantidad de tratamiento: " << cantidad_tratamiento[i] << endl;
				cout << "Ingrese nueva cantidad de tratamiento: ";
				cin >> cantidad_tratamiento[i];
				precio_unitario[i] = precio_tratamiento[i] * cantidad_tratamiento[i];
				cout << "Coste unitario (subtotal) nuevo: $" << precio_unitario[i] << endl;
				precio_total[i] = precio_unitario[i] * .16 + precio_unitario[i];
				cout << "Coste total nuevo: $" << precio_total[i] << endl;
			}
			cout << "Ingrese 1 para modificar nuevo dato y 2 para terminar: ";
			cin >> opcion_2;
			break;
		}
	} while (opcion_2 == 1);
}