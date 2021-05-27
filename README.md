# DLBFoam: Dynamic load balancing for fast reactive simulations
![v1.1](https://img.shields.io/badge/DLBFoam-v1.1-blue)
![OpenFOAM 7](https://img.shields.io/badge/OpenFOAM-7-brightgreen)

## DLBFoam v1.1 - What's new?
DLBFoam v1.1 introduces a fully analytical chemistry Jacobian via [pyJac](https://github.com/SLACKHA/pyJac), and optimized ODE solution routines via [LAPACK](http://www.netlib.org/lapack/). Combined with the load balancing features, v1.1 provides up to x250 speed-up compared to standard OpenFOAM chemistry model. If you are interested with using only dynamic load balancing without any third party dependency, please use [DLBFoam v1.0](https://github.com/blttkgl/DLBFoam-1.0).

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
    make sure that the ```MKLROOT``` bash variable is defined by typing ```echo $MKLROOT``` to your terminal. This option is the fastest option for Intel processors due to optimization of MKL with Intel hardware.

- **OpenBLAS**: Install/load [OpenBLAS](https://www.openblas.net/). It may be available on your cluster as a module, similar to Intel-MKL. Make sure that the ```OPENBLAS_INSTALL_ROOT``` bash variable is defined by typing ```echo $OPENBLAS_INSTALL_ROOT```, and define it in your ```bashrc``` if it is not.

- **Standalone**: A standalone installation may be a good idea if you are on your personal workstation and not on a cluster. Install LAPACKE-dev libraries by:

    ```
    (sudo) apt-get install liblapacke-dev
    ```

## Mechanism generation
After the successful compilation, the C subroutines generated by the pyJac for the analytical Jacobian should be compiled and linked to the OpenFOAM case folder. 

In this repository, we provide the input files and C subroutines generated by pyJac for [GRI-3.0](http://combustion.berkeley.edu/gri-mech/version30/text30.html), [Yao](https://www.sciencedirect.com/science/article/abs/pii/S001623611631184X), and [DRM-19](http://combustion.berkeley.edu/drm/) mechanisms. If you want to use one of these mechanisms, no other dependency is required (except a ```CMake``` installation).

* Go to the ```utilities/``` folder, and execute ```Allrun``` as:

```
./Allrun -m <mechName>
```
where ```<mechName>``` is ```gri30```, ```yao```, or ```drm19```. This command will generate a folder called ```foam_mech```, which contains the chemical mechanism input files and a library generated from the files generated by pyJac. You need to put this folder to your simulation case and link it through ```controlDict```, as explained in the next section.

**If you want to use a different chemical mechanism**, you need to create the thermo input files in a format required by OpenFOAM, as well as analytical Jacobian C subroutines generated by pyJac. This process requires many dependencies, most notably [Cantera](https://cantera.org/) and pyJac.

We have developed a tool called
[ct2foam](https://github.com/kahilah/ct2foam) that makes this process a lot easier. Please check ct2foam (and the pyjac2foam utility in it) if you are interested in using a different mechanism.
## Usage

Once the compilation is successful, any case running with standard OpenFOAM can be easily converted to
use DLBFOAM, following these steps:

* The DLBFoam should be linked to the solver. Add the following to your system/controlDict file:

```
libs
(
    "libchemistryModel_DLB.so" 
    "libODE_DLB.so"
    "$FOAM_CASE/constant/foam_mech/libc_pyjac.so"
);
```
the first two libraries link the DLBFoam and the optimized LAPACK solvers, while the last library links the C subroutines generated in the previous section for the analytical Jacobian.

* Select chemistry solver as ```ode_LAPACK``` and the method as ```loadBalanced_pyJac``` in constant/chemistryProperties:

```
chemistryType
{
    solver          ode_LAPACK;
    method          loadBalanced_pyJac;
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

* Set the solver flag under ```odeCoeffs``` to ```seulex_LAPACK``` in order to use the optimized ODE solvers:
```
odeCoeffs
{
    solver          seulex_LAPACK;
    absTol          1e-08;
    relTol          1e-05;
}
```
* (Optional) Set the refmapping as active in chemistryProperties file if you want to 
    use the reference mapping method (you have to add an empty ```refmapping{}``` dict
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

        #include "$FOAM_CASE/constant/foam_mech/thermo.foam"
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

(Optional) When deltaT is explicitly set, the mapper also checks the temperature
between reference solution and other reference cells and ensures:
abs(T<sub>cell</sub>-T<sub>ref</sub>)<deltaT.


* Run the case normally with OpenFOAM's reactive solvers.

For a working example, check the tutorials given in tutorials folder.

## Contributors
- Bulut Tekgül (buluttekgul@gmail.com)
- Petteri Peltonen (petteri.peltonen@aalto.fi)
- Heikki Kahila (heikki.kahila@wartsila.com)
- Ilya Morev (ilya.morev@aalto.fi)
- Mahmoud Gadalla (mahmoud.gadalla@aalto.fi)


## Getting help and reporting bugs

Please submit a GitHub issue if you found a bug in the program. If you need help with the software or have further questions, either open an issue or contact the contributors.

## Citation

If you use our model, please cite the publication describing its implementation, Refs. [[1]](#1) and [[2]](#2). 

## References

<a id="1">[1]</a> 
B. Tekgül,  P. Peltonen,  H. Kahila,  O. Kaario,  V. Vuorinen,  DLBFoam: An open-source dynamic load balancing model for fast reacting flow simulations in OpenFOAM, arXiv preprint [arXiv:2011.07978](https://arxiv.org/abs/2011.07978) (2020).
<details>
<summary>BibTex</summary>
<p>
 
```
@article{tekgul2020dlbfoam,
  title={DLBFoam: An open-source dynamic load balancing model for fast reacting flow simulations in OpenFOAM},
  author={Tekg{\"u}l, Bulut and Peltonen, Petteri and Kahila, Heikki and Kaario, Ossi and Vuorinen, Ville},
  journal={arXiv preprint arXiv:2011.07978},
  year={2020}
}
```
 
</p>
</details>

<a id="2">[2]</a> 
I. Morev, B. Tekgül, M. Gadalla, A. Shahanaghi, J. Kannan, S. Karimkashi, O. Kaario, V. Vuorinen, Fast reactive flow simulations using analytical Jacobian and dynamic load balancing in OpenFOAM, arXiv preprint [arXiv:2105.12070](https://arxiv.org/abs/2105.12070) (2021).
<details>
<summary>BibTex</summary>
<p>
 
```
@article{morev2021fast,
  title={Fast reactive flow simulations using analytical Jacobian and dynamic load balancing in OpenFOAM},
  author={Morev, Ilya and Tekg{\"u}l, Bulut and Gadalla, Mahmoud and Shahanaghi, Ali and Kannan, Jeevananthan and Karimkashi, Shervin and Kaario, Ossi and Vuorinen, Ville},
  journal={arXiv preprint arXiv:2105.12070},
  year={2021}
}
```
 
</p>
</details>
