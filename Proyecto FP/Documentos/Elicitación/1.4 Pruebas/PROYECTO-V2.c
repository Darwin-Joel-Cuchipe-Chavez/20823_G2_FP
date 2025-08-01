// MINICRUD REGISTRO DE VIAJES TRANS LARA IVAN EXPRESS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

// --- DEFINICION DE ESTRUCTURAS ---
typedef struct {
    char id[8];                 // ID del viaje (Formato VJE001, maximo 6 caracteres + '\0')
    char descripcion[201];      // Descripcion de la carga (maximo 200 caracteres + '\0')
    int cantidad;               // Cantidad (entero)
    char conductor[50];         // Nombre del conductor (maximo 49 caracteres + '\0')
    char vehiculo[51];          // Tipo de vehiculo (ej. Camion, Furgoneta, maximo 50 caracteres + '\0')
    char placa[9];              // Placa del vehiculo (formato PPP-0000, maximo 8 caracteres + '\0')
    char empresa[50];           // Empresa a la que se realiza el viaje (maximo 49 caracteres + '\0')
    char origen[50];            // Origen del viaje (ciudad) (maximo 49 caracteres + '\0')
    char destino[50];           // Destino del viaje (ciudad) (maximo 49 caracteres + '\0')
    char fecha_salida[50];      // Fecha de inicio del viaje (Formato YYYY-MM-DD) (maximo 49 caracteres + '\0')
    char fecha_retorno[50];     // Fecha de retorno (Formato YYYY-MM-DD) (maximo 49 caracteres + '\0')
    int costo;                  // Costo del viaje (entero)
    char observaciones[201];    // Observaciones adicionales (opcional, maximo 200 caracteres + '\0')
} Registro;

// --- PROTOTIPOS DE FUNCIONES ---
void pausar();
void limpiarBuffer();
void limpiarPantalla();
int validarFecha(const char *fecha);
int validarPlaca(const char *placa); // Nueva: Validar formato de placa
int buscarPorID(Registro lista[], int n, char id[]);
void crearRegistro(Registro *r, Registro lista[], int cantidad);
void mostrarRegistro(Registro r);
void editarRegistro(Registro *r);
void eliminarRegistro(Registro *r);
void guardarRegistros(Registro lista[], int cantidad, const char *nombre_archivo);
int cargarRegistros(Registro lista[], int max_cantidad, const char *nombre_archivo);

// --- IMPLEMENTACION DE FUNCIONES AUXILIARES ---

// Pausa la ejecucion del programa.
void pausar() {
    printf("\nPresione Enter para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpia el buffer de entrada.
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpia la pantalla de la consola.
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Valida el formato YYYY-MM-DD.
// Retorna 1 si la fecha es valida, 0 si no.
int validarFecha(const char *fecha) {
    int year, month, day;
    if (sscanf(fecha, "%d-%d-%d", &year, &month, &day) != 3) {
        return 0; // Formato incorrecto
    }
    if (year < 2000 || year>2025) {
        return 0; // Año menor a 2000 o mayor a 2025
    }
    if (month < 1 || month > 12) {
        return 0; // Mes fuera de rango
    }
    // Validar días según el mes
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0 es un placeholder

    if (day<1 || day > daysInMonth[month]) {
        return 0; // Día fuera de rango para el mes
    }
    return 1; // Fecha válida
}

int compararFechas(const char *fecha1_str, const char *fecha2_str) {
    int y1, m1, d1, y2, m2, d2;
    sscanf(fecha1_str, "%d-%d-%d", &y1, &m1, &d1);
    sscanf(fecha2_str, "%d-%d-%d", &y2, &m2, &d2);

    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;
    return d1 - d2;
}

// Valida el formato de la placa del vehiculo (PPP-000 o PPP-0000).
// Retorna 1 si la placa es valida, 0 si no.
int validarPlaca(const char *placa) {
    int len = strlen(placa);
    if (len != 8) {
        return 0;
    }
    return 1;
}

// Busca un registro por su ID unico.
// Retorna el indice (posicion) si lo encuentra, -1 si no existe.
int buscarPorID(Registro lista[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        if (strlen(lista[i].id) > 0 && strcmp(lista[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// --- IMPLEMENTACION DE FUNCIONES CRUD ---

// Permite al usuario ingresar los datos para crear un nuevo registro de viaje.
void crearRegistro(Registro *r, Registro lista[], int cantidad) {
    limpiarPantalla();
    printf("\n===== FORMULARIO DE NUEVO REGISTRO DE VIAJE =====\n");
    char temp_input[205]; // Buffer temporal para inputs

    // 1. ID del viaje - VALIDACIONES: Longitud, No vacío, Único
    do {
        printf("1. Ingrese el ID unico del viaje (ej. VJE001, maximo 6 caracteres): ");
        fgets(temp_input, sizeof(temp_input), stdin);
        temp_input[strcspn(temp_input, "\n")] = '\0';
        strcpy(r->id, temp_input);
        if (strlen(r->id) == 0) {
            printf("Error: El ID no puede estar vacio.\n");
        } else if (strlen(r->id) != 6) {
            printf("Error: El ID no cumple con los 6 caracteres. Ejemplo: VJE001\n");
        } else if (buscarPorID(lista, cantidad, r->id) != -1) {
            printf("Error: El ID '%s' ya existe. Por favor, ingrese un ID unico.\n", r->id);
        }
    } while (strlen(r->id) == 0 || strlen(r->id) != 6 || buscarPorID(lista, cantidad, r->id) != -1);

    // 2. Descripcion - VALIDACION: No vacia
    do {
        printf("2. Ingrese la descripcion de la carga (maximo 200 caracteres): ");
        fgets(r->descripcion, sizeof(r->descripcion), stdin);
        r->descripcion[strcspn(r->descripcion, "\n")] = '\0';
        if (strlen(r->descripcion) == 0) {
            printf("Error: La descripcion de la carga no puede estar vacia.\n");
        }
    } while (strlen(r->descripcion) == 0);

    // 3. Cantidad - VALIDACION: Solo numeros, no negativos
    printf("3. Ingrese la cantidad de la carga (solo numeros no negativos, puede ser decimal): ");
    while (scanf("%d", &r->cantidad) != 1 || r->cantidad < 0) {
        printf("Entrada invalida. Por favor, ingrese un numero no negativo para la cantidad: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    // 4. Conductor - VALIDACION: No vacio
    do {
        printf("4. Ingrese el nombre completo del conductor asignado (maximo 49 caracteres): ");
        fgets(r->conductor, sizeof(r->conductor), stdin);
        r->conductor[strcspn(r->conductor, "\n")] = '\0';
        if (strlen(r->conductor) == 0) {
            printf("Error: El nombre del conductor no puede estar vacio.\n");
        }
    } while (strlen(r->conductor) == 0);

    // 5. Vehiculo - VALIDACION: No vacio
    do {
        printf("5. Ingrese el tipo de vehiculo (ej. Camion, Furgoneta, maximo 50 caracteres): ");
        fgets(r->vehiculo, sizeof(r->vehiculo), stdin);
        r->vehiculo[strcspn(r->vehiculo, "\n")] = '\0';
        if (strlen(r->vehiculo) == 0) {
            printf("Error: El tipo de vehiculo no puede estar vacio.\n");
        }
    } while (strlen(r->vehiculo) == 0);

    // 6. Placa del vehiculo - VALIDACIONES: Formato PPP-000 o PPP-0000, No vacia
    do {
        printf("6. Ingrese la placa del vehiculo (Formato PPP-0000, maximo 8 caracteres): ");
        fgets(r->placa, sizeof(r->placa), stdin);
        r->placa[strcspn(r->placa, "\n")] = '\0';
        if (strlen(r->placa) == 0) {
            printf("Error: La placa no puede estar vacia.\n");
        } else if (!validarPlaca(r->placa)) {
            printf("Error: Formato de placa invalido. Use PPP-0000 (ej. ABC-123, XYZ-9876).\n");
        }
    } while (strlen(r->placa) == 0 || !validarPlaca(r->placa));

    // 7. Empresa - VALIDACION: No vacio
    do {
        printf("7. Ingrese el nombre de la empresa a la que se realizo el viaje (maximo 49 caracteres): ");
        fgets(r->empresa, sizeof(r->empresa), stdin);
        r->empresa[strcspn(r->empresa, "\n")] = '\0';
        if (strlen(r->empresa) == 0) {
            printf("Error: El nombre de la empresa no puede estar vacio.\n");
        }
    } while (strlen(r->empresa) == 0);

    // 8. Origen - VALIDACION: No vacio
    do {
        printf("8. Ingrese la ciudad de origen del viaje (ej. Quito, maximo 49 caracteres): ");
        fgets(r->origen, sizeof(r->origen), stdin);
        r->origen[strcspn(r->origen, "\n")] = '\0';
        if (strlen(r->origen) == 0) {
            printf("Error: El origen no puede estar vacio.\n");
        }
    } while (strlen(r->origen) == 0);

    // 9. Destino - VALIDACION: No vacio
    do {
        printf("9. Ingrese la ciudad de destino del viaje (ej. Guayaquil, maximo 49 caracteres): ");
        fgets(r->destino, sizeof(r->destino), stdin);
        r->destino[strcspn(r->destino, "\n")] = '\0';
        if (strlen(r->destino) == 0) {
            printf("Error: El destino no puede estar vacio.\n");
        }
    } while (strlen(r->destino) == 0);

    // 10. Fecha de salida - VALIDACIONES: Formato YYYY-MM-DD, No vacia
    do {
        printf("10. Ingrese la fecha de salida del viaje (Formato YYYY-MM-DD, maximo 49 caracteres): ");
        fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
        r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';
        if (strlen(r->fecha_salida) == 0) {
            printf("Error: La fecha de salida no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_salida)) { // Esta función debe validar formato, año, mes, día
            printf("Error: Formato o fecha invalida. Use YYYY-MM-DD, con anio >= 2000, mes entre 1-12 y dias validos para el mes.\n");
        }
    } while (strlen(r->fecha_salida) == 0 || !validarFecha(r->fecha_salida));

    // 11. Fecha de retorno - VALIDACIONES: Formato YYYY-MM-DD, No vacia
    do {
        printf("10. Ingrese la nueva fecha de retorno (actual: %s, Formato YYYY-MM-DD): ", r->fecha_retorno);
        fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
        r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';
        if (strlen(r->fecha_retorno) == 0) {
            printf("Error: La fecha de retorno no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_retorno)) { // Esta función ya valida formato, año, mes, día
            printf("Error: Formato o fecha invalida. Use YYYY-MM-DD, con anio >= 2000, mes entre 1-12 y dias validos para el mes.\n");
        } else if (compararFechas(r->fecha_retorno, r->fecha_salida) < 0) { // Validar que retorno no sea menor que salida
            printf("Error: La fecha de retorno no puede ser anterior a la fecha de salida (%s).\n", r->fecha_salida);
        }
    } while (strlen(r->fecha_retorno) == 0 || !validarFecha(r->fecha_retorno) || compararFechas(r->fecha_retorno, r->fecha_salida) < 0);

    // 12. Costo - VALIDACIONES: Solo numeros enteros, no negativos
    printf("12. Ingrese el costo total del viaje (solo numeros enteros no negativos): ");
    while (scanf("%d", &r->costo) != 1 || r->costo < 0) {
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros no negativos para el costo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    // 13. Observaciones adicionales - Opcional
    do {
        printf("13. Ingrese observaciones adicionales (opcional (Si no existe coloque: NN), maximo 200 caracteres): ");
        fgets(r->observaciones, sizeof(r->observaciones), stdin);
        r->observaciones[strcspn(r->observaciones, "\n")] = '\0';
        if (strlen(r->observaciones) == 0) {
            printf("Error: Las observaciones no pueden estar vacias. Si no existen, por favor, coloque 'NN'.\n");
        }
    } while (strlen(r->observaciones) == 0);

    printf("\n" GREEN "Registro de viaje creado con exito!\n" RESET);
}

// Muestra todos los detalles de un registro de viaje.
void mostrarRegistro(Registro r) {
    if (strlen(r.id) == 0) {
        return; // No muestra registros "logicamente eliminados"
    }
    printf("\n===== DETALLES DEL REGISTRO =====\n");
    printf("ID: %s\n", r.id);
    printf("Descripcion de Carga: %s\n", r.descripcion);
    printf("Cantidad: %i\n", r.cantidad);
    printf("Conductor: %s\n", r.conductor);
    printf("Vehiculo: %s\n", r.vehiculo);
    printf("Placa: %s\n", r.placa);
    printf("Empresa: %s\n", r.empresa);
    printf("Origen: %s\n", r.origen);
    printf("Destino: %s\n", r.destino);
    printf("Fecha de Salida: %s\n", r.fecha_salida);
    printf("Fecha de Retorno: %s\n", r.fecha_retorno);
    printf("Costo del Viaje: %i\n", r.costo);
    printf("Observaciones: %s\n", r.observaciones);
    printf("==============================\n");
}

// Permite al usuario modificar los campos de un registro existente.
void editarRegistro(Registro *r) {
    limpiarPantalla();
    printf("\n===== EDITAR REGISTRO =====\n");
    printf("Estas editando el registro con ID: %s\n", r->id);
    printf("El ID no se puede cambiar.\n");

    // 1. Descripcion de la carga
    do {
        printf("1. Ingrese la nueva descripcion de la carga (actual: %s, maximo 200 caracteres): ", r->descripcion);
        fgets(r->descripcion, sizeof(r->descripcion), stdin);
        r->descripcion[strcspn(r->descripcion, "\n")] = '\0';
        if (strlen(r->descripcion) == 0) {
            printf("Error: La descripcion de la carga no puede estar vacia.\n");
        }
    } while (strlen(r->descripcion) == 0);

    // 2. Cantidad
    printf("2. Ingrese la nueva cantidad de la carga (actual: %d, solo numeros no negativos): ", r->cantidad);
    while (scanf("%d", &r->cantidad) != 1 || r->cantidad < 0) {
        printf("Entrada invalida. Por favor, ingrese un numero no negativo para la cantidad: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    // 3. Conductor
    do {
        printf("3. Ingrese el nuevo nombre del conductor (actual: %s, maximo 49 caracteres): ", r->conductor);
        fgets(r->conductor, sizeof(r->conductor), stdin);
        r->conductor[strcspn(r->conductor, "\n")] = '\0';
        if (strlen(r->conductor) == 0) {
            printf("Error: El nombre del conductor no puede estar vacio.\n");
        }
    } while (strlen(r->conductor) == 0);

    // 4. Vehiculo
    do {
        printf("4. Ingrese el nuevo tipo de vehiculo (actual: %s, maximo 50 caracteres): ", r->vehiculo);
        fgets(r->vehiculo, sizeof(r->vehiculo), stdin);
        r->vehiculo[strcspn(r->vehiculo, "\n")] = '\0';
        if (strlen(r->vehiculo) == 0) {
            printf("Error: El tipo de vehiculo no puede estar vacio.\n");
        }
    } while (strlen(r->vehiculo) == 0);

    // 5. Placa del vehiculo
    do {
        printf("5. Ingrese la nueva placa del vehiculo (actual: %s, Formato PPP-000 o PPP-0000, maximo 8 caracteres): ", r->placa);
        fgets(r->placa, sizeof(r->placa), stdin);
        r->placa[strcspn(r->placa, "\n")] = '\0';
        if (strlen(r->placa) == 0) {
            printf("Error: La placa no puede estar vacia.\n");
        } else if (!validarPlaca(r->placa)) {
            printf("Error: Formato de placa invalido. Use PPP-000 o PPP-0000 (ej. ABC-123, XYZ-9876).\n");
        }
    } while (strlen(r->placa) == 0 || !validarPlaca(r->placa));

    // 6. Empresa
    do {
        printf("6. Ingrese el nuevo nombre de la empresa (actual: %s, maximo 49 caracteres): ", r->empresa);
        fgets(r->empresa, sizeof(r->empresa), stdin);
        r->empresa[strcspn(r->empresa, "\n")] = '\0';
        if (strlen(r->empresa) == 0) {
            printf("Error: El nombre de la empresa no puede estar vacio.\n");
        }
    } while (strlen(r->empresa) == 0);

    // 7. Origen
    do {
        printf("7. Ingrese el nuevo origen (actual: %s, maximo 49 caracteres): ", r->origen);
        fgets(r->origen, sizeof(r->origen), stdin);
        r->origen[strcspn(r->origen, "\n")] = '\0';
        if (strlen(r->origen) == 0) {
            printf("Error: El origen no puede estar vacio.\n");
        }
    } while (strlen(r->origen) == 0);

    // 8. Destino
    do {
        printf("8. Ingrese el nuevo destino (actual: %s, maximo 49 caracteres): ", r->destino);
        fgets(r->destino, sizeof(r->destino), stdin);
        r->destino[strcspn(r->destino, "\n")] = '\0';
        if (strlen(r->destino) == 0) {
            printf("Error: El destino no puede estar vacio.\n");
        }
    } while (strlen(r->destino) == 0);

    // 9. Fecha de salida
    do {
        printf("9. Ingrese la nueva fecha de salida (actual: %s, Formato YYYY-MM-DD): ", r->fecha_salida);
        fgets(r->fecha_salida, sizeof(r->fecha_salida), stdin);
        r->fecha_salida[strcspn(r->fecha_salida, "\n")] = '\0';
        if (strlen(r->fecha_salida) == 0) {
            printf("Error: La fecha de salida no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_salida)) {
            printf("Error: Formato o fecha invalida. Use YYYY-MM-DD, con anio >= 2000, mes entre 1-12 y dias validos para el mes.\n");
        }
    } while (strlen(r->fecha_salida) == 0 || !validarFecha(r->fecha_salida));

    // 10. Fecha de retorno
    do {
        printf("10. Ingrese la nueva fecha de retorno (actual: %s, Formato YYYY-MM-DD): ", r->fecha_retorno);
        fgets(r->fecha_retorno, sizeof(r->fecha_retorno), stdin);
        r->fecha_retorno[strcspn(r->fecha_retorno, "\n")] = '\0';

        // Validaciones
        if (strlen(r->fecha_retorno) == 0) {
            printf("Error: La fecha de retorno no puede estar vacia.\n");
        } else if (!validarFecha(r->fecha_retorno)) { // Esta función ya valida formato, año, mes, día
            printf("Error: Formato o fecha invalida. Use YYYY-MM-DD, con anio >= 2000, mes entre 1-12 y dias validos para el mes.\n");
        } else if (compararFechas(r->fecha_retorno, r->fecha_salida) < 0) { // Validar que retorno no sea menor que salida
            printf("Error: La fecha de retorno no puede ser anterior a la fecha de salida (%s).\n", r->fecha_salida);
        }
    } while (strlen(r->fecha_retorno) == 0 || !validarFecha(r->fecha_retorno) || compararFechas(r->fecha_retorno, r->fecha_salida) < 0);

    // 11. Costo
    printf("11. Ingrese el nuevo costo (actual: %i, solo numeros enteros no negativos): ", r->costo);
    while (scanf("%d", &r->costo) != 1 || r->costo < 0) {
        printf("Entrada invalida. Por favor, ingrese solo numeros enteros no negativos para el costo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    // 12. Observaciones adicionales
    do {
        printf("12. Ingrese nuevas observaciones adicionales (actual: %s, opcional (Si no existe coloque: NN), maximo 200 caracteres): ", r->observaciones);
        fgets(r->observaciones, sizeof(r->observaciones), stdin);
        r->observaciones[strcspn(r->observaciones, "\n")] = '\0';
        if (strlen(r->observaciones) == 0) {
            printf("Error: Las observaciones no pueden estar vacias. Si no existen, por favor, coloque 'NN'.\n");
        }
    } while (strlen(r->observaciones) == 0);

    printf("\n" GREEN "Registro actualizado con exito!\n" RESET);
}

// "Elimina" logicamente un registro vaciando todos sus campos.
void eliminarRegistro(Registro *r) {
    strcpy(r->id, "");
    strcpy(r->descripcion, "");
    r->cantidad = 0;
    strcpy(r->conductor, "");
    strcpy(r->vehiculo, "");
    strcpy(r->placa, "");
    strcpy(r->empresa, "");
    strcpy(r->origen, "");
    strcpy(r->destino, "");
    strcpy(r->fecha_salida, "");
    strcpy(r->fecha_retorno, "");
    r->costo = 0;
    strcpy(r->observaciones, "");
}

// --- IMPLEMENTACION DE FUNCIONES DE PERSISTENCIA ---

// Guarda la lista de registros activos en un archivo de texto, usando '|' como delimitador.
void guardarRegistros(Registro lista[], int cantidad, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf(RED "Error: No se pudo abrir el archivo '%s' para escritura.\n" RESET, nombre_archivo);
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        if (strlen(lista[i].id) > 0) { // Solo guarda registros que no han sido logicamente eliminados
            fprintf(archivo, "%s|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%d|%s\n",
                    lista[i].id,
                    lista[i].descripcion,
                    lista[i].cantidad,
                    lista[i].conductor,
                    lista[i].vehiculo,
                    lista[i].placa,
                    lista[i].empresa,
                    lista[i].origen,
                    lista[i].destino,
                    lista[i].fecha_salida,
                    lista[i].fecha_retorno,
                    lista[i].costo,
                    lista[i].observaciones);
        }
    }

    fclose(archivo);
    printf(GREEN "\nRegistros guardados con exito en '%s'.\n" RESET, nombre_archivo);
}

// Carga registros desde un archivo de texto.
int cargarRegistros(Registro lista[], int max_cantidad, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Advertencia: No se encontro el archivo '%s'. Se iniciara con registros vacios.\n", nombre_archivo);
        return 0;
    }

    int i = 0;
    // Lee linea por linea, esperando 13 campos separados por '|' o '\n'
    while (i < max_cantidad &&
           fscanf(archivo, "%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^\n]\n",
                   lista[i].id,
                   lista[i].descripcion,
                   &lista[i].cantidad,
                   lista[i].conductor,
                   lista[i].vehiculo,
                   lista[i].placa,
                   lista[i].empresa,
                   lista[i].origen,
                   lista[i].destino,
                   lista[i].fecha_salida,
                   lista[i].fecha_retorno,
                   &lista[i].costo,
                   lista[i].observaciones) == 13) { // Ahora esperamos 13 campos
        i++;
    }

    fclose(archivo);
    printf(GREEN "\nSe cargaron %d registros desde '%s'.\n" RESET, i, nombre_archivo);
    return i;
}

// --- FUNCION PRINCIPAL ---

int main() {
    Registro lista[100];
    int cantidad = 0;
    int opcion = 0;
    char idBuscada[8]; // Tamaño ajustado para el ID
    int pos;
    const char *nombre_archivo = "viajes_trans_lara.txt";

    // Cargar registros existentes al inicio del programa
    cantidad = cargarRegistros(lista, 100, nombre_archivo);

    // Bucle principal del menu
    while (opcion != 6) {
        limpiarPantalla();
        printf("====================================================\n");
        printf("  BIENVENIDO AL SISTEMA DE REGISTRO DE VIAJES       \n");
        printf("        TRANS LARA IVAN EXPRESS!                    \n");
        printf("====================================================\n");
        printf("  Gestiona tus viajes de manera eficiente y sencilla.\n");
        printf("  Selecciona una opcion del menu para comenzar.     \n");
        printf("====================================================\n");
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. ANADIR NUEVO REGISTRO\n");
        printf("2. EDITAR REGISTRO EXISTENTE\n");
        printf("3. ELIMINAR REGISTRO\n");
        printf("4. MOSTRAR TODOS LOS REGISTROS\n");
        printf("5. GUARDAR CAMBIOS EN ARCHIVO\n");
        printf("6. SALIR DEL PROGRAMA\n");
        printf("Opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero del menu.\n");
            limpiarBuffer();
            pausar();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: // ANADIR REGISTRO
                if (cantidad < 100) {
                    crearRegistro(&lista[cantidad], lista, cantidad);
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
                    printf(RED "Registro con ID '%s' no encontrado. No se pudo editar.\n" RESET, idBuscada);
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
                    scanf(" %c", &confirmacion);
                    limpiarBuffer();

                    if (confirmacion == 's' || confirmacion == 'S') {
                        eliminarRegistro(&lista[pos]);
                        printf(GREEN "Registro con ID '%s' eliminado con exito.\n" RESET, idBuscada);
                    } else {
                        printf(YELLOW "Eliminacion cancelada. El registro no fue modificado.\n" RESET);
                    }
                } else {
                    printf(RED "Registro con ID '%s' no encontrado. No se pudo eliminar.\n" RESET, idBuscada);
                }
                break;

            case 4: // MOSTRAR REGISTROS
                if (cantidad == 0) {
                    printf(YELLOW "\nNo hay registros guardados para mostrar. Anada uno primero.\n" RESET);
                } else {
                    printf("\n===== LISTADO DE REGISTROS ACTIVOS =====\n");
                    int registros_activos = 0;
                    for (int i = 0; i < cantidad; i++) {
                        if (strlen(lista[i].id) > 0) {
                            mostrarRegistro(lista[i]);
                            registros_activos++;
                        }
                    }
                    if (registros_activos == 0) {
                        printf(RED "No hay registros activos para mostrar. Todos han sido eliminados o la lista esta vacia.\n" RESET);
                    }
                }
                break;

            case 5: // GUARDAR CAMBIOS
                guardarRegistros(lista, cantidad, nombre_archivo);
                break;

            case 6: // SALIR DEL PROGRAMA
                printf(GREEN "SALIENDO DEL PROGRAMA... ¡HASTA LUEGO!\n" RESET);
                break;

            default:
                printf(YELLOW "Opcion no valida. Por favor, ingrese un numero del 1 al 6.\n" RESET);
                break;
        }
        if (opcion != 6) {
            pausar();
        }
    }
    return 0;
}
