//
//  evenvector.cpp
//  HW4
//
//  Created by William  Escobar on 5/16/23.
//

// Remove the even integers from v.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original vector.
void removeEven(vector<int>& v)
{
  vector<int>::iterator it;
  it = v.begin();//start at the begining
  while(it != v.end())
  {
      if(*it %2 == 0)
      {
          vector<int>::iterator temp = it;
          it--; //this could have a memory leak, because what if the first one in the list is deleted
          v.erase(temp);
      }
      it++;
  }
}
