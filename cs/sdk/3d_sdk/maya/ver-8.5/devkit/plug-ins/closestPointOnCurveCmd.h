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

// DISCLAIMER: THIS PLUGIN IS PROVIDED AS IS.  IT IS NOT SUPPORTED BY

//            ALIAS, SO PLEASE USE AND MODIFY AT YOUR OWN RISK.

//

// PLUGIN NAME: closestPointOnCurve v1.0

// FILE: closestPointOnCurveCmd.h

// DESCRIPTION: -Class declaration for `closestPointOnCurve` MEL command.

//              -Please see readme.txt for full details.

// AUTHOR: QT

// REFERENCES: -This plugin's concept is based off of the "closestPointOnSurface" node.

//             -The MEL script AEclosestPointOnSurfaceTemplate.mel was referred to for

//              the AE template MEL script that accompanies the closestPointOnCurve node.

// LAST UPDATED: Oct. 13th, 2001.

// COMPILED AND TESTED ON: Maya 4.0 on Windows





// HEADER FILES:

#include <maya/MGlobal.h>

#include <maya/MPxCommand.h>

#include <maya/MArgList.h>

#include <maya/MSyntax.h>

#include <maya/MArgDatabase.h>

#include <maya/MDGModifier.h>

#include <maya/MString.h>

#include <maya/MPlug.h>

#include <maya/MSelectionList.h>

#include <maya/MDoubleArray.h>

#include <maya/MPoint.h>





// MAIN CLASS DECLARATION FOR THE MEL COMMAND:

class closestPointOnCurveCommand : public MPxCommand

{

   public:

      closestPointOnCurveCommand();

      virtual ~closestPointOnCurveCommand();

      static void *creator();

      static MSyntax newSyntax();

      bool isUndoable() const;

      MStatus doIt(const MArgList&);

      MStatus redoIt();

      MStatus undoIt();



   private:

	  bool queryFlagSet, inPositionFlagSet, positionFlagSet, normalFlagSet, tangentFlagSet, paramUFlagSet, distanceFlagSet;

      MString closestPointOnCurveNodeName;

      MPoint inPosition;

      MSelectionList sList;

};

