#include "Components/Reader/Reader.hpp"
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
        int option;
        Reader csv;
        KDTree kdtree(2);
        Direct direct;
        int n;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "1. 1000 points" << std::endl;
        std::cout << "2. 10000 points" << std::endl;
        std::cout << "3. 20000 points" << std::endl;
        std::cout << "4. TESTS" << std::endl;
        std::cin >> option;
        if (option == 1)
        {
            kdtree = csv.readAndConvert(1);
            direct = csv.readAndConvertDirect(1);
        }
        else if (option == 2)
        {
            kdtree = csv.readAndConvert(2);
            direct = csv.readAndConvertDirect(2);
        }
        else if (option == 3)
        {
            kdtree = csv.readAndConvert(3);
            direct = csv.readAndConvertDirect(3);
        }
        else if (option == 4)
        {
            testing::InitGoogleTest();
            return RUN_ALL_TESTS();
        }
        else
        {
            std::cout << "Opcion invalida." << std::endl;
            return 1;
        }
        // Menú principal
        std::vector<Vec3D> vecinos;
        int choice;
        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed;
        do
        {
            std::cout << "\nSeleccione una operacion:" << std::endl;
            std::cout << "1. Imprimir KDTree" << std::endl;
            std::cout << "2. Buscar punto en KDTree" << std::endl;
            std::cout << "3. Buscar punto en Fuerza Bruta" << std::endl;
            std::cout << "4. Buscar N puntos vecinos en KDTree" << std::endl;
            std::cout << "5. Buscar N puntos vecinos en Fuerza Bruta" << std::endl;
            std::cout << "6. Salir" << std::endl;
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
                int x, y, z;
                std::cout << "Ingrese las coordenadas (x, y, z) del punto a buscar: ";
                std::cin >> x >> y >> z;
                start = std::chrono::high_resolution_clock::now();
                kdtree.search(Vec3D(x, y, z)) ? std::cout << "El punto existe en el KDTree." << std::endl : std::cout << "El punto no existe en el KDTree." << std::endl;
                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 3:
                int x1, y1, z1;
                std::cout << "Ingrese las coordenadas (x, y, z) del punto a buscar: ";
                std::cin >> x1 >> y1 >> z1;
                start = std::chrono::high_resolution_clock::now();
                direct.search(Vec3D(x1, y1, z1)) ? std::cout << "El punto existe en Fuerza Bruta." << std::endl : std::cout << "El punto no existe en Fuerza Bruta." << std::endl;
                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 4:
                std::cout << "Ingrese el numero de puntos a buscar: ";
                std::cin >> n;
                int x2, y2, z2;
                std::cout << "Ingrese las coordenadas (x, y, z) del punto a buscar: ";
                std::cin >> x2 >> y2 >> z2;
                start = std::chrono::high_resolution_clock::now();
                vecinos = kdtree.KNN(Vec3D(x2, y2, z2), n);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los " << n << " puntos vecinos son:" << std::endl;
                for (const auto &c : vecinos)
                {
                    std::cout << "(" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")"
                              << " Distance: " << c.distance(Vec3D(x2, y2, z2)) << std::endl;
                }

                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 5:
                std::cout << "Ingrese el numero de puntos a buscar: ";
                std::cin >> n;
                int x3, y3, z3;
                std::cout << "Ingrese las coordenadas (x, y, z) del punto a buscar: ";
                std::cin >> x3 >> y3 >> z3;
                start = std::chrono::high_resolution_clock::now();
                vecinos = direct.KNN(Vec3D(x3, y3, z3), n);
                end = std::chrono::high_resolution_clock::now();
                std::cout << "Los " << n << " puntos vecinos son:" << std::endl;
                for (const auto &c : vecinos)
                {
                    std::cout << "(" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")"
                              << " Distance: " << c.distance(Vec3D(x3, y3, z3)) << std::endl;
                }
                elapsed = end - start;
                std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
                break;
            }
        } while (choice != 6);
    }
    return 0;
}