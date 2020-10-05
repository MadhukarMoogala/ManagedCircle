// (C) Copyright 2020 by Autodesk, Inc. 
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
#include "dbobjptr2.h"
#include "../dbxCircle/asdkCustomCircle.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("asdk")

//-----------------------------------------------------------------------------

Acad::ErrorStatus postToDatabase (AcDbEntity *pEnt, AcDbObjectId &idObj) 
{
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

	AcDbBlockTablePointer blkTable(pDb, AcDb::kForRead);

	if(blkTable.openStatus() != Acad::eOk)
		return blkTable.openStatus();

	AcDbBlockTableRecordPointer btr(ACDB_MODEL_SPACE, pDb, AcDb::kForWrite);

	if(btr.openStatus() != Acad::eOk)
		return btr.openStatus();

	return btr->appendAcDbEntity(idObj, pEnt);
}

//----- ObjectARX EntryPoint
class CArxProject1App : public AcRxArxApp {

public:
	CArxProject1App () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) 
	{	
		// TODO: Load dependencies here
		if (!acrxLoadModule(_T("dbxCircle.dbx"), 0))
			return AcRx::kRetError;

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) 
	{
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode);
	}

	virtual void RegisterServerComponents () 
	{

	}


	// - asdkArxProject1._MyCommand1 command (do not rename)
	static void asdkArxProject1_MyCommand1(void)
	{
		// Add your code for command asdkArxProject1._MyCommand1 here
		Acad::ErrorStatus es;

		AcDbObjectId id;
		ads_name name;
		ads_point pt;

		if(acedEntSel(L"\nSelect Entity: ", name, pt) != RTNORM)
		{	
			return;
		}
			
		acdbGetObjectId(id, name); 
		AcDbObjectPointer <AcDbEntity> pEntity(id, AcDb::kForRead);

		if(pEntity.openStatus() != Acad::eOk)
		{
			return;
		}

		const ACHAR* type = pEntity->isA()->name();
		acutPrintf(L"\nYou selected a %s", type);

		acutPrintf(L"\nPick Point: [%.2f, %.2f, %.2f]", pt[0], pt[1], pt[2]);
	}

	// - asdkArxProject1._AddLine command (do not rename)
	static void asdkArxProject1_AddLine(void)
	{
		// Add your code for command asdkArxProject1._AddLine here
		AcDbSmartObjectPointer<AcDbLine> pLine;
		
		if(pLine.create() != Acad::eOk)
			return;

		pLine->setStartPoint(AcGePoint3d(0,0,0));
		pLine->setEndPoint(AcGePoint3d(10,10,0));

		AcDbObjectId id;
		if(postToDatabase(pLine.object(), id) != Acad::eOk)
		{
			return;
		}

		acutPrintf(L"\nAdd Line succeeded!!");
	}

	// - asdkArxProject1._AddCustCircle command (do not rename)
	static void asdkArxProject1_AddCustCircle(void)
	{
		// Add your code for command asdkArxProject1._AddCustCircle here
		AcDbSmartObjectPointer<asdkCustomCircle> pCircle;
		
		if(pCircle.create() != Acad::eOk)
			return;

		pCircle->setRadius(5);
		pCircle->setCenter(AcGePoint3d(0,0,0));
		
		AcDbObjectId id;
		if(postToDatabase(pCircle.object(), id) != Acad::eOk)
		{
			return;
		}

		acutPrintf(L"\nAdd succeeded!!");
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject1App)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, asdkArxProject1, _MyCommand1, MyCommand1, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, asdkArxProject1, _AddLine, AddLine, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, asdkArxProject1, _AddCustCircle, AddCustCircle, ACRX_CMD_TRANSPARENT, NULL)
