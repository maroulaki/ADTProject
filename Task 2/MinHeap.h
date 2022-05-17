class MinHeap
{
    public:
        MinHeap();
        ~MinHeap();
        void Insert(const float& x);
        void DeleteMin(float& x);
        void Initialize(float a[], int size, int ArraySize);
    private:
        int CurrentSize;
        int MaxSize;
        float *heap;
};

