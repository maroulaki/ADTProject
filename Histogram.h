template<class T>
class HistoNode {
    friend Histogram<T>;
    private:
        T data;
        int times;
        HistoNode<T> *link;
};

template <class T>
class Histogram {
    public:
        Histogram() {first = 0;}
        ~Histogram();
        bool IsEmpty() const;
        int Search(const T& x) const; 
        Histogram<T> & Insert(int k, const T& x);
        Histogram<T> & Increase(const T& x); //Increases the times a number is found in the relevant HistoNode
    private:
        HistoNode<T> *first; // pointer to first node
};