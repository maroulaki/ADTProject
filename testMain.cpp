#include "Chain.h"
#include "Histogram.h"
#include <iostream>
using namespace std;

int main() {
    cout<<"This worked"<<endl;
   

    //-----------CHAIN TESTS----------------
    Chain chain1 = Chain();
    chain1 = chain1.setLength(100);

    void TEST_ERR_POS_K();
    {
        chain1.Insert(101,5);   //ERR
        chain1.Insert(-1,5);    //ERR
        chain1.Insert(1,5);     //ERR   
    }

    
   

    // void TEST_ERR_NOMEM(); {
    //     chain1.Insert(4, 5);    //ERR
    //     chain1.Insert(100,5);   //ERR
    //     chain1.Insert(101,5);   //ERR   
    // }

    //---------HISTOGRAM TESTS---------------
    Histogram h = Histogram();

    

    void TEST_HISTO_INSERT(); 
    {
        cout<<"TEST HISTO INSERT"<<endl;
        cout<<"branch 1 succ"<<endl;
        h = h.Insert(1);
        cout<<"branch 2 succ"<<endl;
        h = h.Insert(0);
        cout<<"branch 3 succ"<<endl;
        h = h.Insert(3);
        cout<<"branch 4 succ"<<endl;
        h = h.Insert(2);
        
    }

    void TEST_HISTO_EXISTS();
    {
        cout<<"TEST HISTO EXISTS"<<endl;
        cout<<h.Exists(1)<<" ";
        cout<<h.Exists(5)<<" ";
        cout<<h.Exists(3)<<" ";
        cout<<h.Exists(100)<<" "<<endl;
        cout<<"EXPECT 1 0 1 0"<<endl;
    }

    void TEST_HISTO_PRINT(); 
    {
        Histogram hp = Histogram();
        cout<<"TEST HISTO PRINT"<<endl;
        hp.printHistogram();
        h.printHistogram();
    }


}