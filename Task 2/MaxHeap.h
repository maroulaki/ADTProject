class Maxheap;

template<class T>
class MaxHeap
{
    public:
        MaxHeap();
        ~MaxHeap();
        MaxHeap<T> & Insert(const T& x);
        MaxHeap<T> & DeleteMax(T& x);
        void Initialize(T a[], int size, int ArraySize);
    private:
        int CurrentSize;
        int MaxSize;
        T *heap[];
};


