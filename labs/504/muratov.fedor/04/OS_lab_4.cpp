// OS_lab_4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//#include "stdafx.h"

#include <iostream>
#include <vector>
#include "AddressGetter.h"


int main() 
{
	try
	{
		AddressGetter getAddrr;
		cout << hex << getAddrr.PhphysicalAddress() << endl;

	}
	catch (exception)
	{
		cout << "INVALID";
	}
//	system("pause");
	return 0;
}