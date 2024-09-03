#include <bits/stdc++.h>
#define all(vector) vector.begin(), vector.end()
#define el '\n'
#define ll long long
#define vll vector<long long>
using namespace std;
template <typename N>
istream &operator>>(istream &istream, vector<N> &v)
{
    for (auto &i : v)
        cin >> i;
    return istream;
}
void FOI()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template<typename T>
class ADTarray{
private:
    T *arr ;
    ll size , length ;
public:
    ADTarray(int i = 0) {
        size = i ;
        length = 0;
        arr = new T[size];
    }
    bool isEmpty(){
        return (length == 0);
    }
    bool isFull(){
        return (length == size);
    }
    void append(const T& value) {
        if (isFull()){
            cout << "FULL" << el ;
            return;
        }
        arr[length++] = value ;
    }
    void insert(int index , T value){
        if (isFull()){
            cout << "FULL" << el ;
            return;
        }
        for (int i = length ; i > index ; --i) {
            arr[i] = arr[i-1] ;
        }
        arr[index] = value ;
        length++ ;
    }
    void print(){
        if (isEmpty()){
            cout << "Empty" << el ;
            return;
        }
        for (int i = 0; i < length; ++i) {
            cout << arr[i] << " " ;
        }
    }
    void printreverse(){
        if (isEmpty()){
            cout << "Empty" << el ;
            return;
        }
        for (int i = length - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
    void reverse() {
        for (int i = 0; i < length / 2; i++) {
            swap(arr[i], arr[length - 1 - i]);
        }
    }
    void rotateArray(int positions, bool toLeft = true){
        if (positions <= 0 || positions >= length) return;
        if (toLeft){
            while(positions--){
                T val = arr[0] ;
                for (int i = 0; i < length -1; ++i) {
                    arr[i] = arr[i+1] ;
                }
                arr[length-1] = val ;
            }
        }else{
            while(positions--){
                T val = arr[length-1] ;
                for (int i = length -1 ; i >= 0; --i) {
                    arr[i] = arr[i-1] ;
                }
                arr[0] = val ;
            }
        }
    }
    ADTarray<T> findDuplicates(){
       ADTarray<T> dup;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (arr[i] == arr[j]) {
                    dup.append(arr[i]);
                    break;
                }
            }
        }
        return dup;
    }
    void mergeWith(const ADTarray& otherArray){
        this->size = size + otherArray.length ;
        for (int i = 0; i < otherArray.length; i++) {
            append(otherArray.arr[i]);
        }
    }
    void resizeArray(int newSize){
        if (newSize < length){
            cout << "error" << el ;
            return;
        }
        this->size = newSize ;
    }
};
void solve(){
}
#define IOF ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    IOF
//    int t = 1;
//    //cin >> t;
//    while (t--)
//    {
//        solve();
//    }
    ADTarray<int> array(5);
    array.append(1);
    array.append(2);
    array.append(3);
    array.append(4);
    array.append(5);
    array.print();
    cout << el ;
    array.insert(2, 10);
    array.print();
    cout << el ;
    array.reverse();
    array.print();
    cout << el ;
    array.rotateArray(2);
    array.print();
    cout << el ;
    ADTarray<int> array2(5);
    array2.append(6);
    array2.append(7);
    array2.append(8);

    array.mergeWith(array2);
    array.print();
    return 0;
}