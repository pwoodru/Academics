#include<iostream> 
#include<memory> 
using namespace std;

int main()
{
    int* s = new int;
    shared_ptr<int> s1(s);
    cout << "s1 count " << s1.use_count() << endl;
    shared_ptr<int> s2 = s1;
    cout << "s1 count " << s1.use_count() << endl;
    shared_ptr<int> s3(s2);
    cout << "s1 count " << s1.use_count() << endl;
    cout << "s2 count " << s2.use_count() << endl;
    cout << "s3 count " << s3.use_count() << endl;
    //delete s; this line will give me a abort or segfault why?
    s = nullptr;
    return 0;
}