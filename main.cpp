#include <iostream>
#include "pnitrax.h"
using namespace std;

int main()
{
   string x;
   PNItrax pni;
   while (1)
   {
        cout << "Ввидите посылку: " << endl;
        cin >> x;
        pni.parser(x);

   }
   return 0;
}
