#include<iostream>
#include<vector>
#include<string>
#include <limits>
#include<stdio.h>
#include<stdlib.h>
#include "ABODAstd.h"

using namespace std;

string AdminsDataFileName = "ADMINS.txt";
string UsersDataFileName = "USERS.txt";

bool ReturnSystemFlag = false;

struct User {
	string Name;
	unsigned int Id;
	int Password;
	string Address;
	string Phone;
	long double Balance;
	long double TakenLoan = 0;
	bool Locked = 0;
};

struct Admin
{
	string AdminName;
	string Password;
	int Permissions = 0;
};

enum EditSettingsChoice {
	EditName = 1, EditId = 2, EditPassword = 3,
	EditAddress = 4, EditPhone = 5, EditBalance = 6,
	ReturnMenu = 7
};

enum ATMMenuChoice {
	Balance = 1, QuickWithDraw = 2, NormalWithDraw = 3, Deposite = 4, Transfer = 5
	, TakeLoan = 6, PayOffLoan = 7, ShowAccount = 8, EditAccount = 9, DeleteAccount = 10
	, LogOutATM = 11, ReturnToSystemMenu = 12, ExitTheSystem = 13
};

enum MainMenuChoice {
	CreateMyAccount = 1, AccessMyAccount = 2, ShowAccounts = 3
	, UnlockAccount = 4, FindAccount = 5, ManageTheAdmins = 6,
	ClearBank = 7, LogOut = 8, ChangeSystemThemes = 9, ReturnToTheSystem = 10, ExitAllTheSystem = 11
};

enum FindMenuChoices {
	FindById = 1, FindByName = 2, FindByAddress = 3,
	FindByPhone = 4, ReturnMainMenu = 5
};

enum ManageAdminsMenuChoices {
	ListTheAdmins = 1, AddNewAdmin = 2, DeleteAdmins = 3
	, UpdateAdmins = 4, FindAdmins = 5, MainMenu = 6
};

enum AdminNameOnlyOrAdminNameAndPassword {
	AdminNameOnly = 1,
	AdminNameAndPassword = 2
};

enum MainMenuPermissions {
	FullAccess = -1, CreateAccountAccess = 1,
	AccessAccountAccess = 2, ShowAccountsAccess = 4,
	UnlockAccountAccess = 8, FindAccountAccess = 16,
	ManageAdminsAccess = 32, ClearTheBankAccess = 64
};

enum AdminOrUserMod { AdminMod = 1, UserMod = 2 };

enum QuickWithdrawMenuChoices {
	Twenty = 1, Fifty = 2, OneHundred = 3, TwoHundreds = 4,
	FourHundreds = 5, SixHundreds = 6, EightHundreds = 7, OneThousand = 8, ExitQuickWithdrawMenu = 9
};

enum DualBankAndATMSystemMenuChoices { TheBankSystem = 1, ATM = 2, ExitAll = 3 };

void SaveUsersDataToFile(vector<User>& Users);

void SaveAdminsDataToFile(vector<Admin>& Admins);

void LoadAdminsDataFromFile(vector<Admin>& Admins);

bool DoesAdminHavePermissionTo(Admin& Admin, MainMenuPermissions MainMenuPermission)
{
	if ((Admin.Permissions == -1) || ((Admin.Permissions & MainMenuPermission) == MainMenuPermission))
	{
		return true;
	}

	system("cls");
	SectionBanner("ACCESS DENIED ,\nYOU DON'T HAVE PERMISSIONS TO DO THIS ,\nPLEASE CONTACT YOU ADMIN.", -1);
	return false;
}

string CreateName()
{
	string AccountName = ReadStringLine("ENTER THE ACCOUNT NAME");

	return AccountName;
}

int CreatePassword()
{
	int AccountPassword = ReadPositiveNumber("ENTER THE ACCOUNT PASSWORD");

	return AccountPassword;
}

bool IsAccountLocked(int AccountIndex, vector<User>& Users)
{
	if (Users[AccountIndex].Locked == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int IsReceiverIdSuitable(int ReceiverAccountId, int SenderAccountId, vector<User>& Users)
{

	for (int i = 0; i < Users.size(); i++)
	{
		if (Users[i].Id == ReceiverAccountId && ReceiverAccountId != SenderAccountId)
		{
			return i;
		}
	}

	cout << "INVALID ID\n";
	return -1;
}

bool IsIdFound(int AccountId, vector<User>& Users)
{
	for (int i = 0; i < Users.size(); i++)
	{
		if (AccountId == Users[i].Id)
		{
			cout << "THIS ID IS TAKEN\n";
			return 1;
		}
	}

	return 0;
}

bool IsIdFound(int EdittedId, vector<User>& Users, int AccountIndex)
{
	for (int i = 0; i < Users.size(); i++)
	{
		if (AccountIndex == i)
		{
			continue;
		}

		if (EdittedId == Users[i].Id)
		{
			cout << "THIS ID IS TAKEN\n";
			return 1;
		}
	}

	return 0;
}

int ReturnAccountIndex(int AccountId, vector<User>& Users)
{
	int AccountIndex;
	for (int i = 0; i < Users.size(); i++)
	{
		if (AccountId == Users[i].Id)
		{
			return i;
		}
	}

	cout << "INVALID ID\n";
	return -1;
}

int CreateId(vector<User>& Users)
{
	int AccountId;
	do
	{
		AccountId = ReadPositiveNumber("ENTER THE ACCOUNT ID");

	} while (IsIdFound(AccountId, Users));

	return AccountId;
}

string CreateAddress()
{
	string AccountAddress = ReadStringLine("ENTER THE ACCOUNT ADDRESS");

	return AccountAddress;
}

long double CreateBalance()
{
	long double AccountBalance = ReadDoublePositiveNumber("ENTER THE ACCOUNT BALANCE");

	return AccountBalance;
}

string CreatePhone()
{
	string AccountPhone = ReadFullPhoneNumber("ENTER THE ACCOUNT PHONE KEY", "ENTER THE ACCOUNT PHONE NUMBER");

	return AccountPhone;
}

void CreateAccount(Admin& Admin, vector<User>& Users)
{
	if (DoesAdminHavePermissionTo(Admin, CreateAccountAccess))
	{

		SectionBanner("CREATE ACCOUNT", 2);

		User User;
		User.Name = CreateName();
		User.Id = CreateId(Users);
		User.Password = CreatePassword();
		User.Address = CreateAddress();
		User.Phone = CreatePhone();
		User.Balance = CreateBalance();
		Users.push_back(User);
		SaveUsersDataToFile(Users);
		cout << "\nYOUR ACCOUNT IS CREATED SUCCESSFULLY\n";
	}

}

void PrintATMMenu()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "TRANSACTIONS SCREEN					 \n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1]  SHOW BALANCE." << "\n";
	cout << Tab(3) << "[2]  QUICK WITHDRAW." << "\n";
	cout << Tab(3) << "[3]  NORMAL WITHDRAW." << "\n";
	cout << Tab(3) << "[4]  DEPOSITE." << "\n";
	cout << Tab(3) << "[5]  TRANSFER." << "\n";
	cout << Tab(3) << "[6]  TAKE A LOAN." << "\n";
	cout << Tab(3) << "[7]  PAY OFF A LOAN." << "\n";
	cout << Tab(3) << "[8]  SHOW MY ACCOUNT." << "\n";
	cout << Tab(3) << "[9]  EDIT MY ACCOUNT." << "\n";
	cout << Tab(3) << "[10] DELETE MY ACCOUNT." << "\n";
	cout << Tab(3) << "[11] LOG OUT." << "\n";
	cout << Tab(3) << "[12] RETURN TO THE DUAL SYSTEM." << "\n";
	cout << Tab(3) << "[13] EXIT THE DUAL SYSTEM." << "\n";
	cout << "====================================================================\n\n";
}

int ReadYourIdAndReturnAccountIndex(vector<User>& Users)
{
	int AccountId;
	do
	{
		AccountId = ReadPositiveNumber("ENTER YOUR ACCOUNT ID");
	} while (ReturnAccountIndex(AccountId, Users) == -1);

	return ReturnAccountIndex(AccountId, Users);
}

bool IsPasswordRight(int AccountIndex, int WrittenPassword, vector<User>& Users, short& WrongCounter)
{
	if (WrittenPassword == Users[AccountIndex].Password)
	{
		cout << "\nRIGHT PASSWORD\n";
		GoToPauseMessage("\n\nPRESS ANY KEY TO GO TO TRANSACTIONS MENU...");
		return 1;
	}
	else
	{
		WrongCounter++;
		cout << "WRONG PASSWORD\n";
		cout << "YOU HAVE " << (3 - WrongCounter) << " TRIALS REMAINING\n";
		return 0;
	}
}

bool ReadYourPassword(int AccountIndex, vector<User>& Users)
{
	int AccountPassword;
	short WrongCounter = 0;
	do
	{
		if (WrongCounter == 3 || Users[AccountIndex].Locked == true)
		{
			Users[AccountIndex].Locked = 1;
			cout << "YOUR ACCOUNT IS LOCKED , GO TO BANK AND ASK THE CUSTOMER SERVICE TO UNLOCK IT\n";
			SaveUsersDataToFile(Users);
			return 0;
		}

		AccountPassword = ReadPositiveNumber("ENTER YOUR ACCOUNT PASSWORD");

	} while (IsPasswordRight(AccountIndex, AccountPassword, Users, WrongCounter) == 0);

	return 1;
}

void ShowBalance(int AccountIndex, vector<User>& Users)
{
	SectionBanner("SHOW BALANCE", 2);
	cout << "YOUR BALANCE : " << Users[AccountIndex].Balance << " L.E\n";
}

bool CanHeWithDraw(int AccountIndex, vector<User>& Users, long double WithdrawnBalance = 0)
{

	if (Users[AccountIndex].Balance == 0)
	{
		printf("YOUR ACCOUNT IS EMPTY! , YOU CAN'T WITHDRAW NOW\n");
		return 0;
	}

	if (Users[AccountIndex].Balance < WithdrawnBalance)
	{
		printf("THIS AMOUNT EXCEEDS YOUR BALANCE , ENTER ANOTHER BALANCE\n");
		return 0;
	}

	return 1;
}

void PrintQuickWithdrawScreen()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "QUICK WITHDRAW				 \n\n";
	cout << "====================================================================\n";
	cout << Tab(2) << "[1] 20";
	cout << Tab(2) << "[2] 50" << "\n";
	cout << Tab(2) << "[3] 100";
	cout << Tab(2) << "[4] 200" << "\n";
	cout << Tab(2) << "[5] 400";
	cout << Tab(2) << "[6] 600" << "\n";
	cout << Tab(2) << "[7] 800";
	cout << Tab(2) << "[8] 1000" << "\n";
	cout << Tab(2) << "[9] EXIT" << "\n";
	cout << "====================================================================\n\n";
}

QuickWithdrawMenuChoices ReadQuickWithdrawMenuChoice()
{
	return (QuickWithdrawMenuChoices)(ValidateDoubleNumberInRange(1, 9, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 9] ?"));
}

short ReturnQuickWithdrawChoiceBalance(QuickWithdrawMenuChoices QuickWithdrawMenuChoice)
{
	short QuickWithdrawBalances[] = { 0 , 20 , 50 , 100 , 200 , 400 , 600 , 800 , 1000 , 0 };

	return QuickWithdrawBalances[QuickWithdrawMenuChoice];
}

void QuickWithdraw(int AccountIndex, vector<User>& Users)
{
	if (CanHeWithDraw(AccountIndex, Users))
	{
		PrintQuickWithdrawScreen();
		printf("YOUR BALANCE IS %.2lf \n", Users[AccountIndex].Balance);
		QuickWithdrawMenuChoices QuickWithdrawMenuChoice = ReadQuickWithdrawMenuChoice();
		if (QuickWithdrawMenuChoice == ExitQuickWithdrawMenu)
		{
			return;
		}

		else
		{
			long double QuickWithdrawnBalance = ReturnQuickWithdrawChoiceBalance(QuickWithdrawMenuChoice);
			if (CanHeWithDraw(AccountIndex, Users, QuickWithdrawnBalance))
			{
				if (DoYouWantToDoThisWithoutClear("ARE YOU SURE YOU WANT TO PERFORM THIS TRANSACTION ?"))
				{
					Users[AccountIndex].Balance -= QuickWithdrawnBalance;
					SaveUsersDataToFile(Users);
					printf("DONE SUCCESSFULLY. NEW BALANCE IS : %.2lf\n", Users[AccountIndex].Balance);
				}
			}
		}
	}
}

void NormalWithDrawBalance(int AccountIndex, vector<User>& Users)
{
	SectionBanner("WITHDRAW BALANCE", 2);

	if (CanHeWithDraw(AccountIndex, Users))
	{
		long double WithDraw = ReadNumberMultipleOf("ENTER AN AMOUNT MULTIPLE OF 5'S ?", 5);

		if (CanHeWithDraw(AccountIndex, Users, WithDraw))
		{
			Users[AccountIndex].Balance -= WithDraw;
			SaveUsersDataToFile(Users);
			cout << "THE MONEY IS WITHDRAWN SUCCESSFULLY\n";
			cout << "YOUR BALANCE NOW : " << Users[AccountIndex].Balance << " L.E" << "\n";
		}
	}
}

void DepositeBalance(int AccountIndex, vector<User>& Users)
{
	SectionBanner("DEPOSITE BALANCE", 2);

	long double Deposite = ReadDoublePositiveNumber("ENTER THE MONEY YOU WANT TO DEPOSITE");
	Users[AccountIndex].Balance += Deposite;

	cout << "YOUR BALANCE NOW : " << Users[AccountIndex].Balance << " L.E" << "\n";
	SaveUsersDataToFile(Users);
	cout << "THE MONEY IS DEPOSITED SUCCESSFULLY\n";
}

int ReadReceiverAccountAndReturnReceiverIndex(int SenderAccountId, vector<User>& Users)
{
	int ReceiverAccountId;
	do
	{
		ReceiverAccountId = ReadPositiveNumber("ENTER THE RECEIVER ACCOUNT ID");
	} while (IsReceiverIdSuitable(ReceiverAccountId, SenderAccountId, Users) == -1);

	return IsReceiverIdSuitable(ReceiverAccountId, SenderAccountId, Users);
}

bool IsTransferInSufficient(long double TransferBalance, int SenderAccountIndex, vector<User>& Users)
{
	if (TransferBalance > Users[SenderAccountIndex].Balance)
	{
		cout << "THIS MONEY BIGGER THAN YOUR BALANCE\n";
		return 1;
	}
	else
	{
		return 0;
	}
}

long double ReadTransferBalance(int SenderAccountIndex, vector<User>& Users)
{
	long double TransferBalance;
	do
	{
		TransferBalance = ReadDoublePositiveNumber("ENTER THE AMOUNT YOU WANT TO TRANSFER");

	} while (IsTransferInSufficient(TransferBalance, SenderAccountIndex, Users) == 1);

	return TransferBalance;
}

void TransferBalance(int SenderAccountIndex, vector<User>& Users)
{
	SectionBanner("TRANSFER BALANCE", 2);

	if (Users.size() != 1)
	{
		int ReceiverAccountIndex = ReadReceiverAccountAndReturnReceiverIndex(Users[SenderAccountIndex].Id, Users);
		long double TransferBalance = ReadTransferBalance(SenderAccountIndex, Users);

		Users[ReceiverAccountIndex].Balance += TransferBalance;
		Users[SenderAccountIndex].Balance -= TransferBalance;
		SaveUsersDataToFile(Users);
		cout << "THE MONEY IS TRANSFERRED SUCCESSFULLY\n";
	}

	else
	{
		cout << "THERE IS NO ACCOUNTS TO TRANSFER TO\n";
	}

}

bool CanHeTakeALoan(int AccountIndex, vector<User>& Users)
{
	if (Users[AccountIndex].Balance >= 5000)
	{
		return 1;
	}
	else
	{
		cout << "YOUR BALANCE SHOULD BE AT LEAST 5000 L.E TO TAKE A LOAN\n";
		return 0;
	}
}

long double Get80PercentOfAccountBalance(int AccountIndex, vector<User>& Users)
{
	return (Users[AccountIndex].Balance - Users[AccountIndex].TakenLoan) * 0.8;
}

bool IsTakenLoanInSufficient(long double TakenLoan, int AccountIndex, vector<User>& Users)
{
	if (TakenLoan + Users[AccountIndex].TakenLoan > Get80PercentOfAccountBalance(AccountIndex, Users))
	{
		cout << "YOU CAN'T TAKE A LOAN MORE THAN 80 PERCENT OF YOUR BALANCE\n";
		cout << "YOU CAN TAKE AT MOST " << Get80PercentOfAccountBalance(AccountIndex, Users) << " L.E AS A TOTAL TAKEN LOAN" << "\n";
		return 1;
	}

	else
	{
		return 0;
	}
}

bool IsLoanFinished(int AccountIndex, vector<User>& Users)
{
	if (Users[AccountIndex].TakenLoan >= Get80PercentOfAccountBalance(AccountIndex, Users))
	{
		cout << "YOU HAVE REACHED YOUR MAXIMUM LIMIT OF LOANING\n";
		cout << "PLEASE PAY OFF YOUR LOANS FAST\n";
		cout << "OR WE WILL COME TO YOUR HOME\n";
		return 1;
	}

	else
	{
		return 0;
	}
}

void ReadALoan(int AccountIndex, vector<User>& Users)
{
	if (IsLoanFinished(AccountIndex, Users) == false)
	{
		long double TakenLoan;
		if (CanHeTakeALoan(AccountIndex, Users) == 1)
		{
			do
			{
				TakenLoan = ReadDoublePositiveNumber("ENTER THE LOAN YOU WANT TO TAKE");
			} while (IsTakenLoanInSufficient(TakenLoan, AccountIndex, Users) == 1);

			Users[AccountIndex].TakenLoan += TakenLoan;
			Users[AccountIndex].Balance += TakenLoan;

			SaveUsersDataToFile(Users);
			cout << "THE LOAN IS TAKED SUCCESSFULLY\n";
		}
	}
}

void TakeALoan(int AccountIndex, vector<User>& Users)
{
	SectionBanner("TAKING LOAN", 2);

	ReadALoan(AccountIndex, Users);
}

bool DoesHeHaveLoan(int AccountIndex, vector<User>& Users)
{
	if (Users[AccountIndex].TakenLoan != 0)
	{
		return 1;
	}

	else
	{
		cout << "YOU DON'T HAVE ANY LOANS TO PAYOFF\n";
		return 0;
	}
}

bool IsPaidOffLoanInSufficient(long double PaidOffLoan, int AccountIndex, vector<User>& Users)
{
	if (PaidOffLoan > Users[AccountIndex].Balance)
	{
		cout << "INSUFFICIENT PAYMENT\n";
		cout << "YOU CAN'T PAY MORE THAN YOUR BANK BALANCE\n";
		return 1;
	}
	else if (PaidOffLoan > Users[AccountIndex].TakenLoan)
	{
		cout << "YOU CAN'T PAY OFF MORE THAN YOUR LOAN\n";
		return 1;
	}

	else
	{
		return 0;
	}
}

void ReadPaidOffLoan(int AccountIndex, vector<User>& Users)
{
	if (DoesHeHaveLoan(AccountIndex, Users) == true)
	{
		long double PaidOffLoan;
		do
		{
			PaidOffLoan = ReadDoublePositiveNumber("ENTER THE AMOUNT OF LOAN YOU WANT TO PAY OFF");
		} while (IsPaidOffLoanInSufficient(PaidOffLoan, AccountIndex, Users) == 1);

		Users[AccountIndex].TakenLoan -= PaidOffLoan;
		Users[AccountIndex].Balance -= PaidOffLoan;

		SaveUsersDataToFile(Users);
		cout << "YOUR PAYING OFF PROCESS IS SUCCESSFULLY OCCURRED\n";
	}
}

void PayOffALoan(int AccountIndex, vector<User>& Users)
{
	SectionBanner("PAYING A LOAN", 2);

	ReadPaidOffLoan(AccountIndex, Users);
}

string LockingState(User& User)
{
	if (User.Locked == 1)
	{
		return "LOCKED";
	}

	else
	{
		return "UNLOCKED";
	}
}

void PrintUser(User& User)
{
	cout << "------------------------------------------------------\n";
	cout << "NAME          : " << User.Name << "\n" <<
		"ID            : " << User.Id << "\n" <<
		"PASSWORD      : " << User.Password << "\n" <<
		"ADDRESS       : " << User.Address << "\n" <<
		"PHONE         : " << User.Phone << "\n" <<
		"BALANCE       : " << User.Balance << "\n" <<
		"TAKEN LOAN    : " << User.TakenLoan << "\n" <<
		"LOCKING STATE : " << LockingState(User) << "\n";
	cout << "------------------------------------------------------\n";
}

void ShowMyAccount(int AccountIndex, vector<User>& Users)
{
	SectionBanner("SHOW ACCOUNT", 2);

	PrintUser(Users[AccountIndex]);
}

void PrintEditMenu()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "EDIT SCREEN				 \n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1] EDIT NAME." << "\n";
	cout << Tab(3) << "[2] EDIT ID." << "\n";
	cout << Tab(3) << "[3] EDIT PASSWORD." << "\n";
	cout << Tab(3) << "[4] EDIT ADDRESS." << "\n";
	cout << Tab(3) << "[5] EDIT PHONE." << "\n";
	cout << Tab(3) << "[6] EDIT ADDRESS." << "\n";
	cout << Tab(3) << "[7] RETURN TO TRANSACTIONS MENU." << "\n";
	cout << "====================================================================\n\n";
}

string EditMyName()
{
	string EdittedName = ReadString("ENTER YOUR NEW ACCOUNT NAME");

	return EdittedName;
}

string EditMyAddress()
{
	string EdittedAddress = ReadString("ENTER YOUR NEW ACCOUNT ADDRESS");

	return EdittedAddress;
}

string EditMyPhone()
{
	string EdittedPhone = ReadStringLine("ENTER YOUR NEW ACCOUNT PHONE");

	return EdittedPhone;
}

int EditMyPassword()
{
	int EdittedPassword = ReadPositiveNumber("ENTER YOUR NEW ACCOUNT PASSWORD");

	return EdittedPassword;
}

long double EditMyBalance()
{
	long double EdittedBalance = ReadDoublePositiveNumber("ENTER YOUR NEW ACCOUNT BALANCE");

	return EdittedBalance;
}

int EditMyId(vector<User>& Users, int AccountIndex)
{
	int EdittedId;
	do
	{
		EdittedId = ReadPositiveNumber("ENTER YOUR NEW ACCOUNT ID");

	} while (IsIdFound(EdittedId, Users, AccountIndex) == 1);

	return EdittedId;
}

EditSettingsChoice ReadEditSettingsChoice()
{
	return (EditSettingsChoice)(ValidateNumberInRange(1, 6));
}

void EditMyAccount(int AccountIndex, vector<User>& Users)
{
	while (true)
	{
		PrintEditMenu();
		EditSettingsChoice EditSettingsChoice = ReadEditSettingsChoice();
		if (EditSettingsChoice == EditName)
		{
			string EdittedName = EditMyName();
			Users[AccountIndex].Name = EdittedName;
			SaveUsersDataToFile(Users);
		}

		else if (EditSettingsChoice == EditId)
		{
			int EdittedId = EditMyId(Users, AccountIndex);
			Users[AccountIndex].Id = EdittedId;
			SaveUsersDataToFile(Users);
		}

		else if (EditSettingsChoice == EditPassword)
		{
			int EdittedPassword = EditMyPassword();
			Users[AccountIndex].Password = EdittedPassword;
			SaveUsersDataToFile(Users);
		}
		else if (EditSettingsChoice == EditAddress)
		{
			string EdittedAddress = EditMyAddress();
			Users[AccountIndex].Address = EdittedAddress;
			SaveUsersDataToFile(Users);
		}

		else if (EditSettingsChoice == EditPhone)
		{
			string EdittedPhone = EditMyPhone();
			Users[AccountIndex].Phone = EdittedPhone;
			SaveUsersDataToFile(Users);
		}

		else if (EditSettingsChoice == EditBalance)
		{
			long double EdittedBalance = EditMyBalance();
			Users[AccountIndex].Balance = EdittedBalance;
			SaveUsersDataToFile(Users);
		}

		else if (EditSettingsChoice == ReturnMenu)
		{
			break;
		}
	}
}

bool AreYouSureToDeleteYourAccount()
{
	string Choice;
	do
	{
		cout << "ARE YOU SURE TO DELETE YOUR ACCOUNT[Y/N]\n";
		cin >> Choice;
	} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

	if (Choice == "Y" || Choice == "y")
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

bool DeleteMyAccount(int AccountIndex, vector<User>& Users)
{
	SectionBanner("DELETE ACCOUNT", 2);

	if (AreYouSureToDeleteYourAccount())
	{
		if (ReadYourPassword(AccountIndex, Users) == true)
		{
			Users.erase(Users.begin() + AccountIndex);
			SaveUsersDataToFile(Users);
			cout << "YOUR ACCOUNT IS DELETED SUCCESSFULLY\n";
			return 1;
		}
		return 1;
	}


}

ATMMenuChoice ReadATMMenuChoice()
{
	return (ATMMenuChoice)(ValidateNumberInRange(1, 13, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 13] ?"));
}

bool IsVectorEmpty(vector<User>& Users)
{
	if (Users.empty() == true)
	{
		return 1;
	}

	else {
		return 0;
	}
}

int LoginATM(vector<User>& Users)
{
	int AccountIndex;
	bool LoginFailed = false;
	SectionBanner("USER LOGIN SCREEN");
	do
	{
		AccountIndex = ReadYourIdAndReturnAccountIndex(Users);
		LoginFailed = ReadYourPassword(AccountIndex, Users) ? false : true;
		if (Users[AccountIndex].Locked)
		{
			return -1;
		}
	} while (LoginFailed);

	return AccountIndex;
}

void AccessAccount(vector<User>& Users, Admin& Admin, AdminOrUserMod AdminOrUserMod = AdminMod)
{
	if (AdminOrUserMod == UserMod)
	{
		goto AccessAccountStart;
	}

	else if (AdminOrUserMod == AdminMod)
	{
		if (DoesAdminHavePermissionTo(Admin, AccessAccountAccess))
		{

		AccessAccountStart:
			ClearScreen();
			if (!IsVectorEmpty(Users))
			{
				int AccountIndex = LoginATM(Users);
				if (AccountIndex != -1)
				{
					while (true)
					{
						ClearScreen();
						PrintATMMenu();
						ATMMenuChoice ATMMenuChoice = ReadATMMenuChoice();
						if (ATMMenuChoice == Balance)
						{
							ClearScreen();
							ShowBalance(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == QuickWithDraw)
						{
							ClearScreen();
							QuickWithdraw(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == NormalWithDraw)
						{
							ClearScreen();
							NormalWithDrawBalance(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == Deposite)
						{
							ClearScreen();
							DepositeBalance(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == Transfer)
						{
							ClearScreen();
							TransferBalance(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == TakeLoan)
						{
							ClearScreen();
							TakeALoan(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == PayOffLoan)
						{
							ClearScreen();
							PayOffALoan(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == ShowAccount)
						{
							ClearScreen();
							ShowMyAccount(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == EditAccount)
						{
							ClearScreen();
							EditMyAccount(AccountIndex, Users);
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == DeleteAccount)
						{
							ClearScreen();
							if (DeleteMyAccount(AccountIndex, Users) == true)
							{
								break;
							}
							GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU...");
						}

						else if (ATMMenuChoice == LogOutATM)
						{
							goto AccessAccountStart;
						}

						else if (ATMMenuChoice == ReturnToSystemMenu)
						{
							return;
						}

						else if (ATMMenuChoice == ExitTheSystem)
						{
							ExitProgram("EXIT BANK SYSTEM :-)");
						}


					}
				}


			}
			else
			{
				cout << "THE BANK IS EMPTY , GO AND CREATE AN ACCOUNT\n";
				GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			}
		}
	}

	GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO DUAL SYSTEM MENU...");

}

void UnlockMyAccount(Admin& Admin, vector<User>& Users)
{
	if (DoesAdminHavePermissionTo(Admin, UnlockAccountAccess))
	{
		SectionBanner("UNLOCK MY ACCOUNT", 2);

		if (IsVectorEmpty(Users) == false)
		{
			int AccountIndex = ReadYourIdAndReturnAccountIndex(Users);
			if (IsAccountLocked(AccountIndex, Users) == true)
			{
				Users[AccountIndex].Locked = 0;
				SaveUsersDataToFile(Users);
				cout << "YOUR ACCOUNT IS UNLOCKED SUCCESSFULLY!\n";
				cout << "YOUR FORGIVEN PASSWORD : " << Users[AccountIndex].Password << "\n";
			}
			else
			{
				cout << "YOUR ACCOUNT IS NOT LOCKED\n";
			}
		}
		else
		{
			cout << "THE BANK IS EMPTY NOW , GO AND CREATE AN ACCOUNT\n";
		}
	}

}

bool IsAdminPasswordRight(int WrittenPassword)
{
	if (WrittenPassword == 1492005)
	{
		cout << "\nRIGHT PASSWORD\n";
		cout << "\nWELCOME ABDELRAHMAN :-)\n";
		return 1;
	}

	else
	{
		cout << "WRONG PASSWORD\n";
		cout << "YOU ARE NOT ABDELRAHMAN :(\n";
		return 0;
	}
}

void ReadAdminPassword()
{
	int AdminPassword;
	do
	{
		AdminPassword = ReadPositiveNumber("ENTER THE ADMIN PASSWORD");
	} while (IsAdminPasswordRight(AdminPassword) == false);
}

long double SumOfAllBalances(vector<User>& Users)
{
	long double SumOfAllBalances = 0;
	for (User& User : Users)
	{
		SumOfAllBalances += User.Balance;
	}

	return SumOfAllBalances;
}

void ShowAllAccounts(Admin& Admin, vector<User>& Users)
{
	if (DoesAdminHavePermissionTo(Admin, ShowAccountsAccess))
	{
		SectionBanner("SHOW ALL ACCOUNTS", 2);

		if (IsVectorEmpty(Users) == false)
		{
			ReadAdminPassword();
			GoToPauseMessage("\n\nPRESS ANY KEY TO SEE ALL ACCOUNTS...");

			ClearScreen();

			cout << "\n\n";
			cout << Tab(5) << "USERS LIST (" << Users.size() << ") USER(S).";

			PrintLineWithNewLines("_", 125, 2, 2);
			cout << "| " << left << setw(7) << "NO.";
			cout << "| " << left << setw(7) << "ID";
			cout << "| " << left << setw(23) << "NAME";
			cout << "| " << left << setw(9) << "PASSWORD";
			cout << "| " << left << setw(16) << "PHONE";
			cout << "| " << left << setw(11) << "ADDRESS";
			cout << "| " << left << setw(14) << "LOCKING STATE";
			cout << "| " << left << setw(12) << "TAKEN LOAN";
			cout << "| " << left << setw(12) << "BALANCE";
			PrintLineWithNewLines("_", 125, 2, 2);

			int UsersCounter = 0;

			for (User& User : Users)
			{
				cout << "| " << left << setw(7) << ++UsersCounter;
				cout << "| " << left << setw(7) << User.Id;
				cout << "| " << left << setw(23) << User.Name;
				cout << "| " << left << setw(9) << User.Password;
				cout << "| " << left << setw(16) << User.Phone;
				cout << "| " << left << setw(11) << User.Address;
				cout << "| " << left << setw(14) << LockingState(User);
				cout << "| " << left << setw(12) << User.TakenLoan;
				cout << "| " << left << setw(12) << User.Balance << "\n";
			}

			PrintLineWithNewLines("_", 125, 2, 2);

			cout << Tab(5) << "SUM OF ALL BALANCES = " << SumOfAllBalances(Users) << "\n";
		}

		else
		{
			cout << "THE BANK IS EMPTY , GO AND CREATE AN ACCOUNT FIRST\n";
		}
	}

}

MainMenuChoice ReadMainMenuChoice()
{
	return (MainMenuChoice)(ValidateNumberInRange(1, 11, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 11] ?"));
}

void ClearTheBank(Admin& Admin, vector<User>& Users)
{
	if (DoesAdminHavePermissionTo(Admin, ClearTheBankAccess))
	{
		SectionBanner("CLEAR THE BANK", 2);

		if (Users.empty())
		{
			cout << "THE BANK IS ALREADY EMPTY!\n";
		}
		else
		{
			ReadAdminPassword();

			Users.clear();
			SaveUsersDataToFile(Users);
			cout << "THE BANK IS CLEARED SUCCESSFULLY\n";
		}
	}

}

void PrintMainMenu()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "MAIN MENU SCREEN					 \n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1]  CREATE AN ACCOUNT." << "\n";
	cout << Tab(3) << "[2]  ACCESS AN ACCOUNT." << "\n";
	cout << Tab(3) << "[3]  SHOW ALL ACCOUNTS." << "\n";
	cout << Tab(3) << "[4]  UNLOCK MY ACCOUNT." << "\n";
	cout << Tab(3) << "[5]  FIND ACCOUNT." << "\n";
	cout << Tab(3) << "[6]  MANAGE ADMINS." << "\n";
	cout << Tab(3) << "[7]  CLEAR THE BANK." << "\n";
	cout << Tab(3) << "[8]  LOG OUT." << "\n";
	cout << Tab(3) << "[9]  CHANGE SYSTEM THEME." << "\n";
	cout << Tab(3) << "[10] RETURN TO THE DUAL SYSTEM." << "\n";
	cout << Tab(3) << "[11] EXIT THE DUAL SYSTEM." << "\n";
	cout << "====================================================================\n\n";
}

void FindUserById(vector<User>& Users)
{
	SectionBanner("FIND ACCOUNT BY ID", 2);

	int SearchResultsCounter = 0;

	int UserId = ReadPositiveNumber("ENTER ID OF THE ACCOUNT");
	int AccountIndex = ReturnAccountIndex(UserId, Users);

	if (AccountIndex != -1)
	{
		SearchResultsCounter++;
		PrintUser(Users[AccountIndex]);

		cout << "\n" << SearchResultsCounter << " SEARCH RESULT(S)\n";
	}

	else
	{
		cout << "ACCOUNT WITH ID (" << UserId << ") IS NOT FOUND !\n";
	}

}

void PrintTableHeader()
{
	PrintLineWithNewLines("_", 125, 2, 2);
	PrintStringElementInTable("NO.", 7);
	PrintStringElementInTable("ID", 7);
	PrintStringElementInTable("NAME", 23);
	PrintStringElementInTable("PASSWORD", 9);
	PrintStringElementInTable("PHONE", 16);
	PrintStringElementInTable("ADDRESS", 11);
	PrintStringElementInTable("LOCKING STATE", 14);
	PrintStringElementInTable("TAKEN LOAN", 12);
	PrintStringElementInTable("BALANCE", 12);
	PrintLineWithNewLines("_", 125, 2, 2);
}

void PrintUserInTable(User User, int& UserNumber)
{
	PrintNumberElementInTable(++UserNumber, 7);
	PrintNumberElementInTable(User.Id, 7);
	PrintStringElementInTable(User.Name, 23);
	PrintNumberElementInTable(User.Password, 9);
	PrintStringElementInTable(User.Phone, 16);
	PrintStringElementInTable(User.Address, 11);
	PrintStringElementInTable(LockingState(User), 14);
	PrintDoubleNumberElementInTable(User.TakenLoan, 12);
	PrintDoubleNumberElementInTable(User.Balance, 12);
	printf("\n");
}

void FindUserByName(vector<User>& Users)
{
	SectionBanner("FIND ACCOUNT BY NAME", 2);

	string UserName = ReadStringLine("ENTER ACCOUNT NAME");

	int SearchResultsCounter = 0;

	cout << "\n\n";
	cout << Tab(5) << "SEARCH RESULT(S) FOR USER NAME (" << UserName << ")";

	PrintTableHeader();

	for (User& User : Users)
	{
		if (LowerCaseAllString(User.Name) == LowerCaseAllString(UserName) || LowerCaseAllString(User.Name).find(LowerCaseAllString(UserName)) != string::npos)
		{
			PrintUserInTable(User, SearchResultsCounter);
		}
	}

	PrintLineWithNewLines("_", 125, 2, 2);

	printf("\n%s%d SEARCH RESULT(S) ARE FOUND\n\n", Tab(5).c_str(), SearchResultsCounter);


}

void FindUserByPhone(vector<User>& Users)
{
	SectionBanner("FIND ACCOUNT BY PHONE", 2);

	string UserPhone = ReadStringLine("ENTER ACCOUNT PHONE");

	int SearchResultsCounter = 0;

	cout << "\n\n";
	cout << Tab(5) << "SEARCH RESULT(S) FOR USER PHONE (" << UserPhone << ")";

	PrintTableHeader();

	for (User& User : Users)
	{
		if (User.Phone == UserPhone)
		{
			PrintUserInTable(User, SearchResultsCounter);
		}
	}

	PrintLineWithNewLines("_", 125, 2, 2);

	printf("\n%s%d SEARCH RESULT(S) ARE FOUND\n\n", Tab(5).c_str(), SearchResultsCounter);

}

void FindUserByAddress(vector<User>& Users)
{
	SectionBanner("FIND ACCOUNT BY ADDRESS", 2);

	string UserAddress = ReadStringLine("ENTER ACCOUNT ADDRESS");

	int SearchResultsCounter = 0;

	cout << "\n\n";
	cout << Tab(5) << "SEARCH RESULT(S) FOR USER ADDRESS (" << UserAddress << ")";

	PrintTableHeader();

	for (User& User : Users)
	{
		if (LowerCaseAllString(User.Address) == LowerCaseAllString(UserAddress) || LowerCaseAllString(User.Address).find(LowerCaseAllString(UserAddress)) != string::npos)
		{
			PrintUserInTable(User, SearchResultsCounter);
		}
	}

	PrintLineWithNewLines("_", 125, 2, 2);

	printf("\n%s%d SEARCH RESULT(S) ARE FOUND\n\n", Tab(5).c_str(), SearchResultsCounter);

}

void PrintFindMenu()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "FIND ACCOUNTS SCREEN\n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1] FIND ACCOUNT BY ID." << "\n";
	cout << Tab(3) << "[2] FIND ACCOUNT BY NAME." << "\n";
	cout << Tab(3) << "[3] FIND ACCOUNT BY ADDRESS." << "\n";
	cout << Tab(3) << "[4] FIND ACCOUNT BY PHONE." << "\n";
	cout << Tab(3) << "[5] RETURN TO MAIN MENU." << "\n";
	cout << "====================================================================\n\n";
}

FindMenuChoices ReadFindMenuChoice()
{
	return (FindMenuChoices)(ValidateNumberInRange(1, 5, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 5] ?"));
}

bool IsBankEmpty(vector<User>& Users)
{
	if (Users.empty())
	{
		printf("\n\nTHE BANK IS EMPTY NOW !\n");
		return 1;
	}

	return 0;
}

void FindAccounts(Admin& Admin, vector<User>& Users)
{
	if (DoesAdminHavePermissionTo(Admin, FindAccountAccess))
	{
		if (!IsBankEmpty(Users))
		{
			while (true)
			{
				ClearScreen();
				PrintFindMenu();
				FindMenuChoices FindMenuChoice = ReadFindMenuChoice();

				if (FindMenuChoice == FindById)
				{
					ClearScreen();
					FindUserById(Users);
					GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO FIND ACCOUNTS MENU...");
				}

				else if (FindMenuChoice == FindByName)
				{
					ClearScreen();
					FindUserByName(Users);
					GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO FIND ACCOUNTS MENU...");
				}

				else if (FindMenuChoice == FindByAddress)
				{
					ClearScreen();
					FindUserByAddress(Users);
					GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO FIND ACCOUNTS MENU...");
				}

				else if (FindMenuChoice == FindByPhone)
				{
					ClearScreen();
					FindUserByPhone(Users);
					GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO FIND ACCOUNTS MENU...");
				}

				else if (FindMenuChoice == ReturnMainMenu)
				{
					break;
				}

				else
				{
					cout << "INVALID CHOICE\n";
				}
			}
		}
	}
}

string UserToRecord(User& User, string Separator)
{
	string Record = "";

	Record += (User.Name + Separator);
	Record += (to_string(User.Id) + Separator);
	Record += (to_string(User.Password) + Separator);
	Record += (User.Address + Separator);
	Record += (User.Phone + Separator);
	Record += (to_string(User.Balance) + Separator);
	Record += (to_string(User.TakenLoan) + Separator);
	Record += (to_string(User.Locked));

	return Record;

}

void SaveUsersDataToFile(vector<User>& Users)
{
	fstream File;

	File.open("USERS.txt", ios::out);
	if (File.is_open())
	{
		for (User& User : Users)
		{
			File << UserToRecord(User, "#//#") << "\n";
		}

		File.close();
	}
}

User RecordToUser(string Record, string Separator)
{
	vector<string>RecordVector = SpiltStringWordsToVector(Record, "#//#");

	User User;
	User.Name = RecordVector[0];
	User.Id = stoi(RecordVector[1]);
	User.Password = stoi(RecordVector[2]);
	User.Address = RecordVector[3];
	User.Phone = RecordVector[4];
	User.Balance = stod(RecordVector[5]);
	User.TakenLoan = stod(RecordVector[6]);
	User.Locked = stoi(RecordVector[7]);

	return User;
}

void LoadUsersDataFromFile(vector<User>& Users)
{
	fstream File;
	File.open("USERS.txt", ios::in);

	if (File.is_open())
	{
		string Line;
		while (getline(File, Line))
		{
			if (Line != "" || Line != " ")
			{
				Users.push_back(RecordToUser(Line, "#//#"));
			}

		}

		File.close();
	}

}

//---------------------------------------------------------------------------------

int FindAdminAndReturnIndex(vector<Admin>& Admins, string AdminName, AdminNameOnlyOrAdminNameAndPassword AdminNameOnlyOrAdminNameAndPassword = AdminNameOnly, string Password = "")
{
	for (int AdminIndex = 0; AdminIndex < Admins.size(); AdminIndex++)
	{
		if (AdminNameOnlyOrAdminNameAndPassword == AdminNameAndPassword)
		{
			if (Admins[AdminIndex].AdminName == AdminName && Admins[AdminIndex].Password == Password)
			{
				return AdminIndex;
			}
		}

		else
		{
			if (AdminNameOnlyOrAdminNameAndPassword == AdminNameOnly)
			{
				if (Admins[AdminIndex].AdminName == AdminName)
				{
					return AdminIndex;
				}
			}
		}
	}

	if (AdminNameOnlyOrAdminNameAndPassword == AdminNameOnly)
	{
		printf("USER WITH USERNAME (%s) IS NOT FOUND\n", AdminName.c_str());
	}

	return -1;
}

bool IsAdminFound(vector<Admin>& Admins, string AdminName)
{
	for (Admin& Admin : Admins)
	{
		if (AdminName == Admin.AdminName)
		{
			printf("\nADMIN WITH ADMINNAME [%s] ALREADY EXISTS , ENTER ANOTHER ADMINNAME\n\n", AdminName.c_str());
			return 1;
		}
	}

	return 0;
}

void PrintAdmin(Admin& Admin)
{
	cout << "\nTHE FOLLOWING ARE THE ADMIN'S DETAILS : \n";
	cout << "------------------------------------------------------\n";
	cout << "ADMIN NAME  : " << Admin.AdminName << "\n" <<
		"PASSWORD    : " << Admin.Password << "\n" <<
		"PERMISSIONS : " << Admin.Permissions << "\n";
	cout << "------------------------------------------------------\n";
}

void ListAdmins(vector<Admin>& Admins)
{
	SectionBanner("LIST ADMINS", 2);

	GoToPauseMessage("\n\nPRESS ANY KEY TO SEE ALL ACCOUNTS...");

	ClearScreen();

	cout << "\n\n";
	cout << Tab(4) << "ADMINS LIST (" << Admins.size() << ") ADMIN(S).";

	cout << "\n\n__________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(7) << "NO.";
	cout << "| " << left << setw(20) << "ADMIN NAME";
	cout << "| " << left << setw(14) << "PASSWORD";
	cout << "| " << left << setw(15) << "PERMISSIONS";
	cout << "\n__________________________________________________________________________________________\n\n";

	int AdminsCounter = 0;

	for (Admin& Admin : Admins)
	{
		cout << "| " << left << setw(7) << ++AdminsCounter;
		cout << "| " << left << setw(20) << Admin.AdminName;
		cout << "| " << left << setw(14) << Admin.Password;
		cout << "| " << left << setw(15) << Admin.Permissions << "\n";

	}

	cout << "__________________________________________________________________________________________\n\n";

	GoToPauseMessage("PRESS ANY KEY TO GO BACK TO MANAGE ADMINS MENU...\n");

}

string ReadNewAdminName(vector<Admin>& Admins)
{
	string AdminName;
	do
	{
		AdminName = ReadStringLine("ENTER ADMIN NAME ?");

	} while (IsAdminFound(Admins, AdminName));

	return AdminName;
}

void DoYouWantToGiveAccessTo(string Message, MainMenuPermissions MainMenuPermission, int& Permissions)
{
	if (DoYouWantToDoThisWithoutClear("\n" + Message))
	{
		Permissions += MainMenuPermission;
	}
}

int ReadPermissions()
{
	int Permissions = 0;

	if (DoYouWantToDoThisWithoutClear("\nDO YOU WANT TO GIVE FULL ACCESS ?"))
	{
		return Permissions = -1;
	}

	printf("DO YOU WANT TO GIVE ACCESS TO : \n");
	DoYouWantToGiveAccessTo("CREATE AN ACCOUNT ?", CreateAccountAccess, Permissions);
	DoYouWantToGiveAccessTo("ACCESS AN ACCOUNT ?", AccessAccountAccess, Permissions);
	DoYouWantToGiveAccessTo("SHOW ALL ACCOUNTS ?", ShowAccountsAccess, Permissions);
	DoYouWantToGiveAccessTo("UNLOCK MY ACCOUNT ?", UnlockAccountAccess, Permissions);
	DoYouWantToGiveAccessTo("FIND ACCOUNT", FindAccountAccess, Permissions);
	DoYouWantToGiveAccessTo("MANAGE ADMINS", ManageAdminsAccess, Permissions);
	DoYouWantToGiveAccessTo("CLEAR THE BANK", ClearTheBankAccess, Permissions);

	return Permissions;
}

Admin ReadNewAdmin(vector<Admin>& Admins)
{
	Admin Admin;
	Admin.AdminName = ReadNewAdminName(Admins);
	Admin.Password = ReadStringLine("ENTER PASSWORD ?");
	Admin.Permissions = ReadPermissions();

	return Admin;
}

void AddNewAdmins(vector<Admin>& Admins)
{
	SectionBanner("ADD NEW ADMIN SCREEN");

	do
	{
		printf("\nADDING NEW ADMIN : \n\n");
		Admins.push_back(ReadNewAdmin(Admins));
		SaveAdminsDataToFile(Admins);

	} while (DoYouWantToDoThisWithoutClear("\nADMIN ADDED SUCCESSFULLY , DO YOU WANT TO ADD MORE ADMINS ?"));

	GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MANAGE ADMINS MENU...");
}

void UpdateAdmin(vector<Admin>& Admins)
{
	SectionBanner("UPDATE ADMINS SCREEN");
	string AdminName = ReadStringLine("PLEASE ENTER ADMINNAME ?");
	int AccountIndex = FindAdminAndReturnIndex(Admins, AdminName);
	if (AccountIndex != -1);
	{
		PrintAdmin(Admins[AccountIndex]);
		if (DoYouWantToDoThisWithoutClear("ARE YOU SURE YOU WANT TO UPDATE THIS ADMIN ?"))
		{
			Admins[AccountIndex].Password = ReadStringLine("ENTER PASSWORD ?");
			Admins[AccountIndex].Permissions = ReadPermissions();

			SaveAdminsDataToFile(Admins);
			printf("\nADMIN IS UPDATED SUCCESSFULLY.\n");
		}
	}

	GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MANAGE ADMINS MENU...");
}

bool IsAdminNameEqualAdmin(string AdminName)
{
	if (AdminName == "ADMIN")
	{
		printf("\nYOU CAN NOT DELETE THIS ADMIN\n");
		return 1;
	}

	return 0;
}

void DeleteAdmin(vector<Admin>& Admins)
{
	SectionBanner("DELETE ADMINS SCREEN");
	string AdminName = ReadStringLine("PLEASE ENTER ADMINNAME ?");
	if (!IsAdminNameEqualAdmin(AdminName))
	{
		int AdminIndex = FindAdminAndReturnIndex(Admins, AdminName);
		if (AdminIndex != -1)
		{
			PrintAdmin(Admins[AdminIndex]);
			if (DoYouWantToDoThisWithoutClear("ARE YOU SURE YOU WANT TO DELETE THIS ADMIN ?"))
			{
				Admins.erase(Admins.begin() + AdminIndex);
				SaveAdminsDataToFile(Admins);
				printf("ADMIN IS DELETED SUCCESSFULLY");
			}
		}
	}

	GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MANAGE ADMINS MENU...");
}

void FindAdmin(vector<Admin>& Admins)
{
	SectionBanner("FIND ADMIN SCREEN");
	string AdminName = ReadStringLine("PLEASE ENTER USERNAME ?");
	int SearchResultsCounter = 0;

	for (Admin& Admin : Admins)
	{
		if (LowerCaseAllString(AdminName) == LowerCaseAllString(Admin.AdminName))
		{
			PrintAdmin(Admin);
			SearchResultsCounter++;
		}
	}

	if (SearchResultsCounter != 0)
	{
		printf("\n%d SEARCH RESULT(S)", SearchResultsCounter);
	}

	else
	{
		printf("ADMIN WITH NAME \"%s\" IS NOT FOUND!\n", AdminName.c_str());
	}

	GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MANAGE ADMINS MENU...");
}

void PrintManageAdminsScreen()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "MANAGE ADMINS MANU SCREEN\n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1] LIST ADMINS." << "\n";
	cout << Tab(3) << "[2] ADD NEW ADMIN." << "\n";
	cout << Tab(3) << "[3] DELETE ADMIN." << "\n";
	cout << Tab(3) << "[4] UPDATE ADMIN." << "\n";
	cout << Tab(3) << "[5] FIND ADMIN." << "\n";
	cout << Tab(3) << "[6] MAIN MENU." << "\n";
	cout << "====================================================================\n\n";
}

ManageAdminsMenuChoices ReadManageAdminsMenuChoice()
{
	return (ManageAdminsMenuChoices)(ValidateNumberInRange(1, 6, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 8] ?"));
}

void ManageAdmins(Admin& Adminv, vector<Admin>& Admins)
{
	if (DoesAdminHavePermissionTo(Adminv, ManageAdminsAccess))
	{
		while (true)
		{
			PrintManageAdminsScreen();
			ManageAdminsMenuChoices ManageAdminsMenuChoice = ReadManageAdminsMenuChoice();

			if (ManageAdminsMenuChoice == ListTheAdmins)
			{
				ClearScreen();
				ListAdmins(Admins);
			}

			else if (ManageAdminsMenuChoice == AddNewAdmin)
			{
				ClearScreen();
				AddNewAdmins(Admins);
			}

			else if (ManageAdminsMenuChoice == DeleteAdmins)
			{
				ClearScreen();
				DeleteAdmin(Admins);
			}

			else if (ManageAdminsMenuChoice == UpdateAdmins)
			{
				ClearScreen();
				UpdateAdmin(Admins);
			}

			else if (ManageAdminsMenuChoice == FindAdmins)
			{
				ClearScreen();
				FindAdmin(Admins);
			}

			else if (ManageAdminsMenuChoice == MainMenu)
			{
				return;
			}

			else
			{
				printf("INVALID CHOICE\n");
			}
			SaveAdminsDataToFile(Admins);
		}
	}
}

string AdminToRecord(Admin& Admin, string Separator)
{
	return Admin.AdminName + Separator + Admin.Password + Separator + to_string(Admin.Permissions);
}

Admin RecordToAdmin(string Record, string Separator)
{
	vector<string>AdminVector = SpiltStringWordsToVector(Record, Separator);
	Admin Admin;

	Admin.AdminName = AdminVector[0];
	Admin.Password = AdminVector[1];
	Admin.Permissions = stoi(AdminVector[2]);

	return Admin;
}

void SaveAdminsDataToFile(vector<Admin>& Admins)
{
	fstream File;
	File.open(AdminsDataFileName, ios::out);

	if (File.is_open())
	{
		for (Admin& Admin : Admins)
		{
			File << AdminToRecord(Admin, "#//#") << "\n";
		}

		File.close();
	}
}

void LoadAdminsDataFromFile(vector<Admin>& Admins)
{
	fstream File;
	File.open(AdminsDataFileName, ios::in);

	if (File.is_open())
	{
		string Record;

		while (getline(File, Record))
		{
			Admins.push_back(RecordToAdmin(Record, "#//#"));
		}

		File.close();
	}
}

int BankLogin(vector<Admin>& Admins)
{
	string AdminName;
	string Password;
	int AdminIndex;
	bool LoginFailed = false;

	do
	{
		system("cls");
		SectionBanner("ADMIN LOGIN SCREEN");
		if (LoginFailed)
		{
			printf("INVALID ADMIN NAME/PASSWORD!\n");
		}
		AdminName = ReadStringLine("ENTER ADMIN NAME ?");
		Password = ReadStringLine("ENTER PASSWORD ?");
		AdminIndex = FindAdminAndReturnIndex(Admins, AdminName, AdminNameAndPassword, Password);
		LoginFailed = (AdminIndex == -1) ? true : false;
	} while (LoginFailed);

	return AdminIndex;
}

void BankSystem(Admin& Adminv, vector<Admin>& Admins)
{
	vector<User>Users;

	LoadUsersDataFromFile(Users);

	cout << "\n\nWELCOME TO ABDELRAHMAN'S BANK SYSTEM\n";

	GoToPauseMessage("\n\nPRESS ANY KEY TO START THE BANK SYSTEM...");

	while (true)
	{
		ClearScreen();
		PrintMainMenu();
		MainMenuChoice MainMenuChoice = ReadMainMenuChoice();
		if (MainMenuChoice == MainMenuChoice::CreateMyAccount)
		{
			ClearScreen();
			CreateAccount(Adminv, Users);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::AccessMyAccount)
		{
			ClearScreen();
			AccessAccount(Users, Adminv);
		}

		else if (MainMenuChoice == MainMenuChoice::ShowAccounts)
		{
			ClearScreen();
			ShowAllAccounts(Adminv, Users);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::UnlockAccount)
		{
			ClearScreen();
			UnlockMyAccount(Adminv, Users);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::FindAccount)
		{
			ClearScreen();
			FindAccounts(Adminv, Users);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::ManageTheAdmins)
		{
			ClearScreen();
			ManageAdmins(Adminv, Admins);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::ClearBank)
		{
			ClearScreen();
			ClearTheBank(Adminv, Users);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::ChangeSystemThemes)
		{
			ClearScreen();
			ChangeSystemTheme(SystemThemeColor);
			GoToPauseMessage("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		}

		else if (MainMenuChoice == MainMenuChoice::LogOut)
		{
			return;
		}

		else if (MainMenuChoice == MainMenuChoice::ReturnToTheSystem)
		{
			ClearScreen();
			::ReturnSystemFlag = true;
			return;
		}

		else if (MainMenuChoice == MainMenuChoice::ExitAllTheSystem)
		{
			ExitProgram("EXIT BANK SYSTEM :-)", 2, "=", 60, SystemThemeColor.BackgroundColor, SystemThemeColor.ForegroundColor);
		}
	}
}

void PrintDualBankAndATMSystemMenu()
{
	cout << "====================================================================\n\n";
	cout << Tab(3) << "DUAL BANK AND ATM SYSTEM\n\n";
	cout << "====================================================================\n";
	cout << Tab(3) << "[1] BANK SYSTEM." << "\n";
	cout << Tab(3) << "[2] ATM SYSTEM." << "\n";
	cout << Tab(3) << "[3] EXIT BANK." << "\n";
	cout << "====================================================================\n\n";

}

DualBankAndATMSystemMenuChoices ReadDualBankAndATMSystemMenuChoice()
{
	return (DualBankAndATMSystemMenuChoices)(ValidateDoubleNumberInRange(1, 3, "CHOOSE WHAT DO YOU WANT TO DO ? [1 TO 3] ?"));
}

void DualBankAndATMSystem()
{
	LoadSystemThemeColorsFromFile();
	ChangeCLIColors(SystemThemeColor.BackgroundColor, SystemThemeColor.ForegroundColor);

	while (true)
	{
		ClearScreen();
		PrintDualBankAndATMSystemMenu();
		DualBankAndATMSystemMenuChoices DualBankAndATMSystemMenuChoice = ReadDualBankAndATMSystemMenuChoice();
		if (DualBankAndATMSystemMenuChoice == TheBankSystem)
		{
			vector<Admin>Admins;
			LoadAdminsDataFromFile(Admins);
			while (true)
			{
				if (::ReturnSystemFlag)
				{
					break;
				}

				::ReturnSystemFlag = false;

				int AccountIndex = BankLogin(Admins);

				BankSystem(Admins[AccountIndex], Admins);

			}
		}

		else if (DualBankAndATMSystemMenuChoice == ATM)
		{
			vector<User>Users;
			LoadUsersDataFromFile(Users);
			Admin Admin;
			AccessAccount(Users, Admin, UserMod);
		}

		else if (DualBankAndATMSystemMenuChoice == ExitAll)
		{
			ClearScreen();
			SectionBanner("EXIT BANK SYSTEM :-)");
			exit(0);
		}
	}
}

int main()
{

	DualBankAndATMSystem();

	return 0;
}