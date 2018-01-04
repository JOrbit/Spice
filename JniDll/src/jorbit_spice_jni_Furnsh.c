#include "jorbit_spice_jni_Furnsh.h"

JNIEXPORT void JNICALL Java_jorbit_spice_jni_Furnsh_cFurnsh
(JNIEnv *je, jclass jc, jstring kernel) {

   //
   // Get a local copy of the kernel string
   //
   jboolean iscopy;
   const char* ns = (*je)->GetStringUTFChars(je, kernel, &iscopy);
    
   //
   // Send kernel string to FURNSH_C
   //
   printf("INFO: Java_jorbit_spice_jni_Furnsh_cFurnsh: kernel = %s\n", ns);

   //
   // Release the kernel string.
   //
   (*je)->ReleaseStringUTFChars(je, kernel, ns);

}