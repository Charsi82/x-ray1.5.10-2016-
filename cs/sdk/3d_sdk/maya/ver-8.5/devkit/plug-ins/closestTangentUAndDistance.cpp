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

// DISCLAIMER: THIS PLUGIN IS PROVIDED AS IS.  IT IS NOT SUPPORTED BY

//            AUTODESK, SO PLEASE USE AND MODIFY AT YOUR OWN RISK.

//

// PLUGIN NAME: closestPointOnCurve v1.0

// FILE: closestTangentUAndDistance.cpp

// DESCRIPTION: -Utility function definition, used by both the command and node.

//              -Please see readme.txt for full details.

// AUTHOR: QT

// REFERENCES: -This plugin's concept is based off of the "closestPointOnSurface" node.

//             -The MEL script AEclosestPointOnSurfaceTemplate.mel was referred to for

//              the AE template MEL script that accompanies the closestPointOnCurve node.

// LAST UPDATED: Oct. 13th, 2001.

// COMPILED AND TESTED ON: Maya 4.0 on Windows





// HEADER FILE:

#include "closestTangentUAndDistance.h"





// FUNCTION WHICH TAKES A SPECIFIED INPUT CURVE AND A WORLDSPACE POSITION, AND FINDS THE CLOSEST POSITION, NORMAL, TANGENT, PARAMETER-U AND CLOSEST-DISTANCE FROM THE CURVE:

void closestTangentUAndDistance(MDagPath curveDagPath, MPoint inPosition, MPoint &position, MVector &normal, MVector &tangent, double &paramU, double &distance, MObject theCurve)

{

   // FIND THE CLOSEST POSITION AND PARAMETER-U FROM THE INPUT POSITION:

   MFnNurbsCurve curveFn(curveDagPath);

   if (theCurve!=MObject::kNullObj)

      curveFn.setObject(theCurve);

   position = curveFn.closestPoint(inPosition, &paramU, 0.0, MSpace::kWorld);



   // FIND THE NORMAL, TANGENT AND DISTANCE FROM THE CLOSEST POINT:

   normal = curveFn.normal(paramU, MSpace::kWorld);

   tangent = curveFn.tangent(paramU, MSpace::kWorld);

   distance = curveFn.distanceToPoint(inPosition, MSpace::kWorld);

}

