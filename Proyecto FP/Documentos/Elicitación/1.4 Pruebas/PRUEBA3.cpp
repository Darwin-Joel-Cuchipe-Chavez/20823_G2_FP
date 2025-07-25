// MINICRUD REGISTRO DE VIAJES TRANS LARA IVAN EXPRESS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necesario para atoi en validaciones de fecha si se implementan más a fondo

// Definicion de la estructura para un Registro de Viaje
typedef struct {
    char id[8];             // ID del viaje (VJE001, maximo 6 caracteres + \0)
    char conductor[50];     // Nombre del conductor que realiza el viaje
    char empresa[50];       // Empresa a la que se realiza el viaje
    char origen[50];        // Origen del viaje
    char destino[50];       // Destino del viaje
    char fecha_salida[50];  // Fecha de inicio del viaje (Formato YYYY-MM-DD)
    char fecha_retorno[50]; // Fecha de retorno (Formato YYYY-MM-DD)
    int costo;              // Costo del viaje
} Registro;

// --- PROTOTIPOS DE FUNCIONES ---
void pausar();
void crearRegistro(Registro *r, Registro lista[], int cantidad); // Añadimos lista y cantidad para validar ID único
void mostrarRegistro(Registro r);
void editarRegistro(Registro *r);
int buscarPorID(Registro lista[], int n, char id[]);
void eliminarRegistro(Registro *r);
void guardarRegistros(Registro lista[], int cantidad, const char *nombre_archivo);
int cargarRegistros(Registro lista[], int max_cantidad, const char *nombre_archivo);
int validarFecha(const char *fecha); // Nueva función para validar formato de fecha
// --- FIN PROTOTIPOS ---

// Funcion para pausar la ejecucion y esperar que el usuario presione Enter
void pausar() {
    printf("\nPresione Enter para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpia el bufer y espera el Enter
}

// Funcion para limpiar el buffer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcion para validar el formato YYYY-MM-DD
// Retorna 1 si es válido, 0 si no
int validarFecha(const char *fecha) {
    if (strlen(fecha) != 10) {
        return 0; // Longitud incorrecta
    }
    // Verifica guiones en las posiciones correctas
    if (fecha[4] != '-' || fecha[7] != '-') {
        return 0;
    }
    // Verifica que los caracteres sean dígitos en las posiciones numéricas
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue; // Ignora los guiones
        if (fecha[i] < '0' || fecha[i] > '9') {
            return 0; // Carácter no numérico
        }
    }
    // Podríamos añadir validación de rango de meses/días, años bisiestos aquí,
    // pero para este ejemplo, nos quedamos con una validación de formato básica.
    return 1;
}

// Funcion para agregar un nuevo registro de viaje
void crearRegistro(Registro *r, Registro lista[], int cantidad) {
    printf("\n===== FORMULARIO DE NUEVO REGISTRO DE VIAJE =====\n");
    char temp_input[100]; // Buffer temporal para inputs

    // 1. ID del viaje - VALIDACIONES: Longitud, No vacío, Único
    while (1) {
        printf("1. Ingrese el ID unico del viaje (ej. VJE001, maximo 6 caracteres): ");
        fgets(temp_input, sizeof(temp_input), stdin);
        temp_input[strcspn(temp_input, "\n")] = '\0';
        strcpy(r->id, temp_input); // Copiar al registro para validar

        if (strlen(r->id) == 0) {
            printf("Error: El ID no puede estar vacio.\n");
        } else if (strlen(r->id) > 6) { // Si el array es de 8, 7 chars + null. Si pedimos max 6, es 6 + null
            printf("Error: El ID excede el maximo de 6 caracteres.\n");
        } else if (buscarPorID(lista, cantidad, r->id) != -1) {
            printf("Error: El ID '%s' ya existe. Por favor, ingrese un ID unico.\n", r->id);
        } else {
            break; // ID válido
        }
    }

    // 2. Conductor - VALIDACION: No vacío
    while (1) {
        printf("2. Ingrese el nombre completo del conductor asignado (maximo 49 caracteres): ");
        fgets(r->conductor, sizeof(r->conductor), stdin);
        r->conductor[strcspn(r->conductor, "\n")] = '\0';
        if (strlen(r->conductor) == 0) {
            printf("Error: El nombre del conductor no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // 3. Empresa - VALIDACION: No vacío
    while (1) {
        printf("3. Ingrese el nombre de la empresa a la que se realizo el viaje (maximo 49 caracteres): ");
        fgets(r->empresa, sizeof(r->empresa), stdin);
        r->empresa[strcspn(r->empresa, "\n")] = '\0';
        if (strlen(r->empresa) == 0) {
            printf("Error: El nombre de la empresa no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // 4. Origen - VALIDACION: No vacío
    while (1) {
        printf("4. Ingrese la ciudad de origen del viaje (ej. Quito, maximo 49 caracteres): ");
        fgets(r->origen, sizeof(r->origen), stdin);
        r->origen[strcspn(r->origen, "\n")] = '\0';
        if (strlen(r->origen) == 0) {
            printf("Error: El origen no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // 5. Destino - VALIDACION: No vacío
    while (1) {
        printf("5. Ingrese la ciudad de destino del viaje (ej. Guayaquil, maximo 49 caracteres): ");
        fgets(r->destino, sizeof(r->destino), stdin);
        r->destino[strcspn(r->destino, "\n")] = '\0';
        if (strlen(r->destino) == 0) {
            printf("Error: El destino no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // 6. Fecha de salida - VALIDACIONES: Formato YYYY-MM-DD, No vacío
    while (1) {
        printf("6. Ingrese la fecha de salida del viaje (Formato YYYY-MM-DD, maximo 49 caracteres): ");
        fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
        r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';
        if (strlen(r->fecha_salida) == 0) {
            printf("Error: La fecha de salida no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_salida)) {
            printf("Error: Formato de fecha invalido. Use YYYY-MM-DD.\n");
        } else {
            break;
        }
    }

    // 7. Fecha de retorno - VALIDACIONES: Formato YYYY-MM-DD, No vacío, Posterior a fecha de salida
    while (1) {
        printf("7. Ingrese la fecha de retorno del viaje (Formato YYYY-MM-DD, maximo 49 caracteres): ");
        fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
        r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';
        if (strlen(r->fecha_retorno) == 0) {
            printf("Error: La fecha de retorno no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_retorno)) {
            printf("Error: Formato de fecha invalido. Use YYYY-MM-DD.\n");
        }
        if (strcmp(r->fecha_retorno, r->fecha_salida) < 0) {
            printf("Error: La fecha de retorno no puede ser anterior a la fecha de salida.\n");
        }
        else{
        	break;
        }
    }

    // 8. Costo - VALIDACIONES: Solo números enteros, no negativos
    printf("8. Ingrese el costo total del viaje (solo numeros enteros no negativos): ");
    while (scanf("%d", &r->costo) != 1 || r->costo < 0) {
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros no negativos para el costo: ");
        limpiarBuffer(); // Limpia el bufer si el usuario ingresa algo que no es un numero
    }
    limpiarBuffer(); // Limpia el buffer después de scanf
    printf("\nRegistro de viaje creado con exito!\n");
}

// Funcion para mostrar los datos de un registro especifico
void mostrarRegistro(Registro r) {
    if (strlen(r.id) == 0) {
        return; // No muestra registros "vacios" (lógicamente eliminados)
    }
    printf("\n===== DETALLES DEL REGISTRO =====\n");
    printf("ID: %s\n", r.id);
    printf("Conductor: %s\n", r.conductor);
    printf("Empresa: %s\n", r.empresa);
    printf("Origen: %s\n", r.origen);
    printf("Destino: %s\n", r.destino);
    printf("Fecha de Salida: %s\n", r.fecha_salida);
    printf("Fecha de Retorno: %s\n", r.fecha_retorno);
    printf("Costo del Viaje: %i\n", r.costo);
    printf("==============================\n");
}

// Funcion para editar un registro existente
void editarRegistro(Registro *r) {
    printf("\n===== EDITAR REGISTRO =====\n");
    printf("Estas editando el registro con ID: %s\n", r->id); // Muestra el ID que se esta editando
    printf("El ID no se puede cambiar.\n");

    // Conductor - VALIDACION: No vacío
    while (1) {
        printf("Ingrese el nuevo nombre del conductor (actual: %s): ", r->conductor);
        fgets(r->conductor, sizeof(r->conductor), stdin);
        r->conductor[strcspn(r->conductor, "\n")] = '\0';
        if (strlen(r->conductor) == 0) {
            printf("Error: El nombre del conductor no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // Empresa - VALIDACION: No vacío
    while (1) {
        printf("Ingrese el nuevo nombre de la empresa (actual: %s): ", r->empresa);
        fgets(r->empresa, sizeof(r->empresa), stdin);
        r->empresa[strcspn(r->empresa, "\n")] = '\0';
        if (strlen(r->empresa) == 0) {
            printf("Error: El nombre de la empresa no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // Origen - VALIDACION: No vacío
    while (1) {
        printf("Ingrese el nuevo origen (actual: %s): ", r->origen);
        fgets(r->origen, sizeof(r->origen), stdin);
        r->origen[strcspn(r->origen, "\n")] = '\0';
        if (strlen(r->origen) == 0) {
            printf("Error: El origen no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // Destino - VALIDACION: No vacío
    while (1) {
        printf("Ingrese el nuevo destino (actual: %s): ", r->destino);
        fgets(r->destino, sizeof(r->destino), stdin);
        r->destino[strcspn(r->destino, "\n")] = '\0';
        if (strlen(r->destino) == 0) {
            printf("Error: El destino no puede estar vacio.\n");
        } else {
            break;
        }
    }

    // Fecha de salida - VALIDACIONES: Formato YYYY-MM-DD, No vacío
    while (1) {
        printf("Ingrese la nueva fecha de salida (actual: %s, Formato YYYY-MM-DD): ", r->fecha_salida);
        fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
        r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';
        if (strlen(r->fecha_salida) == 0) {
            printf("Error: La fecha de salida no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_salida)) {
            printf("Error: Formato de fecha invalido. Use YYYY-MM-DD.\n");
        } else {
            break;
        }
    }

    // Fecha de retorno - VALIDACIONES: Formato YYYY-MM-DD, No vacío, Posterior a fecha de salida
    while (1) {
        printf("Ingrese la nueva fecha de retorno (actual: %s, Formato YYYY-MM-DD): ", r->fecha_retorno);
        fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
        r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';
        if (strlen(r->fecha_retorno) == 0) {
            printf("Error: La fecha de retorno no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_retorno)) {
            printf("Error: Formato de fecha invalido. Use YYYY-MM-DD.\n");
        }
        // VALIDACION EXTRA: Fecha de retorno debe ser posterior o igual a la de salida
        // if (strcmp(r->fecha_retorno, r->fecha_salida) < 0) {
        //     printf("Error: La fecha de retorno no puede ser anterior a la fecha de salida.\n");
        // }
        else {
            break;
        }
    }

    // Costo - VALIDACIONES: Solo números enteros, no negativos
    printf("Ingrese el nuevo costo (actual: %i, solo numeros enteros no negativos): ", r->costo);
    while (scanf("%d", &r->costo) != 1 || r->costo < 0) {
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros no negativos para el costo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    printf("\nRegistro actualizado con exito!\n");
}

// Funcion para buscar un registro por ID
// Retorna la posicion (indice) si lo encuentra, -1 si no existe
int buscarPorID(Registro lista[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        if (strlen(lista[i].id) > 0 && strcmp(lista[i].id, id) == 0) {
            return i; // Registro encontrado en la posicion 'i'
        }
    }
    return -1; // Registro no encontrado
}

// Funcion para "eliminar" logicamente un registro (vacia sus campos)
void eliminarRegistro(Registro *r) {
    strcpy(r->id, "");
    strcpy(r->conductor, "");
    strcpy(r->empresa, "");
    strcpy(r->origen, "");
    strcpy(r->destino, "");
    strcpy(r->fecha_salida, "");
    strcpy(r->fecha_retorno, "");
    r->costo = 0;
}

// Función para guardar los registros en un archivo de texto
void guardarRegistros(Registro lista[], int cantidad, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "w"); // Abre el archivo en modo escritura ("w")
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s para escritura.\n", nombre_archivo);
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        // Solo guarda los registros que no han sido "eliminados" lógicamente
        if (strlen(lista[i].id) > 0) {
            fprintf(archivo, "%s|%s|%s|%s|%s|%s|%s|%d\n",
                    lista[i].id,
                    lista[i].conductor,
                    lista[i].empresa,
                    lista[i].origen,
                    lista[i].destino,
                    lista[i].fecha_salida,
                    lista[i].fecha_retorno,
                    lista[i].costo);
        }
    }

    fclose(archivo); // Cierra el archivo
    printf("\nRegistros guardados con exito en '%s'.\n", nombre_archivo);
}

// Función para cargar los registros desde un archivo de texto
int cargarRegistros(Registro lista[], int max_cantidad, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r"); // Abre el archivo en modo lectura ("r")
    if (archivo == NULL) {
        printf("Advertencia: No se encontro el archivo %s. Se iniciara con registros vacios.\n", nombre_archivo);
        return 0; // No se cargó ningún registro
    }

    int i = 0;
    // Lee línea por línea, usando '|' como delimitador
    while (i < max_cantidad &&
           fscanf(archivo, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n",
                  lista[i].id,
                  lista[i].conductor,
                  lista[i].empresa,
                  lista[i].origen,
                  lista[i].destino,
                  lista[i].fecha_salida,
                  lista[i].fecha_retorno,
                  &lista[i].costo) == 8) { // Verifica que se hayan leído los 8 campos
        i++;
    }

    fclose(archivo); // Cierra el archivo
    printf("\nSe cargaron %d registros desde '%s'.\n", i, nombre_archivo);
    return i; // Retorna la cantidad de registros cargados
}

int main() {
    Registro lista[100]; // Máximo 100 registros
    int cantidad = 0;
    int opcion;
    char idBuscada[20];
    int pos;
    const char *nombre_archivo = "viajes_trans_lara.txt"; // Define el nombre del archivo

    // Cargar registros al inicio del programa
    cantidad = cargarRegistros(lista, 100, nombre_archivo);

    while (1) {
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

        if (scanf("%d", &opcion) != 1) { // Validación de entrada numérica para el menú
            printf("Entrada invalida. Por favor, ingrese un numero del menu.\n");
            limpiarBuffer(); // Limpia el bufer si la entrada no es un entero
            pausar();
            continue; // Vuelve al inicio del bucle para mostrar el menu de nuevo
        }
        limpiarBuffer(); // Limpia el buffer después de scanf

        switch (opcion) {
            case 1: // ANADIR REGISTRO
                if (cantidad < 100) { // Verifica si hay espacio en el arreglo
                    // Pasamos lista y cantidad para la validación de ID único
                    crearRegistro(&lista[cantidad], lista, cantidad);
                    // Solo incrementa la cantidad si el ID no está vacío (registro válido creado)
                    if (strlen(lista[cantidad].id) > 0) {
                        cantidad++;
                    }
                } else {
                    printf("La lista de registros esta llena. No se pueden anadir mas.\n");
                }
                break;

            case 2: // EDITAR REGISTRO
                printf("\n===== BUSCAR REGISTRO PARA EDITAR =====\n");
                printf("Ingrese el ID del registro que desea editar: ");
                fgets(idBuscada, sizeof(idBuscada), stdin);
                idBuscada[strcspn(idBuscada, "\n")] = '\0';

                pos = buscarPorID(lista, cantidad, idBuscada);
                if (pos != -1) {
                    editarRegistro(&lista[pos]);
                } else {
                    printf("Registro con ID '%s' no encontrado. No se pudo editar.\n", idBuscada);
                }
                break;

            case 3: // ELIMINAR REGISTRO
                printf("\n===== BUSCAR REGISTRO PARA ELIMINAR =====\n");
                printf("Ingrese el ID del registro que desea eliminar: ");
                fgets(idBuscada, sizeof(idBuscada), stdin);
                idBuscada[strcspn(idBuscada, "\n")] = '\0';

                pos = buscarPorID(lista, cantidad, idBuscada);
                if (pos != -1) {
                    char confirmacion;
                    printf("¿Esta seguro que desea eliminar el registro con ID '%s'? (s/n): ", idBuscada);
                    scanf(" %c", &confirmacion); // Espacio antes de %c para consumir el \n pendiente
                    limpiarBuffer(); // Limpia el buffer después de scanf

                    if (confirmacion == 's' || confirmacion == 'S') {
                        eliminarRegistro(&lista[pos]); // "Vaciamos" el registro
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
                    printf("\n===== LISTADO DE REGISTROS ACTIVOS =====\n");
                    int registros_activos = 0;
                    for (int i = 0; i < cantidad; i++) {
                        if (strlen(lista[i].id) > 0) { // Solo muestra si el ID no esta vacio (registro activo)
                            mostrarRegistro(lista[i]);
                            registros_activos++;
                        }
                    }
                    if (registros_activos == 0) {
                        printf("No hay registros activos para mostrar. Todos han sido eliminados o la lista esta vacia.\n");
                    }
                }
                break;

            case 5: // SALIR
                // Guardar antes de salir
                guardarRegistros(lista, cantidad, nombre_archivo);
                printf("Saliendo del programa. ¡Hasta luego!\n");
                return 0;

            default: // Opción no válida
                printf("Opcion no valida. Por favor, ingrese un numero del 1 al 5.\n");
                break;
        }
        pausar(); // Pausa despues de cada operacion para que el usuario pueda ver el resultado
    }

    return 0;
}