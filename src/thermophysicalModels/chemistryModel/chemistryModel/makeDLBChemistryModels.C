/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | DLBFoam: Dynamic Load Balancing 
   \\    /   O peration     | for fast reactive simulations
    \\  /    A nd           | 
     \\/     M anipulation  | 2020, Aalto University, Finland
-------------------------------------------------------------------------------
License
    This file is part of DLBFoam library, derived from OpenFOAM.

    https://github.com/blttkgl/DLBFoam

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.
    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.
    
\*---------------------------------------------------------------------------*/

#include "makeChemistryModel.H"

#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"

#include "LoadBalancedChemistryModel.H"
#include "pyJacLoadBalancedChemistryModel.H"


#include "thermoPhysicsTypes.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{


    // Make base types
    makeChemistryModel(psiReactionThermo);
    makeChemistryModel(rhoReactionThermo);

    // Chemistry moldels based on sensibleEnthalpy
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constGasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constGasHThermoPhysics
    );    
//XXX    
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        gasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        gasHThermoPhysics
    );

//XXX        
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constIncompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constIncompressibleGasHThermoPhysics
    );

//XXX 
    
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        incompressibleGasHThermoPhysics
    );


    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        incompressibleGasHThermoPhysics
    );


//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        icoPoly8HThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        icoPoly8HThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constFluidHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constAdiabaticFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constAdiabaticFluidHThermoPhysics
    );

//XXX 


    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constHThermoPhysics
    );


//XXX 
    
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constGasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constGasHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        gasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        gasHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constIncompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constIncompressibleGasHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        incompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        incompressibleGasHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        icoPoly8HThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        icoPoly8HThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constFluidHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constAdiabaticFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constAdiabaticFluidHThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constHThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constHThermoPhysics
    );    
    


    // Chemistry moldels based on sensibleInternalEnergy
    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        gasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        gasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constIncompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constIncompressibleGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        incompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        incompressibleGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        icoPoly8EThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        icoPoly8EThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constFluidEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constAdiabaticFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constAdiabaticFluidEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        psiReactionThermo,
        constEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        psiReactionThermo,
        constEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        gasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        gasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constIncompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constIncompressibleGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        incompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        incompressibleGasEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        icoPoly8EThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        icoPoly8EThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constFluidEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constAdiabaticFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constAdiabaticFluidEThermoPhysics
    );

//XXX 

    makeChemistryModelType
    (
        LoadBalancedChemistryModel,
        rhoReactionThermo,
        constEThermoPhysics
    );

    makeChemistryModelType
    (
        pyJacLoadBalancedChemistryModel,
        rhoReactionThermo,
        constEThermoPhysics
    );
    
}

// ************************************************************************* //
