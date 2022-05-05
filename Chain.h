template<class T>
class ChainNode {
    friend Chain<T>;
    private:
        T data;
        ChainNode<T>
    *link;
};

template <class T>
class Chain {
    public:
        Chain()
        ~Chain();
        bool IsEmpty() const;
        int Length() const;
        bool Find(int k, T& x) const;
        int Search(const T& x) const;
        Chain<T> & Delete(int k, T& x);
        Chain<T> & Insert(int k, const T& x);
        void Output(iostream& out) const;
    private:
        ChainNode<T> *first; // pointer to first node
};



