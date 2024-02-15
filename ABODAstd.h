#pragma once
#pragma warning(disable : 4996) 

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<string>
#include<array>
#include<algorithm>
#include<limits>
#include<cstdio>
#include<cctype>
#include<fstream>
#include<vector>
#include<filesystem>
#include<regex>

using namespace std;

namespace std
{
	//MY LIBRARY "ABODAstd.h" : 
	//------------------------------

	//MISCELLANEOUS FUNCTIONS : 
	//-----------------------------

	string ReadStringLine(string Message);

	int RandomNumber(int From, int To)
	{
		int RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;

	}

	void SwapNumbers(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	long long GetIntegerPart(long double Number)
	{
		return (long long)Number;
	}

	long double GetFloatingPoint(long double Number)
	{
		return Number - (long long)Number;
	}

	bool IsPrime(long long Number)
	{
		for (long long i = 2; i <= sqrt(Number); i++)
		{
			if (Number % i == 0)
			{
				return 0;
			}
		}

		if (Number != 1)
		{
			return 1;
		}

		return 0;

	}

	bool IsPerfect(long long Number)
	{
		long long DivisorsSum = 0;

		for (long long i = 1; i < Number; i++)
		{
			if (Number % i == 0)
			{
				DivisorsSum += i;
			}
		}

		if (Number == DivisorsSum)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	bool IsInteger(long double Number)
	{
		return (GetIntegerPart(Number) == Number);
	}

	bool IsFloat(long double Number)
	{
		return !IsInteger(Number);
	}

	void ClearScreen()
	{
		system("cls");
	}

	string NumberToText(long long Number)
	{
		if (Number == 0)
		{
			return 0;
		}

		if (Number >= 1 && Number <= 19)
		{
			string NumberText[] = { "" , "ONE" , "TWO" , "THREE" , "FOUR" , "FIVE" ,
			"SIX" , "SEVEN" , "EIGHT" , "NINE" , "TEN" , "ELEVEN" , "TWELVE" , "THIRTEEN" ,
			"FOURTEEN" , "FIFTEEN" , "SIXTEEN" , "SEVENTEEN" , "EIGHTEEN" , "NINETEEN" };

			return NumberText[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string NumberText[] = { "" , "" , "TWENTY" , "THIRTY" , "FOURTY" , "FIFTY" ,
			"SIXTY" , "SEVENTY" , "EIGHTY" , "NINETY" };

			return NumberText[Number / 10] + " " + NumberToText(Number % 10);

		}

		if (Number >= 100 && Number <= 199)
		{
			return "ONE HUNDRED " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "HUNDREDS " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "ONE THOUSAND " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "THOUSANDS " + NumberToText(Number % 1000);
		}

		if (Number >= 1e6 && Number <= 1999999)
		{
			return "ONE MILLION " + NumberToText(Number % long long(1e6));
		}

		if (Number >= 2e6 && Number <= 999999999)
		{
			return NumberToText(Number / 1e6) + "MILLIONS " + NumberToText(Number % long long(1e6));
		}

		if (Number >= 1e9 && Number <= 1999999999)
		{
			return "ONE BILLION " + NumberToText(Number % long long(1e9));
		}

		if (Number >= 2e9 && Number <= 999999999999)
		{
			return NumberToText(Number / 1e9) + "BILLIONS " + NumberToText(Number % long long(1e9));
		}

		if (Number >= 1e12 && Number <= 1999999999999)
		{
			return "ONE TRILLION " + NumberToText(Number % long long(1e12));
		}

		if (Number >= 2e12 && Number <= 999999999999999)
		{
			return NumberToText(Number / 1e12) + "TRILLIONS " + NumberToText(Number % long long(1e12));
		}

		else
		{
			return "NUMBER IS BIGGER THAN OR EQUAL THE QUADRILLION\n";
		}
	}

	enum CLIColors {
		Black = 0, Blue = 1, Green = 2, Aqua = 3, Red = 4, Purple = 5,
		Yellow = 6, White = 7, Gray = 8, LightBlue = 9, LightGreen = 10,
		LightAqua = 11, LightRed = 12, LightPurple = 13, LightYellow = 14,
		BrightWhite = 15
	};

	string ReturnColorHexadecimalNumber(CLIColors CLIColor)
	{
		string ColorHexadecimalNumber[] = { "0" , "1" , "2" , "3" , "4" , "5" , "6" , "7"
										  , "8" , "9" , "A" , "B" , "C" , "D" , "E" , "F" };

		return ColorHexadecimalNumber[CLIColor];
	}

	void ChangeCLIColors(CLIColors BackgroundColor = Black, CLIColors ForegroundColor = BrightWhite)
	{
		string CLIColorCommand = "color " + ReturnColorHexadecimalNumber(BackgroundColor) + ReturnColorHexadecimalNumber(ForegroundColor);

		system(CLIColorCommand.c_str());
	}

	bool IsPhoneKey(string PhoneKey)
	{
		for (int i = 0; i < PhoneKey.length(); i++)
		{
			if (PhoneKey[0] != '+')
			{
				printf("\nINVALID PHONE KEY , YOU HAVEN'T ENTERED + SIGN CHARACTER IN THE BEGINNING OF KEY !\n");
				return 0;
			}

			if (i != 0 && isdigit(PhoneKey[i]) == false)
			{
				printf("\nINVALID PHONE KEY , YOU HAVE ENTERED NON-DIGIT CHARACTER !\n");
				return 0;
			}
		}

		return 1;
	}

	bool IsPhoneNumber(string PhoneNumber)
	{
		for (int i = 0; i < PhoneNumber.size(); i++)
		{
			if (!isdigit(PhoneNumber[i]))
			{
				printf("\nINVALID PHONE NUMBER , YOU HAVE ENTERED NON-DIGIT CHARACTER !\n");
				return 0;
			}
		}

		return 1;
	}

	string ReadPhoneNumber(string Message)
	{
		string PhoneNumber;
		do
		{

			PhoneNumber = ReadStringLine(Message);

		} while (!IsPhoneNumber(PhoneNumber));

		return PhoneNumber;
	}

	string ReadPhoneKey(string Message)
	{
		string PhoneKey;
		do
		{

			PhoneKey = ReadStringLine(Message);

		} while (!IsPhoneKey(PhoneKey));

		return PhoneKey;
	}

	string ReadFullPhoneNumber(string PhoneKeyMessage, string PhoneNumberMessage)
	{
		string PhoneNumber, PhoneKey;

		PhoneKey = ReadPhoneKey(PhoneKeyMessage);
		PhoneNumber = ReadPhoneNumber(PhoneNumberMessage);

		return PhoneKey + PhoneNumber;
	}

	bool IsEmailAddressCorrect(string EmailAddress)
	{
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

		if (!regex_match(EmailAddress, pattern))
		{
			printf("\nINVALID EMAIL ADDRESS FORMULA !\n");
			return 0;
		}

		return 1;
	}

	string ReadEmailAddress(string Message)
	{
		string EmailAddress;
		do
		{
			EmailAddress = ReadStringLine(Message);

		} while (!IsEmailAddressCorrect(EmailAddress));

		return EmailAddress;
	}

	//-----------------------------------------------------------------------------
	
	//READ FUNCTIONS : 
	//-----------------

	long double ReadNumber(string Message)
	{
		cout << "\n" << Message << "\n";
		long double Number;
		cin >> Number;

		while (cin.fail() == 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "INVALID NUMBER , " << Message << "\n";
			cin >> Number;
		}

		return Number;
	}

	long long ReadIntegerNumber(string Message)
	{
		long double Number;

		do
		{

			Number = ReadNumber(Message);

		} while (IsFloat(Number));

		return Number;
	}

	long long ReadPositiveNumber(string Message)
	{
		long long Number;
		do {

			Number = ReadNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	long long ReadNumberMultipleOf(string Message, long long FactorNumber)
	{
		long long Number;
		do
		{
			Number = ReadNumber(Message);

		} while (Number % FactorNumber != 0);

		return Number;
	}

	long double ReadDoublePositiveNumber(string Message)
	{
		long double Number;
		do {

			Number = ReadNumber(Message);

		} while (Number < 0);

		return Number;
	}

	long long ValidateNumberInRange(long long From, long long To)
	{
		long long Number;
		string Message = "ENTER A NUMBER BETWEEN " + to_string(From) + " & " + to_string(To);
		do
		{
			Number = ReadIntegerNumber(Message);

		} while (Number < From || Number > To);

		return Number;
	}

	long long ValidateNumberInRange(long long From, long long To, string Message)
	{
		long long Number;
		do
		{
			Number = ReadIntegerNumber(Message);

		} while (Number < From || Number > To);

		return Number;
	}

	long double ValidateDoubleNumberInRange(long double From, long double To)
	{
		long double Number;
		string Message = "ENTER A NUMBER BETWEEN " + to_string(From) + " & " + to_string(To);

		do
		{
			Number = ReadNumber(Message);

		} while (Number < From || Number > To);

		return Number;
	}

	long double ValidateDoubleNumberInRange(long double From, long double To, string Message)
	{
		long double Number;
		do
		{
			Number = ReadNumber(Message);

		} while (Number < From || Number > To);

		return Number;
	}

	long double ReadNumber()
	{
		long double Number;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "INVALID NUMBER\n";
			cin >> Number;
		}

		return Number;
	}

	long long ReadNumberMultipleOf(long long FactorNumber)
	{
		long long Number;
		do
		{
			Number = ReadNumber();

		} while (Number % FactorNumber != 0);

		return Number;
	}

	long long ReadPositiveNumber()
	{
		long long Number;
		do
		{
			Number = ReadNumber();

		} while (Number < 0);

		return Number;
	}

	long double ReadDoublePositiveNumber()
	{
		long double Number;

		do
		{
			Number = ReadNumber();

		} while (Number < 0);

		return Number;
	}

	long long ValidateNumberInRangeWithoutMessage(long long From, long long To)
	{
		long long Number;

		do
		{
			Number = ReadNumber();

		} while (Number < From || Number > To);

		return Number;
	}

	long double ValidateDoubleNumberInRangeWithoutMessage(long double From, long double To)
	{
		long double Number;

		do
		{
			Number = ReadNumber();

		} while (Number < From || Number > To);

		return Number;
	}

	string ReadString(string Message)
	{
		string String;
		cout << "\n" << Message << "\n";
		cin >> String;

		return String;
	}

	string ReadStringLine(string Message)
	{
		string String;
		cout << "\n" << Message << "\n";


		
		getline(cin >> ws, String);

		return String;
	}

	char ReadCharacter(string Message)
	{
		char Character;
		cout << "\n" << Message << "\n";
		cin >> Character;

		return Character;
	}

	char ReadArithmeticOperation(string Message)
	{
		char Operation = ' ';

		bool RepeatingCondition = 1;

		do
		{
			cout << "\n" << Message << "\n";
			cin >> Operation;

			RepeatingCondition = (
				(Operation != '+') &&
				(Operation != '-') &&
				(Operation != '*') &&
				(Operation != '/') &&
				(Operation != '%'));

		} while (RepeatingCondition == true);

		return Operation;
	}

	//------------------------------------------------------------------------------
	
	//ARRAY FUNCTIONS : 
	//--------------------

	void PrintArray(int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			cout << Array[i] << ' ';
		}

		cout << "\n";
	}

	void FillArrayWithRandomNumbers(int Array[100], int& ArraySize)
	{
		ArraySize = ReadPositiveNumber("ENTER SIZE OF ARRAY");

		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = RandomNumber(1, 100);
		}
	}

	void CopyArray(int CopiedArray[], int ArrayCopy[], int CopiedArraySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			ArrayCopy[i] = CopiedArray[i];
		}

	}

	void AddArrayELement(int Number, int Array[], int& ArraySize)
	{
		Array[ArraySize++] = Number;
	}

	void ReadArrayWithArrayLength(int Array[100])
	{
		int ArrayLength = ReadPositiveNumber("ENTER SIZE OF ARRAY");

		cout << "ENTER ARRAY ELEMENT" << endl;

		for (int i = 0; i < ArrayLength; i++)
		{
			printf("ELEMENT[%d] : ", (i + 1));
			cin >> Array[i];
		}
	}

	void ReadArray(int Array[100], int ArrayLength)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			printf("ELEMENT[%d] : ", (i + 1));
			Array[i] = ReadNumber();
		}
	}

	bool IsArrayPalindrome(int Array[100], int ArraySize)
	{
		for (int i = 0; i < (ArraySize / 2); i++)
		{
			if (Array[i] != Array[ArraySize - i - 1])
				return 0;
		}

		return 1;
	}

	int CheckFoundOrNot(int NumberToCheck, int Array[100], int ArraySize)
	{

		for (int i = 0; i < ArraySize; i++)
		{
			if (NumberToCheck == Array[i])
			{
				return i;
			}
		}
		return -1;
	}

	bool IsFoundInArray(int NumberToCheck, int Array[100], int ArraySize)
	{
		return (CheckFoundOrNot(NumberToCheck, Array, ArraySize) != -1);
	}

	bool AreArraysEqual(int Array1[100], int Array2[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			if (Array1[i] != Array2[i])
			{
				return 0;
			}
		}

		return 1;
	}

	void CopyArrayInReversedOrder(int CopiedArray[], int ArrayCopy[], int CopiedArraySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			ArrayCopy[i] = CopiedArray[CopiedArraySize - 1 - i];
		}

	}

	//-----------------------------------------------------------------------------
	
	//MATRIX FUNCTIONS : 
	//--------------------

	void PrintMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				cout << Matrix[i][j] << "	";
			}
			cout << endl;
		}
	}

	void ReadMatrixWithRowsAndColumns(int Matrix[100][100])
	{
		int Rows = ReadPositiveNumber("ENTER NUMBER OF ROWS OF MATRIX");
		int Columns = ReadPositiveNumber("ENTER NUMBER OF COLUMNS OF MATRIX");

		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{

				printf("ELEMENT [%d] : ", ++Counter);
				Matrix[i][j] = ReadNumber();
			}
		}
	}

	void ReadMatrixWithoutRowsAndColumns(int Matrix[100][100], int Rows, int Columns)
	{
		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				printf("ELEMENT[%d] : ", ++Counter);
				Matrix[i][j] = ReadNumber();
			}
		}
	}

	void FillMatrixWithRandomNumbers(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = RandomNumber(1, 100);
			}
		}
	}

	int RowSum(int Matrix[100][100], int RowNumber, int Columns)
	{
		int RowSum = 0;
		for (int i = 0; i < Columns; i++)
		{
			RowSum += Matrix[RowNumber][i];
		}

		return RowSum;
	}

	int ColumnSum(int Matrix[100][100], int Rows, int ColumnNumber)
	{
		int ColumnSum = 0;
		for (int i = 0; i < Rows; i++)
		{
			ColumnSum += Matrix[i][ColumnNumber];
		}

		return ColumnSum;
	}

	void FillMatrixWithOrderedNumber(int Matrix[100][100], int Rows, int Columns)
	{
		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = ++Counter;
			}
		}
	}

	void GetMatrixTranspose(int Matrix[100][100], int TransposeMatrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				TransposeMatrix[i][j] = Matrix[j][i];
			}
		}
	}

	void MultiplyContentOfTwoMatrices(int Matrix1[100][100], int Matrix2[100][100], int ResultMatrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
			}
		}
	}

	void PrintMiddleRow(int Matrix[100][100], int Rows, int Columns)
	{
		int MiddleRow = Rows / 2;

		cout << "\nMIDDLE ROW CONTENT : \n";
		for (int i = 0; i < Columns; i++)
		{
			printf("%0*d	", 2, Matrix[MiddleRow][i]);
		}
	}

	void PrintMiddleColumn(int Matrix[100][100], int Rows, int Columns)
	{
		int MiddleColumn = Columns / 2;

		cout << "\nMIDDLE COLUMN CONTENT : \n";
		for (int i = 0; i < Rows; i++)
		{
			printf("%0*d	", 2, Matrix[i][MiddleColumn]);
		}
	}

	int SumOfMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int SumOfMatrix = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				SumOfMatrix += Matrix[i][j];
			}
		}

		return SumOfMatrix;
	}

	bool AreMatricesEqual(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		return (SumOfMatrix(Matrix1, Rows, Columns) == SumOfMatrix(Matrix2, Rows, Columns));
	}

	bool AreMatricesIdentical(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix1[i][j] != Matrix2[i][j])
				{
					return 0;
				}
			}
		}

		return 1;
	}

	bool IsMatrixIdentity(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if ((i == j && Matrix[i][j] != 1) || (i != j && Matrix[i][j] != 0))
				{
					return 0;
				}
			}
		}

		return 1;
	}

	bool IsScalarMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int FirstElementInDiagonal = Matrix[0][0];
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if ((i == j && Matrix[i][j] != FirstElementInDiagonal) || (i != j && Matrix[i][j] != 0))
				{
					return 0;
				}
			}
		}
		return 1;
	}

	short NumberFrequencyInMatrix(int Matrix[100][100], int Rows, int Columns, int TargetedNumber)
	{
		short TargetedNumberFrequency = 0;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] == TargetedNumber)
				{
					TargetedNumberFrequency++;
				}
			}
		}

		return TargetedNumberFrequency;
	}
	
	bool IsSparseMatrix(int Matrix[100][100], int Rows, int Columns)
	{

		return (NumberFrequencyInMatrix(Matrix, Rows, Columns, 0) >= (Rows * Columns * 0.5));
	}

	bool IsNumberFoundInMatrix(int Matrix[100][100], int Rows, int Columns, int TargetedNumber)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] == TargetedNumber)
				{
					return 1;
				}
			}
		}

		return 0;
	}

	void PrintIntersectedNumbersInTwoMatrices(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		cout << "\nINTERSECTED NUMBERS BETWEEN THE TWO MATRICES ARE : \n";

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (IsNumberFoundInMatrix(Matrix2, Rows, Columns, Matrix1[i][j]))
				{
					cout << Matrix1[i][j] << "	";
				}
			}
		}
	}

	int MaximumNumberInMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int MaximumNumberInMatrix = INT_MIN;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] > MaximumNumberInMatrix)
				{
					MaximumNumberInMatrix = Matrix[i][j];
				}
			}
		}

		return MaximumNumberInMatrix;
	}

	int MinimumNumberInMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int MinimumNumberInMatrix = INT_MAX;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] < MinimumNumberInMatrix)
				{
					MinimumNumberInMatrix = Matrix[i][j];
				}
			}
		}

		return MinimumNumberInMatrix;
	}

	bool IsMatrixPalindrome(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < (Columns / 2); j++)
			{
				if (Matrix[i][j] != Matrix[i][Columns - 1 - j])
				{
					return 0;
				}
			}
		}

		return 1;
	}

	//----------------------------------------------------------------------------

	//REPEATING FUNCTIONS : 
	//-------------------------
	
	bool DoYouWantToDoThisWithoutClear(string Message)
	{
		string ReadAgain;
		do
		{

			ReadAgain = ReadStringLine(Message + " [Y/N]");

		}while(ReadAgain != "Y" && ReadAgain != "y" && ReadAgain != "N" && ReadAgain != "n");
		
		if (ReadAgain == "Y" || ReadAgain == "y")
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	bool DoYouWantToDoThisWithClear(string Message)
	{
		string ReadAgain;
		do
		{

			ReadAgain = ReadStringLine(Message + " [Y/N]");

		} while (ReadAgain != "Y" && ReadAgain != "y" && ReadAgain != "N" && ReadAgain != "n");

		if (ReadAgain == "Y" || ReadAgain == "y")
		{
			system("cls");
			return 1;
		}

		else
		{
			return 0;
		}
	}

	bool DoYouWantToDoThisWithFullClear(string Message)
	{
		string ReadAgain;
		do
		{

			ReadAgain = ReadStringLine(Message + " [Y/N]");

		} while (ReadAgain != "Y" && ReadAgain != "y" && ReadAgain != "N" && ReadAgain != "n");

		if (ReadAgain == "Y" || ReadAgain == "y")
		{
			system("color 0F");
			system("cls");
			return 1;
		}

		else
		{
			return 0;
		}
	}

	//-----------------------------------------------------------------------------

	// FILES FUNCTIONS : 
	//-----------------------

	void PrintFileContent(string FileName)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				if (Line != "")
				{
					cout << Line << "\n";
				}

			}

			File.close();
		}
	}

	void LoadDataFromFileToVector(string FileName, vector<string>& FileContent)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				if (Line != "")
				{
					FileContent.push_back(Line);
				}

			}

			File.close();
		}
	}

	void SaveVectorDataToFile(string FileName, vector<string>& VectorContent)
	{
		fstream File;
		File.open(FileName, ios::out);

		if (File.is_open())
		{
			for (string& Line : VectorContent)
			{
				if (Line != "")
				{
					File << Line << "\n";
				}

			}

			File.close();
		}
	}

	void DeleteRecordFromFile(string FileName, string Record)
	{
		// ALWAYS WE USE VECTOR IN FILES AS A MEDIUM
		vector<string>FileContent;

		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Line : FileContent)
		{
			if (Line == Record)
			{
				Line = "";
			}
		}

		SaveVectorDataToFile(FileName, FileContent);

	}

	void UpdateRecordFromFile(string FileName, string Record, string Update)
	{
		//ALWAYS WE USE VECTORS IN FILES AS A MEDIUM
		vector<string>FileContent;

		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Line : FileContent)
		{
			if (Line == Record)
			{
				Line = Update;
			}
		}

		SaveVectorDataToFile(FileName, FileContent);
	}

	//------------------------------------------------------------------------------

	//FORMATTING FUNCTIONS : 
	//-------------------------

	string Tab(short NumberOfTabs)
	{
		string Tab = "";
		for(short i = 1 ; i<= NumberOfTabs ; i++)
		{
			Tab += "\t";
		}
		
		return Tab;
	}

	string NewLine(short NumberOfNewLines)
	{
		string NewLine = "";

		for (int i = 0; i < NumberOfNewLines; i++)
		{
			NewLine += "\n";
		}

		return NewLine;
	}

	string Line(string LineStyle = "_", short LineLength = 60)
	{
		string Line = "";

		for (int i = 0; i < LineLength; i++)
		{
			Line += LineStyle;
		}

		return Line;
	}

	void SectionBanner(string SectionName, short NumberOfTabs = 2 ,string LineStyle = "-" , short LineLength = 60)
	{
		string SectionBannerLine = Line(LineStyle, LineLength);

		printf("\n%s\n", SectionBannerLine.c_str());
		cout << Tab(NumberOfTabs) << SectionName;
		printf("\n%s\n", SectionBannerLine.c_str());
	}

	void PrintLineWithNewLines(string LineStyle = "_", short LineLength = 60 , short StartNewLinesNumber = 2 , short EndNewLinesNumber = 2 , short NumberOfLines = 1)
	{
		string Linev = Line(LineStyle, LineLength);

		string StartNewLines = NewLine(StartNewLinesNumber);
		string EndNewLines = NewLine(EndNewLinesNumber);

		for (int i = 0; i < NumberOfLines; i++)
		{
			printf("%s%s%s", StartNewLines.c_str(), Linev.c_str() , EndNewLines.c_str());
		}
	}

	void PrintLineWithoutNewLines(string LineStyle = "_", short LineLength = 60, short NumberOfLines = 1)
	{
		string Linev = Line(LineStyle , LineLength);
		
		printf("%s" , Linev.c_str());
	}

	void PrintStringElementInTable(string StringElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << StringElement;
	}

	void PrintCharacterElementInTable(char CharacterElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << CharacterElement;
	}

	void PrintNumberElementInTable(long long NumberElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << NumberElement;
	}

	void PrintDoubleNumberElementInTable(long double DoubleNumberElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << DoubleNumberElement;
	}

	void PrintBooleanElementInTable(bool BooleanElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << BooleanElement;
	}

	void PrintChoiceInMenu(short ChoiceNumber , string Choice, short NumberOfTabs = 3)
	{
		printf("%s[%d] %s.\n", Tab(NumberOfTabs).c_str(), ChoiceNumber, Choice.c_str());
	}

	//--------------------------------------------------------------------------------
	
	//TIME FUNCTIONS : 
	//-------------------

	struct Time
	{
		short Hour;
		short Minute;
		short Second;
	};

	Time GetSystemTime()
	{
		time_t TimeNow = time(0);
		tm* SystemTime = localtime(&TimeNow);

		Time Time;
		Time.Hour = SystemTime->tm_hour;
		Time.Minute = SystemTime->tm_min;
		Time.Second = SystemTime->tm_sec;

		return Time;
	}

	void PrintLocalTime()
	{
		time_t t = time(0);
		char* LocalTime = ctime(&t);

		cout << "LOCAL TIME : " << LocalTime << "\n";
	}

	void PrintGlobalTime()
	{
		time_t t = time(0);
		char* LocalTime = ctime(&t);

		tm* gmtm = gmtime(&t);
		char* GlobalTime = asctime(gmtm);
		cout << "GLOBAL TIME : " << GlobalTime << "\n";
	}

	void PrintBothLocalAndGlobalTime()
	{
		time_t t = time(0);
		char* LocalTime = ctime(&t);

		cout << "LOCAL TIME : " << LocalTime << "\n";

		tm* gmtm = gmtime(&t);
		char* GlobalTime = asctime(gmtm);
		cout << "GLOBAL TIME : " << GlobalTime << "\n";
	}

	//-----------------------------------------------------------------------

	//STRING & CHARACTERS PROCESSING FUNCTIONS : 
	//----------------------------------------------

	void PrintFirstLetterOfEachWordInString(string String)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				cout << String[i] << "\n";
			}

			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
	}

	string UpperCaseFirstLetterInEachWordInString(string String)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				String[i] = toupper(String[i]);
			}

			IsFirstLetter = (String[i] == ' ' ? true : false);
		}

		return String;
	}

	string LowerCaseFirstLetterInEachWordInString(string String)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				String[i] = tolower(String[i]);
			}

			IsFirstLetter = (String[i] == ' ' ? true : false);
		}

		return String;
	}

	string LowerCaseAllString(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{
			String[i] = tolower(String[i]);
		}

		return String;
	}

	string UpperCaseAllString(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{
			String[i] = toupper(String[i]);
		}

		return String;
	}

	char InvertLetterCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	string InvertAllLettersCaseInString(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{
			String[i] = InvertLetterCase(String[i]);
		}

		return String;
	}

	enum WhatToCountInString { CapitalLetters = 1, SmallLetters = 2, VowelLetters = 3, AllLetters = 4, Digits = 5, SpecialCharacters = 6 , AllCharacters = 7 };

	short CountSmallLettersInString(string String)
	{
		short SmallLettersCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (islower(String[i]))
			{
				SmallLettersCounter++;
			}
		}

		return SmallLettersCounter;
	}

	short CountCapitalLettersInString(string String)
	{
		short CapitalLettersCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (isupper(String[i]))
			{
				CapitalLettersCounter++;
			}
		}

		return CapitalLettersCounter;
	}

	short CountAllLettersInString(string String)
	{
		short LettersCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (isupper(String[i]) || islower(String[i]))
			{
				LettersCounter++;
			}
		}

		return LettersCounter;
	}

	short CountDigitsInString(string String)
	{
		short DigitsCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (isdigit(String[i]))
			{
				DigitsCounter++;
			}
		}

		return DigitsCounter;
	}

	short CountSpecialCharactersInString(string String)
	{
		short SpecialCharactersCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (ispunct(String[i]))
			{
				SpecialCharactersCounter++;
			}
		}

		return SpecialCharactersCounter;
	}

	bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'o' || Letter == 'i' || Letter == 'u');
	}

	short CountVowelLettersInString(string String)
	{
		short VowelLettersCounter = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (IsVowel(String[i]))
			{
				VowelLettersCounter++;
			}
		}

		return VowelLettersCounter;
	}

	short CountCharactersInString(string String, WhatToCountInString WhatToCountInString = AllCharacters)
	{
		switch (WhatToCountInString)
		{
		case std::CapitalLetters:
			return CountCapitalLettersInString(String);
		case std::SmallLetters:
			return CountSmallLettersInString(String);
		case std::VowelLetters:
			return CountVowelLettersInString(String);
		case std::AllLetters:
			return CountAllLettersInString(String);
		case std::Digits:
			return CountDigitsInString(String);
		case std::SpecialCharacters:
			return CountSpecialCharactersInString(String);
		case std::AllCharacters:
			return String.length();
		default:
			cout << "INVALID CHARACTER TYPE\n";
			return 0;
		}
	}

	short LetterFrequencyInString(string String, char TargetedLetter, bool MatchCase = true)
	{
		short TargetedLetterFrequency = 0;

		for (int i = 0; i < String.length(); i++)
		{
			if (MatchCase)
			{
				if (String[i] == TargetedLetter)
				{
					TargetedLetterFrequency++;
				}
			}

			else
			{
				if (tolower(String[i]) == tolower(TargetedLetter))
				{
					TargetedLetterFrequency++;
				}
			}
		}

		return TargetedLetterFrequency;
	}

	short CountWordsInString(string String, string Delimiter)
	{
		short DelimiterPosition = 0;
		string Word = "";
		short WordCounter = 0;

		while ((DelimiterPosition = String.find(Delimiter)) != std::string::npos)
		{
			Word = String.substr(0, DelimiterPosition);

			if (Word != "")
			{
				WordCounter++;
			}


			String.erase(0, DelimiterPosition + Delimiter.length());
		}

		if (String != "")
		{
			WordCounter++;
		}

		return WordCounter;
	}

	vector<string> SpiltStringWordsToVector(string String, string Delimiter)
	{
		short DelimiterPosition = 0;
		string Word = "";
		vector<string>StringVector;

		while ((DelimiterPosition = String.find(Delimiter)) != std::string::npos)
		{
			Word = String.substr(0, DelimiterPosition);

			if (Word != "")
			{
				StringVector.push_back(Word);
			}

			String.erase(0, DelimiterPosition + Delimiter.length());
		}

		if (String != "")
		{
			StringVector.push_back(String);
		}

		return StringVector;
	}

	string TrimLeft(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ')
			{
				return String = String.substr(i, String.length() - i);
			}
		}

		return String = "";
	}

	string TrimRight(string String)
	{
		for (int i = String.length() - 1; i >= 0; i--)
		{
			if (String[i] != ' ')
			{
				return String = String.substr(0, i + 1);
			}
		}

		return String = "";
	}

	string Trim(string String)
	{
		return TrimLeft(TrimRight(String));
	}

	string JoinStringsFromVector(vector<string>& StringVector, string Separator)
	{
		string String = "";

		for (string& Word : StringVector)
		{
			String += (Word + Separator);
		}

		return String = String.substr(0, String.length() - Separator.length());
	}

	string JoinStringsFromArray(string StringArray[100], int ArrayLength, string Separator)
	{
		string String = "";

		for (int i = 0; i < ArrayLength; i++)
		{
			String += (StringArray[i] + Separator);
		}

		return String = String.substr(0, String.length() - Separator.length());
	}

	string JoinStringsFromVectorInReversedOrder(vector<string>& StringVector, string Separator)
	{
		string String = "";

		for (int i = StringVector.size() - 1; i >= 0; i--)
		{
			String += (StringVector[i] + Separator);
		}

		return String.substr(0, String.length() - Separator.length());
	}

	string JoinStringsFromArrayInReversedArray(string StringArray[100], int ArrayLength, string Separator)
	{
		string String = "";

		for (int i = ArrayLength - 1; i >= 0; i--)
		{
			String += (StringArray[i] + Separator);
		}

		return String = String.substr(0, String.length() - Separator.length());
	}

	string ReverseWordsInString(string String)
	{
		vector<string>StringVector = SpiltStringWordsToVector(String, " ");
		vector<string>::iterator iter;
		string ReversedString = "";

		for (iter = StringVector.end(); iter != StringVector.begin(); iter += 0)
		{
			iter--;
			String += (*iter + " ");
		}

		return ReversedString = ReversedString.substr(0, String.length() - 1);
	}

	string ReplaceWordsInStringUsingBuiltInFunction(string String, string ReplacedWord, string ReplacingWord)
	{
		short ReplacedWordPosition = 0;
		while ((ReplacedWordPosition = String.find(ReplacedWord)) != std::string::npos)
		{
			String = String.replace(ReplacedWordPosition, ReplacedWord.length(), ReplacingWord);
		}

		return String;
	}

	string ReplaceWordsInString(string String, string ReplacedWord, string ReplacingWord, bool MatchCase = true)
	{
		vector<string>StringVector = SpiltStringWordsToVector(String, " ");

		for (string& Word : StringVector)
		{
			if (MatchCase)
			{
				if (Word == ReplacedWord)
				{
					Word = ReplacingWord;
				}
			}

			else
			{
				if (LowerCaseAllString(Word) == LowerCaseAllString(ReplacedWord))
				{
					Word = ReplacingWord;
				}
			}
		}

		return JoinStringsFromVector(StringVector, " ");
	}

	string RemoveSpecialCharactersFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!ispunct(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveCapitalLettersFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!isupper(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveSmallLettersFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!islower(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveVowelLettersFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!IsVowel(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveDigitsFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!isdigit(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveAllLettersFromString(string String)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (!isupper(Character) && !islower(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	string RemoveCharacterFromString(string String, char TargetedCharacter)
	{
		string FilteredString = "";

		for (char& Character : String)
		{
			if (Character != TargetedCharacter)
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	enum WhatToRemoveFromString { rCapitalLetters = 1, rSmallLetters = 2, rVowelLetters = 3, rAllLetters = 4, rDigits = 5, rSpecialCharacters = 6, rAllCharacters = 7 };

	string RemoveCharactersFromString(string String, WhatToRemoveFromString WhatToRemoveFromString = rAllCharacters)
	{
		switch (WhatToRemoveFromString)
		{
		case std::rCapitalLetters:
			return RemoveCapitalLettersFromString(String);
		case std::rSmallLetters:
			return RemoveSmallLettersFromString(String);
		case std::rVowelLetters:
			return RemoveVowelLettersFromString(String);
		case std::rAllLetters:
			return RemoveAllLettersFromString(String);
		case std::rDigits:
			return RemoveDigitsFromString(String);
		case std::rSpecialCharacters:
			return RemoveSpecialCharactersFromString(String);
		case std::rAllCharacters:
			return "";
		default:
			cout << "INVALID CHARACTER TYPE\n";
			return String;
		}
	}

	//-------------------------------------------------------------------------
	// 
	//PAUSE AND EXIT FUNCTIONS : 
	//----------------------------------------------

	void GoToPauseMessage(string Message)
	{
		cout << Message << "\n";
		system("pause>0");
		system("cls");
	}

	void StartProgram(string Message, short NumberOfTabs = 2, string LineStyle = "-", short LineLength = 60 , CLIColors BackgroundColor = Black , CLIColors ForegroundColor = BrightWhite)
	{
		ClearScreen();
		ChangeCLIColors(BackgroundColor, ForegroundColor);
		SectionBanner(Message, NumberOfTabs, LineStyle , LineLength);
		GoToPauseMessage("\n\nPRESS ANY KEY TO START :-) ...\n");
	}

	void ExitProgram(string Message , short NumberOfTabs = 2 , string LineStyle = "-" , short LineLength = 60, CLIColors BackgroundColor = Black, CLIColors ForegroundColor = BrightWhite)
	{
		ClearScreen();
		ChangeCLIColors(BackgroundColor, ForegroundColor);
		SectionBanner(Message , NumberOfTabs , LineStyle , LineLength);
		GoToPauseMessage("\n\nPRESS ANY KEY TO EXIT :-) ...\n");
		exit(0);
	}

	//----------------------------------------------------------------------------

	//DATES & PERIODS FUNCTIONS :
	//-----------------------------------------------

	struct Date {
		short Day;
		short Month;
		long long Year;
	};

	struct Period {
		Date StartDate;
		Date EndDate;
	};

	bool IsLeapYear(long long Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAYear(long long Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfHoursInAYear(long long Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	int NumberOfMinutesInAYear(long long Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear(long long Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	short NumberOfDaysInAMonth(short Month , long long Year)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		short NumberOfDaysInAMonth[] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDaysInAMonth[Month - 1];
	}

	short NumberOfHoursInAMonth(short Month , long long Year)
	{
		return NumberOfDaysInAMonth(Month , Year) * 24;
	}

	unsigned short NumberOfMinutesInAMonth(short Month , long long Year)
	{
		return NumberOfHoursInAMonth(Month , Year) * 60;
	}

	int NumberOfSecondsInAMonth(short Month , long long Year)
	{
		return NumberOfMinutesInAMonth(Month , Year) * 60;
	}

	short DayOrderInWeek(short Day, short Month, long long Year)
	{
		// GREGORIAN METHOD:
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}

	short DayOrderInWeek(Date Date)
	{
		// GREGORIAN METHOD:
		short a, y, m;
		a = (14 - Date.Month) / 12;
		y = Date.Year - a;
		m = Date.Month + (12 * a) - 2;

		return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}

	string DayShortName(short DayOrderInWeek)
	{
		string DayShortName[] = { "SUN" , "MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT" };

		return DayShortName[DayOrderInWeek];
	}

	string DayLongName(short DayOrderInWeek)
	{
		string DayLongName[] = { "SUNDAY" , "MONDAY" , "TUESDAY" , "WEDNESDAY" , "THURSDAY" ,
								 "FRIDAY" , "SATURDAY" };

		return DayLongName[DayOrderInWeek];
	}

	string MonthShortName(short Month)
	{
		string MonthShortName[] = { "JAN" , "FEB" , "MAR" , "APRIL" , "MAY" , "JUN" , "JUL" ,
									"AUG" , "SEP" , "OCT" , "NOV" , "DEC" };

		return MonthShortName[Month - 1];
	}

	string MonthLongName(short Month)
	{
		string MonthLongName[] = { "JANUARY" , "FEBRUARY" , "MARCH" , "APRIL" , "MAY" ,
								   "JUNE" , "JULY" , "AUGUST" , "SEPTEMBER" , "OCTOBER" ,
								   "NOVEMBER" , "DECEMBER" };

		return MonthLongName[Month - 1];
	}

	void PrintMonthCalender(short Month, long long Year)
	{
		short MonthDays = NumberOfDaysInAMonth(Month, Year);
		short FirstDayInMonthOrder = DayOrderInWeek(1, Month, Year);

		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
		printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");

		short i;

		for (i = 0; i < FirstDayInMonthOrder; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= MonthDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n\n");
	}

	void PrintYearCalender(long long Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           CALENDER - %d", Year);
		printf("\n  _________________________________\n");

		for (short Month = 1; Month <= 12; Month++)
		{
			PrintMonthCalender(Month, Year);
		}
	}

	short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, long long Year)
	{
		short DaysFromBeginningOfTheYear = 0;

		for (short Months = 1; Months < Month; Month++)
		{
			DaysFromBeginningOfTheYear += NumberOfDaysInAMonth(Months, Year);
		}

		return DaysFromBeginningOfTheYear += Day;
	}

	short NumberOfDaysFromTheBeginningOfTheYear(Date Date)
	{
		short DaysFromBeginningOfTheYear = 0;

		for (short Month = 1; Month < Date.Month; Month++)
		{
			DaysFromBeginningOfTheYear += NumberOfDaysInAMonth(Date.Month, Date.Year);
		}

		return DaysFromBeginningOfTheYear += Date.Day;
	}

	Date GetDateFromDayOrderInYear(short DayOrderInYear, long long Year)
	{
		Date Date;
		Date.Month = 1;
		Date.Year = Year;
		short RemainingDays = DayOrderInYear;

		while (true)
		{
			short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	Date AddDaysToDateLongMethod(Date Date, long long Days)
	{
		long long RemainingDays = NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year) + Days;
		Date.Month = 1;

		while (true)
		{
			short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	bool IsDate1BeforeDate2(Date Date1, Date Date2)
{
	return (Date1.Year < Date2.Year) ||
		(Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
		(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}

	bool IsDate1EqualDate2(Date Date1, Date Date2)
	{
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	bool IsLastDayInTheMonth(Date Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastMonthInTheYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastDayInTheYear(Date Date)
	{
		return (Date.Day == 31 && Date.Month == 12);
	}

	bool IsFirstDayInTheMonth(Date Date)
	{
		return (Date.Day == 1);
	}

	bool IsFirstMonthInTheYear(short Month)
	{
		return (Month == 1);
	}

	bool IsFirstDayInTheYear(Date Date)
	{
		return (Date.Day == 1 && Date.Month == 1);
	}

	Date IncreaseDateByOneDay(Date Date)
	{
		if (IsLastDayInTheMonth(Date))
		{
			if (IsLastMonthInTheYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}

			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}

		else
		{
			Date.Day++;
		}

		return Date;
	}

	long long GetDifferenceBetweenTwoDatesInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
	{
		long long DifferenceInDays = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DifferenceInDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++DifferenceInDays : DifferenceInDays;
	}

	Date GetSystemDate()
	{
		time_t SystemTime = time(0);
		tm* SystemDate = localtime(&SystemTime);

		Date Date;
		Date.Day = SystemDate->tm_mday;
		Date.Month = SystemDate->tm_mon + 1;
		Date.Year = SystemDate->tm_year + 1900;

		return Date;
	}

	bool IsDateValid(Date Date)
	{
		short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > MonthDays)
		{
			printf("\n\nTHIS DATE IS NOT VALID , YOU CAN'T ENTER MORE THAN %d AS A DAY IN %s %d\n"
				, MonthDays, MonthLongName(Date.Month).c_str(), Date.Year);

			printf("PLEASE TRY AGAIN AND ENTER ANOTHER DATE :)\n\n");

			return false;
		}

		return true;
	}

	Date ReadDate()
	{
		Date Date;
		do
		{
			Date.Day = ReadPositiveNumber("ENTER DAY");
			Date.Month = ValidateNumberInRange(1, 12, "ENTER MONTH [BETWEEN 1 & 12]");
			Date.Year = abs(ReadPositiveNumber("ENTER YEAR"));

		} while (!IsDateValid(Date));

		return Date;
	}

	long long AgeInDays(Date BirthDate)
	{
		Date TodayDate = GetSystemDate();

		return GetDifferenceBetweenTwoDatesInDays(BirthDate, TodayDate, true);
	}

	void SwapDates(Date& Date1, Date& Date2)
	{
		Date TemporaryDate;
		TemporaryDate.Day = Date1.Day;
		TemporaryDate.Month = Date1.Month;
		TemporaryDate.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Day = Date2.Day;
		Date1.Day = Date2.Day;

		Date2.Day = TemporaryDate.Day;
		Date2.Day = TemporaryDate.Day;
		Date2.Day = TemporaryDate.Day;
	}

	long long GetDifferenceBetweenTwoUnorderedDatesInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
	{
		short SwapFlagValue = 1;
		long long DifferenceInDays = 0;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DifferenceInDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++DifferenceInDays * SwapFlagValue : DifferenceInDays * SwapFlagValue;
	}
	
	Date IncreaseDateByXDays(Date Date, long long Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneWeek(Date Date)
	{
		return Date = IncreaseDateByXDays(Date, 7);
	}

	Date IncreaseDateByXWeeks(Date Date, long long Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneMonth(Date Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}

		else
		{
			Date.Month++;
		}

		short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > MonthDays)
		{
			Date.Day = MonthDays;
		}

		return Date;
	}

	Date IncreaseDateByXMonths(Date Date, long long Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneYear(Date Date)
	{
		return Date = IncreaseDateByXMonths(Date, 12);
	}

	Date IncreaseDateByXYears(Date Date, long long Years)
	{
		for (int i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneDecade(Date Date)
	{
		return Date = IncreaseDateByXYears(Date, 10);
	}

	Date IncreaseDateByXDecades(Date Date, long long Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneCentury(Date Date)
	{
		return Date = IncreaseDateByXDecades(Date, 10);
	}

	Date IncreaseDateByXCenturies(Date Date, long long Centuries)
	{
		for (int i = 1; i <= Centuries; i++)
		{
			Date = IncreaseDateByOneCentury(Date);
		}

		return Date;
	}

	Date IncreaseDateByOneMillennium(Date Date)
	{
		return Date = IncreaseDateByXCenturies(Date, 10);
	}

	Date IncreaseDateByXMillenniums(Date Date, long long Millenniums)
	{
		for (int i = 1; i <= Millenniums; i++)
		{
			Date = IncreaseDateByOneMillennium(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneDay(Date Date)
	{
		if (IsFirstDayInTheMonth(Date))
		{
			if (IsFirstMonthInTheYear(Date.Month))
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}

			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}

		else
		{
			Date.Day--;
		}

		return Date;
	}

	Date DecreaseDateByXDays(Date Date, long long Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneWeek(Date Date)
	{
		return Date = DecreaseDateByXDays(Date, 7);
	}

	Date DecreaseDateByXWeeks(Date Date, long long Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneMonth(Date Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}

		else
		{
			Date.Month--;
		}

		short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > MonthDays)
		{
			Date.Day = MonthDays;
		}

		return Date;
	}

	Date DecreaseDateByXMonths(Date Date, long long Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneYear(Date Date)
	{
		return Date = DecreaseDateByXMonths(Date, 12);
	}

	Date DecreaseDateByXYears(Date Date, long long Years)
	{
		for (int i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneDecade(Date Date)
	{
		return Date = DecreaseDateByXYears(Date, 10);
	}

	Date DecreaseDateByXDecades(Date Date, long long Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneCentury(Date Date)
	{
		return Date = DecreaseDateByXDecades(Date, 10);
	}

	Date DecreaseDateByXCenturies(Date Date, long long Centuries)
	{
		for (int i = 1; i <= Centuries; i++)
		{
			Date = DecreaseDateByOneCentury(Date);
		}

		return Date;
	}

	Date DecreaseDateByOneMillennium(Date Date)
	{
		return Date = DecreaseDateByXCenturies(Date, 10);
	}

	Date DecreaseDateByXMillenniums(Date Date, long long Millenniums)
	{
		for (int i = 1; i <= Millenniums; i++)
		{
			Date = DecreaseDateByOneMillennium(Date);
		}

		return Date;
	}

	bool IsThisDayTheEndOfTheWeek(Date Date)
	{
		return DayOrderInWeek(Date) == 6; //SATURDAY = 6 IN GREGORIAN METHOD
	}

	bool IsThisDayAWeekEnd(Date Date)
	{
		return (DayOrderInWeek(Date) == 5 || DayOrderInWeek(Date) == 6);

		//FRIDAY = 5 & SATURDAY = 6 IN GREGORIAN METHOD
	}

	bool IsThisDayABusinessDay(Date Date)
	{
		return (!IsThisDayAWeekEnd(Date));
	}

	short DaysUntilTheEndOfTheWeek(Date Date)
	{
		return 6 - DayOrderInWeek(Date);
	}

	short DaysUntilTheEndOfTheMonth(Date Date)
	{
		return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day + 1;
	}

	short DaysUntilTheEndOfTheYear(Date StartDate)
	{
		Date EndYearDate;
		EndYearDate.Day = 31;
		EndYearDate.Month = 12;
		EndYearDate.Year = StartDate.Year;

		return GetDifferenceBetweenTwoDatesInDays(StartDate, EndYearDate, true);
	}

	long long CalculateVacationDays(Date VacationStartDate, Date VacationEndDate)
	{
		long long VacationDays = 0;

		while (IsDate1BeforeDate2(VacationStartDate, VacationEndDate))
		{
			if (IsThisDayABusinessDay(VacationStartDate))
			{
				VacationDays++;
			}

			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);
		}

		return VacationDays;
	}

	Date CalculateVacationEndDate(Date VacationStartDate, long long VacationDays)
	{
		Date VacationEndDate;

		while (VacationDays > 0)
		{
			if (IsThisDayABusinessDay(VacationStartDate))
			{
				VacationDays--;
			}

			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);
		}

		return VacationEndDate = VacationStartDate;
	}

	bool IsDate1AfterDate2(Date Date1, Date Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	enum ComapareDatesResults { Before = -1, Equal = 0, After = 1 };

	ComapareDatesResults CompareDates(Date Date1, Date Date2)
	{
		if (IsDate1EqualDate2(Date1, Date2))
		{
			return Equal;
		}

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return Before;
		}

		return After;
	}

	bool ArePeriodsOverlap(Period Period1, Period Period2)
	{
		return !(IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) || IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate));
	}

	long long PeriodLengthInDays(Period Period , bool IncludeEndDay = false)
	{
		return GetDifferenceBetweenTwoDatesInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsThisDateInThisPeriod(Date Date, Period Period)
	{
		return !(IsDate1BeforeDate2(Date, Period.StartDate) || IsDate1AfterDate2(Date, Period.EndDate));
	}

	long long CountOverlapDaysBetweenTwoPeriods(Period Period1, Period Period2)
	{
		if (!ArePeriodsOverlap(Period1, Period2))
		{
			return 0;
		}

		long long Period1Length = PeriodLengthInDays(Period1, true);
		long long Period2Length = PeriodLengthInDays(Period2, true);
		long long OverlapDays = 0;

		if (Period1Length <= Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsThisDateInThisPeriod(Period1.StartDate, Period2))
				{
					OverlapDays++;
				}

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}

		else
		{
			while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsThisDateInThisPeriod(Period2.StartDate, Period1))
				{
					OverlapDays++;
				}

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}

		return OverlapDays;
	}

	Date StringToDate(string DateString)
	{
		vector<string>DateVector = SpiltStringWordsToVector(DateString, "/");

		Date Date;
		Date.Day = stoi(DateVector[0]);
		Date.Month = stoi(DateVector[1]);
		Date.Year = stoll(DateVector[2]);

		return Date;
	}

	string DateToString(Date Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string FormatDate(Date Date, string Format = "DD/MM/YYYY")
	{
		string FormattedDate;

		FormattedDate = ReplaceWordsInStringUsingBuiltInFunction(Format, "DD", to_string(Date.Day));
		FormattedDate = ReplaceWordsInStringUsingBuiltInFunction(FormattedDate, "MM", to_string(Date.Month));
		FormattedDate = ReplaceWordsInStringUsingBuiltInFunction(FormattedDate, "YYYY", to_string(Date.Year));

		return FormattedDate;
	}


	//----------------------------------------------------------------------------
	//TEMPERATURE CONVERSIONS FUNCTIONS :
	//-----------------------------------------------

	long double CelsiusToKelvin(long double CelsiusTemperature)
	{
		return CelsiusTemperature + 273.15;
	}

	long double CelsiusToFahrenheit(long double CelsiusTemperature)
	{
		return (CelsiusTemperature * (9 / 5.0)) + 32;
	}

	long double CelsiusToRankine(long double CelsiusTemperature)
	{
		return (CelsiusTemperature * (9 / 5.0)) + 491.67;
	}

	long double CelsiusToNewton(long double CelsiusTemperature)
	{
		return CelsiusTemperature * (33 / 100.0);
	}

	long double CelsiusToRømer(long double CelsiusTemperature)
	{
		return (CelsiusTemperature * (21 / 40.0) + 7.5);
	}

	long double CelsiusToRéaumur(long double CelsiusTemperature)
	{
		return CelsiusTemperature * (4 / 5.0);
	}

	long double CelsiusToDelisle(long double CelsiusTemperature)
	{
		return (100 - CelsiusTemperature) * (3 / 2.0);
	}

	long double CelsiusToGasMark(long double CelsiusTemperature)
	{
		return pow(2, ((1.8 * CelsiusTemperature - 243) / 25));
	}

	//----------------------------------------------------------------------------
	//KELVIN FUNCTIONS :
	//-------------------------

	long double KelvinToCelsius(long double KelvinTemperature)
	{
		return KelvinTemperature - 273.15;
	}

	long double KelvinToFahrenheit(long double KelvinTemperature)
	{
		return ((KelvinTemperature - 273.15) * (9 / 5.0)) + 32;
	}

	long double KelvinToRankine(long double KelvinTemperature)
	{
		return (KelvinTemperature * (9 / 5.0));
	}

	long double KelvinToNewton(long double KelvinTemperature)
	{
		return (KelvinTemperature - 273.15) * (33 / 100.0);
	}

	long double KelvinToRømer(long double KelvinTemperature)
	{
		return (((KelvinTemperature - 273.15) * (21 / 40.0)) + 7.5);
	}

	long double KelvinToRéaumur(long double KelvinTemperature)
	{
		return (KelvinTemperature - 273.15) * (4 / 5.0);
	}

	long double KelvinToDelisle(long double KelvinTemperature)
	{
		return (373.15 - KelvinTemperature) * (3 / 2.0);
	}

	long double KelvinToGasMark(long double KelvinTemperature)
	{
		return CelsiusToGasMark(KelvinToCelsius(KelvinTemperature));
	}

	//----------------------------------------------------------------------------
	//FAHRENHEIT FUNCTIONS :
	//-------------------------

	long double FahrenheitToCelsius(long double FahrenheitTemperature)
	{
		return (FahrenheitTemperature - 32) * (5 / 9.0);
	}

	long double FahrenheitToKelvin(long double FahrenheitTemperature)
	{
		return ((FahrenheitTemperature - 32) * (5 / 9.0)) + 273.15;
	}

	long double FahrenheitToRankine(long double FahrenheitTemperature)
	{
		return FahrenheitTemperature + 459.67;
	}

	long double FahrenheitToNewton(long double FahrenheitTemperature)
	{
		return (FahrenheitTemperature - 32) * (11 / 60.0);
	}

	long double FahrenheitToRømer(long double FahrenheitTemperature)
	{
		return (((FahrenheitTemperature - 32) * (7 / 24.0)) + 7.5);
	}

	long double FahrenheitToRéaumur(long double FahrenheitTemperature)
	{
		return (FahrenheitTemperature - 32) * (4 / 9.0);
	}

	long double FahrenheitToDelisle(long double FahrenheitTemperature)
	{
		return (212 - FahrenheitTemperature) * (5 / 6.0);
	}

	long double FahrenheitToGasMark(long double FahrenheitTemperature)
	{
		return CelsiusToGasMark(FahrenheitToCelsius(FahrenheitTemperature));
	}


	//----------------------------------------------------------------------------
	//RANKINE FUNCTIONS :
	//-------------------------

	long double RankineToCelsius(long double RankineTemperature)
	{
		return (RankineTemperature - 491.67) * (5 / 9.0);
	}

	long double RankineToKelvin(long double RankineTemperature)
	{
		return RankineTemperature * (5 / 9.0);
	}

	long double RankineToFahrenheit(long double RankineTemperature)
	{
		return RankineTemperature - 459.67;
	}

	long double RankineToNewton(long double RankineTemperature)
	{
		return (RankineTemperature - 491.67) * (11 / 60.0);
	}

	long double RankineToRømer(long double RankineTemperature)
	{
		return (((RankineTemperature - 491.67) * (7 / 24.0)) + 7.5);
	}

	long double RankineToRéaumur(long double RankineTemperature)
	{
		return (RankineTemperature - 491.67) * (4 / 9.0);
	}

	long double RankineToDelisle(long double RankineTemperature)
	{
		return (671.67 - RankineTemperature) * (5 / 6.0);
	}

	long double RankineToGasMark(long double RankineTemperature)
	{
		return CelsiusToGasMark(RankineToCelsius(RankineTemperature));
	}

	//----------------------------------------------------------------------------
	//NEWTON FUNCTIONS :
	//-------------------------

	long double NewtonToCelsius(long double NewtonTemperature)
	{
		return NewtonTemperature * (100 / 33.0);
	}

	long double NewtonToKelvin(long double NewtonTemperature)
	{
		return (NewtonTemperature * (100 / 33.0)) + 273.15;
	}

	long double NewtonToFahrenheit(long double NewtonTemperature)
	{
		return (NewtonTemperature * (60.0 / 11)) + 32;
	}

	long double NewtonToRankine(long double NewtonTemperature)
	{
		return (NewtonTemperature * (60 / 11.0)) + 491.67;
	}

	long double NewtonToRømer(long double NewtonTemperature)
	{
		return (NewtonTemperature * (35.0 / 22) + 7.5);
	}

	long double NewtonToRéaumur(long double NewtonTemperature)
	{
		return NewtonTemperature * (80 / 33.0);
	}

	long double NewtonToDelisle(long double NewtonTemperature)
	{
		return (150 - (NewtonTemperature * (50 / 11.0)));
	}

	long double NewtonToGasMark(long double NewtonTemperature)
	{
		return CelsiusToGasMark(NewtonToCelsius(NewtonTemperature));
	}

	//----------------------------------------------------------------------------
	//RØMER FUNCTIONS :
	//-------------------------

	long double RømerToCelsius(long double RømerTemperature)
	{
		return (RømerTemperature - 7.5) * (40 / 21.0);
	}

	long double RømerToKelvin(long double RømerTemperature)
	{
		return ((RømerTemperature - 7.5) * (40 / 21.0) + 273.15);
	}

	long double RømerToFahrenheit(long double RømerTemperature)
	{
		return ((RømerTemperature - 7.5) * (24 / 7.0) + 32);
	}

	long double RømerToRankine(long double RømerTemperature)
	{
		return ((RømerTemperature - 7.5) * (24 / 7.0) + 491.67);
	}

	long double RømerToNewton(long double RømerTemperature)
	{
		return (RømerTemperature - 7.5) * (22 / 35.0);
	}

	long double RømerToRéaumur(long double RømerTemperature)
	{
		return (RømerTemperature - 7.5) * (32 / 21.0);
	}

	long double RømerToDelisle(long double RømerTemperature)
	{
		return (150 - ((RømerTemperature - 7.5) * (20 / 7.0)));
	}

	long double RømerToGasMark(long double RømerTemperature)
	{
		return CelsiusToGasMark(RømerToCelsius(RømerTemperature));
	}

	//----------------------------------------------------------------------------
	//RÉAUMUR FUNCTIONS :
	//-------------------------

	long double RéaumurToCelsius(long double RéaumurTemperature)
	{
		return RéaumurTemperature * (5 / 4.0);
	}

	long double RéaumurToKelvin(long double RéaumurTemperature)
	{
		return RéaumurTemperature * (5 / 4.0) + 273.15;
	}

	long double RéaumurToFahrenheit(long double RéaumurTemperature)
	{
		return RéaumurTemperature * (9 / 4.0) + 32;
	}

	long double RéaumurToRankine(long double RéaumurTemperature)
	{
		return RéaumurTemperature * (9 / 4.0) + 491.67;
	}

	long double RéaumurToNewton(long double RéaumurTemperature)
	{
		return RéaumurTemperature * (33 / 80.0);
	}

	long double RéaumurToRømer(long double RéaumurTemperature)
	{
		return (RéaumurTemperature * (21 / 32.0) + 7.5);
	}

	long double RéaumurToDelisle(long double RéaumurTemperature)
	{
		return (80 - RéaumurTemperature) * (15 / 8.0);
	}

	long double RéaumurToGasMark(long double RéaumurTemperature)
	{
		return CelsiusToGasMark(RéaumurToCelsius(RéaumurTemperature));
	}

	//----------------------------------------------------------------------------
	//DELISLE FUNCTIONS :
	//-------------------------

	long double DelisleToCelsius(long double DelisleTemperature)
	{
		return (150 - DelisleTemperature) * (2 / 3.0);
	}

	long double DelisleToKelvin(long double DelisleTemperature)
	{
		return (150 - DelisleTemperature) * (2 / 3.0) + 273.15;
	}

	long double DelisleToFahrenheit(long double DelisleTemperature)
	{
		return (212 - (DelisleTemperature * (6 / 5.0)));
	}

	long double DelisleToRankine(long double DelisleTemperature)
	{
		return (671.67 - (DelisleTemperature * (6 / 5.0)));
	}

	long double DelisleToNewton(long double DelisleTemperature)
	{
		return (150 - DelisleTemperature) * (11 / 50.0);
	}

	long double DelisleToRømer(long double DelisleTemperature)
	{
		return ((150 - DelisleTemperature) * (7 / 20.0) + 7.5);
	}

	long double DelisleToRéaumur(long double DelisleTemperature)
	{
		return (150 - DelisleTemperature) * (8 / 15.0);
	}

	long double DelisleToGasMark(long double DelisleTemperature)
	{
		return CelsiusToGasMark(DelisleToCelsius(DelisleTemperature));
	}


	//----------------------------------------------------------------------------
	//GAS MARK FUNCTIONS :
	//-------------------------

	long double GasMarkToCelsius(long double GasMark)
	{
		return ((243 - (-25 * (log(GasMark) / log(2)))) / 1.8);
	}

	long double GasMarkToKelvin(long double GasMark)
	{
		return CelsiusToKelvin(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToFahrenheit(long double GasMark)
	{
		return CelsiusToFahrenheit(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToRankine(long double GasMark)
	{
		return CelsiusToRankine(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToNewton(long double GasMark)
	{
		return CelsiusToNewton(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToRømer(long double GasMark)
	{
		return CelsiusToRømer(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToRéaumur(long double GasMark)
	{
		return CelsiusToRéaumur(GasMarkToCelsius(GasMark));
	}

	long double GasMarkToDelisle(long double GasMark)
	{
		return CelsiusToDelisle(GasMarkToCelsius(GasMark));
	}
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//FEATURES SECTION :
	//-------------------------
	//CHANGE SYSTEM THEME FEATURE :
	//-------------------------------

	string SystemThemeColorsDataFileName = "SYSTEM THEME COLORS.txt";

	struct SystemThemeColors
	{
		CLIColors BackgroundColor = Black;
		CLIColors ForegroundColor = BrightWhite;
	};

	SystemThemeColors SystemThemeColor;

	enum ChangeSystemThemeMenuChoices { Background = 1, Foreground = 2, Default = 3 };

	void PrintChangeSystemThemeMenu()
	{
		cout << "=====================================================================\n\n";
		cout << Tab(3) << "CHANGE SYSTEM THEME MENU\n\n";
		cout << "=====================================================================\n";
		cout << Tab(3) << "[1] CHANGE BACKGROUND COLOR." << "\n";
		cout << Tab(3) << "[2] CHANGE FOREGROUND COLOR [TEXT COLOR]." << "\n";
		cout << Tab(3) << "[3] RETURN DEFAULT SYSTEM THEME." << "\n";
		cout << "=====================================================================\n\n";
	}

	ChangeSystemThemeMenuChoices ReadChangeSystemThemeMenuChoice()
	{
		return (ChangeSystemThemeMenuChoices)(ValidateNumberInRange(1, 3, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 3] ? "));
	}

	void PrintColorsMenu()
	{
		cout << "====================================================================\n\n";
		cout << Tab(3) << "COLORS MENU\n\n";
		cout << "====================================================================\n";
		cout << Tab(2) << "[1] BLACK";
		cout << Tab(2) << "[2] BLUE" << "\n";
		cout << Tab(2) << "[3] GREEN";
		cout << Tab(2) << "[4] AQUA" << "\n";
		cout << Tab(2) << "[5] RED";
		cout << Tab(3) << "[6] PURPLE" << "\n";
		cout << Tab(2) << "[7] YELLOW";
		cout << Tab(2) << "[8] WHITE" << "\n";
		cout << Tab(2) << "[9] GRAY";
		cout << Tab(2) << "[10] LIGHT BLUE" << "\n";
		cout << Tab(2) << "[11] LIGHT GREEN";
		cout << Tab(1) << "[12] LIGHT AQUA" << "\n";
		cout << Tab(2) << "[13] LIGHT RED";
		cout << Tab(2) << "[14] LIGHT PURPLE" << "\n";
		cout << Tab(2) << "[15] LIGHT YELLOW";
		cout << Tab(1) << "[16] BRIGHT WHITE" << "\n";
		cout << "====================================================================\n\n";
	}

	CLIColors ReadColorsMenuChoice()
	{
		return (CLIColors)(ValidateNumberInRange(1, 16, "CHOOSE THE COLOR YOU WANT ? [1 TO 16] ? ") - 1);
	}

	string ReturnChangeSystemThemeMenuChoiceString(ChangeSystemThemeMenuChoices ChangeSystemThemeMenuChoice)
	{
		string ChoiceString[]{ "" , "BACKGROUND" , "FOREGROUND" };

		return ChoiceString[ChangeSystemThemeMenuChoice];
	}

	void SaveSystemThemeColorsToFile();

	void ChangeSystemTheme(SystemThemeColors& SystemThemeColor)
	{
		do
		{
			PrintChangeSystemThemeMenu();
			ChangeSystemThemeMenuChoices ChangeSystemThemeMenuChoice = ReadChangeSystemThemeMenuChoice();

			if (ChangeSystemThemeMenuChoice == Default)
			{
				ChangeCLIColors(SystemThemeColor.BackgroundColor = Black, SystemThemeColor.ForegroundColor = BrightWhite);
				SaveSystemThemeColorsToFile();
			}

			else
			{
				do
				{
					PrintColorsMenu();
					CLIColors Color = ReadColorsMenuChoice();

					ChangeSystemThemeMenuChoice == Background ? ChangeCLIColors(SystemThemeColor.BackgroundColor = Color, SystemThemeColor.ForegroundColor) : ChangeCLIColors(SystemThemeColor.BackgroundColor, SystemThemeColor.ForegroundColor = Color);
					SaveSystemThemeColorsToFile();

				} while (DoYouWantToDoThisWithoutClear("DO YOU WANT TO CHANGE ANOTHER COLOR IN " + ReturnChangeSystemThemeMenuChoiceString(ChangeSystemThemeMenuChoice) + " ?"));
			}

		} while (DoYouWantToDoThisWithClear("DO YOU WANT TO CHANGE ANOTHER COLOR IN SYSTEM THEME?"));
	}

	string SystemThemeColorsToRecord(SystemThemeColors SystemThemeColors, string Separator)
	{
		return to_string(SystemThemeColors.BackgroundColor) + Separator + to_string(SystemThemeColors.ForegroundColor);
	}

	SystemThemeColors RecordToSystemThemeColors(string Record, string Separator)
	{
		vector<string>SystemThemeColorsVector = SpiltStringWordsToVector(Record, Separator);

		SystemThemeColors SystemThemeColors;
		SystemThemeColors.BackgroundColor = (CLIColors)(stoi(SystemThemeColorsVector[0]));
		SystemThemeColors.ForegroundColor = (CLIColors)(stoi(SystemThemeColorsVector[1]));

		return SystemThemeColors;
	}

	void SaveSystemThemeColorsToFile()
	{
		fstream File;

		File.open(SystemThemeColorsDataFileName, ios::out);

		if (File.is_open())
		{
			File << SystemThemeColorsToRecord(SystemThemeColor, "#//#");

			File.close();
		}

	}

	void LoadSystemThemeColorsFromFile()
	{
		fstream File;

		File.open(SystemThemeColorsDataFileName, ios::in);

		if (File.is_open())
		{
			string Record;
			File >> Record;
			SystemThemeColor = RecordToSystemThemeColors(Record, "#//#");
		}
	}


}
