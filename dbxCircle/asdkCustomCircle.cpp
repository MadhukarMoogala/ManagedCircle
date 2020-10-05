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
//----- asdkCustomCircle.cpp : Implementation of asdkCustomCircle
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "asdkCustomCircle.h"

//-----------------------------------------------------------------------------
Adesk::UInt32 asdkCustomCircle::kCurrentVersionNumber =1 ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	asdkCustomCircle, AcDbCircle,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, ASDKCUSTOMCIRCLE,
ASDKDBXCIRCLEAPP
|Product Desc:     A description for your object
|Company:          Your company name
|WEB Address:      Your company WEB site address
)

//-----------------------------------------------------------------------------
asdkCustomCircle::asdkCustomCircle () : AcDbCircle () 
{
	setDatabaseDefaults();

	adjustUCS();
}

asdkCustomCircle::~asdkCustomCircle () 
{

}

void asdkCustomCircle::adjustUCS ()
{
	AcGeMatrix3d ucsToWcsMatrix;

	acdbUcsMatrix(ucsToWcsMatrix);

	AcGePoint3d origin;
    
    ucsToWcsMatrix.getCoordSystem(origin, mxAxis, myAxis, mzAxis);
}

void asdkCustomCircle::setEyesPos ()
{
	mEye[0] = AcGePoint3d(center().x - mxAxis.x * radius()*0.5f + myAxis.x * radius()*0.35f, 
						  center().y - mxAxis.y * radius()*0.5f + myAxis.y * radius()*0.35f,
						  center().z - mxAxis.z * radius()*0.5f + myAxis.z * radius()*0.35f);

	mEye[1] = AcGePoint3d(center().x + mxAxis.x * radius()*0.5f + myAxis.x * radius()*0.35f, 
						  center().y + mxAxis.y * radius()*0.5f + myAxis.y * radius()*0.35f,
						  center().z + mxAxis.z * radius()*0.5f + myAxis.z * radius()*0.35f);
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus asdkCustomCircle::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCircle::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (asdkCustomCircle::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus asdkCustomCircle::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCircle::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =0 ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > asdkCustomCircle::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < asdkCustomCircle::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....

	return (pFiler->filerStatus ()) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean asdkCustomCircle::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;

	AcDbCircle::subWorldDraw (mode);

	mode->geometry().circle(mEye[0], radius()*0.2f, normal());
	mode->geometry().circle(mEye[1], radius()*0.2f, normal());

	return Adesk::kTrue;
}

Adesk::UInt32 asdkCustomCircle::subSetAttributes (AcGiDrawableTraits *traits) {
	assertReadEnabled () ;
	return (AcDbCircle::subSetAttributes (traits)) ;
}

	//- Osnap points protocol
Acad::ErrorStatus asdkCustomCircle::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
	return (AcDbCircle::subGetOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
}

Acad::ErrorStatus asdkCustomCircle::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds,
	const AcGeMatrix3d &insertionMat) const
{
	assertReadEnabled () ;
	return (AcDbCircle::subGetOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat)) ;
}

//- Grip points protocol
Acad::ErrorStatus asdkCustomCircle::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
) const {
	assertReadEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new getGripPoints() method below (which is the default implementation)

	return (AcDbCircle::subGetGripPoints (gripPoints, osnapModes, geomIds)) ;
}

Acad::ErrorStatus asdkCustomCircle::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)

	return (AcDbCircle::subMoveGripPointsAt (indices, offset)) ;
}

Acad::ErrorStatus asdkCustomCircle::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
) const {
	assertReadEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.

	Acad::ErrorStatus es = Acad::eOk;

	//es = AcDbCircle::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags);

	AcDbGripData *pGripData0 = new AcDbGripData();

	GripAppData *appData0 = new GripAppData(0);
	
	pGripData0->setGripPoint(center());
	pGripData0->setAppData(appData0);
    //pGripData0->setHoverDimensionFunc(hoverDimensionCbackFunc);
    //pGripData0->setHotGripDimensionFunc(hotGripDimensionCbackFunc);
	grips.append(pGripData0);



	AcDbGripData *pGripData1 = new AcDbGripData();

	GripAppData *appData1 = new GripAppData(1);
	
	pGripData1->setGripPoint(mEye[0]);
	pGripData1->setAppData(appData1);
    //pGripData1->setHoverDimensionFunc(hoverDimensionCbackFunc);
    //pGripData1->setHotGripDimensionFunc(hotGripDimensionCbackFunc);
	grips.append(pGripData1);



	AcDbGripData *pGripData2 = new AcDbGripData();

	GripAppData *appData2 = new GripAppData(2);
	
	pGripData2->setGripPoint(mEye[1]);
	pGripData2->setAppData(appData2);
    //pGripData2->setHoverDimensionFunc(hoverDimensionCbackFunc);
    //pGripData2->setHotGripDimensionFunc(hotGripDimensionCbackFunc);
	grips.append(pGripData2);

	return es ;
}

Acad::ErrorStatus asdkCustomCircle::subMoveGripPointsAt (
	const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset,
	const int bitflags
) {
	assertWriteEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.

	Acad::ErrorStatus es = Acad::eOk;

	if (!gripAppData.length())
		return Acad::eInvalidInput;

	GripAppData* pGripAppData = (GripAppData*)gripAppData[0];

	switch(pGripAppData->gripId())
	{
		//Center
		case 0:
		{
			AcGeVector3d newCenter = center().asVector() + offset;
			setCenter(AcGePoint3d(newCenter.x, newCenter.y, newCenter.z));
			break;
		}

		//Left & Right Eye
		case 1:
		case 2:
		{
			double dotProd = offset.dotProduct(mxAxis);
			setRadius( radius() - dotProd);
			break;
		}

		default:
			return es;
	}
		
	//es = AcDbCircle::subMoveGripPointsAt (gripAppData, offset, bitflags);

	return es ;
}


// -----------------------------------------------------------------------------
Acad::ErrorStatus asdkCustomCircle::setRadius(double param2)
{
	assertWriteEnabled () ;

	Acad::ErrorStatus retCode = AcDbCircle::setRadius (param2) ;

	setEyesPos();

	return (retCode) ;
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus asdkCustomCircle::setCenter(const AcGePoint3d & param2)
{
	assertWriteEnabled () ;

	Acad::ErrorStatus retCode = AcDbCircle::setCenter (param2) ;

	setEyesPos();

	return (retCode) ;
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus asdkCustomCircle::subTransformBy(const AcGeMatrix3d & xform)
{
	assertWriteEnabled () ;

	if (!xform.isUniScaledOrtho())
        return Acad::eCannotScaleNonUniformly;

	Acad::ErrorStatus retCode = AcDbCircle::subTransformBy (xform) ;

	setEyesPos();

	return (retCode) ;
}

// -----------------------------------------------------------------------------
void asdkCustomCircle::modified(const AcDbObject * dbObj)
{
	AcDbCircle::modified (dbObj) ;
}

// -----------------------------------------------------------------------------
Acad::ErrorStatus asdkCustomCircle::subClose()
{
	Acad::ErrorStatus retCode =AcDbCircle::subClose () ;
	return (retCode) ;
}

// -----------------------------------------------------------------------------
AcRxObject * asdkCustomCircle::clone(void) const
{
	AcRxObject * retCode = AcDbCircle::clone () ;

	asdkCustomCircle* pClone = asdkCustomCircle::cast(retCode);

	pClone->setxAxis(mxAxis);
	pClone->setyAxis(myAxis);

	return (retCode) ;
}
