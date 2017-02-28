#include <cstring>
#include "test_qapx_nodedata.h"
#include "qapx_nodedata.h"

using namespace std;

void TestApxNodeData::test_createNodeData()
{
   const char *apxText =
   "APX/1.2\n"
   "N\"Simulator\"\n"
   "T\"InactiveActive_T\"C(0,3)\n"
   "P\"VehicleSpeed\"S:=65535\n"
   "P\"MainBeam\"C(0,3):=3\n"
   "P\"FuelLevel\"C\n"
   "P\"ParkBrakeFault\"T[0]:=3\n"
   "R\"TurnIndicator_StalkStatus\"C(0,7):=7\n"
   "R\"RheostatLevel\"C:=255\n";

   Apx::NodeData *nodeData = new Apx::NodeData(apxText);

   Apx::File *inputFile = nodeData->getInPortDataFile();
   Apx::File *outputFile = nodeData->getOutPortDataFile();
   Apx::File *definitionFile = nodeData->getDefinitionFile();
   QVERIFY (inputFile != NULL);
   QVERIFY (outputFile != NULL);
   QVERIFY (definitionFile != NULL);
   QCOMPARE(inputFile->mLength, (quint32) 2);
   QCOMPARE(outputFile->mLength, (quint32) 5);
   QCOMPARE(definitionFile->mLength, (quint32) strlen(apxText));

   QByteArray definitionFileContent(definitionFile->mLength,0);
   int result = definitionFile->read((quint8*) definitionFileContent.data(), 0, (quint32) definitionFile->mLength);
   QCOMPARE(result, (int) strlen(apxText));
   QCOMPARE(definitionFileContent, QByteArray(apxText));
   QCOMPARE(nodeData->mInPortDataElements.length(), 2);
   QCOMPARE(nodeData->mOutPortDataElements.length(), 4);

   QCOMPARE(nodeData->mInPortDataMapLen, 2);
   QCOMPARE(nodeData->mOutPortDataMapLen, 5);
   QVERIFY(nodeData->mInPortDataMap[0] == &nodeData->mInPortDataElements[0]);
   QVERIFY(nodeData->mInPortDataMap[1] == &nodeData->mInPortDataElements[1]);
   QVERIFY(nodeData->mOutPortDataMap[0] == &nodeData->mOutPortDataElements[0]);
   QVERIFY(nodeData->mOutPortDataMap[1] == &nodeData->mOutPortDataElements[0]);
   QVERIFY(nodeData->mOutPortDataMap[2] == &nodeData->mOutPortDataElements[1]);
   QVERIFY(nodeData->mOutPortDataMap[3] == &nodeData->mOutPortDataElements[2]);
   QVERIFY(nodeData->mOutPortDataMap[4] == &nodeData->mOutPortDataElements[3]);


   delete nodeData;

}
