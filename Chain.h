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
        Chain & Insert(int k, const int& x);
    private:
        ChainNode *first; // pointer to first node
        ChainNode *last; //pointer to last node
        int length; //length of list
        int maxL;
};



