#include "Vector.h"
using namespace std;

int main()
{
    cout << "First create a vector with ctor." << endl;
    Vector<int> vec0;
    cout << "Check if is empty:" << vec0.empty() << endl;
    cout << "The size is: " << vec0.size() << endl;
    cout << "The capacity is: " << vec0.capalicity() << endl << endl;

    cout << "Then create a vector with 5 as a capacity" << endl;
    Vector<int> vec(5);
    cout << "Check if is empty:" << vec.empty() << endl;
    cout << "The size is: " << vec.size() << endl;
    cout << "The capacity is: " << vec.capalicity() << endl << endl;

    cout << "Then push_back 0-4 to the end: " << endl;
    for(int i = 0; i < vec.capalicity(); i++){
        vec.push_back(i);
        cout << "using vec[i] visit at index " << i << " : " << vec[i] << endl;
        cout << "using vec.at(i) visit at index " << i << " : " << vec.at(i) << endl;
        cout << "Check if is empty:" << vec.empty() << endl;
        cout << "The size is: " << vec.size() << endl;
        cout << "The capacity is: " << vec.capalicity() << endl;
    }

    cout << endl << "Then using copy ctor: " << endl;
    Vector<int> vec2(vec);
    cout << "Check if is empty:" << vec2.empty() << endl;
    cout << "The size is: " << vec2.size() << endl;
    cout << "The capacity is: " << vec2.capalicity() << endl << endl;

    cout << "Then try to use vec[i] to visit a illegal position:" << endl;
    cout << vec[6] << endl << endl;   

    cout << "Then try to use vec.at(i) to visit a illegal position:" << endl;
    // cout << vec.at(6) << endl; 
    cout << "The program will throw out exception and quit" << endl << endl; 
    
    cout << "Then check the function of inflate()" << endl;
    vec.push_back(6);
    cout << "The size is: " << vec.size() << endl;
    cout << "The capacity is: " << vec.capalicity() << endl << endl;
    
    cout << "Then clear the vector" << endl;
    vec.clear();
    cout << "The size is: " << vec.size() << endl;
    cout << "The capacity is: " << vec.capalicity() << endl << endl;
    system("PAUSE");
    return 0;
}