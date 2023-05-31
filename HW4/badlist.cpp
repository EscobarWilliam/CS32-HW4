//
//  badlist.cpp
//  HW4
//
//  Created by William  Escobar on 5/16/23.
//
// Remove the restaurants in li with 2 or fewer stars and destroy them.
// It is acceptable if the order of the remaining restaurants is not
// the same as in the original list. Keep in mind that the resturaunts
// list is a list of pointers, not just objects
void removeBad(list<Restaurant*>& li)
{
  //in order to use the erase() member function, we need to use an iterator
  list<Restaurant*>::iterator it;
  it = li.begin();
  while(it != li.end())
  {
      if( (*it)->stars() <= 2)
      {
          list<Restaurant*>::iterator temp = it;
          it--;
          delete *temp;//NEED this line otherwise the allocated memory won't be deleted
          li.erase(temp); //this erases the pointer, but not the object(i.e. memory leak)
          
      }
      it++;
  }
}
