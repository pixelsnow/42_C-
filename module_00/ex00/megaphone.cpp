#include <iostream>

class Megaphone
{

public:

	Megaphone(void)
	{
		return;
	}

	~Megaphone(void)
	{
		return;
	}

	void activate(int ac, char** av)
	{
		if (ac <= 1)
		{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		}
		else
		{
			for (int i=1; i<ac; i++)
				printUpper(av[i]);
			std::cout << std::endl;
		}
	}

private:

	void printUpper(char* arg)
	{
		std::string str = arg;
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
	}

};

int main(int ac, char** av)
{
	Megaphone megaphone;

	megaphone.activate(ac, av);
	return 0;
}