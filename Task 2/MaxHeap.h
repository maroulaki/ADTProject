class MaxHeap
{
    public:
        MaxHeap();
        ~MaxHeap();
        void Insert(const float& x);
        void DeleteMax(float& x);
        void Initialize(float a[], int size, int ArraySize);
    private:
        int CurrentSize;
        int MaxSize;
        float *heap;
};


