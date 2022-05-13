class MinHeap
{
    public:
        MinHeap();
        ~MinHeap();
        MinHeap & Insert(const float& x);
        MinHeap & DeleteMin(float& x);
        void Initialize(float a[], int size, int ArraySize);
    private:
        int CurrentSize;
        int MaxSize;
        float *heap;
};

