#include "PmergeMe.hpp"

int main(int ac, char ** av)
{
	PMerge pmerge(ac, av);
	pmerge.timeSorts();

	return 0;
}
