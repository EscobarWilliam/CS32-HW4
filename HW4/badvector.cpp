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
//int main()
//{
//    const int N = some value;
//    bool hasCommunicatedWith[N][N];
//    ...
//    int numIntermediaries[N][N];
//    for (int i = 0; i < N; i++)
//    {
//        numIntermediaries[i][i] = -1;  // the concept of intermediary
//        // makes no sense in this case
//        for (int j = 0; j < N; j++)
//        {
//            if (i == j)
//                continue;
//            numIntermediaries[i][j] = 0;
//            for (int k = 0; k < N; k++)
//            {
//                if (k == i  ||  k == j)
//                    continue;
//                if (hasCommunicatedWith[i][k]  &&  hasCommunicatedWith[k][j])
//                    numIntermediaries[i][j]++;
//            }
//        }
//    }
//}
