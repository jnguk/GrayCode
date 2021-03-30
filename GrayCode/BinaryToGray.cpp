#include <iostream>
#include <string>

std::string newBinToGray(std::string binary);
std::string newGrayToBin(std::string gray);
std::string newInsertBar(std::string binary);

int main()
{
    while (true)
    {
        std::string binary;
        std::string gray;

        std::cout << "binary: ";
        std::cin >> binary;

        std::cout << std::endl
                  << "binary:\t\t" << newInsertBar(binary) << std::endl;

        gray = newBinToGray(binary);
        std::cout << "gray:\t\t" << newInsertBar(gray) << std::endl;
        std::cout << "grayToBin:\t" << newInsertBar(newGrayToBin(gray)) << std::endl;

        std::cout << std::endl;
    }

    return 0;
}

std::string newBinToGray(std::string binary)
{
    std::string temp;

    temp.insert(0, 1, binary[0]);

    for (int i = 1; i < binary.length(); i++)
    {
        temp.insert(i, 1, ((binary[i - 1] == binary[i]) ? '0' : '1'));
        if (binary[i + 1] == '\0')
            break;
    }

    return temp;
}

std::string newGrayToBin(std::string gray)
{
    std::string temp;

    temp.insert(0, 1, gray[0]);

    for (int i = 1; i < gray.length(); i++)
    {
        temp.insert(i, 1, ((temp[i - 1] == gray[i]) ? '0' : '1'));
        if (gray[i + 1] == '\0')
            break;
    }

    return temp;
}

std::string newInsertBar(std::string binary)
{
    std::string temp = binary;

    for (int i = temp.length() - 4; i > 0; i -= 4)
    {
        temp.insert(i, "_");
    }

    return temp;
}