#include <iostream>
#include "max.h"
#include "min.h"

using namespace std;

int main()
{
	int a1 = 33;
	int a2 = 21;
	int maxNum = max(a1, a2);
	printf("the max value is %d\n", maxNum);
	int minNum = min(a1, a2);
	printf("the min value is %d\n", minNum);
	return 0;
}