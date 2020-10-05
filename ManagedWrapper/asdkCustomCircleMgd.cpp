// (C) Copyright 2005-2007 by Autodesk, Inc. 
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
#include "StdAfx.h"
#include "asdkCustomCircleMgd.h"

//-----------------------------------------------------------------------------
//- Template class that wraps GCHandle from mscorlib.dll
#include <gcroot.h>

//-----------------------------------------------------------------------------
//- autodesk interop header, to aid converting between unmanaged ObjectARX and managed ObjectARX.NET
#include "mgdinterop.h"

//-----------------------------------------------------------------------------
ADN::CustomWrapper::asdkCustomCircleMgd::asdkCustomCircleMgd () 
	: Autodesk::AutoCAD::DatabaseServices::Circle ((System::IntPtr)new asdkCustomCircle (), true)
{

}

//-----------------------------------------------------------------------------
ADN::CustomWrapper::asdkCustomCircleMgd::asdkCustomCircleMgd (System::IntPtr unmanagedPointer, bool bAutoDelete)
	: Autodesk::AutoCAD::DatabaseServices::Circle (unmanagedPointer, bAutoDelete)
{
}

void ADN::CustomWrapper::asdkCustomCircleMgd::setCenter(Autodesk::AutoCAD::Geometry::Point3d center)
{
	AcGePoint3d _center = GETPOINT3D(center);

	GetImpObj()->setCenter(_center);
}

void ADN::CustomWrapper::asdkCustomCircleMgd::setRadius(double radius)
{
	wchar_t *pFirst = new wchar_t[50];
	
	wchar_t *pSecond = new wchar_t[50];
	
	GetImpObj()->setRadius(radius);
}

void ADN::CustomWrapper::asdkCustomCircleMgd::gc2AcString(System::String^ s)
{
	/*
	System::IntPtr ip = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s);
	AcString ss = static_cast<const ACHAR*>(ip.ToPointer());
	System::Runtime::InteropServices::Marshal::FreeHGlobal(ip);
	//*/

	System::IntPtr ip = System::Runtime::InteropServices::Marshal::StringToCoTaskMemUni(s);
	AcString ss = static_cast<const ACHAR*>(ip.ToPointer());
	System::Runtime::InteropServices::Marshal::FreeCoTaskMem(ip);

	acutPrintf(ss);
}

void ADN::CustomWrapper::asdkCustomCircleMgd::convertFromMgdObjectId(Autodesk::AutoCAD::DatabaseServices::ObjectId mgdId)
{
	System::String^ hStr = mgdId.Handle.ToString();
	UInt64 hInt = System::Convert::ToInt64(hStr, 16);
	AcDbHandle handle(hInt);

	AcDbObjectId objId;
	Acad::ErrorStatus es = acdbHostApplicationServices()->workingDatabase()->getAcDbObjectId(objId,false,handle);
	if(es == Acad::eOk)
	{
		acutPrintf(ACRX_T("\nObjectClass from Id : %s"), objId.objectClass()->name());
	}
}
