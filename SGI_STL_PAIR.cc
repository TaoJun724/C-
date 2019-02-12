#include<iostream>

template<class T1,class T2>
struct Pair
{
   typedef T1 first_type;
   typedef T2 second_type;

   T1 first;
   T2 second;

   Pair()
     :first(T1())
     ,second(T2())
  {}

   Pair(const T1& a,const T2& b)
     :first(a)
     ,second(b)
  {}
};

