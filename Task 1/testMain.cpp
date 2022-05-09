#include "Chain.h"
#include "Histogram.h"
#include <iostream>
using namespace std;

//Το αρχείο αυτό περιέχει blocks εντολών με unit tests για 
//τις μεθόδους των Chain.h και Histogram.h
//Δεν έχει ενημερωθεί.

int main() {
    cout<<"This worked"<<endl;

    //-----------CHAIN TESTS----------------
    Chain chain1 = Chain();
    chain1 = chain1.setLength(100);


    cout<<"TEST ERR POS K"<<endl;
    { 
        cout<<"try 1"<<endl;
        chain1.Insert(101,5);   //ERR
        cout<<"try 1"<<endl;
        chain1.Insert(-1,5);    //ERR
        cout<<"try 1"<<endl;
        chain1.Insert(1,5);     //ERR   
        cout<<"-------------------------"<<endl;
    }

    cout<<"TEST CHAIN INSERT"<<endl; 
    {
        for (int i = 0; i < 100; i++)
        {
            cout<<i+1<<endl;
            chain1.Insert(i,i+1);
        }
        cout<<"-------------------------"<<endl;
    }
   
    cout<<"TEST CHAIN ACCESS"<<endl; 
    {
        cout<<"Try 1 ERR"<<endl;
        cout<<chain1.accessX(0)<<endl;    //ERR
        cout<<"Try 2 100"<<endl;
        cout<<chain1.accessX(100)<<endl;  //100
        cout<<"Try 3 ERR"<<endl;
        cout<<chain1.accessX(101)<<endl;  //ERR 
        cout<<"-------------------------"<<endl;      
    }

    cout<<"TEST ERR NOMEM"<<endl; 
    {
        chain1.Insert(4, 5);    //ERR
        chain1.Insert(100,5);   //ERR
        cout<<"-------------------------"<<endl;   
    }

    //---------HISTOGRAM TESTS---------------
    Histogram h = Histogram();

    

    cout<<"TEST HISTO INSERT"<<endl;
    {
        cout<<"branch 1 succ"<<endl;
        h = h.Insert(1);
        cout<<"branch 2 succ"<<endl;
        h = h.Insert(0);
        cout<<"branch 3 succ"<<endl;
        h = h.Insert(3);
        cout<<"branch 4 succ"<<endl;
        h = h.Insert(2);
        cout<<"-------------------------"<<endl;
    }

    cout<<"TEST HISTO EXISTS"<<endl;
    {
        cout<<h.Exists(1)<<" ";
        cout<<h.Exists(5)<<" ";
        cout<<h.Exists(3)<<" ";
        cout<<h.Exists(100)<<" "<<endl;
        cout<<"EXPECT 1 0 1 0"<<endl;
        cout<<"-------------------------"<<endl;
    }

    cout<<"TEST HISTO PRINT"<<endl; 
    {
        Histogram hp = Histogram();
        hp.printHistogram();
        h.printHistogram();
    }
}