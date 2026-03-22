// **************************************************************
//
//      ------ CrystalEyeSteppingAction  ------
//           by Aleksei Smirnov (23 Sep 2023)
//           Email: aleksei.smirnov@gssi.it
//
// **************************************************************

#include "CrystalEyeSteppingAction.hh"
#include "CrystalEyeDetectorConstruction.hh"
#include "CrystalEyeEventAction.hh"
#include "CrystalEyeAnalysis.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4GeometryTolerance.hh"
#include "G4TransportationManager.hh"
#include "G4Navigator.hh"
#include <cmath>
#include <set>


using namespace CLHEP;

//------------------------------------------------------------
CrystalEyeSteppingAction::CrystalEyeSteppingAction(CrystalEyeEventAction* evt)
	:G4UserSteppingAction()
{
	eventAct  = evt;

	fevtid = -1;
}
//------------------------------------------------------------
CrystalEyeSteppingAction::~CrystalEyeSteppingAction()
{
}

void CrystalEyeSteppingAction::cartesianToSpherical(double x, double y, double z, double &r, double &phi, double &theta) {
    r = std::sqrt(x * x + y * y + z * z);
    phi = std::acos(z / r);
    theta = std::atan2(y, x);
}

bool CrystalEyeSteppingAction::isAbovePlane(double x, double y, double z, double* normal, double D) {
    double dotProduct = normal[0] * x + normal[1] * y + normal[2] * z;
    return dotProduct + D < 0;
}

// Check if the point is within the specified layer
bool CrystalEyeSteppingAction::isInLayer(double phi, double theta) {
    // Convert radians to degrees
    double phiDeg = phi * 180.0 / M_PI;
    double thetaDeg = theta * 180.0 / M_PI;
    // Check ranges
    return phiDeg >= 0 && phiDeg <= 30 && thetaDeg >= -15 && thetaDeg <= 15;
}

//------------------------------------------------------------
void CrystalEyeSteppingAction::UserSteppingAction(const G4Step* step)
{
	G4int fID = eventAct->GetEventID();

    //G4cout << "ID: " << fID << G4endl;
	G4double fedep = step->GetTotalEnergyDeposit();
	G4int    ftrackid = step->GetTrack()->GetTrackID();
	G4int    fstepid  = step->GetTrack()->GetCurrentStepNumber();
	//G4int fparentid= step->GetTrack()->GetParentID();
	//G4int fpdg = step->GetTrack()->GetDefinition()->GetPDGEncoding();

	G4StepPoint* fpreStepPoint = step->GetPreStepPoint();
	G4StepPoint* fpostStepPoint= step->GetPostStepPoint();
	G4LogicalVolume* fpreVolum =  fpreStepPoint ->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

	G4String fpreVolumName = fpreVolum->GetName();
	G4String fparticleName = step->GetTrack()->GetDefinition()->GetParticleName();
	G4ThreeVector fposition= fpreStepPoint->GetPosition();

	G4ThreeVector position = step->GetTrack()->GetVertexPosition();


//    G4GeometryTolerance::GetInstance()->SetSurfaceTolerance(1e-6);


	if(fpreVolumName.find("Structure") != std::string::npos){
		eventAct->AddStructureEdep(fedep);
	}

	//if(ftrackid==1 && fstepid==2){//Judge the first hits;


if(ftrackid==1 && eventAct->GetEvtInFOV()==0){
		//if (fpreVolumName.find("ACD0") != std::string::npos || 
		//fpreVolumName.find("UpStructure") != std::string::npos ||
        //fpreVolumName.find("UpPixel0") != std::string::npos || 
        //fpreVolumName.find("UpPixel1") != std::string::npos ||
        //fpreVolumName.find("UpPixel2") != std::string::npos ||  
        //fpreVolumName.find("DownPixel0") != std::string::npos ||
        //fpreVolumName.find("DownPixel1") != std::string::npos ||
        //fpreVolumName.find("DownPixel2") != std::string::npos){
		if( fpreVolumName.find("World")==std::string::npos ){
		//G4LogicalVolume* fpostVolum = fpostStepPoint->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
		//G4String fpostVolumName = fpostVolum->GetName();
		//G4cout
		//	<<"######  PriVolume: "<<fpreVolumName.c_str()
		//	<<"  PostVolume: "<<fpostVolumName.c_str()
		//	<<"  ######"<<G4endl;

		//G4cout
		//	<<"  EventID = "<<fID
		//	<<"  trackID = "<<ftrackid
		//	<<"  stepID = "<<fstepid
		//	<<G4endl;
		eventAct->SetEvtInFOV(1);
		G4cout << "HHHH" << G4endl;
	    G4double edep = step->GetTotalEnergyDeposit();
            if (edep > 0) {

   	    eventAct->SetFirstPos(fposition);  
   	    }
           double x = position.x() / CLHEP::cm; // Convert from default (probably mm) to meters
		   double y = position.y() / CLHEP::cm;
	       double z = position.z() / CLHEP::cm;
			//G4cout <<"PROVERKA:" << z<< G4endl;

            //double r, phi, theta;
            //cartesianToSpherical(x, y, z, r, phi, theta);
           
         //   if ((isAbovePlane(x, y, z, normal, D)) && (fpreVolumName.find("ACD0")!=std::string::npos) ) {
         //	 if ((isAbovePlane(x, y, z, normal, D)) ) {

        /* if (fpreVolumName.find("UpStructure") == std::string::npos) {
    // Проверяем, что это один из детекторов
        if (fpreVolumName.find("ACD0") != std::string::npos || 
        fpreVolumName.find("UpPixel0") != std::string::npos || 
        fpreVolumName.find("UpPixel1") != std::string::npos ||
        fpreVolumName.find("UpPixel2") != std::string::npos ||  
        fpreVolumName.find("DownPixel0") != std::string::npos ||
        fpreVolumName.find("DownPixel1") != std::string::npos ||
        fpreVolumName.find("DownPixel2") != std::string::npos){


         //	if ((fpreVolumName.find("ACD0")!=std::string::npos) ) {
          //  	G4cout << "this is:   " << normal[0] << G4endl;
          //  	G4cout << "this is D:   " << D << G4endl;
          //  	G4cout << "this is our z: " << z << G4endl;
            //	G4cout << "hui" << G4endl;
 				eventAct->SetEvtInFOV(1);
			    eventAct->SetFirstPos(fposition);  
			    }         	
            }*/
			/*if( fpreVolumName.find("ACD1")!=std::string::npos){
				eventAct->SetEvtInFOV(1);
			    eventAct->SetFirstPos(fposition);
			}*/


			//Judge the first hit Volume; 0:suppoting Sturcture 1:Senstive Detector 
			if( fpreVolumName.find("Structure")==std::string::npos){
				eventAct->SetFirstHisVolume(1);
			}
		}
	}



	if(ftrackid!=1 && eventAct->GetInteraction()==0){
		if( fpreVolumName.find("World")==std::string::npos ){
			eventAct->SetInteraction(1);
		}
	}

	G4double stepTime = fpreStepPoint->GetGlobalTime();
	//if(stepTime>30.)
	//	G4cout
	//		<<"  stepTime = "<<stepTime
	//		<<"  stepTime = "<<stepTime/CLHEP::us
	//		<<"  stepTime = "<<stepTime/CLHEP::s
	//		<<"  stepEdep = "<<fedep
	//		<<G4endl;



}
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
