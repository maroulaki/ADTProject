#include <iostream>
#include <random>
#include <functional>


// now it works for real
//Maria δουλευει ο κοδηκας αυτος κανει ακριβος οτι του ζητα η ασκηση
// τελικα ηταν μικρο το bug το εφτιαξα





// Comments are gonna be in english because we am to bored to
// switch between languages also fuck you
std::default_random_engine generator;
std::uniform_int_distribution<int> data_element_distribution(0, 100);
auto random_element = std::bind(data_element_distribution, generator);
//RNG as shown in the provided instruction


class node {       // node chain class
public:
    int num;
    node* link = NULL;
};



int main() {
        node* T = 0 ; //TEMPORARY POINTER
        node* H = 0 ; //HEAD POINTER        // start out as 0 because cpp is a fucking cocksucker
        node* N = 0 ; //NEW POINTER         //Also fuck cpp for being case sensitive I am to bored to fix the pointer names now and I hate it and I hate myself

        int size; //give size
        std::cout << "give me size \n";
        std::cin >> (size);

        for (int i = 1; i <= size; i++) // Creating the chain 
        {
            if (i == 1)             // making the head node
            {
                N = new node;
                H = N;
                T = N;
                N->num = random_element();

            }
            else {
                N = new node;
                N->num = random_element();
                T->link = N;
                T = N;
                //N->link = NULL ;//temporary fix
            }
        }
        // prints the chain
        N = H;
        while (true){         //continues untill break
            std::cout << N->num << "\n";
            if (!N->link) { break; } //stops when the link is null
            N = N->link;
        }

        // build historohtgram or whatever

        node* HH = 0; //HEAD HISTORIOGRAM POINTER
        node* TH = 0; // TEMORARY HITOGRAM

        T = H;
        int AIA; // the numbers found
        for (int i = 0; i <= 100; i++) {// for to create the histo chain //searching for i
            AIA = 0;
            
            N = H;
            while (true) {         //continues untill break
                if (i == N->num) {
                    AIA++ ; }
                if (!N->link) { break; } //stops when the link is null
                N = N->link;
            }
            
            
            
            
            
            
            if (i == 0)             // making the head istorogram node
            {
                N = new node;
                HH = N;
                TH = N;
                TH->num = AIA;
            }else {
                N = new node;
                TH->link = N;
                TH = N;
                TH->num = AIA;
            }
        
        


        }


        

        //int hell;
        N = HH;
        // prints the histogram second attemp
        for (int i = 0; i <= 100; i++)
        {
            //hell = i + 1;
            std::cout << "the number : " << (i) << " appears " << N->num << " Time \n";
            N = N->link;
        }
        
        
        
        
        
        
        /*
        int j = 1;
        // prints the Historogrand
        N = HH;
        while (true) {         //continues untill break
            std::cout << "the number : " << (j) << " appears " << N->num << "\n";
            if (!N->link) { break; } //stops when the link is null
            N = N->link;
            j++ ;
        }*/







    return 0;
}
