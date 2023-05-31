//
//  main.cpp
//  HW4
//
//  Created by William  Escobar on 5/15/23.
//
//#include <vector>
//    #include <algorithm>
//    #include <iostream>
//    #include <cassert>
//    using namespace std;
//
//    vector<int> destroyedOnes;
//
//    class Restaurant
//    {
//      public:
//        Restaurant(int s) : m_stars(s) {}
//        ~Restaurant() { destroyedOnes.push_back(m_stars); }
//        int stars() const { return m_stars; }
//      private:
//        int m_stars;
//    };
//
//      // Remove the restaurants in v with 2 or fewer stars and destroy them.
//      // It is acceptable if the order of the remaining restaurants is not
//      // the same as in the original vector.
//void removeBad(vector<Restaurant*>& v)
//{
//  //in order to use the erase() member function, we need to use an iterator
//  vector<Restaurant*>::iterator it;
//  it = v.begin();
//  while(it != v.end())
//  {
//      if( (*it)->stars() <= 2)
//      {
//          vector<Restaurant*>::iterator temp = it;
//          it--;
//          delete *temp;//NEED this line otherwise the allocated memory won't be deleted
//          v.erase(temp); //this erases the pointer, but not the object(i.e. memory leak)
//
//      }
//      it++;
//  }
//}
//
//
//    void test()
//    {
//        int a[8] = { 4, 3, 2, 4, 1, 1, 5, 2 };
//        vector<Restaurant*> x;
//        for (int k = 0; k < 8; k++)
//            x.push_back(new Restaurant(a[k]));
//        assert(x.size() == 8 && x.front()->stars() == 4 && x.back()->stars() == 2);
//        removeBad(x);
//        assert(x.size() == 4 && destroyedOnes.size() == 4);
//        vector<int> v;
//        for (int k = 0; k < 4; k++)
//            v.push_back(x[k]->stars());
//        sort(v.begin(), v.end());
//        int expect[4] = { 3, 4, 4, 5 };
//        for (int k = 0; k < 4; k++)
//            assert(v[k] == expect[k]);
//        sort(destroyedOnes.begin(), destroyedOnes.end());
//        int expectGone[4] = { 1, 1, 2, 2 };
//        for (int k = 0; k < 4; k++)
//            assert(destroyedOnes[k] == expectGone[k]);
//        for (vector<Restaurant*>::iterator p = x.begin(); p != x.end(); p++)
//            delete *p;
//    }
//
//    int main()
//    {
//
//        test();
//        cout << "Passed" << endl;
//    }
//#include "Sequence.h"
//    #include <iostream>
//    #include <string>
//    #include <cassert>
//    using namespace std;
//
//    void test()
//    {
//        Sequence<int> si;
//        assert(si.empty());
//        assert(si.size() == 0);
//        assert(si.insert(0, 20) == 0);
//        assert(si.insert(10) == 0);
//        assert(si.find(20) == 1);
//        assert(si.remove(10) == 1);
//        int i;
//        assert(si.get(0, i));
//        assert(si.set(0, 30));
//        assert(si.erase(0));
//        Sequence<int> si2(si);
//        si2.swap(si);
//        si2 = si;
//        assert(subsequence(si,si) == -1);
//        concatReverse(si,si2,si);
//
//        Sequence<string> ss;
//        assert(ss.empty());
//        assert(ss.size() == 0);
//        assert(ss.insert(0, "Hello") == 0);
//        assert(ss.insert("Goodbye") == 0);
//        assert(ss.find("Hello") == 1);
//        assert(ss.remove("Goodbye") == 1);
//        string s;
//        assert(ss.get(0, s));
//        assert(ss.set(0, "Aloha"));
//        assert(ss.erase(0));
//        Sequence<string> ss2(ss);
//        ss2.swap(ss);
//        ss2 = ss;
//        assert(subsequence(ss,ss2) == -1);
//        concatReverse(ss,ss2,ss);
//    }
//
//    int main()
//    {
//        test();
//        cout << "Passed all tests" << endl;
//    }

//#include "Sequence.h"  // class template from problem 2
//
//    class Coord
//    {
//      public:
//        Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
//        Coord() : m_r(0), m_c(0) {}
//        double r() const { return m_r; }
//        double c() const { return m_c; }
//      private:
//        double m_r;
//        double m_c;
//    };
//
//    int main()
//    {
//        Sequence<int> si;
//        si.insert(50);               // OK
//        Sequence<Coord> sc;
//        sc.insert(0, Coord(50,20));  // OK
//        sc.insert(Coord(40,10));     // error!
//    }
