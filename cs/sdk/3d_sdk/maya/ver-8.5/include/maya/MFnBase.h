
#ifndef _MFnBase
#define _MFnBase
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
// CLASS:    MFnBase
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnBase)
//
// The API provides access to Maya Objects as generic MObjects.  Under the
// C++ class scheme MObjects simply have type MObject with no base or
// derived hierarchy.  However,  MObjects may be many different types of
// model or scene objects, from Attributes to Xforms, within Maya.  This
// allows many different types of objects to be moved across or accessed
// through the API without undue concern on the part of plug-in developers
// for the type of object being manipulated.
// 
// Since it is impractical to provide every applicable method on MObjects,
// the methods applicable to Maya Objects are encapsulated in Function
// Sets.  Function Sets can be attached to compatible MObjects to provide
// an external interface to methods appropriate to that MObject.
// 
// The link between an MObject and the role it performs as a Maya scene or
// model object, as well as the compatibility between MObjects and
// Function Sets is managed by the API Run-Time Type Identification (RTTI)
// system.  The two key concepts of this system are the Maya Object type
// and the Function Set type (both are MFn::Type).  All MObjects have
// one and only one Maya Object type.  All Function Sets have one and only
// one Function Set type.  MObjects may, however, be compatible with many
// types of Function Sets.  This compatibility follows the class hierarchy
// of the Function Sets.  Thus an MObject with Maya Object type
// MFn::kNurbsSurface would be compatible with MFnNurbsSurface,
// MFnDagNode, MFnDependencyNode, MFnNamedObject and MFnBase.
// 
// Any MObject can be queried with the MObject::hasFn() method to
// determine if it is comaptible with a given Function Set.
// 
// The purpose of the Base Function Set (MFnBase) is to provide methods
// for determining whether or not a Function Set is compatible with a
// given Maya Object (MObject) type (MFn::Type) or a specific MObject.  See:
// 				MFnBase::hasObj(MFn::Type)
// 						and
// 				MFnBase::hasObj(const MObject &)
// 
// As well, this Function Set provides virtual methods for determining the
// type of a Function Set under the API RTTI system. 
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MFn.h>
#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MObject;
class MPtrBase;

// *****************************************************************************

// CLASS DECLARATION (MFnBase)

///  Function Set Base Class. (OpenMaya) (OpenMaya.py)
/**

Defines the interface for the API RTTI and Maya Object attachment methods
common to all Function Set Classes.

Implements the Function Set compatibility test methods for all Function Sets.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnBase  
{
public:
    ///
 	virtual				~MFnBase();
    ///
	virtual MFn::Type	type() const;
    ///
	bool				hasObj( MFn::Type ) const;
    ///
	bool				hasObj( const MObject & ) const;
	///
	MObject				object( MStatus* ReturnStatus = NULL ) const;
    ///
 	virtual MStatus		setObject( MObject & object );

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
 	virtual MStatus		setObject( const MObject & object );
 
END_NO_SCRIPT_SUPPORT:

protected:
	MFnBase(); 
	virtual const char*	className() const;
	void				setPtr( MPtrBase* );
	void				setPtr( const MPtrBase* );
	void				setPtrNull();
	virtual bool		objectChanged( MFn::Type, MStatus * );
 	MPtrBase* 			f_ptr;	    // initialized/set with volatile
 	const MPtrBase*		f_constptr;	// initialized/set with volatile/const

	// Specific for function sets which use internally reference counted objects!
	// Only those function sets which use these objects need to set this to true.
	// By default it is set to false.
	//
	// Classes which do not use internally reference counted objects must not
	// tamper with this boolean value. Doing so can cause crashes when dealing with
	// manually deleted objects.
	//
	bool				fIsReferenceCounted;
private:
#ifndef _WIN32
	MFnBase & operator=( const MFnBase & ) const;
#endif
	MFnBase & operator=( const MFnBase & );
	MFnBase * operator& () const;
	MFnBase * operator& ();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#define declareMinimalMFn( MFnClass )							 	\
	public:														 	\
		virtual MFn::Type type() const;							 	\
		virtual ~MFnClass();									 	\
																 	\
	protected:													 	\
		virtual const char* className() const;					 	\
																 	\
	private:													 	\
		MFnClass & operator=( const MFnClass & ) const;			 	\
		MFnClass & operator=( const MFnClass & );				 	\
		MFnClass * operator& () const;							 	\
		MFnClass * operator& ()

#define declareMinimalMFnDisallowCopyConstructor( MFnClass )		\
	declareMinimalMFn( MFnClass );								 	\
	private:														\
		MFnClass( const MFnClass &rhs )

#define declareMFn( MFnClass, MFnParentClass )					 	\
	declareMinimalMFn( MFnClass );								 	\
	public:	        											 	\
		MFnClass() {};											 	\
		MFnClass( MObject & object, MStatus * ReturnStatus = NULL );
		
#define declareMFnConstConstructor( MFnClass, MFnParentClass ) 		\
		MFnClass( const MObject & object, MStatus * ReturnStatus = NULL )

// Standard MFn class interface *without* the class constructor. This
// is to allow derived MFn classes to optionally specify their own
// custom constructor. For example if they wanted to declare that they
// use internally reference counted objects, they could set fIsReferenceCounted
// to true inside their own custom constructor.
//
#define declareMFnNoVoidConstructor( MFnClass, MFnParentClass )			\
	declareMinimalMFn( MFnClass );									\
	public:															\
		MFnClass( MObject & object, MStatus * ReturnStatus = NULL );\

#define declareMFnNoVoidConstructorConstConstructor( MFnClass, MFnParentClass )			\
		MFnClass( const MObject & object, MStatus * ReturnStatus = NULL )


#endif /* __cplusplus */
#endif /* _MFnBase */
