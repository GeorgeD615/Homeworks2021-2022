#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    //Вывод аргументов командной строки
    std::cout << "My arguments: " << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << " - " << argv[i] << std::endl;
    }

    //Создание файла для записи данных
    std::ofstream outFile(argv[1], std::ios_base::binary);
    if (!outFile) {
        std::cout << "Can not open file " << argv[1] << std::endl;
        return 1;
    }

    //Создание файла для получения данных
    std::ifstream inFile(argv[2],std::ios_base::binary);
    if (!inFile) {
        std::cout << "Can not open file " << argv[2] << std::endl;
        outFile.close();
        return 2;
    }

    //Узнать размер файла с помощью файловых указателей
    /*
    outFile << "My list:" << '\n' << "first" << '\n' << "second" << '\n' << "third";
    outFile.seekp(0, std::ios_base::beg);//переносим указатель put в начало файла
    int begin = outFile.tellp();
    outFile.seekp(0, std::ios_base::end);//переносим указатель put в конец файла
    int end = outFile.tellp();
    std::cout << "Size of file " << argv[1] << " - " << end - begin << "bytes" << std::endl;//размер файла
    */

    //Создание двумерного массива (MyArray) для отправления в файл
    /*int rows = 5;
    int cols = 5;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100;
        }
    }
    std::cout << "My Array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    */

    //Запись массива (MyArray) в файл outFile.txt
    /*
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int c = arr[i][j];
            outFile.write((char*)&c, sizeof(c));
            outFile << ' ';
        }
        outFile << '\n';
    }
    std::cout << "My Array goes to " << argv[1] << std::endl;
    */

    //Получение элемента из бинарного массива по заданным индексам
    //Введение координат
    int l, c;
    char e;
    std::cout << "Input indices of element what you want to take from " << argv[3] << std::endl;
    do {
        std::cout << "Input line (from 1 to 4): ";
        std::cin >> l;
    } while (l > 4 || l < 1);
    do {
        std::cout << "Input column (from 1 to 6): ";
        std::cin >> c;
    } while (c > 6 || c < 1);
    std::ifstream fileWithArray;
    fileWithArray.open(argv[3], std::ios_base::in);//Открытие файла с бинарным массивом из 4 строк и 6 столбцов
    fileWithArray.seekg((l-1)*6+c-1,std::ios_base::beg);//Перенос указателя get на место элемента массива с введёнными индексами
    e = fileWithArray.get();
    std::cout << '(' << l << ',' << c << ") = " << e << std::endl;
    fileWithArray.close();

    //Вывод каждого 4-го байта файла
    char byte4;
    int step = 4;
    std::ifstream file4bytes;
    file4bytes.open(argv[4], std::ios_base::in);//Открытие файла с буквой "b" в каждом 4-ом байте 
    //Узнаём размер файла
    file4bytes.seekg(0, std::ios_base::beg);//переносим указатель put в начало файла
    int begin = file4bytes.tellg();
    file4bytes.seekg(0, std::ios_base::end);//переносим указатель put в конец файла
    int end = file4bytes.tellg();
    int size = end - begin; //Находим размер файла
    file4bytes.seekg(0, std::ios_base::beg);//возвращаем указатель put в начало
    byte4 = file4bytes.get();
    while (!file4bytes.eof()) {
        std::cout << byte4;
        if ((int(file4bytes.tellg()) + step) > size) break; //если следующим через 4 байта файл закончится прерываем цикл
        file4bytes.seekg(step, std::ios_base::cur);//Перенос указателя get на 4 байта вперёд
    }
    file4bytes.close();
    std::cout << std::endl;
    std::cout << "If every simbol is 'b' then code correct" << std::endl;
    //Чтение BMP файла
    std::ifstream fileWithPicture;
    file4bytes.open(argv[5], std::ios_base::in);
    file4bytes.seekg(19,std::ios_base::beg);
    int n = 4;
    //Создаем буффер
    char* buffer = new char[4];
    //Читаем в него байты
    file4bytes.read(buffer, 4);
    //выводим их на экран
    std::cout << buffer;
    delete[] buffer;
    file4bytes.close();
}
