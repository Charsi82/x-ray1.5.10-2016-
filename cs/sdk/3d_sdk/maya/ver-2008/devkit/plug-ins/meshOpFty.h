#ifndef _meshOpFty
#define _meshOpFty

//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc. and/or its licensors.  All 
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors, which is protected by U.S. and Canadian federal copyright 
// law and by international treaties.
//
// The Data is provided for use exclusively by You. You have the right 
// to use, modify, and incorporate this Data into other products for 
// purposes authorized by the Autodesk software license agreement, 
// without fee.
//
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the 
// following disclaimer, must be included in all copies of the 
// Software, in whole or in part, and all derivative works of 
// the Software, unless such copies or derivative works are solely 
// in the form of machine-executable object code generated by a 
// source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR 
// PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE, OR 
// TRADE PRACTICE. IN NO EVENT WILL AUTODESK AND/OR ITS LICENSORS 
// BE LIABLE FOR ANY LOST REVENUES, DATA, OR PROFITS, OR SPECIAL, 
// DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK 
// AND/OR ITS LICENSORS HAS BEEN ADVISED OF THE POSSIBILITY 
// OR PROBABILITY OF SUCH DAMAGES.
//
// ==========================================================================
//+

//
// ***************************************************************************
//
// Overview:
//
//		The meshOp factory implements the actual meshOperation operation. 
//		It takes in three parameters:
//
//			1) A polygonal mesh
//			2) An array of component IDs
//          3) A mesh operation identifier
//
// Please refer to MFnMeshOperations to get more information on the different 
// mesh operations.
//

#include "polyModifierFty.h"

// General Includes
//
#include <maya/MObject.h>
#include <maya/MIntArray.h>
#include <maya/MString.h>

class MFnMesh;

enum MeshOperation
{
	kSubdivideEdges = 0,
	kSubdivideFaces = 1,
	kExtrudeEdges = 2,
	kExtrudeFaces = 3,
	kCollapseEdges = 4,
	kCollapseFaces = 5,
	kDuplicateFaces = 6,
	kExtractFaces = 7,
	kSplitLightning = 8,
	
	// Number of valid operations
	kMeshOperationCount = 9
};

class meshOpFty : public polyModifierFty
{

public:
				meshOpFty();
	virtual		~meshOpFty();

	// Modifiers
	//
	void		setMesh( MObject& mesh );
	void		setComponentList( MObject& componentList );
	void		setComponentIDs( MIntArray& componentIDs );
	void		setMeshOperation( MeshOperation operationType );

	// Returns the type of component expected by a given mesh operation
	//
	static MFn::Type getExpectedComponentType( MeshOperation operationType );

	// polyModifierFty inherited methods
	//
	MStatus		doIt();

private:
	// Mesh Node - Note: We only make use of this MObject during a single 
	//					 call of the meshOperation plugin. It is never 
	//					 maintained and used between calls to the plugin as 
	//					 the MObject handle could be invalidated between 
	//                   calls to the plugin.
	//
	MObject		fMesh;

	// Selected Components and Operation to execute
	//
	MIntArray		fComponentIDs;
	MeshOperation	fOperationType;
	MObject			fComponentList;

	MStatus doLightningSplit(MFnMesh& meshFn);
};

#endif
