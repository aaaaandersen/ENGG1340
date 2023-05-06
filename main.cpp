#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Manager.h"
using namespace std;

int main()
{
	Manager* manager = new Manager;
	manager->Run();

	system("pause");
	return 0;
}