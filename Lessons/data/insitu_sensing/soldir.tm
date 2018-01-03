   KPL/MK
 
   The names and contents of the kernels referenced by this meta-kernel are
   as follows:
 
   File Name                            Description 
   --------------------------           ---------------------------------- 
   naif0008.tls                         Generic LSK.
   cas00084.tsc                         Cassini SCLK. 
   020514_SE_SAT105.bsp                 Saturnian Satellite
   030201AP_SK_SM546_T45.bsp            Ephemeris SPK. 
   981005_PLTEPH-DE405S.bsp             Cassini Spacecraft SPK.
   sat128.bsp                           Planetary Ephemeris SPK. 
   04135_04171pc_psiv2.bc               Saturnian Satellite Ephemeris SPK. 
   cas_v37.tf                           Cassini Spacecraft CK.

 
   \begindata 
       KERNELS_TO_LOAD = ( 
                           './data/insitu_sensing/kernels/lsk/naif0008.tls'
                           './data/insitu_sensing/kernels/sclk/cas00084.tsc' 
                           './data/insitu_sensing/kernels/spk/020514_SE_SAT105.bsp'
                           './data/insitu_sensing/kernels/spk/030201AP_SK_SM546_T45.bsp'
                           './data/insitu_sensing/kernels/spk/981005_PLTEPH-DE405S.bsp' 
                           './data/insitu_sensing/kernels/spk/sat128.bsp'
                           './data/insitu_sensing/kernels/ck/04135_04171pc_psiv2.bc' 
                           './data/insitu_sensing/kernels/fk/cas_v37.tf' ) 
   \begintext
  
 