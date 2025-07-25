// MINICRUD REGISTRO DE VIAJES TRANS LARA IVAN EXPRESS

#include <stdio.h> // Necesario para funciones de entrada/salida como printf, scanf, fopen, fclose, etc.
#include <string.h> // Necesario para funciones de manipulación de cadenas como strlen, strcmp, strcpy, strcspn
#include <windows.h> // Incluido en el código original, aunque no estrictamente necesario para esta versión de consola, se mantiene por consistencia.

// Define la ruta completa del archivo donde se guardarán los registros.
// NOTA IMPORTANTE: Asegúrate de que la carpeta "C:\Users\Nataly\Desktop\PROYECTO DE PROGRAMACION\" exista.
// El programa NO creará la carpeta, solo el archivo dentro de una carpeta existente.
#define FILENAME "C:\\Users\\Nataly\\Desktop\\PROYECTO DE PROGRAMACION\\registros julio-2025.txt"

// Definicion de la estructura para un Registro de Viaje
typedef struct {
    char id[7];          // ID del viaje (ej. VJE001, 6 caracteres + 1 para el '\0')
    char conductor[50];  // Nombre del conductor que realiza el viaje
    char empresa[50];    // Empresa a la que se realiza el viaje
    char origen[50];     // Origen del viaje
    char destino[50];    // Destino del viaje
    char fecha_salida[50]; // Fecha de inicio del viaje
    char fecha_retorno[50]; // Fecha de retorno
    int costo;           // Costo del viaje
} Registro;

// --- DECLARACION DE FUNCIONES ---
void pausar();
void crearRegistro(Registro *r); // Modificada para no pedir el ID, ya que se valida antes.
void mostrarRegistro(Registro r);
void editarRegistro(Registro *r);
// Funcion para eliminar un registro fisicamente del arreglo, ajustando la cantidad.
void eliminarRegistroFisico(Registro lista[], int *n, int pos);
int buscarPorID(Registro lista[], int n, char id[]);
void guardarRegistros(Registro lista[], int n);
int cargarRegistros(Registro lista[], int max_n);


// --- IMPLEMENTACION DE FUNCIONES ---

/**
 * @brief Pausa la ejecución del programa y espera que el usuario presione Enter.
 * Utiliza getchar() para limpiar el búfer de entrada y esperar la tecla Enter.
 */
void pausar() {
    printf("\nPresione Enter para continuar...");
    int c;
    // Limpia el búfer de entrada hasta encontrar un salto de línea o EOF.
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Solicita al usuario los datos para un nuevo registro de viaje (excepto el ID).
 * @param r Puntero a la estructura Registro donde se guardarán los datos.
 */
void crearRegistro(Registro *r) {
    // Nota: El ID ya se ha solicitado y validado antes de llamar a esta función en main().
    // Aquí se piden el resto de los campos del registro.

    printf("2. Ingrese el nombre completo del conductor asignado (maximo 49 caracteres): ");
    fgets(r->conductor, sizeof(r->conductor), stdin);
    r->conductor[strcspn(r->conductor, "\n")] = '\0'; // Eliminar el salto de línea

    printf("3. Ingrese el nombre de la empresa a la que se realizo el viaje (maximo 49 caracteres): ");
    fgets(r->empresa, sizeof(r->empresa), stdin);
    r->empresa[strcspn(r->empresa, "\n")] = '\0';

    printf("4. Ingrese la ciudad de origen del viaje (ej. Quito, maximo 49 caracteres): ");
    fgets(r->origen, sizeof(r->origen), stdin);
    r->origen[strcspn(r->origen, "\n")] = '\0';

    printf("5. Ingrese la ciudad de destino del viaje (ej. Guayaquil, maximo 49 caracteres): ");
    fgets(r->destino, sizeof(r->destino), stdin);
    r->destino[strcspn(r->destino, "\n")] = '\0';

    printf("6. Ingrese la fecha de salida del viaje (Formato YYYY-MM-DD, maximo 49 caracteres): ");
    fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
    r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';

    printf("7. Ingrese la fecha de retorno del viaje (Formato YYYY-MM-DD, maximo 49 caracteres): ");
    fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
    r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';

    printf("8. Ingrese el costo total del viaje (solo numeros enteros): ");
    while (scanf("%d", &r->costo) != 1) { // Valida que la entrada sea un número entero.
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros para el costo: ");
        int c_costo;
        while ((c_costo = getchar()) != '\n' && c_costo != EOF); // Limpia el búfer
    }
    getchar(); // Consumir el salto de línea pendiente después de scanf
}

/**
 * @brief Muestra los detalles de un registro de viaje.
 * No muestra registros si su ID está vacío (considerado "eliminado").
 * @param r La estructura Registro a mostrar.
 */
void mostrarRegistro(Registro r) {
    if (strlen(r.id) == 0) {
        return; // No muestra registros "vacíos" (borrados lógicamente o por eliminación física).
    }
    printf("\n--- DETALLES DEL REGISTRO ---\n");
    printf("ID: %s\n", r.id);
    printf("Conductor: %s\n", r.conductor);
    printf("Empresa: %s\n", r.empresa);
    printf("Origen: %s\n", r.origen);
    printf("Destino: %s\n", r.destino);
    printf("Fecha de Salida: %s\n", r.fecha_salida);
    printf("Fecha de Retorno: %s\n", r.fecha_retorno);
    printf("Costo del Viaje: %i\n", r.costo);
    printf("------------------------------\n");
}

/**
 * @brief Permite al usuario editar los campos de un registro de viaje existente.
 * El ID del registro no puede ser modificado.
 * @param r Puntero a la estructura Registro a editar.
 */
void editarRegistro(Registro *r) {
    printf("\n--- EDITAR REGISTRO ---\n");
    printf("Estas editando el registro con ID: %s\n", r->id);
    printf("El ID no se puede cambiar.\n");

    printf("Ingrese el nuevo nombre del conductor (actual: %s): ", r->conductor);
    fgets(r->conductor, sizeof(r->conductor), stdin);
    r->conductor[strcspn(r->conductor, "\n")] = '\0';

    printf("Ingrese el nuevo nombre de la empresa (actual: %s): ", r->empresa);
    fgets(r->empresa, sizeof(r->empresa), stdin);
    r->empresa[strcspn(r->empresa, "\n")] = '\0';

    printf("Ingrese el nuevo origen (actual: %s): ", r->origen);
    fgets(r->origen, sizeof(r->origen), stdin);
    r->origen[strcspn(r->origen, "\n")] = '\0';

    printf("Ingrese el nuevo destino (actual: %s): ", r->destino);
    fgets(r->destino, sizeof(r->destino), stdin);
    r->destino[strcspn(r->destino, "\n")] = '\0';

    printf("Ingrese la nueva fecha de salida (actual: %s, Formato YYYY-MM-DD): ", r->fecha_salida);
    fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
    r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';

    printf("Ingrese la nueva fecha de retorno (actual: %s, Formato YYYY-MM-DD): ", r->fecha_retorno);
    fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
    r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';

    printf("Ingrese el nuevo costo (actual: %i, solo numeros enteros): ", r->costo);
    while (scanf("%d", &r->costo) != 1) {
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros para el costo: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    getchar(); // Consumir el salto de línea restante

    printf("\nRegistro actualizado con exito!\n");
}

/**
 * @brief Busca un registro por su ID en el arreglo de registros.
 * @param lista El arreglo de estructuras Registro.
 * @param n La cantidad actual de registros en el arreglo.
 * @param id El ID a buscar.
 * @return La posición (índice) del registro si lo encuentra, o -1 si no existe.
 */
int buscarPorID(Registro lista[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        // Asegurarse de que el registro no esté lógicamente vacío antes de comparar el ID.
        // Esto es importante si se usó una "eliminación lógica" antes de cambiar a física.
        if (strlen(lista[i].id) > 0 && strcmp(lista[i].id, id) == 0) {
            return i;
        }
    }
    return -1; // Registro no encontrado
}

/**
 * @brief Elimina físicamente un registro del arreglo moviendo los elementos posteriores.
 * Esto asegura que el arreglo se mantenga compacto y que la cantidad de registros sea precisa.
 * @param lista El arreglo de estructuras Registro.
 * @param n Puntero a la variable que almacena la cantidad actual de registros.
 * @param pos La posición (índice) del registro a eliminar.
 */
void eliminarRegistroFisico(Registro lista[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        return; // Posición inválida
    }
    // Mueve los elementos posteriores una posición hacia atrás para llenar el hueco.
    for (int i = pos; i < *n - 1; i++) {
        lista[i] = lista[i + 1];
    }
    // Decrementa la cantidad total de registros.
    (*n)--;
}

// --- FUNCIONES PARA MANEJO DE ARCHIVOS ---

/**
 * @brief Guarda todos los registros activos del arreglo en un archivo de texto.
 * El archivo se sobrescribe cada vez que se llama a esta función.
 * @param lista El arreglo de estructuras Registro a guardar.
 * @param n La cantidad actual de registros en el arreglo.
 */
void guardarRegistros(Registro lista[], int n) {
    FILE *archivo = fopen(FILENAME, "w"); // Abrir en modo escritura (sobrescribe si existe)
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo para guardar los registros. Asegurese de que la ruta exista y tenga permisos.\n");
        return;
    }

    // Itera sobre los registros activos (hasta 'n') y los escribe en el archivo.
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%s\n", lista[i].id);
        fprintf(archivo, "%s\n", lista[i].conductor);
        fprintf(archivo, "%s\n", lista[i].empresa);
        fprintf(archivo, "%s\n", lista[i].origen);
        fprintf(archivo, "%s\n", lista[i].destino);
        fprintf(archivo, "%s\n", lista[i].fecha_salida);
        fprintf(archivo, "%s\n", lista[i].fecha_retorno);
        fprintf(archivo, "%d\n", lista[i].costo); // Guardar entero, seguido de un salto de línea
    }

    fclose(archivo); // Cerrar el archivo.
    printf("Registros guardados con exito en '%s'\n", FILENAME);
}

/**
 * @brief Carga registros desde un archivo de texto al inicio del programa.
 * Lee los datos línea por línea y los asigna a las estructuras Registro.
 * @param lista El arreglo de estructuras Registro donde se cargarán los datos.
 * @param max_n El tamaño máximo del arreglo (para evitar desbordamiento).
 * @return La cantidad de registros que se cargaron exitosamente.
 */
int cargarRegistros(Registro lista[], int max_n) {
    FILE *archivo = fopen(FILENAME, "r"); // Abrir en modo lectura
    if (archivo == NULL) {
        printf("Advertencia: No se encontro el archivo de registros '%s'. Se iniciara con una lista vacia.\n", FILENAME);
        return 0; // No se cargaron registros.
    }

    int i = 0;
    // Lee cada campo de un registro. fgets devuelve NULL al final del archivo o si hay un error.
    while (i < max_n && fgets(lista[i].id, sizeof(lista[i].id), archivo) != NULL) {
        lista[i].id[strcspn(lista[i].id, "\n")] = '\0'; // Eliminar el salto de línea leído por fgets.

        fgets(lista[i].conductor, sizeof(lista[i].conductor), archivo);
        lista[i].conductor[strcspn(lista[i].conductor, "\n")] = '\0';

        fgets(lista[i].empresa, sizeof(lista[i].empresa), archivo);
        lista[i].empresa[strcspn(lista[i].empresa, "\n")] = '\0';

        fgets(lista[i].origen, sizeof(lista[i].origen), archivo);
        lista[i].origen[strcspn(lista[i].origen, "\n")] = '\0';

        fgets(lista[i].destino, sizeof(lista[i].destino), archivo);
        lista[i].destino[strcspn(lista[i].destino, "\n")] = '\0';

        fgets(lista[i].fecha_salida, sizeof(lista[i].fecha_salida), archivo);
        lista[i].fecha_salida[strcspn(lista[i].fecha_salida, "\n")] = '\0';

        fgets(lista[i].fecha_retorno, sizeof(lista[i].fecha_retorno), archivo);
        lista[i].fecha_retorno[strcspn(lista[i].fecha_retorno, "\n")] = '\0';

        // Lee el costo como entero.
        if (fscanf(archivo, "%d", &lista[i].costo) != 1) {
            printf("Error en el formato del archivo al leer el costo. Se cargaron %d registros.\n", i);
            fclose(archivo);
            return i; // Retorna los registros que se pudieron leer correctamente.
        }
        // Consume el salto de línea que queda en el búfer después de fscanf,
        // para que la siguiente llamada a fgets funcione correctamente.
        int c;
        while ((c = fgetc(archivo)) != '\n' && c != EOF);
        if (c == EOF && !feof(archivo)) {
            // Maneja el caso donde el archivo termina sin un salto de línea después del último entero.
            // No es necesario hacer nada especial aquí, ya estamos al final.
        }

        i++; // Incrementa el contador de registros cargados.
    }

    fclose(archivo); // Cerrar el archivo.
    printf("Se cargaron %d registros desde '%s'\n", i, FILENAME);
    return i; // Retorna la cantidad de registros cargados.
}


// --- FUNCION PRINCIPAL (main) ---
int main() {
    Registro lista[100]; // Arreglo para almacenar hasta 100 registros.
    int cantidad = 0;    // Variable que controlará la cantidad actual de registros, se inicializa al cargar.
    int opcion;          // Para la opción del menú.
    char idBuscada[20];  // Para almacenar el ID a buscar.
    int pos;             // Para almacenar la posición de un registro encontrado.

    // --- CARGAR REGISTROS AL INICIO DEL PROGRAMA ---
    // Al iniciar, intentamos cargar los registros existentes del archivo.
    // La variable 'cantidad' se actualizará con el número de registros cargados.
    cantidad = cargarRegistros(lista, 100);

    // Bucle principal del menú.
    while (1) {
        printf("\n");
        printf("====================================================\n");
        printf("             TRASNLARA IVAN EXPRESS                 \n");
        printf("====================================================\n");
        printf("  BIENVENIDO AL SISTEMA DE REGISTRO DE VIAJES      \n");
        printf("      TRANS LARA IVAN EXPRESS!                       \n");
        printf("====================================================\n");
        printf("  Gestiona tus viajes de manera eficiente y sencilla.\n");
        printf("  Selecciona una opcion del menu para comenzar.      \n");
        printf("====================================================\n");
        printf("\n===== MENU =====\n");
        printf("1. ANADIR REGISTRO\n");
        printf("2. EDITAR REGISTRO\n");
        printf("3. ELIMINAR REGISTRO\n");
        printf("4. MOSTRAR REGISTROS\n");
        printf("5. SALIR\n");
        printf("Opcion: ");

        // Lee la opción del menú y valida que sea un número.
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero del menu.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpia el búfer si la entrada no es un entero.
            pausar();
            continue; // Vuelve al inicio del bucle para mostrar el menú de nuevo.
        }
        getchar(); // Consumir el salto de línea pendiente después de scanf.

        switch (opcion) {
            case 1: // ANADIR REGISTRO
                if (cantidad < 100) { // Verifica si hay espacio en el arreglo.
                    printf("\n--- FORMULARIO DE NUEVO REGISTRO DE VIAJE ---\n");
                    char temp_id[7];
                    printf("1. Ingrese el ID unico del viaje (ej. VJE001, maximo 6 caracteres): ");
                    fgets(temp_id, sizeof(temp_id), stdin);
                    temp_id[strcspn(temp_id, "\n")] = '\0'; // Limpia el salto de línea.

                    // Verifica si el ID ya existe para evitar duplicados.
                    if (buscarPorID(lista, cantidad, temp_id) != -1) {
                        printf("Error: El ID '%s' ya existe. Por favor, ingrese un ID unico.\n", temp_id);
                    } else {
                        // Si el ID es único, asignarlo y luego pedir el resto de los campos.
                        strcpy(lista[cantidad].id, temp_id);
                        crearRegistro(&lista[cantidad]); // Llama a la función para pedir los demás campos.
                        cantidad++; // Incrementa la cantidad de registros.
                        // El mensaje de éxito se muestra dentro de crearRegistro ahora.
                    }
                } else {
                    printf("La lista de registros esta llena. No se pueden anadir mas.\n");
                }
                break;

            case 2: // EDITAR REGISTRO
                printf("\n--- BUSCAR REGISTRO PARA EDITAR ---\n");
                printf("Ingrese el ID del registro que desea editar: ");
                fgets(idBuscada, sizeof(idBuscada), stdin);
                idBuscada[strcspn(idBuscada, "\n")] = '\0';

                pos = buscarPorID(lista, cantidad, idBuscada);
                if (pos != -1) {
                    editarRegistro(&lista[pos]); // Llama a la función de edición.
                } else {
                    printf("Registro con ID '%s' no encontrado. No se pudo editar.\n", idBuscada);
                }
                break;

            case 3: // ELIMINAR REGISTRO
                printf("\n--- BUSCAR REGISTRO PARA ELIMINAR ---\n");
                printf("Ingrese el ID del registro que desea eliminar: ");
                fgets(idBuscada, sizeof(idBuscada), stdin);
                idBuscada[strcspn(idBuscada, "\n")] = '\0';

                pos = buscarPorID(lista, cantidad, idBuscada);
                if (pos != -1) {
                    char confirmacion;
                    printf("¿Esta seguro que desea eliminar el registro con ID '%s'? (s/n): ", idBuscada);
                    scanf(" %c", &confirmacion);
                    getchar(); // Consumir el salto de línea.

                    if (confirmacion == 's' || confirmacion == 'S') {
                        eliminarRegistroFisico(lista, &cantidad, pos); // Llama a la función de eliminación física.
                        printf("Registro con ID '%s' eliminado con exito.\n", idBuscada);
                    } else {
                        printf("Eliminacion cancelada. El registro no fue modificado.\n");
                    }
                } else {
                    printf("Registro con ID '%s' no encontrado. No se pudo eliminar.\n", idBuscada);
                }
                break;

            case 4: // MOSTRAR REGISTROS
                if (cantidad == 0) {
                    printf("\nNo hay registros guardados para mostrar. Anada uno primero.\n");
                } else {
                    printf("\n--- LISTADO DE REGISTROS ACTIVOS ---\n");
                    for (int i = 0; i < cantidad; i++) {
                        mostrarRegistro(lista[i]); // Muestra cada registro.
                    }
                }
                break;

            case 5: // SALIR
                // --- GUARDAR REGISTROS ANTES DE SALIR ---
                // Esta es la parte crucial para guardar los datos antes de que el programa termine.
                guardarRegistros(lista, cantidad);
                printf("Saliendo del programa. Hasta luego!\n");
                return 0; // Finaliza el programa.

            default: // Opción no válida.
                printf("Opcion no valida. Por favor, ingrese un numero del 1 al 5.\n");
                break;
        }
        pausar(); // Pausa después de cada operación para que el usuario pueda ver el resultado.
    }

    return 0;
}