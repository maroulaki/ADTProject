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
        Histogram();
        ~Histogram();
        HistoNode<T>* & Exists(const T& x) const; 
        int getMax() const; //fetches the largest (essentially last) number of the histogram
        Histogram<T> & Insert(const T& x); //Inserts the number in the appropriate position
        void Increase(const HistoNode<T> *ptr); //Increases the times a number is found in the relevant HistoNode
        
    private:
        HistoNode<T> *first; // pointer to first Histonode
        HistoNode<T> *last;
};