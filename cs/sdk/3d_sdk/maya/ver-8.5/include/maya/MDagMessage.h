#ifndef _MDagMessage
#define _MDagMessage
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MDagMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDagMessage)
//
// This class is used to register callbacks for Dag messages.
// There are 4 add callback methods which will add callbacks for the
// following messages
//     Time change
//     Node Added
//     Node Removed
//     Connection made or broken
//
// A filter can be specified for node added/removed messages. The default 
// node type is "dependNode" which matches all nodes.
// Each method returns an id which is used to remove the callback.
//
// To remove a callback use MMessage::removeCallback.
// All callbacks that are registered by a plug-in must be removed by that
// plug-in when it is unloaded. Failure to do so will result in a fatal error.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MMessage.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MDagMessage)

class MDagPath;

/// Dependency graph messages. (OpenMaya) (OpenMaya.py)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDagMessage : public MMessage
{ 
public:
	/// The type of DAG changed messages that have occurred
	enum DagMessage {
		/// an invalid message was used. 
		kInvalidMsg = -1,
		/// a dummy enum used for looping through the message types
		kParentAdded,
		///	a parent was removed from a DAG node
		kParentRemoved,
		///	a child was added to a DAG node
		kChildAdded,
		///	a child was removed from a DAG node
		kChildRemoved,
		///	a child of a DAG node was reordered
		kChildReordered,
		///	a DAG node was instanced
		kInstanceAdded,
		///	a DAG node instance was removed
		kInstanceRemoved,
		///	last value of the enum
		kLast
	};
	
public:
	
	// Function pointer typedef
	typedef void (*MMessageParentChildFunction)( MDagMessage::DagMessage msgType,MDagPath &child, MDagPath &parent, void * clientData );

	
	// Parent added callback for all nodes
	///
	static MCallbackId	addParentAddedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	
	// Parent added callback for a specified node
	///
	static MCallbackId	addParentAddedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	
	// Parent removed callback for all nodes
	///
	static MCallbackId  addParentRemovedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Parent removed callback for a specified node
	///
	static MCallbackId  addParentRemovedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	
	// Child added callback for all nodes
	///
	static MCallbackId	addChildAddedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Child added callback for a specified node
	///
	static MCallbackId	addChildAddedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Child removed callback for all nodes
	///
	static MCallbackId	addChildRemovedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Child removed callback for a specified node
	///
	static MCallbackId	addChildRemovedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Child reordered callback for all nodes
	///
	static MCallbackId	addChildReorderedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	// Child reordered callback for a specified node
	///
	static MCallbackId	addChildReorderedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	


	//	Any DAG change callback with the DagMessage for all nodes
	///
	static MCallbackId	addDagCallback(
								DagMessage msgType,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	//	Any Dag change callback with the DagMessage for a specified node
	///
	static MCallbackId	addDagDagPathCallback(
								MDagPath &dagPath,
								DagMessage msgType,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	//	Adds a Dag change callback for all known Dag change messages for
	//	all nodes.
	///
	static MCallbackId	addAllDagChangesCallback(
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	//	Adds a Dag change callback for all known Dag change messages for
	//	the specified node.
	///
	static MCallbackId	addAllDagChangesDagPathCallback(
								MDagPath &dagPath,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	
	
	//	Adds a Dag change callback for the instancing of
	//	all the nodes in the DAG
	///
	static MCallbackId	addInstanceAddedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );


	//	Adds a Dag change callback for the instancing of
	//	the specified node.
	///
	static MCallbackId	addInstanceAddedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	//	Adds a Dag change callback for the instance removed/deleted of
	//	all the nodes in the DAG
	///
	static MCallbackId	addInstanceRemovedCallback(
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	
	//	Adds a Dag change callback for the instance removed of
	//	the specified node.
	///
	static MCallbackId	addInstanceRemovedDagPathCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	
	
BEGIN_NO_SCRIPT_SUPPORT:

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addParentAddedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId  addParentRemovedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addChildAddedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addChildRemovedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addChildReorderedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addInstanceAddedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addInstanceRemovedCallback(
								MDagPath &dagPath,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addDagCallback(
								DagMessage msgType,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addDagCallback(
								MDagPath &dagPath,
								DagMessage msgType,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addDagCallback(
								MDagPath &dagPath,
								DagMessage msgType,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	/// OBSOLETE and NO SCRIPT SUPPORT
	static MCallbackId	addAllDagChangesCallback(
								MDagPath &dagPath,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

END_NO_SCRIPT_SUPPORT:

private: 
	static MCallbackId	addDagCallback(
								MDagPath *dagPath,
								DagMessage msgType,
								MMessage::MParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );


	static MCallbackId	addDagCallback(
								MDagPath *dagPath,
								DagMessage msgType,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	static MCallbackId	addAllDagChangesCallback(
								MDagPath *dagPath,
								MDagMessage::MMessageParentChildFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	static const char* className();			 
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MDagMessage */
