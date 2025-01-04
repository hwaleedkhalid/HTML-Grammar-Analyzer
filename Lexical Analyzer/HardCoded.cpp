#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	cout << endl << endl;
	int state = 0;
	string token;
	char ch;
	ifstream file("input.txt");

	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return 1;
	}

	while (file.get(ch))
	{
		if (state == 0)
		{
			token = "";
			if(isspace(ch))
            {
                state = 0;
            }
            else if(ch == '<')
            {
                state = 1;
                token += ch;
            }
            else if(isupper(ch))
            {
                state = 13;
                token += ch;
            }
            else 
            {
                while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
            }
		}
		else if (state == 1)
		{
			if (islower(ch))
			{
				token += ch;
				state = 2;  // Move to a state that confirms it's a valid identifier
			}
            else if(ch == '/')
            {
                token += ch;
                state = 7;
            }
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
		}
		else if (state == 2)
		{
			if (isdigit(ch))
			{
				token += ch;
				state = 3;  // Move to a state that confirms it's a valid identifier
			}
			else if (islower(ch))
			{
                token += ch;
				state = 4;
			}
            else if(ch == '>')
            {
                token += ch;
                state = 5;
            }
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
		}
        else if(state == 3)
        {
            if(ch == '>')
            {
                token += ch;
                state = 5;
            }
        }
		else if (state == 4)
		{
			if (islower(ch))
			{
				state = 4;
				token += ch;
			}
            else if(ch == '>')
            {
                token += ch;
                state = 5;
            }
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}

		}
		else if (state == 5)
		{
			if (isspace(ch))
			{
				state = 6;
				token += ch;
			}
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
		}
		else if (state == 6)
		{
			cout << "Starting Tag withot Attributes found: \t" << token << endl;
			token = "";
			state = 0;
		}
		else if (state == 7)
		{
			if (islower(ch))
			{
				state = 8;
				token += ch;
			}
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
		}
		else if (state == 8)
		{
			if (islower(ch))
			{
				state = 10;
				token += ch;
			}
			else if (isdigit(ch))
			{
				state = 9;
				token += ch;
			}
            else if(ch == '>')
            {
                state = 11;
                token += ch;
            }
			else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
		}
		else if (state == 9)
		{
            if(ch == '>')
            {
                token += ch;
                state = 11;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
			
		}
        else if(state == 10)
        {
            if(islower(ch))
            {
                token += ch;
                state = 10;
            }
            else if(ch == '>')
            {
                token += ch;
                state = 11;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 11)
        {
            if(isspace(ch))
            {
                token += ch;
                state = 12;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 12)
        {
            cout << "Closing Tag found: \t" << token << endl;
			token = "";
			state = 0;
        }
        else if(state == 13)
        {
            if(isupper(ch))
            {
                token += ch;
                state = 14;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 14)
        {
            if(isupper(ch))
            {
                token += ch;
                state = 15;
            }
            else if(ch == '-')
            {
                token += ch;
                state = 16;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 15)
        {
            if(isupper(ch))
            {
                token += ch;
                state = 17;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 16)
        {
            if(isupper(ch))
            {
                token += ch;
                state = 15;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 17)
        {
            if(isupper(ch))
            {
                token += ch;
                state = 18;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 18)
        {
            if(isspace(ch))
            {
                token += ch;
                state = 19;
            }
            else
			{
				while (!isspace(ch) && file.get(ch))
				{
				} // skip to next whitespace
				state = 0;  // Reset state
			}
        }
        else if(state == 19)
        {
            cout << "Property Tag found: \t" << token << endl;
			token = "";
			state = 0;
        }
		else
		{
			cout << "Invalid Input" << endl;
		}
	}
	file.close();
	cout << endl << endl;

	system("pause");
	return 0;
}