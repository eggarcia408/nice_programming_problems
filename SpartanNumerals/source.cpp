#include <iostream>
#include <string.h>

using namespace std;

/*
	I = 1
	E = 3
	V = 5
	X = 10
	L = 50

	Convert a spartan numeral to an integer. Below are the rules
		Numbers are read from left side to right side
		Each character value increases the total value of the numeral, except in the case below(case 3)
		If a lower value character occurs after a higher valued character, then that lower characte decrements the total value1
		If a character follows itself, you count the vakue again.
		If a lowervalue character appears after a higher values character and occurs many times, then each time is a lowering of that character

	Example:
		II = 2
		III = 3
		IIII = 4
		V = 5
		VII = 3
		VX = 15
		VVV = 15
		LVVV = 35
		LIX = 59
		VIIXL = 63
		EXL = 63
		EII = 2


*/



int ConvertSpartanNumeral(string& sn);

int main()
{
	string mine;
	cin>>mine;
	cout<<ConvertSpartanNumeral(mine);
}



int ConvertSpartanNumeral(string& sn) {
    
    int i = 0;
    int num = 0;
    int x;
    
    
    while(i<sn.length())
    {
        x = 0;
        switch(sn[i])
        {
            case 'I':
                    num = num + 1;
					i++;
                break;
            case 'E':
                if(sn[i+1] == 'I' && i<sn.length())
                {
                    i++;   
                    while(sn[i] == 'I' && i<sn.length())
                    {
                        x++;
                        i++;
                    }
                    num = num + (3 - (1*x));
                }
                else
                {
                  num = num + 3;
                  i++;
                }
                break;
            case 'V':
                if(sn[i+1] == 'E' && i<sn.length())
                {
                    i++;
                    while(sn[i] == 'E' && i<sn.length())
                    {
                        x++;
                        i++;
                    }
                    num = num + (5 - (3*x));
                }
                else
                {
                    if(sn[i+1] == 'I' && i<sn.length())
                    {
                        i++;
                        while(sn[i] == 'I' && i<sn.length())
                        {
                            x++;
                            i++;
                        }
                        num = num + (5 - (1*x));
                    }
                    else
                    {
                        num = num + 5;
						i++;
                    }
                }
                break;
            case 'X':
                if(sn[i+1] == 'V' && i<sn.length())
                {
                    i++;
                    while(sn[i] == 'V' && i<sn.length())
                    {
                        x++;
                        i++;
                    }
                    num = num + (10 - (5*x));
                }
                else
                {
                    if(sn[i+1] == 'E' && i<sn.length())
                    {
                        i++;
                        while(sn[i] == 'E' && i<sn.length())
                        {
                            x++;
                            i++;
                        }
                        num = num + (10 - (3*x));
                    }    
                    else
                    {
                        if(sn[i+1] == 'I' && i<sn.length())
                        {
                            i++;
                            while(sn[i] == 'I' && i<sn.length())
                            {
                                x++;
                                i++;
                            }
                            num = num + (10 - (1*x));
                        }
                        else
                        {
                            num = num + 10;
							i++;
                        }
                    }
                }
                break;
            case 'L':
                if(sn[i+1] == 'X' && i<sn.length())
                {
                    i++;
                    while(sn[i] == 'X' && i<sn.length())
                    {
                        x++;
                        i++;
                    }
                    num = num + (50 - (10*x));
                }
                else
                {
                    if(sn[i+1] == 'V' && i<sn.length())
                    {
                        i++;
                        while(sn[i] == 'V' && i<sn.length())
                        {
                            x++;
                            i++;
                        }
                        num = num + (50 - (5*x));
                    }
                    else
                    {
                        if(sn[i+1] == 'E' && i<sn.length())
                        {
                            i++;
                            while(sn[i] == 'E' && i<sn.length())
                            {
                                x++;
                                i++;
                            }
                            num = num + (50 - (3*x));
                        }
                        else
                        {
                            if(sn[i+1] == 'I' && i<sn.length())
                            {
                                i++;
                                while(sn[i] == 'I' && i<sn.length())
                                {
                                    x++;
                                    i++;
                                }
                                num = num + (50 - (1*x));
                            }
							else
							{
								num = num + 50;
								i++;	
							}
                        }
                    }
                }
                break;
            default:
                cout<<"unexpected error\n";
                i++; 
        }
    }
       
    
    return num;
}











