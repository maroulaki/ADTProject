template<class T>
class ChainNode {
    friend Chain<T>;
    private:
        T data;
        ChainNode<T> *link;
};

template <class T>
class Chain {
    public:
        Chain() {first = 0;}
        ~Chain();
        int Search(const T& x) const; 
        Chain<T> & Insert(int k, const T& x);
    private:
        ChainNode<T> *first; // pointer to first node
};



