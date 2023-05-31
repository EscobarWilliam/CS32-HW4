//
//  evenlist.cpp
//  HW4
//
//  Created by William  Escobar on 5/16/23.
//

// Remove the even integers from li.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original list.
void removeEven(list<int>& li)
{
  list<int>::iterator it;
  it = li.begin();//start at the begining
  while(it != li.end())
  {
      if(*it %2 == 0)
      {
          list<int>::iterator temp = it;
          it--;
          li.erase(temp);
      }
      it++;
  }
}
