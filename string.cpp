#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

// String s = new String(xxx);

class String
{
  char * m_str; //4
  static const uint32_t m_limit = 26; //4
  char m_storage[m_limit]; // 26 + 2(padding for alignment) must be padded to the multiple of size of next member
  size_t m_size; //4
  size_t m_capacity; //4
  
  public:

  // ctor
  String(const char * input)
  {
    m_size = strlen(input);
    if( m_size > m_limit)
    {
      m_str = new char[m_size];
      m_capacity = m_size;
      memcpy(m_str, input, m_size);
    }
    else
    {
      // small string optimization
      memcpy(m_storage, input, m_size);
      m_str = m_storage;
      m_capacity = m_limit;
    }
  }
  
  // operator +=
  String & operator+=(const char * input)
  {
    auto input_size = strlen(input);
    auto new_size = input_size + m_size; 
    if(new_size > m_limit)
    {
      auto new_str = new char[new_size]; 
      memcpy(new_str, m_str, m_size);
      memcpy(new_str+m_size, input, input_size);
      if(m_str != m_storage) delete [] m_str;
      m_str = new_str;
      m_capacity = new_size;
    }
    else
    {
      memcpy(m_str + m_size, input, input_size);
    }
    
    m_size = new_size ;
    return *this;
  }
  
  char * c_str() const { return m_str; }
};


ostream& operator<< (ostream& os, const String& str) {
  os << str.c_str();
  return os;
}

int main(void) {
  String test_string("hello");
  test_string += " Bo";

  cout << endl;
  cout.operator<<(endl);
  
  cout << test_string << endl;
  operator<<(cout, test_string).operator<<(endl);
  
  // cout.operator<<(test_string); invalid, why?
  
  test_string += ", hello !!!!!!!!!!!!";
  cout << test_string << endl;
  
  return 0;
}


// Things to ponder:
// what is the size of String on stack
// Why does std::string operator+= return a string&?
// What is the difference of implementing operator<< as a member function or a non-memeber function, why?

// to compile:
// g++ -std=c++11 string.cpp