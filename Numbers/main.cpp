#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
//#include "Number.h"
using namespace std;

class Number
{
private:
  int number;


public:
  Number()
  {number = 0;}

  Number(int n)
  {number = n;}

  void setNumber(int n)
  {number = n;}

  int getNumber()
  {return number;}
  void showNumber()
  {
    cout<<number<<endl;
  }

  void showNumberText()
  {
    string LT20[20] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven"
                        ,"Twelve","Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string GT20[9] = {"Twenty","Thirty","Fourty","FIDDY","Sixty","Seventy","Eighty","Ninety"};
    string hun = " Hundred ";
    string thou = " Thousand ";
    int thousands, hundreds, tens, ones;
    thousands = (number%10000)/1000;
    hundreds  = (number%1000)/100;
    tens      = (number%100)/10;
    ones      = (number%10);

    if(thousands > 0)
    {
      cout<<LT20[thousands]<<thou;
    }
    if(hundreds > 0)
    {
      cout<<LT20[hundreds]<<hun;
    }
    if(tens >= 2)
    {
      cout<<GT20[tens-2];
      if(ones>0)
        cout<<" "<<LT20[ones];
    }
    else
    {
      tens = (tens*10)+ones;
      cout<<LT20[tens];
    }
    cout<<endl;
  }
};

int main()
{
  //int choice;
  //bool exit = false;
  Number number(0);
  for(int i = 1 ; i < 10000 ; i++)
  {
    cout<<"Number = "<<i<<endl;;
    number.setNumber(i);
    number.showNumberText();
  }



/*
  while(!exit)
  {
    cout<<"Pick a number or type -1 for exit > ";
    cin>>choice;
    if(choice>=0)
    {
      Number temp(choice);
      temp.showNumber();
    }
    else
      exit = true;
  }
*/
  return 0;
}
