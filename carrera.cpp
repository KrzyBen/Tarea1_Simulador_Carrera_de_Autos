//Librerias
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip> // Formato de salida

std::mutex mtx; //Para la sincronizacion del acceso a la salida

struct Auto {
    int id;
    int lugarFinal;
};

void carreraAuto(int id, int M, int &posicion, std::vector<Auto>& resultados){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distMetros(1,10); // Avance
    std::uniform_int_distribution<> distTiempo(100,500); // Velocidad

    int distanciaRecorrida = 0;

    while(distanciaRecorrida < M){
        int avanzar = distMetros(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(distTiempo(gen)));
        distanciaRecorrida +=avanzar;

        //Bloquear la salida para mostrar el progreso correctamente
        std::lock_guard<std::mutex> lock(mtx);
        std::cout<<"Auto" << id << " avanza " << avanzar << " metros (total: " << std::setw(3) << distanciaRecorrida << " metros)" << std::endl;
    }

    // Al llegar a la meta, registra el lugar de llegada
    {
        std::lock_guard<std::mutex> lock(mtx);
        posicion++;
        resultados[id].lugarFinal = posicion;
        std::cout << "Auto" << id << " termina la carrera en el lugar " << posicion << "!" << std::endl;
    }
}

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cerr << "Uso: " << argv[0] << "<distancia_total> <numero_autos>" << std::endl;
        return 1;
    }

    int M = std::stoi(argv[1]); //Distancia total de la carrera
    int N = std::stoi(argv[2]); // Numero de autos

    std::vector<std::thread> autos;
    int posicion = 0;
    std::vector<Auto> resultados(N); // Almacena el lugar final de cada auto

    // Inicializar los resultados de los autos
    for(int i = 0; i < N; ++i){
        resultados[i].id = i;
        resultados[i].lugarFinal = 0;
    }

    // Crea hebras para cada auto
    for (int i=0; i <N; ++i){
        autos.emplace_back(carreraAuto, i, M, std::ref(posicion), std::ref(resultados));

    }

    //Espera a que todas las hebras terminen
    for(auto &auto_thread : autos){
        auto_thread.join();
    }

    // Muestra el resultado por lugar de llegada
    std::sort(resultados.begin(), resultados.end(), [](const Auto &a, const Auto &b){
        return a.lugarFinal < b.lugarFinal;
    });

    // Muestra los resultados finales
    std::cout << "\n=== Resultados finales ===" << std::endl;
    std::cout << "Lugar   | Auto" << std::endl;
    std::cout << "--------------------" << std::endl;
    for(const auto &autoInfo : resultados){
        std::cout << std::setw(5) << autoInfo.lugarFinal << "  | Auto" << autoInfo.id << std::endl;
    }

    return 0;
}


