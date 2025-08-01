// MINICRUD REGISTRO DE VIAJES TRANS LARA IVAN EXPRESS

#include <stdio.h>
#include <string.h>

// Definición de la estructura
typedef struct {
    char id[20];           // ID del viaje
    char conductor[50];    // Nombre del conductor que realiza el viaje
	char empresa[50];      // Empresa a la que se realiza el viaje
	char origen[50];       // Origen del viaje
    char destino[50];      // Destino del viaje
    char fecha_salida[50];      // Fecha de inicio del viaje
    char fecha_retorno[50];     // Fecha de retorno
    int costo;             // Costo del viaje
} Registro;

// Función para agregar un registro nuevo
void crearRegistro(Registro *r) {
    printf("Ingrese ID del viaje: ");
    fgets(r->id, 20, stdin);
    r->id[strcspn(r->id, "\n")] = '\0';

    printf("Ingrese el nombre del conductor asignado: ");
    fgets(r->conductor, 50, stdin);
    r->conductor[strcspn(r->conductor, "\n")] = '\0';

    printf("Ingrese el nombre de la empresa a la que se realizo el viaje: ");
    fgets(r->empresa, 50, stdin);
    r->empresa[strcspn(r->empresa, "\n")] = '\0';
    
    printf("Ingrese la ciudad de donde inicia el viaje: ");
    fgets(r->origen, 50, stdin);
    r->origen[strcspn(r->origen, "\n")] = '\0';
    
    printf("Ingrese la ciudad donde se entrega el producto: ");
    fgets(r->destino, 50, stdin);
    r->destino[strcspn(r->destino, "\n")] = '\0';

    printf("Ingrese la fecha de salida: ");
    fgets(r->fecha_salida, 50, stdin);
    r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';
    
    printf("Ingrese la fecha de retorno: ");
    fgets(r->fecha_retorno, 50, stdin);
    r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';
    
    printf("Ingrese el costo del viaje: ");
    scanf("%i", &r->costo,"\n");
    
    getchar(); // Limpia el buffer del teclado
}

// Función para mostrar los datos de un estudiante
void mostrarRegistro(Registro r) {
    printf("\nID: %s\n", r.id);
    printf("Nombre del conductor: %s\n", r.conductor);
    printf("Nombre de la empresa a la que se realizo el viaje: %s\n", r.empresa);
    printf("Ciudad de donde inicia el viaje: %s\n",r.origen);
    printf("Ciudad donde se entrega el producto: %s\n",r.destino);
    printf("Fecha de salida: %s\n", r.fecha_salida);
    printf("Fecha de retorno: %s\n",r.fecha_retorno);
    printf("Costo del viaje: %i\n",r.costo);
}

// Función para buscar un estudiante por ID
// Retorna la posición si lo encuentra, -1 si no existe
//int buscarPorID(Estudiante lista[], int n, char id[]) {
//    for (int i = 0; i < n; i++) {
//        if (strcmp(lista[i].id, id) == 0) {
//            return i;
//        }
//    }
//    return -1;
//}

// Función para eliminar un estudiante (vacía el registro)
//void eliminarEstudiante(Estudiante *e) {
//    strcpy(e->id, "");
//    strcpy(e->apellidos, "");
//    strcpy(e->nombres, "");
//    e->edad = 0;
//}

int main() {
    Registro lista[100];
    int cantidad = 0;
    int opcion;
    char idBuscada[20];

    while (1) {
        printf("\n--- MENU CRUD DE REGISTRO ---\n");
        printf("1. Agregar registro\n");
        printf("2. Mostrar todos los registros\n");
        //printf("3. Buscar por ID\n");
        //printf("4. Eliminar estudiante\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer

        if (opcion == 1) {
            // Agrega un nuevo registro
            crearRegistro(&lista[cantidad]);
            cantidad++;
        } else if (opcion == 2) {
            // Muestra todos los registros
            for (int i = 0; i < cantidad; i++) {
                if (strlen(lista[i].id) > 0)
                    mostrarRegistro(lista[i]);
            }
        //} else if (opcion == 3) {
            // Busca un estudiante por ID
            //printf("Ingrese el ID a buscar: ");
            //fgets(idBuscada, 20, stdin);
            //idBuscada[strcspn(idBuscada, "\n")] = '\0';
            //int pos = buscarPorID(lista, cantidad, idBuscada);
            //if (pos != -1 && strlen(lista[pos].id) > 0)
                //mostrarEstudiante(lista[pos]);
            //else
                //printf("Estudiante no encontrado.\n");
        //} else if (opcion == 4) {
            // Elimina un estudiante por ID
            //printf("Ingrese el ID a eliminar: ");
            //fgets(idBuscada, 20, stdin);
            //idBuscada[strcspn(idBuscada, "\n")] = '\0';
            //int pos = buscarPorID(lista, cantidad, idBuscada);
            //if (pos != -1 && strlen(lista[pos].id) > 0) {
                //eliminarEstudiante(&lista[pos]);
                //printf("Estudiante eliminado.\n");
            //} else {
                //printf("Estudiante no encontrado.\n");
            //}
        } else if (opcion == 5) {
            //Opción para salir del programa
            printf("Saliendo...\n");
            break;
        //} else {
            //printf("Opción no válida. Intente de nuevo.\n");
       }
    }
    return 0;
}
