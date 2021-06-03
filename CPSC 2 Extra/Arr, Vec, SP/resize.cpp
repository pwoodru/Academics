#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int i;

    vector<int>test(15, 1);
    vector<int>test2(26, 10);
    vector<int>test3(15);
    cout << test.size() << endl;

    /*Adds 10 to the size ofthe vector*/
    test.resize(25);
    for(i = 0; i < test.size(); i++)
    {

       cout << test[i] << " ";
    }
    cout << endl;
    cout << test.size() << endl;
    test.resize(28, -1);
    for(i = 0; i < test.size(); i++)
    {

       cout << test[i] << " ";
    }
    cout << endl;
    /*Since this is actually reducing the size of the vector, the -1 is ignored
    *This is because when increasing the size if you pass in the initial 
    *value for those elements it can only change the value of the new ones. 
    *Reducing does not change the value of existing elements.  When reducing 
    *the size all element beyound the reduced size will be discarded*/
    //test.clear();
    test.shrink_to_fit();
    cout << test.size() << " " << test.capacity()<< endl;
    test.resize(5, -1);
    
    cout << test.size() << " " << test.capacity()<< endl;

    cout << "printing the content of test\n";
   for(i = 0; i < test.size(); i++)
   {

       cout << test[i] << " ";
   }
   cout << endl;
    cout << test.size() << " " << test.capacity()<< endl;

    /*Adds another element to the vector*/
    test.push_back(5);
    cout << test.size() << endl;

    /*back only returns the value of the last element.  It does not change the
     *size of the array.*/
    cout << test.back() << endl;
    cout << test.size() << endl;

    /*Now we are going to give a new value to each element in test.  We will
     *use "at" to access each element of test.  */

    for(i = 0; i < test.size(); i++)
    {

        test.at(i) = i+1;
    }

    /*Now using array notation we are going to print the value of each element
     *of test.*/
     cout << "printing the content of test\n";
    for(i = 0; i < test.size(); i++)
    {

        cout << test[i] << " ";
    }
    cout << endl;
   /*Now I am going to introduce the 'at' function. When using the [] to asccess
    *elements of a vector is not real safe because it does not check the bounds
    *of your vector.  However the at() function acts just like the [] but does
    *provide bounds checking*/
   
    for(i = 0; i < test3.size(); i++)
    {

        test3.at(i) = i+1;
    }

    /*Now we will call reverse to see what happens. 
    
    The vector class provides several functions that allow us to access the 
    data in the vector two of these are begin() and end(). The following
    reverse funtion call basically says start at the beginning of the vector 
    stopping at the end.  I want you to reverse the elements in the vector*/
    reverse(test.begin(), test.end());
    cout << endl;

    cout << "printing the content of test after reverse\n";
    for(i = 0; i < test.size(); i++)
    {

        cout << test.at(i) << " ";
    }
    cout << endl;

       cout << "Before Swap size and capacity"<< test.capacity() << " " << test2.capacity() << endl;
    /*This should swap the content of test and test2.*/
    test.swap(test2);

    cout << "printing the content of test after swap\n";
    for(i = 0; i < test.size(); i++)
    {

        cout << test.at(i) << " ";
    }
    cout << endl;

    cout << "printing the content of test2 after swap\n";
    for(i = 0; i < test2.size(); i++)
    {

        cout << test2.at(i) << " ";
    }
    cout << endl;
    cout << "After Swap size and capacity" << test.capacity() << " " << test2.capacity() << endl;

    /*Now we are going to clear the elements of test2*/
    cout << "Before clear " <<test2.size() << endl;
    test2.clear();
    cout << "After clear " << test2.size() << endl;

    /*Now we will print the content of test2*/
    cout << "printing test2 after calling clear (this should be empty)\n";
    for(i = 0; i < test2.size(); i++)
    {

        cout << test2.at(i) << " ";
    }

   
    
    return 0;

}
