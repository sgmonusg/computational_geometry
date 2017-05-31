//
//  DCEL.hpp
//  ComputationalGeometryFinal
//
//  Created by Shikhar  on 19/04/17.
//  Copyright © 2017 Shikhar . All rights reserved.
//

#ifndef DCEL_hpp
#define DCEL_hpp

#include "Face.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"

#include "Data.hpp"
#include <unordered_map>
class DCEL
/**
* class DCEL
* aim: To construct a DCEL for Triangulation
*/
{
public:
    unordered_map<int,Vertex> VertexRecord;
    /**<
    * unordered map for the list of vertices
    * VertexRecord
    */
    unordered_map<int,Edge> EdgeRecord;
    /**<
    * unordered map for the list of edges
    * Name : EdgeRecord
    */
    unordered_map<int,Face> FaceRecord;
    /**<
    * unordered map for the list of faces
    * Name : FaceRecord
    */
public:

    DCEL(Data ob);
    /**
    * Constructor for intializing DCEL
    * params : Data object
    */
    void addEdge(Vertex start,Vertex end);
    /**
    * Method Name : addEgde
    * params : start vertex
    * params : end vertex
    * aim : add egde in the DCEL
    */
    void addVertex(Edge &e_l,Point p); ///implemented test this
    /**
    * Mathod Name : addVertex
    * Parmas : edge pointer e_1
    * params : point p
    * aim : to add a new vertex to DCEL
    */
    vector<Edge> walkAround(Face f);
    /**
    * Method Name : walkaround
    * params : Face f
    * aim : to return the edges of the given face by walking around them
    */
    vector<Face> incidentFaces(Vertex v);
    /**
    * Method name : incidentFaces
    * params : Vertex V
    * aim : to return the list of incident faces on a given vertex
    */
    vector<Vertex> generateFaceVertices(Face f);
    /**
    * Method Name: generateFaceVertices
    * params : Face f
    * aim : to list all the vertices of a face
    */
    void flipEdge(Edge &e);
    /**
    * Method Name : flipEdge
    * params : edge e
    * aim :
    */
    void display();
    /**
    * Method Name : display
    * aim :
    */
    void output();
    /**
    * Method Name: output
    * aim :
    */
};
#endif /* DCEL_hpp */
