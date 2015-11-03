#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

// Charles Ratkie
// The purpose of this program is to read in user preferences and have them put in a password.
// The password will then be checked for strength.

const char NAME = 21;

// Prototypes

void welcome_user(char answer);
void get_last_name(char last_name[]);
void get_pet_name(char pet_name[]);
void get_birthdate(char birthdate[]);
void get_fav_num(char fav_num[]);
void password_rules();
void get_password(char pw[]);
void validate_letter(char array[]);
void validate_num(char array[]);
bool caps(char password[]);
bool first_letter(char password[]);
bool symbol(char password[]);
bool number(char password[]);
bool space(char password[]);


int main()
{

	char last_name[NAME];
	char pet_name[NAME];
	char birthdate[NAME];
	char fav_num[NAME];
	char password[NAME];
	char answer;
	int count = 0;
	int weakness_count = 0;

	welcome_user(answer);
	get_last_name(last_name);
	validate_letter(last_name);
	get_pet_name(pet_name);
	validate_letter(pet_name);
	get_birthdate(birthdate);
	validate_num(birthdate);
	get_fav_num(fav_num);
	validate_num(fav_num);



	// Display the arrays for the user to view.
	cout << endl;
	cout << "=======================================" << endl;
	cout << "1. Last Name: " << last_name << endl;
	cout << "2. Pet's Name: " << pet_name << endl;
	cout << "3. Birthdate: " << birthdate << endl;
	cout << "4. Favorite Number: " << fav_num << endl;



	password_rules();
	do
	{
	    count++;
	    get_password(password);

	    if(count > 4)
	    {
		password_rules();
		count = 0;
	    }

	} while ( caps(password) == true && first_letter(password) == true && symbol(password) == true && number(password) == true && space(password) == true );

/*
	// Compare Password for strength
	if (password[0] == last_name[0])

	cout << last_name[0] << endl;

	{
	    weakness_count = 1;
	}
	cout << "Your password strength is " << weakness_count << endl;

	cout << "Password: " << password << endl;




*/







	return 0;
}


// *******************************************************
// Functions

// Welcome the user and provide information
void welcome_user(char answer)
{
	do
	{
		cout << endl << endl;
		cout << "This is a password program that will check the strength of your password.\n";
		cout << "Wold you like to try the password program?: (Y/N)";
		cin >> answer;
		cin.ignore(100, '\n');
		answer = toupper(answer);
	} while ( answer != 'Y');

}

// Get the user's last name
void get_last_name(char last_name[])
{
	cout << endl;
	cout << "Please enter your LAST name: ";
	cin.get(last_name,NAME,'\n');
	cin.clear();
	cin.ignore(100,'\n');
}

// Get the user's pet's name
void get_pet_name(char pet_name[])
{
	cout << endl;
	cout << "Please enter your pet's name: ";
	cin.get(pet_name,NAME,'\n');
	cin.clear();
	cin.ignore(100,'\n');
}

// Get the user's birthdate
void get_birthdate(char birthdate[])
{
	cout << endl;
	cout << "Please enter your BIRTHDATE (1989): ";
	cin.get(birthdate,NAME,'\n');
        cin.clear();
	cin.ignore(100,'\n');
}

// Get the user's favorite number
void get_fav_num(char fav_num[])
{
	cout << endl;
	cout << "Please enter your favorite NUMBER: ";
	cin.get(fav_num,NAME,'\n');
	cin.clear();
	cin.ignore(100,'\n');
}

// Read in a Password from the user
void password_rules()
{
    cout << endl;
    cout << "PASSWORD RULES:" << endl;
    cout << "1. Must start with a letter." << endl;
    cout << "2. Must be at least ONE uppercase." << endl;
    cout << "3. Must have at least ONE symbol." << endl;
    cout << "4. No spaces or tabs allowed." << endl;
}

// Read in a Password from the user
void get_password(char pw[])
{
    cout << endl;
    cout << "Please enter a PASSWORD: ";
    cin.get(pw, NAME,'\n');
    cin.ignore(100,'\n');
}

// Validate that the user enters letters only

void validate_letter(char array[])
{
    int length = strlen(array);
    for (int i = 0; i < length; i++)
    {
	while (!(isalpha(array[i])))
	{
	    cout << "Oops!" << endl;
	    cout << "Make sure you are using only letters: ";
	    cin.get(array, NAME,'\n');
	    cin.ignore(100,'\n');
	    length = strlen(array);
	}
    }
}

void validate_num(char array[])
{
    int length = strlen(array);
    for (int i = 0; i < length; i++)
    {
	while (!(isdigit(array[i])))
	{
	    cout << "Oops!" << endl;
	    cout << "Make sure you are using only numbers: ";
	    cin.get(array, NAME,'\n');
	    cin.ignore(100,'\n');
	    length = strlen(array);
	}
    }
}


bool caps(char password[])
{
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
	if(isupper(password[i]))
	{
	    return true;
	}
    }
return false;
}
bool first_letter(char password[])
{
	if ( (isalpha(password[0])))
	{
	    return true;
	}
return false;

}
bool symbol(char password[])
{
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
	if ( (!isalpha(password[i])) && (!isdigit(password[i])) )
	{
	    return true;
	}
    }
return false;
}
bool number(char password[])
{
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
	if(isdigit(password[i]))
	{
	    return true;
	}
    }
return false;
}
bool space(char password[])
{
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
	if(!isspace(password[i]))
	{
	    return true;
	}
    }
return false;
}














/*

// Display the user's inputs and check to see if everything is correct.
// If not, provide the chance for the user to go back and make changes.
void display_list()
{

	cout << endl << endl;

	cout << "** Please review your information below **";
	cout << endl << endl;
	cout << " 1. " << char last_name << endl;
	cout << " 2. " << char pet_name << endl;
	cout << " 3. " << char birthdate << endl;
	cout << " 4. " << char fav_num << endl << endl;
}

// Provide the user to go back by having them enter
// numbers 1 - 4 according to the categorized list above.
/*
	cout << "If you made any errors when entering your information,"
		 << " you can enter any single number 1 - 4 to make your adjustments";
	cout << "However, if you are satisfied, simply press <ENTER> to continue..." << endl << endl;

	cin >> number;
	cin.ignore(100, '\n');

	while (number != '\n')
	{

		if (number == 1)
		{
			get_last_name();
		}
		else if (number == 2)
		{
			get_pet_name();
		}
		else if (number == 3)
		{
			get_birthdate();
		}
		else if (number == 4)
		{
			get_fav_num();
		}

    }

    return;
}

*/





