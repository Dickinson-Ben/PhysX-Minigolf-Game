#pragma once

#include "BasicActors.h"
#include <iostream>
#include <iomanip>

namespace PhysicsEngine
{
	using namespace std;

	//a list of colours: Circus Palette
	static const PxVec3 color_palette[] = {PxVec3(46.f/255.f,9.f/255.f,39.f/255.f),PxVec3(217.f/255.f,0.f/255.f,0.f/255.f),
		PxVec3(255.f/255.f,45.f/255.f,0.f/255.f),PxVec3(255.f/255.f,140.f/255.f,54.f/255.f),PxVec3(4.f/255.f,117.f/255.f,111.f/255.f)};

	//pyramid vertices
	static PxVec3 pyramid_verts[] = {PxVec3(0,1,0), PxVec3(1,0,0), PxVec3(-1,0,0), PxVec3(0,0,1), PxVec3(0,0,-1)};
	//pyramid triangles: a list of three vertices for each triangle e.g. the first triangle consists of vertices 1, 4 and 0
	//vertices have to be specified in a counter-clockwise order to assure the correct shading in rendering
	static PxU32 pyramid_trigs[] = {1, 4, 0, 3, 1, 0, 2, 3, 0, 4, 2, 0, 3, 2, 1, 2, 4, 1};

	class Pyramid : public ConvexMesh
	{
	public:
		Pyramid(PxTransform pose=PxTransform(PxIdentity), PxReal density=1.f) :
			ConvexMesh(vector<PxVec3>(begin(pyramid_verts),end(pyramid_verts)), pose, density)
		{
		}
	};

	class PyramidStatic : public TriangleMesh
	{
	public:
		PyramidStatic(PxTransform pose=PxTransform(PxIdentity)) :
			TriangleMesh(vector<PxVec3>(begin(pyramid_verts),end(pyramid_verts)), vector<PxU32>(begin(pyramid_trigs),end(pyramid_trigs)), pose)
		{
		}
	};

	///Custom scene class
	class MyScene : public Scene
	{
		//define the objects to render in the scene
		Plane* plane;
		Box* box;
		CompoundObject* cObject;
		Sphere* golfBall;
		courseObject* cBoundary;
		courseObject2* cBoundary2;
		archObject* aObject;



	public:
		///A custom scene class
		void SetVisualisation()
		{
			px_scene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
			px_scene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
		}

		//Custom scene initialisation
		virtual void CustomInit()
		{
			SetVisualisation();

			GetMaterial()->setDynamicFriction(.2f);

			plane = new Plane();
			plane->Color(PxVec3(210.f / 255.f, 210.f / 255.f, 210.f / 255.f));
			Add(plane);

			//objects go here

			////Adds box object to the scene
			//box = new Box(PxTransform(PxVec3(.0f, 10.f, .0f)));
			//box->Color(color_palette[0]);
			//Add(box);

			//add the tutorial compound object
			
			//Club
			cObject = new CompoundObject(PxTransform(PxVec3(.0f, 0.f, 2.0f))); //don't forget to delete this later
			//the 3 floats here dictate the starting position of the object
			cObject->Color(color_palette[0]);
			Add(cObject);


			//Ball
			golfBall = new Sphere(PxTransform(PxVec3(0.0f, 0.0f, 1.0f)));
			golfBall->Color(color_palette[0]);
			Add(golfBall);


			//Basic 3 piece arch 
			aObject = new archObject (PxTransform(PxVec3(-0.5f, 0.0f, -9.0f)));
			aObject->Color(color_palette[5]);
			Add(aObject);





			//basic L shape course, one 45 degree angle brace at corner. Course comprised of indivcidual objects
			//Course objects go here: Boundaries

			cBoundary = new courseObject(PxTransform(PxVec3(-4.0f, 0.0f, -6.0f)));
			cBoundary->Color(color_palette[1]);
			Add(cBoundary);

			cBoundary = new courseObject(PxTransform(PxVec3(3.0f, 0.0f, -6.0f)));

			cBoundary->Color(color_palette[1]);
			Add(cBoundary);			

			

			cBoundary2 = new courseObject2(PxTransform(PxVec3(-5.0f, 0.0f, -25.0f)));
			cBoundary2->Color(color_palette[1]);
			Add(cBoundary2);

			cBoundary2 = new courseObject2(PxTransform(PxVec3(-13.0f, 0.0f, -16.5f)));
			cBoundary2->Color(color_palette[1]);
			Add(cBoundary2);

		}


		//Custom udpate function
		virtual void CustomUpdate() 
		{
			//constant application of forces goes here maybe.
		}


		
		
	};
	
	

}
