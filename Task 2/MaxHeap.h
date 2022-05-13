class MaxHeap
{
    public:
        MaxHeap();
        ~MaxHeap();
        MaxHeap & Insert(const float& x);
        MaxHeap & DeleteMax(float& x);
        void Initialize(float a[], int size, int ArraySize);
    private:
        int CurrentSize;
        int MaxSize;
        float *heap;
};


