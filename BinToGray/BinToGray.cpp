#include <iostream>
#include <string>

std::string BinToGray(std::string binary);
std::string GrayToBin(std::string gray);
std::string InsertBar(std::string binary);

int main()
{
	while (true)
	{
		std::string input;

		std::cout << "binary or gray: ";
		std::cin >> input;
		
		std::cout << std::endl << "Origin:\t\t\t" << InsertBar(input) << std::endl << std::endl;

		const auto toGray = BinToGray(input);
		const auto toBin = GrayToBin(input);
		
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "Bin -> Gray:\t\t" << InsertBar(toGray) << std::endl;
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "Gray -> Bin:\t\t" << InsertBar(toBin) << std::endl;
		std::cout << std::string(50, '-') << std::endl << std::endl;

		std::cout << "Convert -> Origin:\t" << InsertBar(GrayToBin(toGray)) << std::endl;
		std::cout << "Convert -> Origin:\t" << InsertBar(BinToGray(toBin)) << std::endl;
		
		std::cout << std::string(50, '=') << std::endl << std::endl;
	}

	return 0;
}


std::string BinToGray(std::string binary)
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

std::string GrayToBin(std::string gray)
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

std::string InsertBar(std::string binary)
{
	std::string temp = binary;
	
	for (int i = temp.length() - 4; i > 0; i -= 4)
	{
		temp.insert(i, "_");
	}

	return temp;
}