#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const int TAM=3;
    const float CAPITAL=850000;

    int opcion, i;
    bool datosCargados=false, calculo=false;

    float vecProvincia[TAM];
    float vecHipotecario[TAM];
    float vecNacion[TAM];
    float promProvincia=0, promNacion=0, promHipotecario=0;
    float contPromProvincia=0, contPromNacion=0, contPromHipotecario=0;
    float tasas[3];
    float mensual, trimestral, anual;
    float mejorRend=0;
    float tasaAnual;

    string bancos[3]={"Provincia", "Nacion", "Hipotecario"};
    string mejorBanco;
    string mejorModo;

    while(true){

        system("cls");
        cout<<"--------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"  PARCIAL 2 - INTRODUCCION AL ANALISIS DE DATOS"<<endl;
        cout<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"      ---- CALCULADORA DE INVERSIONES ----"<<endl;
        cout<<endl;
        cout<<"1- Ingresar valores historicos (TNA % anual)"<<endl;
        cout<<endl;
        cout<<"2- Calcular promedio de tasas anuales"<<endl;
        cout<<endl;
        cout<<"3- Evaluar conveniencia de inversion"<<endl;
        cout<<endl;
        cout<<"4- Salir de la calculadora"<<endl;
        cout<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            ///CASO 1
            case 1:
                system("cls");
                for (i=0; i<TAM; i++){
                cout << "--- VALORES HISTORICOS (TNA % ANUAL) ---"<<endl;
                cout<<endl;
                cout<<"Banco Provincia (>=100) - Anio "<<i+1<<": ";
                cin>>vecProvincia[i];
                cout<<"Banco Nacion (>=100) - Anio "<<i+1<<": ";
                cin>>vecNacion[i];
                cout<<"Banco Hipotecario (>=100) - Anio "<<i+1<<": ";
                cin>>vecHipotecario[i];
                cout<<endl;
            }
            datosCargados = true;
            cout << "Datos cargados correctamente."<<endl;
            system("pause");
            break;

            ///CASO 2
            case 2:
                system("cls");
                if (!datosCargados){
                    cout<<"Primero debe ingresar los datos (opcion 1)."<<endl;
                    system("pause");
                    break;
                }

            if (!calculo){
                for (i=0; i<TAM; i++) {
                    contPromProvincia+=vecProvincia[i];
                    contPromNacion+=vecNacion[i];
                    contPromHipotecario+=vecHipotecario[i];
                }
            }

            promProvincia=contPromProvincia/TAM;
            promNacion=contPromNacion/TAM;
            promHipotecario=contPromHipotecario/TAM;

            tasas[0] = promProvincia;
            tasas[1] = promNacion;
            tasas[2] = promHipotecario;

            cout<<"--- PROMEDIOS DE TASAS ANUALES ---"<<endl;
            cout<<endl;
            cout<<"Banco Provincia: "<<promProvincia<<"%"<<endl;
            cout<<"Banco Nacion: "<<promNacion<<"%"<<endl;
            cout<<"Banco Hipotecario: "<<promHipotecario<<"%"<<endl;
            calculo=true;
            system("pause");
            break;

            ///CASO 3
            case 3:
                system("cls");
                if (promProvincia==0 && promNacion==0 && promHipotecario==0){
                cout << "Primero calcule los promedios (opcion 2)."<<endl;
                system("pause");
                break;
            }

            cout<<"--- EVALUACION DE INVERSIONES ---"<<endl;
            cout<<endl;
            for (i=0; i<3; i++){
                tasaAnual=tasas[i]/100;

                // modalidad anual
                anual=CAPITAL*(1 + tasaAnual);

                // modalidad trimestral (4 trimestres)
                trimestral=CAPITAL*pow((1 + tasaAnual / 4), 4);

                // modalidad mensual (12 meses)
                mensual=CAPITAL*pow((1 + tasaAnual / 12), 12);

                cout<<"---------------------------------------------"<<endl;
                cout<<"Banco "<<bancos[i]<<": "<<endl;
                cout<<endl;
                cout << "- Inversion anual directa: $"<<fixed<<setprecision(2)<<anual<<endl;
                cout << "- Inversion trimestral:    $"<<fixed<<setprecision(2)<<trimestral<<endl;
                cout << "- Inversion mensual:       $"<<fixed<<setprecision(2)<<mensual<<endl;
                cout<<endl;
                cout<<"---------------------------------------------"<<endl;

                // determinar el mejor de todas
                if (anual>mejorRend) {
                    mejorRend=anual;
                    mejorBanco=bancos[i];
                    mejorModo="Anual";
                }
                if (trimestral>mejorRend) {
                    mejorRend=trimestral;
                    mejorBanco=bancos[i];
                    mejorModo="Trimestral";
                }
                if (mensual>mejorRend) {
                    mejorRend=mensual;
                    mejorBanco=bancos[i];
                    mejorModo="Mensual";
                }
            }

            cout<<"---------------------------------------------"<<endl;
            cout<<endl;
            cout<<"La mejor opcion es invertir en el Banco "<<mejorBanco<<endl;
            cout<<"Modalidad: "<<mejorModo<<endl;
            cout<<"Monto final estimado: $"<<mejorRend<<endl;
            cout<<endl;
            cout<<"---------------------------------------------"<<endl;
            system("pause");
            break;

            ///SALIR
            case 4:
                cout << "Saliendo del programa..."<<endl;
                return 0;

            ///DEFAULT
            default:
                cout<<"Por favor, ingrese una opcion valida"<<endl;
                system("pause");
                break;
        }

    }

    return 0;
}
