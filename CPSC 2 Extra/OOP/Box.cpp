#include <iostream>
using namespace std;

class Box
{
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box

   public:


      double getVolume(void) {
         return length * breadth * height;
      }

      void setLength( double len ) {
         length = len;
      }

      void setBreadth( double bre ) {
         breadth = bre;
      }

      void setHeight( double hei ) {
         height = hei;
      }

      // Overload + operator to add two Box objects.
      Box operator+(const Box& b)
      {
         cout << "One parameters\n";
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }

      /*This is not overloading an operator but defining an operator*/
      //Box operator+(Box& a, Box& b)
      friend Box operator+(const Box& a, const Box& b)
      {
          cout << "Two parameters\n";
          Box temp;
          temp.length = a.length + b.length;
          temp.breadth = a.breadth + b.breadth;
          temp.height = a.height + b.height;
          return temp;
      }

};



// Main function for the program

int main( ) {
   Box Box1;
   Box Box2;
   Box Box3;
   Box Box4;
   double volume = 0.0;     

   // box 1 specification
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);

   // box 2 specification
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);

   // volume of box 1
   volume = Box1.getVolume();
  // cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
  // cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;
   //Box4 = Box1.operator+(Box2);
   Box4 = Box1 + Box2;
   //This will not work.  I am defining the + operator I can not call it
   //Box4 = Box4.operator+(Box1,Box2);
   Box4 = operator+(Box1, Box2);

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
   //volum of box 4
   volume = Box4.getVolume();
   cout << "Volume of Box4 : " << volume <<endl;
   return 0;
}
