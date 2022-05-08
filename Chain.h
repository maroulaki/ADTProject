class Chain;

class ChainNode {
    friend Chain;
    private:
        int data;
        ChainNode *link;
    
};


class Chain {
    public:
        Chain();
        ~Chain();
        Chain & setLength(const int& x); //set maximum length of the list
        void Insert(int k, const int& x);
    private:
        ChainNode *first;               //pointer to first node
        int length;                     //length of list
        int maxL;                       //maximum length allowed 
};



