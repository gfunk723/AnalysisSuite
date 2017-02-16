####################################################################################################
# config file containing all electron selections
# contains : 
#              electronFilter - cms.string of initial cuts imposed on slimmedElectrons
#
#

import FWCore.ParameterSet.Config as cms
from and_string_concatonator import and_string_concatonator

####################################################################################################
####################################################################################################
####################################################################################################
# electronFilter : initial cut applied to slimmedElectrons
# only objects passing these requirements will be considered 
# (everything failing is dropped)


########################
# user should modify the append statements below to change electron filter cut settings
# they will be (&&) concatenated to form one string cut
# see (https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuidePhysicsCutParser) 
# for allowed syntax

filter_ = []

# ----------------------------------------------------
# ------------[user edit here]------------------------
filter_.append('pt>10.0')
filter_.append('abs(eta)<2.5')
filter_.append('abs(userFloat("dxy"))<0.045')
filter_.append('abs(userFloat("dz"))<0.2')
filter_.append('userFloat("passConversionVeto")==1.0')
filter_.append('userFloat("numberOfMissingInnerHits")<=1.0')
filter_.append('( (abs(userFloat("PASS_generalPurposeMVA80"))==1.0) || (abs(userFloat("PASS_generalPurposeMVA90"))==1.0) )')

# ----------------------------------------------------
# ----------------------------------------------------

electronFilter = cms.string(and_string_concatonator(filter_))


####################################################################################################
####################################################################################################
####################################################################################################




