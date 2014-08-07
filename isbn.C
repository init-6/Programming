#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int sum=0, cksum=0;
	int Qpos = -1;

	//Check if the length is 10
	if(input.length() != 10)
	{
		cout << "INVALID INPUT" << endl;
		return 0;
	}

	//Check if the input has valid 9 digits except the last digit.
	for(int i=0;i<9;i++)
	{
		//Note the position of question mark.
		if(input[i] == '?')
		Qpos = i;
		if((input[i] != '?') && (input[i] < '0' || input[i] > '9'))
		{
			cout << "INVALID INPUT" << endl;
			return 0;
		}
	}

	if(input[9] == '?')
	Qpos = 9;

	//Check if the last digit is 'X' or a digit
	if((input[9] != 'X') && (input[9] < '0' || input[9] > '9'))
	{
		cout << "INVALID INPUT" << endl;
		return 0;
	}

	//Compute the sum and checksum
	for(int i = 0;i<10;i++)
	{
		if(input[i] != 'X' && input[i] != '?')
		sum += (input[i] - '0')*(10-i);
		else if(input[i] == 'X')
		sum += 10;
	}

	int rem = (input[9] == 'X') ? 10 : input[9]-'0';

	if(Qpos == -1 && (sum % 11) == 0)
	{
		cout << "ALREADY VALID" << endl;
		return 0;
	}

	for(int i = 0;i<=9 && Qpos != -1;i++)
	{
		if(((10-Qpos)*i + sum)%11 == 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "NO SOLUTION POSSIBLE" << endl;


	return 0;
}
