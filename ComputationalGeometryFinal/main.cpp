//
//  main.cpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 18/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//

#include "DCEL.hpp"
#include "primitives.hpp"
#include "Vertex.hpp"
#include "Face.hpp"
#include "Edge.hpp"
#include "Data.hpp"
#include "Triangulation.hpp"
#include "ConvexHull.hpp"
#include "DelaunayTriangulation.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    Data x;
    x.getInput();
   // ConvexHull CH(x);
   // CH.grahamScan().display();
    
    DCEL Y(x);
    Y.output();
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    
    //Y.display();
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    Triangulation t;
    t.performTriangulation(Y);
    //Y.display();
    Y.output();
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    DelaunayTriangulation dt;
    cout<<"Starting the thing now\n"<<endl;
    dt.performLawson(Y);
    Y.output();
    /*Edge e=Y.EdgeRecord[0];
    Point p;
    p.x=(e.p_start->coord.x+e.p_twin->p_start->coord.x)/2;
    p.y=(e.p_start->coord.y+e.p_twin->p_start->coord.y)/2;
    Y.addVertex(Y.EdgeRecord[0],p);
    Y.output();
     */
    
}
