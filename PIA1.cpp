#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>

using namespace std;
struct VENTA
{
	int nT, dd, mm, aa, nArt, art[20];
	float total, prop, iva, totalmiva;
    string estatusb;
};
int alta;
VENTA* TICKET;

void Alta();
void Eliminar();
void Listas();
void Modificar();
void Archivos();

int main() {
	int op;
	cout << "1. Alta\n2. Mostrar listas\n3. Limpiar pantalla\n4. Modificar\n5. Eliminar\n6. Salir\n";
	cin >> op;
	switch (op) {
	case 1:
		cout << "\n=====================================\n";
		Alta();
		return main();
		break;
	case 2:
		cout << "\n=====================================\n";
		Listas();
		return main();
		break;
	case 3:
		cout << "\n=====================================\n";
		system("cls");
		return main();
		break;
	case 4:
		cout << "\n=====================================\n";
		Modificar();
		return main();
		break;
	case 5:
		cout << "\n=====================================\n";
		Eliminar();
		return main();
		break;
	case 6:
		cout << "\n=====================================\n";
		Archivos();
		exit(1);
		break;
	default:
		cout << "\n=====================================\n";
		cout << "\nIngresa una opcion valida\n";
		return main();
		break;
	}
}

void Alta() {
    int v, a = 0, op;
	printf("Cuantos tickets se van a dar de alta: ");
	scanf_s("%d", &alta);
	TICKET = new VENTA[alta];
	for (int i = 0; i < alta; i++) {
		cout << "Ticket #: " << i + 1 << endl;
        TICKET[i].nArt = 0;
        TICKET[i].total = 0;
        TICKET[i].nT = alta;

        cout << "Ingrese la fecha de hoy (dd/mm):\ndd: ";
        cin >> TICKET[i].dd;
        do {
            if (TICKET[i].dd < 1 || TICKET[i].dd > 30) {
                cout << "******************************************************\n";
                cout << "ERROR -- INGRESA UN DIA VALIDO: ";
                cin >> TICKET[i].dd;
            }
            else {
                v = 1;
            }
        } while (v == 0);
        v = 0;
        cout << "mm: ";
        cin >> TICKET[i].mm;
        do {
            if (TICKET[i].mm < 1 || TICKET[i].mm > 12) {
                cout << "******************************************************\n";
                cout << "ERROR -- INGRESA UN MES VALIDO: ";
                cin >> TICKET[i].mm;
            }
            else {
                v = 1;
            }
        } while (v == 0);
        TICKET[i].aa = 2023;
        cout << "******************************************************\n";
        cout << "Seleccione los articulos que llevara el cliente:\n1. Refresco de cola (600ml)\t\t$ 17.50\n2. Jugo natural de fruta (500ml)\t$ 15.00\n3. Frituras de queso (58g)\t\t$ 23.00\n4. Cacahuates enchilados (67g)\t\t$ 17.00\n5. Galletas de chocolate (114g)\t\t$ 21.50\n6. Cafe helado (281ml)\t\t\t$ 32.00\n0. Terminar seleccion.\n---\n";
        do {
            cout << "Realiza tu seleccion: ";
            cin >> op;
            TICKET[i].art[a] = op;
            TICKET[i].nArt++;
            a++;
            switch (op) {
            case 1:
                TICKET[i].total = TICKET[i].total + 17.50;
                break;
            case 2:
                TICKET[i].total = TICKET[i].total + 15;
                break;
            case 3:
                TICKET[i].total = TICKET[i].total + 23;
                break;
            case 4:
                TICKET[i].total = TICKET[i].total + 17;
                break;
            case 5:
                TICKET[i].total = TICKET[i].total + 21.50;
                break;
            case 6:
                TICKET[i].total = TICKET[i].total + 32;
                break;
            case 0:
                break;
            default:
                cout << "******************************************************\n";
                cout << "ERROR -- SELECCIONA UNA OPCION VALIDA\n";
                break;
            }
        } while (op != 0);
        TICKET[i].iva = TICKET[i].total * 0.16;
        TICKET[i].totalmiva = TICKET[i].total * 1.16;
        cout << "******************************************************\n";
        cout << "GRACIAS POR SU COMPRA\n";
        printf("Su total es : $ %.2f", TICKET[i].totalmiva);
        cout << "\n******************************************************\n";
	}
}

void Eliminar() {
    int borrar;
    cout << "Ingresa el ticket a eliminar: ";
    cin >> borrar;
    borrar--;

    for (int i = borrar; i == borrar; i++) {
        cout << "Eliminando ticket " << borrar + 1 << endl;
        TICKET[i].estatusb = "ELIMINADO";
    }
}

void Listas() {
    for (int i = 0; i < alta; i++) {
        cout << "\n=======================================\n";
        cout << "Ticket # " << i + 1 << endl;
        if (TICKET[i].estatusb == "ELIMINADO") {
            cout << "***TICKET ELIMINADO***\n";
        }
        cout << TICKET[i].dd << "/" << TICKET[i].mm << "/" << TICKET[i].aa << endl;
        printf("Numero de articulos : %d\nTotal : $ %.2f \nTotal + IVA : $ %.2f", TICKET[i].nArt, TICKET[i].total, TICKET[i].totalmiva);
        cout << "\n=======================================\n";
    }
}

void Modificar() {
    int mod, opc, v;
    cout << "Ingresa el numero de ticket a modificar: ";
    cin >> mod;
    mod--;
    for (int i = mod; i == mod; i++) {
        if (TICKET[i].estatusb == "ELIMINADO") {
            cout << "El ticket fue eliminado anteriormente\nIngresa un # de ticket valido\n";
            return Modificar();
        }
        cout << "Ingrese la opcion que quiere modificar\n1. Fecha\n2. Total\n3. Agregar propina\n";
        cin >> opc;
        switch (opc) {
        case 1:
            cout << "Ingrese la fecha de hoy (dd/mm):\ndd: ";
            cin >> TICKET[i].dd;
            do {
                if (TICKET[i].dd < 1 || TICKET[i].dd > 30) {
                    cout << "******************************************************\n";
                    cout << "ERROR -- INGRESA UN DIA VALIDO: ";
                    cin >> TICKET[i].dd;
                }
                else {
                    v = 1;
                }
            } while (v == 0);
            v = 0;
            cout << "mm: ";
            cin >> TICKET[i].mm;
            do {
                if (TICKET[i].mm < 1 || TICKET[i].mm > 12) {
                    cout << "******************************************************\n";
                    cout << "ERROR -- INGRESA UN MES VALIDO: ";
                    cin >> TICKET[i].mm;
                }
                else {
                    v = 1;
                }
            } while (v == 0);
            TICKET[i].aa = 2023;
            break;
        case 2:
            cout << "Ingresa el total: ";
            cin >> TICKET[i].total;
            TICKET[i].totalmiva = TICKET[i].total * 1.16;
            TICKET[i].iva = TICKET[i].total * 0.16;
            break;
        case 3:
            cout << "Ingresa la propina: ";
            cin >> TICKET[i].prop;
        }
    }
}

void Archivos() {
    ofstream archivo;
    string nombrearchivo;
    nombrearchivo = "tickets.dat";
    archivo.open(nombrearchivo.c_str(), ios::binary);
    if (archivo.fail()) {
        cout << "ERROR ¡ NO SE PUDO CREAR EL ARCHIVO !";
        exit(1);
    }
    archivo << "#TICKET\tFECHA\t#ARTICULOS\tTOTAL\tIVA\tTOTAL+IVA\tPROPINA\tESTATUS\n";
    for (int i = 0; i < alta; i++) {
        archivo << i + 1 << "\t";
        archivo << TICKET[i].dd << "/" << TICKET[i].mm << "/" << TICKET[i].aa;
        archivo << TICKET[i].nArt;
        archivo << TICKET[i].total;
        archivo << TICKET[i].iva;
        archivo << TICKET[i].totalmiva;
        archivo << TICKET[i].prop;
        archivo << TICKET[i].estatusb;
    }
    archivo.close();
}