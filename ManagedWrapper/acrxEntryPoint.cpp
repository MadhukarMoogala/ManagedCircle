// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "asdkCustomCircleMgd.h"
//-----------------------------------------------------------------------------
#define szRDS _RXST("Adsk")

//-----------------------------------------------------------------------------
static AcMgObjectFactoryBase** g_PEs = NULL;

//----- ObjectARX EntryPoint
class CManagedWrapperApp : public AcRxArxApp 
{

public:
	CManagedWrapperApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) 
	{
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxDbxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here
		AcMgObjectFactoryBase* PEs[] = 
		{
			new AcMgObjectFactory<ADN::CustomWrapper::asdkCustomCircleMgd, asdkCustomCircle>(), 
				NULL
		};

		g_PEs = PEs;

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) 
	{
		// TODO: Add your code here
		// clean up
		int i=0;
		while (g_PEs[i] != NULL)
			delete g_PEs[i++];

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxDbxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here
		return (retCode) ;
	}

	virtual void RegisterServerComponents () 
	{

	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CManagedWrapperApp)

