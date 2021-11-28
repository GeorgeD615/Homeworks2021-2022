#include <iostream>
#include <bitset>
#include <fstream>

void createPicture(const char src_file_name[256], const char dest_file_name[256], int rows, int cols)
{
    std::ifstream DataFile(src_file_name, std::ios_base::in | std::ios_base::binary);
    std::ofstream PictureFile(dest_file_name, std::ios_base::out);
    if (DataFile && PictureFile)
    {
       unsigned char ch;
       while(DataFile.peek() != EOF)
       {    
            ch = DataFile.get();
            if (ch == 10){
                PictureFile << '\n';
            }
            else
            {
                std::bitset<8> binArr(ch);
                for (int i = 7; i >= 0; i--)
                {
                    if (binArr[i] == 1)
                    {
                        PictureFile << '*';
                    }
                    else
                    {
                        PictureFile << ' ';
                    }
                }
            }
        }
    }
    else
        std::cout << "Error" << std::endl;
    DataFile.close();
    PictureFile.close();
}


int main()
{
    char src_file_name[256], dest_file_name[256];

    std::cout << "Input file name with data: ";
    std::cin.getline(src_file_name, 256);

    std::cout << "Input file name with picture: ";
    std::cin.getline(dest_file_name, 256);
    int rows, cols;
    std::cout << "Input size of the picture " << std::endl;
    std::cout << "rows: ";
    std::cin >> rows;
    std::cout << "columns ";
    std::cin >> cols; 
    
    createPicture(src_file_name, dest_file_name, rows, cols);
}
