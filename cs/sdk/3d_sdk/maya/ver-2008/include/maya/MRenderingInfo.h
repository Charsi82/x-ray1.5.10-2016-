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
// CLASS:    MRenderingInfo
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRenderingInfo)
//
// MRenderingInfo is a class which holds information about rendering into
// hardware render targets.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#ifndef _MRenderingInfo
#define _MRenderingInfo

#include <maya/MTypes.h>
#include <maya/MDagPath.h>
#include <maya/MViewportRenderer.h>
#include <maya/MRenderTarget.h>
#include <maya/MMatrix.h>

class MHardwareRenderer;
class THviewportRenderer;

// *****************************************************************************

// CLASS DECLARATION (MRenderingInfo)

/// Information to perform rendering into a hardware render target. (OpenMayaRender) (OpenMayaRender.py)
/**
This class contains information about render targets
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32


class OPENMAYARENDER_EXPORT MRenderingInfo
{
public:
	/// Origin (x) of region to render to in pixels
	unsigned int	originX() const;

	/// Origin (y) of region to render to in pixels
	unsigned int	originY() const;

	/// Width of region to render in pixels
	unsigned int	width() const;

	/// Height of region to render in pixels
	unsigned int	height() const;	

	/// Native target rendering API
	MViewportRenderer::RenderingAPI renderingAPI() const;	

	/// Native target rendering version
	float renderingVersion() const;

	/// Current camera being used to render with
    const MDagPath & cameraPath() const;

	/// Current render target
	const MRenderTarget	& renderTarget() const;

	/// Current view matrix
	const MMatrix & viewMatrix() const; 

	/// Current projection matrix
	const MMatrix & projectionMatrix() const;

protected:
	// No protected data

private:
	MRenderingInfo();
	~MRenderingInfo();
	void			set( void * );
	const void *	get() const;

	friend class MViewportRenderer;
	friend class MHardwareRenderer;

	unsigned int	fOriginX;
	unsigned int	fOriginY;
	unsigned int	fWidth;
	unsigned int	fHeight;
	MViewportRenderer::RenderingAPI fRenderingAPI;
	MDagPath		fCameraPath;

	MMatrix			fViewMatrix;
	MMatrix			fProjectionMatrix;

	float			fRenderingVersion;

	MRenderTarget	fRenderTarget;

	const void*	 _info;
};

#endif // _MRenderingInfo
#endif


