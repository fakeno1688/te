#include <bits/stdc++.h>
using namespace std;
class arry
{
private:
    int size;
    int length;
    int *item;

public:
    // creat
    arry(int sizes)
    {
        size = sizes;
        length = 0;
        item = new int[sizes];
    }
    // enter elements
    void fill()
    {
        int num_items;
        cout << "please enter length  ::";
        cin >> num_items;
        cout << "\n";
        if (num_items > size)
        {
            cout << "you can't enter more elements than the size of array"<<endl;
            return;
        }
        else
        {
            for (int i = 0; i < num_items; i++)
            {
                cout << "enter element at position " << i + 1 << " ::";
                cin >> item[i];
                length++;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << "item num " << i +1<< "  _" << item[i] << endl;
        }
    }
    ~arry()
    {
        delete[] item; // deleting the dynamically allocated array
        cout << "Array deleted" << endl;
    }
    int  get_length(){
        return length;
    }
    int get_size(){
        return size;
    }
    int search(int key)
    {
        int start = 0;
        int end = length - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (item[mid] == key)
            {
                cout<<"index :";
                return mid;
                
            }
            else if (item[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    void append(int num)
    {
        if (length < size)
        {
            item[length] = num;
            length++;
        }
        else
        {
            cout << "array is filled \n";
        }
    }
    void insert(int index, int value)
    {
        if (index>=0 &&length < size)
        {
            for (int i = length; i > index; i--)
            {
                item[i] = item[i - 1];
        
            }
            item[index] = value;
            length++;
        }
        else
        {
            cout << "array is filled \n";
        }
    }
    void deletes(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length; i++)
            {
                item[i] = item[i + 1];
            }
            length--;
        }
        else
        {
            cout << "index out of range \n";
        }
    }
    void enlarge(int new_size)
    {
        if (new_size <= size)
        {
            cout << "array is already at max size \n";
        }
        else
        {
            size = new_size;
            int *old = item;
            item = new int[new_size];
            for (int i = 0; i < length; i++)
            {
                item[i] = old[i];
            }
            size = new_size;
            delete[] old;
        }
    }
    void merge(arry other)
    {
        size = size + other.get_size();
        int *old = item;
        item = new int[size];
        for (int i = 0; i < length; i++)
        {
            item[i] = old[i];
        }
        delete[] old;
        int count = length ;
        for (int i = 0; i < other.get_length(); i++)
        {
            item[count++] = other.item[i];
            length++;
        }
    }
};
int main()
{
    cout<<"----------------------hello in your programs---------------------------"<<endl;
    arry x(5);
    x.fill();
    x.display();
    /*cout<<"please enter num want search  ::";
    int key;
    cin>>key;
    cout<<x.search(key)<<"\nkey :: "<<key<<endl;
    int add_num;
    cout<<"\nenter num want to add ::";
    cin>>add_num;
    x.append(add_num);
    cout<<"please enter index num to add";
    int index_num;
    cin>>index_num;
    cout<<"\nenter num want to insert ::";
    int insert_num;
    cin>>insert_num;
    x.insert(index_num,insert_num);
    x.display(); 
    x.deletes(1);
    x.display();
    x.enlarge(10);
    x.display();*/
    arry y(9);
    y.fill();
    x.merge(y);
    x.display();
    return 0;
}