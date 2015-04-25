#ifndef DavisRunIITauTau_CustomPatCollectionProducers_ELECTRONCLONES_h
#define DavisRunIITauTau_CustomPatCollectionProducers_ELECTRONCLONES_h



/* clones a pat::Electron collection with embedded user floats */

// system include files
#include <memory>
#include <assert.h>     

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
//#include "FWCore/Framework/interface/EDAnalyzer.h"

//#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "DataFormats/Common/interface/ValueMap.h"

#include "DataFormats/PatCandidates/interface/Electron.h"

#include "EgammaAnalysis/ElectronTools/interface/EGammaMvaEleEstimatorCSA14.h"
#include "DavisRunIITauTau/CustomPatCollectionProducers/interface/LeptonRelativeIsolationTool.h"

#include "DavisRunIITauTau/CustomPatCollectionProducers/interface/TriggerInfoEmbeddingTool.h"





#include "TH1D.h"
#include <map>
#include "TFile.h"
#include <math.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TString.h"

typedef edm::Handle<edm::View<pat::Electron> > 	slimmedPatElectronCollection;

class electronClones
{

	// input electrons and vertex
	const slimmedPatElectronCollection& electrons;
	const reco::Vertex & first_vertex;



	// the mva ID evaluators and the names of thier embedded userFloats
	EGammaMvaEleEstimatorCSA14 & MVA_PHYS14nonTrig;
	std::string & MVA_PHYS14nonTrig_NAME;

	// trigger related collections

	edm::Handle<edm::TriggerResults> & triggerBits;   
	edm::Handle<pat::TriggerObjectStandAloneCollection> & triggerObjects;
	edm::Handle<pat::PackedTriggerPrescales> & triggerPreScales;
	const edm::TriggerNames & names;
	double trigMatchDRcut;
	std::vector<int> trigMatchTypes;
	std::vector<std::string> trigSummaryPathsAndFilters;

	// rho related info
	std::vector<std::string> rhoLabels;
	std::vector<double> rhoValues;


	public:
		electronClones(const slimmedPatElectronCollection&, const reco::Vertex &,
				EGammaMvaEleEstimatorCSA14 &, 
				std::string &,
				edm::Handle<edm::TriggerResults> &,
				edm::Handle<pat::TriggerObjectStandAloneCollection> &,
				edm::Handle<pat::PackedTriggerPrescales>&,
				const edm::TriggerNames &,
				double,
				std::vector<int>,
				std::vector<std::string>,
				std::vector<std::string>,
				std::vector<double>);

		virtual ~electronClones();

		// the cloned collection which will have the user floats embedded
		std::vector <pat::Electron> clones;

	private:
		void clone();
		void fillUserFloats();		  


};





#endif
  


