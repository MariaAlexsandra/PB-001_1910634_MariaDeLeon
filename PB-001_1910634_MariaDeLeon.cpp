/**************************************/
/******SIMULADOR DE CITAS DENTALES*****/
/**************************************/

//Mar�a Alexsandra De Le�n Aguilera

#include <iostream>

using namespace std;

int main() {

	int num_cit = 0, hora, opcion_1, opcion_m, cantidad_tratamiento;
	char nombre[50], tratamiento [20], descripcion[100];
	float precio_total, precio_tratamiento, precio_unitario;
 
	do {
/*MEN� DE OPCIONES*/
		cout << endl << "*****BIENVENIDO A DENTALIA*****" << endl <<
			"Seleccione" << endl <<
			"1. Agendar citas" << endl <<
			"2. Modificar cita" << endl <<
			"3. Cancelar cita" << endl <<
			"4. Listado de citas vigentes" << endl <<
			"5. Limpiar pantalla" << endl <<
			"6. Salir" << endl <<
			"Su opcion: ";
		cin >> opcion_m; //Variable para la opcion de men�

		switch (opcion_m) {

//*SELECCI�N 1*//
		case 1:
			do {
	//NUMERO DE CITA: se agrega un numero mas al recuento de citas original:
					num_cit = num_cit + 1;  
					cout << endl << "Numero de cita: " << num_cit << endl;	//Se muestra en pantalla el numero de cita correspondiente
	//NOMBRE: se pide el nombre al usuario:
					cout << "Nombre de paciente: " << endl;
					cin.ignore(); //funcion para ignorar el buffer de la l�nea anterior y no entrometa con la siguiente funci�n.
					cin.getline(nombre, 50, '\n'); /*funcion que permite la entrada de cadena de caracteres :
													primero la variable que se leer�, la cantidad limitada de
													caracteres permitidos y que terminar� cuando el usuario ingrese un enter*/
	//HORA: en un formato de 24, se pide al usuario la hora de la cita:
					cout << "Hora (24h): " << endl;
					cin >> hora;
	//TRATAMIENTO: De acuerdo al listado, el usuario deber� elegir una opci�n
					cout << "Ingrese nombre de tratamiento" << endl;
					cin.ignore();
					cin.getline (tratamiento, 20,'\n');
	//DESCRIPCI�N: breve explicaci�n del tratamiento
					cout << "Descripcion: " << endl;
					cin.ignore();
					cin.getline(descripcion, 100, '\n');
	//PRECIO UNITARIO DE TRATAMIENTO
					cout << "Ingrese precio del tratamiento $ ";
					cin >> precio_tratamiento;
	//CANTIDAD DE TRATAMIENTO
					cout << "Ingrese cantidad de tratamiento: ";
					cin >> cantidad_tratamiento;
	//PRECIO UNITARIO: El precio seg�n el tipo y la cantidad de tratamientos previamente.
					precio_unitario = precio_tratamiento * cantidad_tratamiento;
					cout << "Coste unitario $ " << precio_unitario << endl;
	//PRECIO TOTAL: El precio total del tratamiento m�s los impuestos.
					precio_total = precio_unitario * .16 + precio_unitario;
					cout << "Coste total $ " << precio_total << endl;
	//AGENDAR CITA NUEVA
					cout << "�Desea agendar una cita nueva?" << endl << "Ingrese 1 para si y 2 para no: ";
					cin >> opcion_1;
				
			} while (opcion_1 == 1);
			//REGRESAR AL MEN� (1) O SALIR (2)
			cout << "�Volver al menu? Ingrese 1 para volver y 2 para salir del programa: ";
			cin >> opcion_m;
			break;

			system("pause");

//*SELECCI�N 2*//
		case 2:
			cout << "Escogio la opcion 2" << endl;
			
			//REGRESAR AL MEN� (1) O SALIR (2)
			cout << "�Volver al menu? Ingrese 1 para volver y 2 para salir: ";
			cin >> opcion_m;
			break;


//*SELECCI�N 3*//
		case 3:
			cout << "Escogio la opcion 3" << endl;

			//REGRESAR AL MEN� (1) O SALIR (2)
			cout << "�Volver al menu? Ingrese 1 para volver y 2 para salir: ";
			cin >> opcion_m;
			break;


//*SELECCI�N 4*//
		case 4:
			cout << "Escogio la opcion 4" << endl;
			
			//REGRESAR AL MEN� (1) O SALIR (2)
			cout << "�Volver al menu? Ingrese 1 para volver y 2 para salir: ";
			cin >> opcion_m;
			break;


//*SELECCI�N 5*//
		case 5:
			cout << "Escogio la opcion 5" << endl;

			//REGRESAR AL MEN� (1) O SALIR (2)
			cout << "�Volver al menu? Ingrese 1 para volver y 2 para salir: ";
			cin >> opcion_m;
			break;


//*SELECCI�N 6*//
		case 6:
				cout << "�Seguro que desea salir? Escriba 1 para volver al menu y 2 para salir del programa: ";
				cin >> opcion_m;
			break;
		}
	} while (opcion_m == 1);

	
}