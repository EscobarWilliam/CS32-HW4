//
//  badvector.cpp
//  HW4
//
//  Created by William  Escobar on 5/16/23.
//

// Remove the restaurants in v with 2 or fewer stars and destroy them.
// It is acceptable if the order of the remaining restaurants is not
// the same as in the original vector.
void removeBad(vector<Restaurant*>& v)
{
  //in order to use the erase() member function, we need to use an iterator
  vector<Restaurant*>::iterator it;
  it = v.begin();
  while(it != v.end())
  {
      if( (*it)->stars() <= 2)
      {
          vector<Restaurant*>::iterator temp = it;
          it--;
          delete *temp;//NEED this line otherwise the allocated memory won't be deleted
          v.erase(temp); //this erases the pointer, but not the object(i.e. memory leak)
          
      }
      it++;
  }
}
