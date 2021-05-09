# DLBFoam: Dynamic load balancing for fast reactive simulations
![v1.1](https://img.shields.io/badge/DLBFoam-v1.1-blue)
![OpenFOAM 8](https://img.shields.io/badge/OpenFOAM-8-brightgreen)

## DLBFoam v1.1 - What's new?
DLBFoam v1.1 introduces a fully analytical chemistry Jacobian via [pyJac](https://github.com/SLACKHA/pyJac), and optimized ODE solution routines via [LAPACK](http://www.netlib.org/lapack/). Combined with the load balancing features, v1.1 provides up to x250 speed-up compared to standard OpenFOAM chemistry model. If you are interested with using only dynamic load balancing without any third party dependency, please use [DLBFoam v1.0](https://github.com/blttkgl/DLBFoam/releases/tag/v1.0_OF8).

## What is DLBFoam?
DLBFoam is an open-source library for OpenFOAM. It introduces dynamic load balancing and a zonal reference mapping model 
for fast chemistry calculation in parallel simulations. In addition, it also introduces a fully analytical Jacobian formulation and optimized ODE solution routines for further speed-up.

 
## Why do I need this?

Load imbalance in parallel reactive simulations is an issue that causes very long
simulation times in OpenFOAM simulations utilizing finite-rate chemistry.

DLBFoam introduces runtime load balancing through MPI routines
to minimize the load imbalance between ranks and gain speed-up. The implementation
details can be found in our paper [[1]](#1). In addition, the cell-wise chemistry problem is vastly improved by the analytical Jacobian formulation and optimized matrix operations in the ODE solver class. The details for those implementations can be found in our follow-up paper [[2]](#2).


![crab pet](https://i.imgur.com/yYVBgHV.gif)

## Prerequisites
- OpenFOAM installation (with correct version)
- LAPACK (Intel-MKL, OpenBLAS or standalone)
- Cmake
- [ct2foam](https://github.com/kahilah/ct2foam) (Optional)

## Compilation

DLBFoam can be compiled by typing the following command after sourcing appropriate OpenFOAM version and making sure a valid LAPACK installation exists:

```
./Allwmake --clean --platform <LAPACK_INSTALLATION_TYPE>
```
<LAPACK_INSTALLATION_TYPE> can be MKL, OPENBLAS or STANDALONE.


DLBFoam requires LAPACK packages for improved ODE routines (LAPACKE C interface for OPENBLAS and standalone installation). There are three different ways to provide LAPACK for DLBFoam:

- **Intel-MKL**: Install/load [Intel-MKL](https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/onemkl.html) on your workstation/cluster. Installation instructions can be found online. If you are on cluster, you can most probably load it by:  
    ```
    module load intel-mkl
    ```
    make sure that the MKLROOT bash variable is defined by typing ```echo $MKLROOT``` to your terminal. This option is the fastest option for Intel processors due to optimization of MKL with Intel hardware.

- **OpenBLAS**: Install/load [OpenBLAS](https://www.openblas.net/). It may be available on your cluster as a module, similar to Intel-MKL. Make sure that the OPENBLAS_INSTALL_ROOT bash variable is defined by typing ```echo $OPENBLAS_INSTALL_ROOT```, and define it in your ```bashrc``` if it is not.

- **Standalone**: A standalone installation may be a good idea if you are on your personal workstation and not on a cluster. Install LAPACKE-dev libraries by:

    ```
    (sudo) apt-get install liblapacke-dev
    ```

## Usage
Once the compilation is successful, any case running with standard OpenFOAM can be easily converted to
use DLBFOAM, following these steps:

* The DLBFoam should be linked to the solver. Add the following to your system/controlDict file:

```
libs
(
    "libchemistryModel_DLB.so" 
);
```

* Select chemistry solver method as loadBalanced in constant/chemistryProperties:

```
chemistryType
{
    solver          ode_LAPACK;
    method          loadBalanced;
}
```

* Add the loadbalancing subdictionary to the same chemistryProperties file:

```
loadbalancing
{
    active true;
    log	true;
}
```

* (Optional) Set the refmapping as active in chemistryProperties file if you want to 
    use the reference mapping method (you have to add an empty refmapping{} dict
    even if you do not use it):

```
refmapping
{
    active  true;
    
    mixtureFractionProperties
    {
        oxidizerMassFractions
        {
            N2       0.77;
            O2       0.23;
        }

        fuelMassFractions
        {
            NC12H26       1.0;
        }

        #include "$FOAM_CASE/constant/thermo.compressibleGasGRI"
    }
    tolerance	1e-4;  // mixture fraction tolerance
    deltaT	2; // temperature tolerance
}
```
Reference mapping uses mixture fraction (Z) and maps a reference solution to reference
cells satisfying a condition.

The entry above sets the Z=0 and Z=1 conditions from given mass fractions. For each
CFD iteration it finds a reference solution where Z<tolerance and solves the chemistry.
Subsequent cells following the same condition are mapped from this reference solution.

Optional: When deltaT is explicitly set, the mapper also checks the temperature
between reference solution and other reference cells and ensures:
abs(T<sub>cell</sub>-T<sub>ref</sub>)<deltaT.


* Run the case normally with OpenFOAM's reactive solvers.

For a working example, check the tutorials given in tutorials folder.

## Getting help and reporting bugs

Please submit a GitHub issue if you found a bug in the program. If you need help with the software or have further questions,
contact bulut.tekgul@aalto.fi.

## Citation

If you use our model, please cite the publication describing its implementation [[1]](#1). 

## References

<a id="1">[1]</a> 
Tekgul, Peltonen, Kahila, Kaario, Vuorinen (2020). [DLBFoam: An open-source dynamic load balancing model for fast reacting flow simulations in OpenFOAM](https://arxiv.org/abs/2011.07978)
