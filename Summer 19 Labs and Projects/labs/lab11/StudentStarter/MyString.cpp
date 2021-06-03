#include "MyString.h"

using namespace std;

MyString::MyString() : data(" "), size(0) {
}

MyString::MyString(const char* a) : data(a), size(0) {
}

MyString::MyString(const MyString& a) : data(a.data), size(a.size) {
}

int MyString::len() const {
  return this->size;
}

MyString& MyString::operator=(const MyString& a) {
  MyString b;
  b = a;

  return &b;
}

MyString& MyString::operator=(const char* a) {
  MyString c;
  c.data = a;
  return c;
}

MyString& MyString::operator+= (const MyString& a) {
  MyString c;
  c.data = this->data + a.data;
  return c;
}

MyString operator+ (const MyString& a, const MyString& b) {
  MyString c;
  c.data = a.data + b.data;
  c.size = a.size + b.size;
  return c;
}

MyString operator+ (const MyString& a, const char* b) {
  MyString c;
  c.data = a.data + b;
  c.size = a.size;
  return c;
}

MyString operator+ (const char* a, const MyString& b) {
  return MyString(b.data + a);
}

bool MyString::operator==(const MyString& a) const {

}

bool MyString::operator!=(const MyString& right) const {

}

bool operator< (const MyString& a, const MyString& b) {

}

bool operator> (const MyString& a, const MyString& b) {

}

bool operator<= (const MyString& a, const MyString& b) {

}

bool operator>= (const MyString& a, const MyString& b) {

}

char MyString::operator[] (int ndx) const {

}

MyString MyString::operator() (int a, int b=0) const {

}

ostream& operator<<(ostream& out, const MyString& a) {

}

istream& operator>>(istream& in, MyString &a) {

}
