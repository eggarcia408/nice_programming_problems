#include <iostream>
#include <string>

using namespace std;
/*
    Problem Description
        
        User inputs three integers, N,p,and q where it is
        assumed that p!=q, (p and q) !=1, (p and q) must be less than 10
        (a single digit), and N != 1

        print out 1-N by following these rules:
            1) If the integer is divisible by p or q,then  output OUT
            2) If the integer contains p or q, then  output THINK
            3) If 1 and 2 above is true, then output OUTTHINK
            4) Otherwise just print the integer

        Example input:
                20 6 3
        Example output:
                1,2,OUTTHINK,4,5,OUTTHINK,7,8,OUT,10,11,OUT,THINK,14,OUT,THINK,17,OUT,19,20
                


*/


bool isDivisibleByDigit(int par_num, int par_digit);
bool containsDigit(int par_num, int par_digit);


int main(int argc, char **argv)
{
    
    int N,p,q,i;

    string NString,pString,qString; //string that will contain N,P, and q
    cout<<"Please enter N: "; 
    cin>>N;

    cout<<"Please enter p: ";
    cin>>p;
    
    cout<<"Please enter q: ";
    cin>>q;

    cout<<endl;


    //parsing line string into thre integers

    cout<<NString<<" "<<pString<<" "<<qString<<endl;
    for(i = 1; i<=N; i++)
    {
        cout<<"i: "<<i<<endl;
        cout<<"p: "<<p<<endl;
        cout<<"q: "<<q<<endl;

        if(  ( isDivisibleByDigit(i,p) ||  isDivisibleByDigit(i,q) )
                                      && 
             ( containsDigit(i,p) || containsDigit(i,q) )
          )
        {
            cout<<"OUTTHINK\n ";
        }
        else
            if( isDivisibleByDigit(i,p) || isDivisibleByDigit(i,q) )
                cout<<"OUT\n";
            else
                if(containsDigit(i,p) || containsDigit(i,q) )
                    cout<<"THINK\n";
                else
                    cout<<i<<"\n";
        cout<<endl;
    }

/*
    USED FOR TESTING DEBUGGING PURPOSES ONLY
    for(i = 1; i<= N; i++)
    {
        if(isDivisibleByDigit(i,p))
            cout<<i<<" is divisible by: "<<p<<endl;
        else
            cout<<i<<" is not divisible by: "<<p<<endl;
    }


    for(i = 1; i<= N; i++)
    {
        if(containsDigit(i,p))
            cout<<i<<" contains digit: "<<p<<endl;
        else
            cout<<i<<" does not contains digit: "<<p<<endl;
    }
*/

    return 0;

}

bool isDivisibleByDigit(int par_num, int par_digit)
{
    if(par_num%par_digit == 0)
        return true;
    else 
        return false;
}



bool containsDigit(int par_num, int par_digit)
{
    int digitInNumber;

    while(par_num != 0)
    {
        digitInNumber = par_num % 10; //if its two digit integer, I think you can do: par_num %100 and so on
        par_num = par_num / 10;       //regardless if you looking for a two digit int, still divide by 10

        if(digitInNumber == par_digit)
            return true;
    }

    return false;
}


