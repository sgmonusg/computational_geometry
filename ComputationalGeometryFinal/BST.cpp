//
//  BST.cpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 19/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//

#include "BST.hpp"
void BST::insert(Edge e,Vertex v)
{
    comp.compareAt=v.coord.y;
    S.push_back(e);
}
void BST::setHelper(Edge e,Vertex v)
{
    helper[e.myaddr]=v;
}
void BST::remove(Edge e)
{
    comp.compareAt=e.p_twin->p_start->coord.y;
    for(std::vector<Edge>::iterator it=S.begin();it!=S.end();it++)
        if(*it==e)
        {
            S.erase(it);
            break;
            
        }
    //S.erase(S.find(e));
}
Edge BST::find(Vertex v)
{
    std::cout<<"Reached hurray\n"<<std::endl;
    comp.compareAt=v.coord.y;
    Edge e;
    Edge etwin;
    etwin.p_start=&v;
    e.p_twin=&etwin;
    e.p_start=&v;
    /*set<Edge,edge_compare>::iterator it=S.lower_bound(e);
     //comp.getPriority(e);
     cout<<"HELPER RETURNED FOR "<<v.myaddr<<"is-->";
     cout<<it->myaddr<<endl;
     if(it==S.end())
     return *(S.rbegin());
     else
     {
     it--;
     return *it;
     }
     */
    std::vector<Edge>::iterator i=S.end();
    for(std::vector<Edge>::iterator it=S.begin();it!=S.end();it++)
    {
        std::cout<<it->myaddr<<"<=====present in list now\n";
        if(comp.getPriority(*it)<comp.getPriority(e))
        {
            if(i==S.end())
                i=it;
            if(comp.getPriority(*i)<comp.getPriority(*it))
                i=it;
            std::cout<<"works on "<<it->myaddr<<std::endl;
            std::cout<<"currently holding"<<i->myaddr<<std::endl;
        }
    }
    std::cout<<"Just bwfore\n";
    std::cout<<i->myaddr<<std::endl;
    if(i==S.end())
    {
        return *(S.rbegin());
    }
    else
    {
        
        return *i;
    }
}
