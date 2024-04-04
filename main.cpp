#include <iostream>
#include <fstream>
#include "lista.h"

using namespace std;

int main ()
{
   nod *cap=NULL;
   nod *ultim=NULL;
   ifstream fin("date.txt");
   float x;
   while(fin>>x) citire(cap,ultim, x);
   fin.close();

   afisare(cap);

   int operatie;
   int operatie1;

   do
   {
        switch(operatie)
        {
            case 1:
            {
                cout<<"\n\nCe tip de adaugare se va realiza: \n1|Adaugare la inceput\t2|Adaugare la sfarsit\t3|Adaugare dupa element dat\n\n";
                cin>>operatie1;
                while(operatie1<1 or operatie1>3) 
                   {
                      cout<<"\n\nOperatiile care se pot realiza sunt: \n1|Adaugare la inceput\t2|Adaugare la sfarsit\t3|Adaugare dupa element dat\n";
                      cin>>operatie1;
                   }
                    
                switch(operatie1)
                {
                    case 1:
                    {
                        adaug_inainte_de_prim(cap);
                        break;
                    }
                    case 2:
                    {
                        adaug_dupa_ultim(ultim);
                        break;
                    }
                    case 3:
                    {
                        adaug_dupa_element(cap);
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout<<"\n\nCe tip de cautare se va realiza: \n1|Cautare dupa pozitie\t2|Cautare dupa valoare\n\n";
                cin>>operatie1;
                while(operatie1<1 or operatie1>2) 
                {
                  cout<<"\n\nOperatiile care se pot realiza sunt: \n1|Cautare dupa pozitie\t2|Cautare dupa valoare\n";
                  cin>>operatie1;
               }
                switch(operatie1)
                {
                    case 1:
                    {
                        cautare_pozitie(cap);
                        break;
                    }
                    case 2:
                    {
                        cautare_valoare(cap);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                cout<<"\n\nCe tip de stergere se va realiza: \n1|Stergere pozitie\t2|Stergere valoare\n\n";
                cin>>operatie1;
                while(operatie1<1 or operatie1>2) 
                {cout<<"\n\nOperatiile care se pot realiza sunt: \n1|Stergere pozitie\t2|Stergere valoare\n";
                  cin>>operatie1;
               }
                switch(operatie1)
                {
                    case 1:
                    {
                        stergere_pozitie(cap);
                        break;
                    }
                    case 2:
                    {
                        stergere_valoare(cap);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                afisare(cap);
                break;
            }
        }
        cout<<"\nCe operatie va fi efectuata: \n1|Adaugare\t2|Cautare\t3|Stergere\t4|Afisare\n\n";
        cin>>operatie;
        while(operatie<0 or operatie>4) 
           {cout<<"\n\nOperatiile posibile sunt: \n1|Adaugare\t2|Cautare\t3|Stergere\t4|Afisare\n";
            cin>>operatie;
         }
   }while(operatie!=0);

   return 0;
}
