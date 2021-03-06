 KPL/MK
 
      Meta-kernel for the ``Moon Rotation'' task in the Binary PCK
      Hands On Lesson.
 
      The names and contents of the kernels referenced by this
      meta-kernel are as follows:
 
      File name                    Contents
      ---------------------------  ------------------------------------
      naif0008.tls                 Generic LSK
      de414_2000_2020.bsp          Solar System Ephemeris
      moon_060721.tf               Lunar FK
      pck00008.tpc                 NAIF text PCK
      moon_pa_de403_1950-2198.bpc  Moon binary PCK
 
      \begindata
 
         KERNELS_TO_LOAD = ( './data/binary_pck/kernels/lsk/naif0008.tls'
                             './data/binary_pck/kernels/spk/de414_2000_2020.bsp'
                             './data/binary_pck/kernels/fk/moon_060721.tf'
                             './data/binary_pck/kernels/pck/pck00008.tpc'
                             './data/binary_pck/kernels/pck/moon_pa_de403_1950-2198.bpc' )
      \begintext
