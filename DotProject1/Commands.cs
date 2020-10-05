// (C) Copyright 2002-2009 by Autodesk, Inc. 
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

using System;
using Autodesk.AutoCAD.Runtime;
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.EditorInput;

using ADN.CustomWrapper;
using Autodesk.AutoCAD.ApplicationServices.Core;

[assembly: CommandClass(typeof(ManagedTest.Commands))]

namespace ManagedTest
{
    public class Commands: IExtensionApplication
    {
        public void Initialize()
        {
            RXClass rxc = asdkCustomCircleMgd.GetClass(typeof(asdkCustomCircleMgd));
            Application.ShowAlertDialog($"Custom Object: \n{rxc.DxfName}");
        }

        public void Terminate()
        {
            
        }

        [CommandMethod("AddObjectMng")]
        static public void AddObjectMng()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptPointOptions ppo = new PromptPointOptions("\nSelect center: ");

            PromptPointResult ppr = ed.GetPoint(ppo);

            if (ppr.Status != PromptStatus.OK)
                return;

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                BlockTable bt = Tx.GetObject(db.BlockTableId, OpenMode.ForRead) 
                    as BlockTable;

                BlockTableRecord model = Tx.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite) 
                    as BlockTableRecord;

                asdkCustomCircleMgd entity = new asdkCustomCircleMgd();

                entity.setCenter(ppr.Value);
                entity.setRadius(3.0);
                entity.gc2AcString("My Test String");
                entity.convertFromMgdObjectId(model.Id);

                model.AppendEntity(entity);
                Tx.AddNewlyCreatedDBObject(entity, true);

                Tx.Commit();
            }
        }

        [CommandMethod("GetObjectMng")]
        static public void GetObjectMng()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptEntityOptions peo = new PromptEntityOptions("\nSelect custom object: ");
            peo.SetRejectMessage("\nInvalid selection...");
            peo.AddAllowedClass(typeof(asdkCustomCircleMgd), true);

            PromptEntityResult per = ed.GetEntity(peo);

            if (per.Status != PromptStatus.OK)
                return;

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                asdkCustomCircleMgd entity = Tx.GetObject(per.ObjectId, OpenMode.ForWrite) 
                    as asdkCustomCircleMgd;

                entity.ColorIndex = 1;

                Tx.Commit();
            }
        }
    }
}
