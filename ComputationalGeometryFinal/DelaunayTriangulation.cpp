//
//  DelaunayTriangulation.cpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 19/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//

#include "DelaunayTriangulation.hpp"
bool DelaunayTriangulation::checkConvexity(vector<Vertex> a,vector<Vertex> b)
{
    vector<Point> combined;
    
    for(int i=0;i<a.size();i++)
    {
        bool flag=true;
        for(int j=0;j<combined.size() && flag;j++)
            if(a[i].coord.equals(combined[j]))
                flag=false;
        if(flag)
            combined.push_back(a[i].coord);
        
    }
    
    for(int i=0;i<b.size();i++)
    {
        bool flag=true;
        for(int j=0;j<combined.size() && flag;j++)
            if(b[i].coord.equals(combined[j]))
                flag=false;
        if(flag)
            combined.push_back(b[i].coord);
    }
    Data tempOb(combined);
    ConvexHull c(tempOb);
   // cout<<"Stuck here?"<<endl;
    return (c.grahamScan().getSize()==4);
}
bool DelaunayTriangulation::checkSemicircle(vector<Vertex> a,vector<Vertex> b)
{
    Point center;
double D=2*( a[0].coord.y * a[2].coord.x + a[1].coord.y * a[0].coord.x - a[1].coord.y * a[2].coord.x -a[0].coord.y * a[1].coord.x - a[2].coord.y * a[0].coord.x + a[2].coord.y * a[1].coord.x );
    center.x=(  a[1].coord.y * a[0].coord.x *a[0].coord.x
              - a[2].coord.y * a[0].coord.x * a[0].coord.x
              - a[1].coord.y * a[1].coord.y * a[0].coord.y
              + a[2].coord.y * a[2].coord.y * a[0].coord.y
              + a[1].coord.x * a[1].coord.x * a[2].coord.y
              + a[0].coord.y * a[0].coord.y * a[1].coord.y
              + a[2].coord.x * a[2].coord.x * a[0].coord.y
              - a[2].coord.y * a[2].coord.y * a[1].coord.y
              - a[2].coord.x * a[2].coord.x * a[1].coord.y
              - a[1].coord.x * a[1].coord.x * a[0].coord.y
              + a[1].coord.y * a[1].coord.y * a[2].coord.y
              - a[0].coord.y * a[0].coord.y * a[2].coord.y ) / D;
    center.y= (  a[0].coord.x * a[0].coord.x * a[2].coord.x
               + a[0].coord.y * a[0].coord.y * a[2].coord.x
               + a[1].coord.x * a[1].coord.x * a[0].coord.x
               - a[1].coord.x * a[1].coord.x * a[2].coord.x
               + a[1].coord.y * a[1].coord.y * a[0].coord.x
               - a[1].coord.y * a[1].coord.y * a[2].coord.x
               - a[0].coord.x * a[0].coord.x * a[1].coord.x
               - a[0].coord.y * a[0].coord.y * a[1].coord.x
               - a[2].coord.x * a[2].coord.x * a[0].coord.x
               + a[2].coord.x * a[2].coord.x * a[1].coord.x
               - a[2].coord.y * a[2].coord.y * a[0].coord.x
               + a[2].coord.y * a[2].coord.y * a[1].coord.x) / D;
    double R=((a[0].coord.x - center.x)*(a[0].coord.x - center.x) + (a[0].coord.y - center.y)*(a[0].coord.y - center.y));
    
    
    for(int i=0;i<b.size();i++)
    {
        bool flag=true;
        for(int j=0;j<a.size();j++)
            flag=flag && !(b[i].coord.equals(a[j].coord));
        if(flag && center.distance(b[i].coord)<sqrt(R))
        {
            
            return true;
        }
    }
    D=2*( b[0].coord.y * b[2].coord.x + b[1].coord.y * b[0].coord.x - b[1].coord.y * b[2].coord.x -b[0].coord.y * b[1].coord.x - b[2].coord.y * b[0].coord.x + b[2].coord.y * b[1].coord.x );
    center.x=(  b[1].coord.y * b[0].coord.x * b[0].coord.x
              - b[2].coord.y * b[0].coord.x * b[0].coord.x
              - b[1].coord.y * b[1].coord.y * b[0].coord.y
              + b[2].coord.y * b[2].coord.y * b[0].coord.y
              + b[1].coord.x * b[1].coord.x * b[2].coord.y
              + b[0].coord.y * b[0].coord.y * b[1].coord.y
              + b[2].coord.x * b[2].coord.x * b[0].coord.y
              - b[2].coord.y * b[2].coord.y * b[1].coord.y
              - b[2].coord.x * b[2].coord.x * b[1].coord.y
              - b[1].coord.x * b[1].coord.x * b[0].coord.y
              + b[1].coord.y * b[1].coord.y * b[2].coord.y
              - b[0].coord.y * b[0].coord.y * b[2].coord.y ) / D;
    center.y= (  b[0].coord.x * b[0].coord.x * b[2].coord.x
               + b[0].coord.y * b[0].coord.y * b[2].coord.x
               + b[1].coord.x * b[1].coord.x * b[0].coord.x
               - b[1].coord.x * b[1].coord.x * b[2].coord.x
               + b[1].coord.y * b[1].coord.y * b[0].coord.x
               - b[1].coord.y * b[1].coord.y * b[2].coord.x
               - b[0].coord.x * b[0].coord.x * b[1].coord.x
               - b[0].coord.y * b[0].coord.y * b[1].coord.x
               - b[2].coord.x * b[2].coord.x * b[0].coord.x
               + b[2].coord.x * b[2].coord.x * b[1].coord.x
               - b[2].coord.y * b[2].coord.y * b[0].coord.x
               + b[2].coord.y * b[2].coord.y * b[1].coord.x) / D;
    R=(b[0].coord.x - center.x)*(b[0].coord.x - center.x) + (b[0].coord.y - center.y)*(b[0].coord.y - center.y);
    for(int i=0;i<a.size();i++)
    {
        bool flag=true;
        for(int j=0;j<b.size();j++)
        {
            flag=flag && !(a[i].coord.equals(b[j].coord));
        }
        if(flag && center.distance(a[i].coord)<sqrt(R))
        {
            return true;
        }
    }
    return false;
}
Edge DelaunayTriangulation::getEdgeToFlip(DCEL &X)
{
    for(unordered_map<int, Edge>::iterator it=X.EdgeRecord.begin();it!=X.EdgeRecord.end();it++)
    {
       // cout<<"Iterating on --> "<<it->second.myaddr<<endl;
        if(it->second.p_incident->myaddr==1 || it->second.p_twin->p_incident->myaddr==1)
            continue;
        vector<Vertex> listOfPoints_l=X.generateFaceVertices(*(it->second.p_incident));
        vector<Vertex> listOfPoints_r=X.generateFaceVertices(*(it->second.p_twin->p_incident));
        if(checkConvexity(listOfPoints_l,listOfPoints_r) && checkSemicircle(listOfPoints_l,listOfPoints_r))
            return (it->second);
        
    }
    Edge t;
    //cout<<t.myaddr<<endl;
    return t;
}
void DelaunayTriangulation::performLawson(DCEL &X)
{
    Edge flip=getEdgeToFlip(X);
    while(flip.myaddr!=-1)
    {
       // cout<<(flip.p_start->coord.x)<<" "<<(flip.p_twin->p_start->coord.x)<<endl;
        X.flipEdge(flip);
        flip=getEdgeToFlip(X);
       // cout<<flip.myaddr<<endl;
    }
}
void DelaunayTriangulation::Delaunayrefine(DCEL &X,double alpha)
{
    double xmax=std::numeric_limits<double>::min();
    double xmin=std::numeric_limits<double>::max();
    double ymax=std::numeric_limits<double>::min();
    double ymin=std::numeric_limits<double>::max();
    for(unordered_map<int, Vertex>::iterator it=X.VertexRecord.begin();it!=X.VertexRecord.end();it++)
    {
        xmax=max(xmax,it->second.coord.x);
        xmin=min(xmin,it->second.coord.x);
        ymax=max(ymax, it->second.coord.y);
        ymin=min(ymin,it->second.coord.y);
    }
    double span=max(xmax-xmin,ymax-ymin);
    
}
