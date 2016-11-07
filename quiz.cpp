#include <iostream>
#include <vector>
using namespace std;
vector<int> quicksort(vector<int> unsort)
{
    if(unsort.size()<2)
        return unsort;
    
    int pivot = unsort.back();
    vector<int> small, large;
    for(int i = 0; i < unsort.size()-1;++i)
    {
        if(unsort[i] < pivot)
            small.push_back(unsort[i]);
        else
            large.push_back(unsort[i]);
    }
    small=quicksort(small);
    large=quicksort(large);
    small.push_back(pivot);
    large.insert(large.begin(),small.begin(),small.end());
    return large;
}
class MaxHeap
{
private:
    vector<int> data;
    int left_index(int index)
    {
        return 2 * index + 1;
    }
    int right_index(int index)
    {
        return 2 * index + 2;
    }
    int parent_index(int index)
    {
        return (index - 1) / 2;
    }
    
public:
    MaxHeap()
    {
        vector<int> data;
    }
    
    void Heapify_Up()
    {
        int start_index = data.size() - 1;
        while (start_index > 0 && data[start_index] > data[parent_index(start_index)])
        {
            swap(data[start_index], data[parent_index(start_index)]);
            start_index = parent_index(start_index);
        }
    }
    
    
    void Add(int val)
    {
        data.push_back(val);
        Heapify_Up();
    }
    
    void Print()
    {
        for (int i = 0; i < data.size(); ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
};

void test_maxheap()
{
    MaxHeap myheap;
    for (int i = 1; i < 10; ++i) {
        myheap.Add(i);
    }
    myheap.Print();
}
void test_quicksort()
{
    vector<int> a;
    for(int i = 5; i >= 0; --i)
        a.push_back(i);
    a = quicksort(a);
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
}

int main()
{
    test_quicksort;
    test_maxheap();
    return 0;
}



