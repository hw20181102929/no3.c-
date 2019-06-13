#include <iostream>
using namespace std;

template<class T>
class MyArray{
private:
    int size;
    T *data;
public:
    MyArray(int size);
    ~MyArray();
    bool check();
    void sort();
    void display();
};
template<class T>
MyArray<T>::MyArray(int size):size(size){
    data=new T[size];
}
template<class T>
void MyArray<T>::sort(){
    int i;
    for(i=0;i<size;i++){
        cin>>data[i];
    }
    T t=data[0];
    for(i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(data[j]>data[j+1]){
                t=data[j];
                data[j]=data[j+1];
                data[j+1]=t;
            }
        }
    }
}
template<class T>
void MyArray<T>::display(){
    int i;
    for(i=0;i<size;i++){
        if(i<size-1)
            cout<<data[i]<<" ";
        else
        {
            cout<<data[i];
        }
    }
    cout<<endl;
}

template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
