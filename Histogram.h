class Histogram;

class HistoNode {
    friend Histogram;

    private:
        int data;
        int times;
        HistoNode *link;
};

class Histogram {
    public:
        Histogram();
        ~Histogram();
        bool Exists(int x) const; 
        Histogram & Insert(int x);                     //Inserts the number in the appropriate position
        Histogram & Increase(int x);                   //Increases the times a number is found in the relevant HistoNode
        void printHistogram() const;
    private:
        HistoNode *first; // pointer to first Histonode
        HistoNode *last;
};