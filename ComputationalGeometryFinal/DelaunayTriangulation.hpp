//
//  DelaunayTriangulation.hpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 19/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//

#ifndef DelaunayTriangulation_hpp
#define DelaunayTriangulation_hpp

#include "DCEL.hpp"
#include "Triangulation.hpp"
#include "ConvexHull.hpp"
#include "primitives.hpp"
/**
*
*/
class DelaunayTriangulation : Triangulation
{
private:
    /**
    *
    */
    bool checkConvexity(vector<Vertex> a,vector<Vertex> b);
    /**
    *
    */
    bool checkSemicircle(vector<Vertex> a,vector<Vertex> b);
    /**
    *
    */
    Edge getEdgeToFlip(DCEL &X);
public:
    /**
    *
    */
    void performLawson(DCEL &X);
    /**
    *
    */
    void Delaunayrefine(DCEL &X,double);
};

#endif /* DelaunayTriangulation_hpp */
