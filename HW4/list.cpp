//
//  list.cpp
//  HW4
//
//  Created by William  Escobar on 5/26/23.


//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class MenuItem
//{
//  public:
//    MenuItem(string nm) : m_name(nm) {}
//    virtual ~MenuItem() {}
//    string name() const { return m_name; }
//    virtual bool add(MenuItem* m) = 0;
//    virtual const vector<MenuItem*>* menuItems() const = 0;
//  private:
//    string m_name;
//};
//
//class PlainMenuItem : public MenuItem   // PlainMenuItem allows no submenus
//{
//  public:
//    PlainMenuItem(string nm) : MenuItem(nm) {}
//    virtual bool add(MenuItem* m) { return false; }
//    virtual const vector<MenuItem*>* menuItems() const { return nullptr; }
//};
//
//class CompoundMenuItem : public MenuItem  // CompoundMenuItem allows submenus
//{
//  public:
//    CompoundMenuItem(string nm) : MenuItem(nm) {}
//    virtual ~CompoundMenuItem();
//    virtual bool add(MenuItem* m) { m_menuItems.push_back(m); return true; }
//    virtual const vector<MenuItem*>* menuItems() const { return &m_menuItems; }
//  private:
//    vector<MenuItem*> m_menuItems;
//};
//
//CompoundMenuItem::~CompoundMenuItem()
//{
//    for (int k = 0; k < m_menuItems.size(); k++)
//        delete m_menuItems[k];
//}

void listAll(const MenuItem* m, string path) // two-parameter overload
{
    //what are the base cases?
    //path = "" (i.e empty) or path has some value
    //m won't equal nullptr since the one parameter listAll() checks for that
    //m could be a pointer to a PlainMeneuItem
    //m could be a pointer to a CompoundMeneuItem
    
    if(path != "" && m->menuItems() == nullptr)//i.e. no submeneus
    {
        std::cout << path + "/" + m->name() << std::endl;
        return;
    }
    if(path != "" && m->menuItems() != nullptr)//i.e with submeneus
    {
        for(int i=0; i<m->menuItems()->size(); i++)
        {
            std::cout << path + "/" + m->name() << std::endl;
            listAll( (*m->menuItems())[i], path + "/" + m->name());
        }
        return;
    }
    
    //now we need to consider when the path name is empty
    if(m->menuItems() != nullptr)
    {
        if(m->name() != "")
            std::cout << m->name() << std::endl;
        
        for(int i=0; i<m->menuItems()->size(); i++)
        {
            listAll( (*m->menuItems())[i], m->name());
        }
        return;
    }
    else
        std::cout << m->name() << std::endl;
        return;
}

//void listAll(const MenuItem* m)  // one-parameter overload
//{
//    if (m != nullptr)//handels the case that we send the function an address to nullptr
//        listAll(m, "");
//}
//
//int main()
//{
//    CompoundMenuItem* cm0 = new CompoundMenuItem("New");
//    cm0->add(new PlainMenuItem("Window"));
//    CompoundMenuItem* cm1 = new CompoundMenuItem("File");
//    cm1->add(cm0);
//    cm1->add(new PlainMenuItem("Open"));
//    cm1->add(new PlainMenuItem("Exit"));
//    CompoundMenuItem* cm2 = new CompoundMenuItem("Help");
//    cm2->add(new PlainMenuItem("Index"));
//    cm2->add(new PlainMenuItem("About"));
//    CompoundMenuItem* cm3 = new CompoundMenuItem("");  // main menu bar
//    cm3->add(cm1);
//    cm3->add(new PlainMenuItem("Refresh"));  // no submenu
//    cm3->add(new CompoundMenuItem("Under Development")); // no submenus yet
//    cm3->add(cm2);
//    listAll(cm3);
//    delete cm3;
//}


