# Carrera de Autos - Simulación Multihebra

Este programa simula una carrera de autos utilizando hebras (hilos) en C++. Cada auto corre en su propia hebra, avanza una distancia aleatoria y se detiene durante un tiempo aleatorio. La carrera termina cuando todos los autos han llegado a la meta y el programa muestra el orden de llegada.

## Requisitos

- **Sistema operativo**: El programa ha sido desarrollado y probado en **Linux** (Ubuntu).
- **Compilador**: GNU Compiler Collection (`g++`) con soporte para C++11 o superior.
- **Herramientas**:
    - **Visual Studio Code** (opcional, recomendado para desarrollo).
    - **Make** (opcional, para facilitar la compilación).

## Instalación de herramientas necesarias

Para instalar las herramientas necesarias, ejecuta los siguientes comandos en tu terminal:

1. **Instalar `g++`**:
    ```bash
    sudo apt update
    sudo apt install g++
    ```

2. **Instalar Visual Studio Code**:
   - Puedes instalarlo desde el centro de aplicaciones de tu distribución o directamente desde [Visual Studio Code Download](https://code.visualstudio.com/Download).
   - Para usar Visual Studio Code con C++, se recomienda instalar la extensión de C/C++.

3. **Instalar `make` (opcional)**:
    ```bash
    sudo apt install make
    ```

## Como ejecutar el programa en Visual Studio Code

### Compilación

1. Abre el archivo del proyecto en Visual Studio Code.
2. Para configurar la compilación fácilmente, presiona `Ctrl + Shift + B`. Esto creará un archivo `tasks.json` dentro del directorio de tu proyecto (si aún no existe).
3. Compila el programa abierto con `Ctrl + Shift + B`.

### Ejecución

1. Abre una terminal integrada en Visual Studio Code.
2. Ejecuta el programa con el siguiente comando:
   ```bash
   ./carrera <distancia> <numero_autos>
   ```

## Como ejecutar con el Archivo y comando  Make (opcional)

### Compilación

1. Se abre una terminal y se busca la carpeta en donde esta el archivo Makefile.
2. Se ejecuta el comando `make` para compilar el programa.

### Ejecución

1. Si ya tienes la terminal abierta puedes ejecutar el comando: 
   
   ```bash
   ./carreraMake <distancia> <numero_autos>
   ```

## Compilación Manual

Si no tienes o no quieres seguir ninguna de las opciones anteriores puedes compilarlo de manera manual.

### Compilación

1. Abre una terminal en la carpeta donde estan los programas.
2. Ejecuta el comando para compilar el programa:

   ```bash
   g++ -std=c++11 -pthread carrera.cpp -o carrera
   ```

## Ejecución

1. Con la misma terminal lo puedes ejecutar, con el comando: 

   ```bash
   ./carrera <distancia> <numero_autos>
   ```