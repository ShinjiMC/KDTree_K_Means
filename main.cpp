#include "Components/Reader/reader.hpp"
#include "Components/Tester/tester.cpp"
#include <iostream>
#include <chrono>
int main(int argc, char **argv)
{
    if (argc > 1 && std::string(argv[1]) == "--run-tests")
    {
        // Ejecutar las pruebas
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    else
    {
        Reader csv;
        KDTree kdtree(2);
        kdtree = csv.readAndConvert("data2k.csv");
        Direct direct;
        direct = csv.readAndConvertDirect("data2k.csv");
        int n;
        // Menú principal
        std::vector<Vec2D> vecinos;
        int choice;
        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        std::vector<std::vector<Vec2D>> clusters;
        std::chrono::duration<double, std::milli> elapsed;
        do
        {
            std::cout << "\nSeleccione una operacion:" << std::endl;
            std::cout << "1. Imprimir KDTree" << std::endl;
            std::cout << "2. Buscar punto en KDTree" << std::endl;
            std::cout << "3. Buscar punto en Fuerza Bruta" << std::endl;
            std::cout << "4. Buscar N puntos vecinos en KDTree" << std::endl;
            std::cout << "5. Buscar N puntos vecinos en Fuerza Bruta" << std::endl;
            std::cout << "6. Buscar K-Means en KDTree" << std::endl;
            std::cout << "7. Hacer K-Means en Fuerza Bruta" << std::endl;
            std::cout << "8. TESTS" << std::endl;
            std::cout << "9. Salir" << std::endl;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                start = std::chrono::high_resolution_clock::now();
                kdtree.print();
                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 2:
                long double x, y;
                std::cout << "Ingrese las coordenadas (x, y) del punto a buscar: ";
                std::cin >> x >> y;
                start = std::chrono::high_resolution_clock::now();
                kdtree.search(Vec2D(x, y)) ? std::cout << "El punto existe en el KDTree." << std::endl : std::cout << "El punto no existe en el KDTree." << std::endl;
                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 3:
                long double x1, y1;
                std::cout << "Ingrese las coordenadas (x, y) del punto a buscar: ";
                std::cin >> x1 >> y1;
                start = std::chrono::high_resolution_clock::now();
                direct.search(Vec2D(x1, y1)) ? std::cout << "El punto existe en Fuerza Bruta." << std::endl : std::cout << "El punto no existe en Fuerza Bruta." << std::endl;
                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 4:
                std::cout << "Ingrese el numero de puntos a buscar: ";
                std::cin >> n;
                long double x2, y2;
                std::cout << "Ingrese las coordenadas (x, y) del punto a buscar: ";
                std::cin >> x2 >> y2;
                start = std::chrono::high_resolution_clock::now();
                vecinos = kdtree.KNN(Vec2D(x2, y2), n);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los " << n << " puntos vecinos son:" << std::endl;
                for (const auto &c : vecinos)
                {
                    std::cout << "(" << c.getX() << ", " << c.getY() << ")"
                              << " Distance: " << c.distance(Vec2D(x2, y2)) << std::endl;
                }
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 5:
                std::cout << "Ingrese el numero de puntos a buscar: ";
                std::cin >> n;
                long double x3, y3;
                std::cout << "Ingrese las coordenadas (x, y) del punto a buscar: ";
                std::cin >> x3 >> y3;
                start = std::chrono::high_resolution_clock::now();
                vecinos = direct.KNN(Vec2D(x3, y3), n);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los " << n << " puntos vecinos son:" << std::endl;
                for (const auto &c : vecinos)
                {
                    std::cout << "(" << c.getX() << ", " << c.getY() << ")"
                              << " Distance: " << c.distance(Vec2D(x3, y3)) << std::endl;
                }
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 6:
                start = std::chrono::high_resolution_clock::now();
                clusters = kdtree.KMeans(18);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los clusters son:" << std::endl;
                for (int i = 0; i < clusters.size(); i++)
                    std::cout << "Cluster " << i << ":" << clusters[i].size() << std::endl;
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 7:
                start = std::chrono::high_resolution_clock::now();
                clusters = direct.KMeans(18);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los clusters son:" << std::endl;
                for (int i = 0; i < clusters.size(); i++)
                    std::cout << "Cluster " << i << ":" << clusters[i].size() << std::endl;
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 8:
                testing::InitGoogleTest();
                return RUN_ALL_TESTS();
            case 9:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
                break;
            }
        } while (choice != 9);
    }
    return 0;
}