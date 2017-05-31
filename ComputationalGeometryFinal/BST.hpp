//
//  BST.hpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 19/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//


#ifndef BST_hpp
#define BST_hpp

#include "Vertex.hpp"
#include "Edge.hpp"
#include <set>
#include <utility>
#include <unordered_map>

class BST
{
public:
    /**
    * Struct of comparing edges
    * elements : compareAt ,
    * Methods : getPriority(edge)
    */
    struct edge_compare {
        double compareAt;
        double getPriority(const Edge &	e)
        {
            Vertex start=*(e.p_start);
            Vertex end=*(e.p_twin->p_start);
            if(end.coord.y==start.coord.y)
                return start.coord.x;
            double r=(end.coord.y-start.coord.y);
            //cout<<e.myaddr<<"PRiority---> "<<r<<endl;

            return (((compareAt-start.coord.y)*(end.coord.x-start.coord.x))/r)+start.coord.x;

        }
        bool operator() (const Edge &first, const Edge &other) {
            return getPriority(first)<getPriority(other);
        }
    } comp;
    /**
    * a list of edges
    */
    std::vector<Edge> S;
    /**
    *  helper unordered map of vertex interest time O(1)
    */
    //set<Edge, edge_compare> S;
    std::unordered_map<int,Vertex> helper;

public:
    /**
    *   method name : insert
    *   params : edge e
    *   params : vertex v
    *   aim to interest
    */
    void insert(Edge e,Vertex v);
    /**
    *   method name : setHelper
    *   params : edge e
    *   params : vertex v
    *   aim to set helper
    */
    void setHelper(Edge e,Vertex v);
    /**
    *   method name : remove
    *   params : edge e
    *   aim to set helper
    */
    void remove(Edge e);
    /**
    *   method name : find
    *   params : vertex v
    *   aim to set helper
    */
    Edge find(Vertex v);
};
#endif /* BST_hpp */
