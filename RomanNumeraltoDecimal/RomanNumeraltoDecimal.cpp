#include <iostream>
#include <string>
#include <ctype.h> //this is to use isalpha

using namespace std;


/*
    this is a program that converts a roman numeral to
    an  integer from I(1) to M(1000) 
*/

class RomantoInt
{
    public:
        string romanNum; //this will represented Roman Numeral input

        void   outputRomanNum(void);
        void   inputRomanNum(void);
        bool   validInput(void);
		int    convertToInt(); //this will do the conversion for you
		int    intValue;
        RomantoInt();
    private:
        int mem;

};

int main(int argc, char **argv)
{
    RomantoInt num;
    
   
    do
    {
        cout<<"Please enter a roman numeral\n";
        num.inputRomanNum();
    }while(!num.validInput());

	cout<<"Roman Numeral is: ";
	num.outputRomanNum();
	
	cout<<"Its decimal equivalence is: "<< num.convertToInt()<<endl;
        
    return 0;
}

void  RomantoInt:: inputRomanNum(void)
{
    cin>>romanNum;
}


/* this just checks if they are a valid
   characters. This does not check if its a valid roman numeral number
   or if its in the range
*/
bool RomantoInt:: validInput(void)
{
    bool valid = true;
	int i = 0;
	cout<<"entered valid input\n";
    while( (i<romanNum.length()) && valid)
	{
		//if input is not a character, then wrong input
        if(!isalpha(romanNum[i]))
        {
			cout<<"Invalid character\n";
            valid = false;
            break;
        }

		romanNum[i] = toupper(romanNum[i]);//if this executes this, that means its a valid character

		//at this point, everything is an upper case character
		switch(romanNum[i])
		{
			case 'I':
			case 'V':
			case 'X':
			case 'L':
			case 'C':
			case 'D':
			case 'M':
				break; //this breaks out of the switch, not while
			default:
				cout<<"Please input a valid roman numeral digit\n";
				valid = false;
				break;
		}
		
		i++;
    }
    return valid;
}
void  RomantoInt::outputRomanNum(void)
{
    cout<<romanNum<<endl;
}

int RomantoInt::convertToInt(void)
{

	int i = 0;

	// at this point, roman numeral characters are all upper case
	// due to the valid input function	
	while(i<romanNum.length())
	{	
		switch(romanNum[i])
		{
			case 'I':
				if(romanNum[i+1] == 'V' && (i+1)<romanNum.length())
				{
					intValue = intValue + 4;
					i = i + 2;
				}
				else if(romanNum[i+1] == 'X' && (i+1)<romanNum.length())
				{
					intValue = intValue + 9;
					i = i + 2;
				}
				else
				{
					intValue = intValue + 1;
					i++;
				}	
				break;	
	
			case 'V':
				intValue = intValue + 5;
				i++;
				break;
			
			case 'X':
				if(romanNum[i+1] == 'L' && (i+1)<romanNum.length())
				{
					intValue = intValue + 40;
					i = i + 2;
				}
				else if(romanNum[i+1] == 'C' && (i+1)<romanNum.length())
				{
					intValue = intValue + 90;
					i = i + 2;
				}
				else
				{
					intValue = intValue + 10;
					i++;
				}	
				break;	
				
			case 'L':
				intValue = intValue + 50;
				i++;
				break;

			case 'C':
				if(romanNum[i+1] == 'D' && (i+1)<romanNum.length())
				{
					intValue = intValue + 400;
					i = i + 2;
				}
				else if(romanNum[i+1] == 'M' && (i+1)<romanNum.length())
				{
					intValue = intValue + 900;
					i = i + 2;
				}
				else
				{
					intValue = intValue + 100;
					i++;
				}	
				break;	
			
			case 'D':
				intValue = intValue + 500;
				i++;
				break;
		
			//if you encounter an M, than thats the only charcter since M represents 1000
			//and you specify 1(I) to 1000(M) only
			case 'M':
				intValue = intValue + 1000;
				i++;
				break;
			//unsuspecting error
			default:
				cout<<"Unsuspecting error\n";
				i++;
				break;		
		}//end switch statement
	}//end while loop

	return intValue;
}

RomantoInt :: RomantoInt()
{
	romanNum = "";
	intValue = 0;
}




