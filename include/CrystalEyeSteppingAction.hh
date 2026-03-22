// **************************************************************
//
//      ------ CrystaliEyeSteppingAction  ------
//           by Aleksei Smirnov (23 Sep 2023)
//           Email: aleksei.smirnov@gssi.it
//
// **************************************************************

#ifndef CrystalEyeSteppingAction_h
#define CrystalEyeSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

class CrystalEyeDetectorConstruction;
class CrystalEyeEventAction;

class CrystalEyeSteppingAction : public G4UserSteppingAction
{
	public:
		CrystalEyeSteppingAction(
				CrystalEyeEventAction * evt);
		~CrystalEyeSteppingAction();

		void UserSteppingAction(const G4Step*);
		void cartesianToSpherical(double x, double y, double z, double &r, double &phi, double &theta);
		bool isInLayer(double phi, double theta);
		bool isAbovePlane(double x, double y, double z, double normal[], double D); 


	private:
		CrystalEyeEventAction*	eventAct;
		double normal[3] = {-0.0, -21.70820544654001, -81.00447167592}; // Нормаль к плоскости
	//	double normal[3] = {-0.0, -13.129510446005371, -48.99999997084212};
        double D = 1408.4247490292212; // Коэффициент D уравнения плоскости
	//	 double D = 662.6251164399999;
       double R = 18.0; // Радиус сферы
	//	 double R = 14.0;

		G4int fevtid;

	//	'-0.0x + -13.129510446005371y + -48.99999997084212z + 662.6251164399999 = 0'

};


#endif
